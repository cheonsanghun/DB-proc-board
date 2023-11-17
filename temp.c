
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

// 텍스트 입력 헤더
#include <locale.h>
#include <io.h>
#include <fcntl.h>

/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>


/*---------------  화면 커서 위치 제어 ----------------------*/
#include < windows.h >
void gotoxy(int x, int y) ;
void getxy(int *x, int *y) ;
void clrscr(void) ;
/*-----------------------------------------------------------*/

void DB_connect();
void Get_tuple();
void sql_error(char *msg) ;
void login();
int check_user_info();
void signup();
int check_id(const char *id);
void pw_input(char *pw);
void save_user_info(char *id, char *pw);
void text_input();
void input_post(const char* title, const wchar_t* w_text);
int get_post_id();

EXEC SQL BEGIN DECLARE SECTION;
	VARCHAR uid[80];
	VARCHAR pwd[20];
EXEC SQL END DECLARE SECTION;

// win32 Visual C 컴파일시 추가
#define getch() _getch()

/* 사용자 정보를 저장할 구조체 */
struct UserInfo {
    char id[20];
    char pw[20];
};

bool login_state = false;

// 유저 정보 
struct UserInfo user;

void get_text() {
    EXEC SQL BEGIN DECLARE SECTION;
        varchar text[2000];
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* Cursor 선언 */
    EXEC SQL DECLARE text_cursor CURSOR FOR
        SELECT text FROM test;

    /* Cursor 열기 */
    EXEC SQL OPEN text_cursor;

    /* 결과 읽기 */
    while (1) {
        EXEC SQL FETCH text_cursor INTO :text;
        if (sqlca.sqlcode != 0) break;  // No more rows

        text.arr[text.len] = '\0';
        printf("%s\n", text.arr);
    }

    /* Cursor 닫기 */
    EXEC SQL CLOSE text_cursor;
}

void main(){
    // 인코딩 설정
    _putenv("NLS_LANG=American_America.KO16KSC5601");
	DB_connect();
    int msg_state = 0;// 1: 명령어 없음, 2: 이미 로그인 상태
    while(true){
        system("cls"); // 콘솔화면 초기화
        // 가로 80, 세로 24
        printf("--------------------------------------------------------------------------------\n");
        printf("                                    메인화면\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                                   [ 명령어 ]\n");
        printf("\n");
        if(msg_state==1){printf("                           명령어를 찾을 수 없습니다.\n");}else if (msg_state==2){gotoxy(0 ,5);printf("                               로그인 상태입니다.\n");}else if(msg_state==3){gotoxy(0 ,5);printf("                               게스트 모드입니다.\n");}else{printf("\n");}
        printf("\n");
        printf("\n");
        printf("                                     login\n");
        printf("\n");
        printf("                                     logout\n");
        printf("\n");
        printf("                                     singup\n");
        printf("\n");
        printf("                                     write\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        if (login_state){gotoxy(0, 22);printf("%s\n",user.id);}else{printf("\n");}
        printf("--------------------------------------------------------------------------------\n");
        printf("> ");
        msg_state = 0;
        char op[20];
        gotoxy(2, 24);
        scanf("%s", op);
        if (strcmp(op, "login") == 0) {
            if (!login_state)
                login();
            else{
                msg_state = 2;
            }
        } else if (strcmp(op, "signup") == 0) {
            signup();
        } else if(strcmp(op, "logout") == 0){
            login_state = false;
            user.id[0] = '\0';
            user.pw[0] = '\0';
            msg_state = 0;
        } else if(strcmp(op, "write") == 0){
            if(!login_state){
                msg_state = 3;
            } else{
                text_input();
            }
        } else if(strcmp(op, "a") == 0){
            get_text();
        }
        else {
            msg_state = 1;
        }
    }
}

// 이번에 입력에 사용할 게시물 id를 가져옵니다.
int get_post_id(){
    EXEC SQL BEGIN DECLARE SECTION;
        int max_post_id;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 실행시킬 SQL 문장*/
    EXEC SQL SELECT NVL(MAX(post_id), 0) INTO :max_post_id FROM post;

    /* 확인용: 오류 코드 출력 */
    printf("SQLCODE: %d\n", sqlca.sqlcode);

    if (sqlca.sqlcode != 0) {
        /* 오류 발생 시 처리 */
        return 1; // 예외 처리를 원하는 방식으로 수정하세요.
    }

    /* 결과에 1을 더한 값을 반환 */
    return max_post_id + 1;
}

void input_post(const char* title, const wchar_t* w_text) {
    int strSize = WideCharToMultiByte(CP_ACP, 0, w_text, -1, NULL, 0, NULL, NULL);
    char* pStr;
    
    pStr = (char *)malloc(strSize);

    WideCharToMultiByte(CP_ACP, 0, w_text, -1, pStr, strSize, 0, 0);
    
    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
        varchar v_id[20];
        varchar v_title[128];
        varchar v_text[2000]; 
        int v_del;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 사용자가 입력한 데이터를 Oracle 변수에 복사 */
    v_post_id = get_post_id();

    strncpy((char *)v_title.arr, title, 128);
    v_title.len = strlen((char *)v_title.arr);

    strncpy((char *)v_text.arr, pStr, 2000);
    v_text.len = strlen((char *)v_text.arr);

    v_del = 0;

    // v_id에 user.id를 복사
    strncpy((char*)v_id.arr, user.id, 20); 
    v_id.len = strlen((char*)v_id.arr);

    /* 실행시킬 SQL 문장*/
    EXEC SQL INSERT INTO post (post_id, id, title, text, del) VALUES (:v_post_id, :v_id, :v_title, :v_text, :v_del);

    EXEC SQL COMMIT;
    
    /* 확인용: 오류 코드 출력 */
    printf("SQLCODE: %d\n", sqlca.sqlcode);
    free(pStr);
}

void text_input(){
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("제목:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                     [ 본문 ]\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("종료하려면 Esc 키를 누르세요.\n");

    char title[128];
    // 제목 입력단.
    gotoxy(6, 1);
    scanf("%s",title);

    // 본문 입력단.
    gotoxy(0, 4);
    _setmode(_fileno(stdout), _O_U16TEXT); // 유니코드 출력을 위한 모드 설정
    _setmode(_fileno(stdin), _O_U16TEXT);  // 유니코드 입력을 위한 모드 설정

    wchar_t inputBuffer[2000]; // 충분한 크기의 배열로 설정
    memset(inputBuffer, 0, sizeof(inputBuffer)); // 배열 초기화
    int index = 0;
    wchar_t ch;

    while (1) {
        ch = _getwch(); // _getwch() 함수를 사용하여 유니코드 키 입력을 받음

        if (ch == 27) { // 27은 Esc 키의 ASCII 코드
            inputBuffer[index] = L'\0';
            _setmode(_fileno(stdout), _O_TEXT); // 텍스트 출력 모드로 전환
            _setmode(_fileno(stdin), _O_TEXT);  // 텍스트 입력 모드로 전환
            input_post(title, inputBuffer);
            return;  // text_input 함수를 종료하고 main 함수의 while 루프로 돌아감
        }
        else if (ch == 8) {
            if (index > 0) {
                wprintf(L"\b \b"); // 백스페이스 효과
                inputBuffer[--index] = L'\0';
                gotoxy(0, 0);
                system("cls");
                wprintf(L"--------------------------------------------------------------------------------\n");
                _setmode(_fileno(stdout), _O_TEXT); // 텍스트 출력 모드로 전환
                _setmode(_fileno(stdin), _O_TEXT);  // 텍스트 입력 모드로 전환
                printf("제목: %s\n", title);
                _setmode(_fileno(stdout), _O_U16TEXT); // 유니코드 출력을 위한 모드 설정
                _setmode(_fileno(stdin), _O_U16TEXT);  // 유니코드 입력을 위한 모드 설정
                wprintf(L"--------------------------------------------------------------------------------\n");
                wprintf(L"                                     [ 본문 ]\n");
                wprintf(L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                wprintf(L"--------------------------------------------------------------------------------\n");
                wprintf(L"종료하려면 Esc 키를 누르세요.\n");
                gotoxy(0, 4);
                wprintf(L"%ls", inputBuffer);
            }
        }
        else if (ch == L'\r') {
            if(index < 18){
                wprintf(L"\n");
                inputBuffer[index++] = '\n';
            }
        }
        // Enter 키를 누를 때는 처리하지 않음
        else if (ch != L'\r') {
            wprintf(L"%c", ch);
            inputBuffer[index++] = ch;
        }
        // 배열이 가득 차면 입력을 종료
        if (index >= sizeof(inputBuffer) / sizeof(inputBuffer[0]) - 1) {
            inputBuffer[index] = L'\0'; // 배열의 끝에 NULL 문자 추가
            break;
        }
    }
}

int check_id(const char *id) {
    EXEC SQL BEGIN DECLARE SECTION;
        varchar id_var[20];
        int result_count;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 사용자가 입력한 ID를 Oracle 변수에 복사 */
    strcpy((char *)id_var.arr, id);
    id_var.len = strlen((char *)id_var.arr);

    /* 실행시킬 SQL 문장*/
    EXEC SQL SELECT count(id)
             INTO :result_count
             FROM user_info
             WHERE id = :id_var;

    return result_count;  // 결과 값 반환 (0 또는 1)
}

void signup() {
    char temp_id[20];   
    char temp_pw[20];
    char temp_pw2[20];

    system("cls"); // 콘솔화면 초기화
    printf("--------------------------------------------------------------------------------\n");
    printf("                                    회원가입\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                  [ 가입정보 ]\n");
    printf("\n\n\n");
    printf("                             ID :\n");
    printf("\n\n");
    printf("                             PW :\n");
    printf("\n\n");
    printf("                   PW (CONFIRM) : \n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");

    while (true){
        gotoxy(34, 7);
        scanf("%s", temp_id);

        if (check_id(temp_id) == 0){
            break;
        } else {
            gotoxy(32, 5);
            printf("ID가 중복됩니다!");
            gotoxy(0, 7);
            printf("                             ID :                             \n");
        }
    }

    while(1){
        gotoxy(34, 10);
        pw_input(temp_pw);
        gotoxy(34, 13);
        pw_input(temp_pw2);
        if (strcmp(temp_pw, temp_pw2) == 0) {
            break;
        } else {
            gotoxy(26, 5);
            printf("비밀번호가 일치하지 않습니다.");
            gotoxy(0, 10);
            printf("                             PW :                             ");
            gotoxy(0, 13);
            printf("                   PW (CONFIRM) :                              ");
        }        
    }
    save_user_info(temp_id, temp_pw);
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                    회원가입\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                  [ 가입정보 ]\n\n\n\n");
    printf("                           회원가입이 완료되었습니다!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
}

void save_user_info(const char *id, const char *pw){
    EXEC SQL BEGIN DECLARE SECTION;
        varchar id_var[20];
        varchar pw_var[20];
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 사용자가 입력한 ID와 PW를 Oracle 변수에 복사 */
    strcpy((char *)id_var.arr, id);
    id_var.len = strlen((char *)id_var.arr);

    strcpy((char *)pw_var.arr, pw);
    pw_var.len = strlen((char *)pw_var.arr);

    // printf("%s, %s", id_var.arr, pw_var.arr);
    // getch();

    /* 실행시킬 SQL 문장*/
    EXEC SQL INSERT INTO user_info VALUES (:id_var, :pw_var);

    EXEC SQL COMMIT;
    
    /* 확인용: 오류 코드 출력 */
    printf("SQLCODE: %d\n", sqlca.sqlcode);
}


void pw_input(char *pw) {
    int i = 0;
    while (1) {
        char ch = getch();  // 사용자 입력을 받음
        if (ch == '\r' || ch == '\n') {
            // Enter 키가 입력되면 종료
            break;
        } else if (ch == 8 && i > 0) {
            // Backspace 키가 입력되면 이전 문자 삭제
            printf("\b \b");
            pw[--i] = '\0';
        } else if (ch != 8) {
            // 비밀번호를 배열에 저장하고 '*' 출력
            pw[i++] = ch;
            printf("*");
        }
    }

    // NULL 문자를 추가하여 문자열 완성
    pw[i] = '\0';
}

void login() {
        system("cls");
        printf("--------------------------------------------------------------------------------\n");
        printf("                                      로그인\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                                  [ 로그인 정보 ]\n\n\n\n");
        printf("\n\n");
        printf("                             ID:\n");
        printf("\n\n\n");
        printf("                             PW:\n");
        printf("\n\n\n\n\n\n\n\n\n");
        printf("--------------------------------------------------------------------------------\n");

    while(1){
        gotoxy(34, 9);
        scanf("%s", user.id);
        gotoxy(34, 13);
        pw_input(user.pw);

        if (check_user_info(user) == 0) {
            gotoxy(0, 5);
            printf("                              ID나 PW를 확인해주세요.\n");
            gotoxy(0, 9);
            printf("                             ID:                             ");
            gotoxy(0, 13);
            printf("                             PW:                             ");
        } else {
            login_state = true;
            break;

        }
    }
}

int check_user_info() {
    EXEC SQL BEGIN DECLARE SECTION;
        varchar  id[20];
        varchar pw[20];
        int result_count;
    EXEC SQL END DECLARE SECTION;

   /* Register sql_error() as the error handler. */
   EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

   /* 사용자가 입력한 ID와 PW를 Oracle 변수에 복사 */
   strcpy((char *)id.arr, user.id);
   id.len = strlen((char *)id.arr);

   strcpy((char *)pw.arr, user.pw);
   pw.len = strlen((char *)pw.arr);

   /* 실행시킬 SQL 문장*/
   EXEC SQL SELECT count(id)
                   INTO :result_count
            FROM   user_info
            WHERE  id = :id AND pw = :pw;

    return result_count;  // 결과 값 반환 (0 또는 1)
}

void DB_connect()
{
   /* 본인 계정이름으로 바꾸어 쓸 것 */
   strcpy((char *)uid.arr,"a20192162@//sedb.deu.ac.kr:1521/orcl");
   uid.len = (short) strlen((char *)uid.arr);
   /* 본인 계정 암호로 바꾸어 쓸 것 */
   strcpy((char *)pwd.arr,"20192162");
   pwd.len = (short) strlen((char *)pwd.arr);

   EXEC SQL CONNECT :uid IDENTIFIED BY :pwd;

	// connection이 실패했을경우의 처리부분

	if (sqlca.sqlcode != 0 && sqlca.sqlcode != -1405){ 
		printf("\7Connect error: %s", sqlca.sqlerrm.sqlerrmc);
		getch();
		exit(-1);
	}

    printf("Oracle Connect SUCCESS by %s\n", uid.arr);
}

void Get_tuple()
{
    /* --------------------------------------------------------------------------
       Retrieve the current maximum employee number
    -------------------------------------------------------------------------- */
    EXEC SQL BEGIN DECLARE SECTION;
       varchar id[20];
       varchar pw[20];
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 실행시킬 SQL 문장*/
    EXEC SQL SELECT id, pw 
              INTO :id, :pw 
              FROM user_info 
              WHERE id = 'admin' ; 

    pw.arr[pw.len] = '\0';   
    printf("id = %s, idlen=%d, pw = %s\n", id.arr, id.len, pw.arr);
}


/* --------------------------------------------------------------------------
void sql_error(msg)

   errrpt prints the ORACLE error msg and number.
-------------------------------------------------------------------------- */
void sql_error(char *msg)

{
    char err_msg[128];
    size_t buf_len, msg_len;

    EXEC SQL WHENEVER SQLERROR CONTINUE;

    printf("\n%s\n", msg);
    buf_len = sizeof (err_msg);
    sqlglm(err_msg, &buf_len, &msg_len);
    printf("%.*s\n", msg_len, err_msg);
    getch();
    
    EXEC SQL ROLLBACK WORK;

}

/*---------------  화면 커서 제어 함수 --------------------*/
#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD Cur= {(SHORT)x, (SHORT) y};

    SetConsoleCursorPosition(STD_HANDLE, Cur);
}

void getxy(int *x, int *y)
{
    CONSOLE_SCREEN_BUFFER_INFO Buf ;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Buf);
    *x = (int)Buf.dwCursorPosition.X ;
    *y = (int)Buf.dwCursorPosition.Y ;
 
}

void clrscr(void)
{
    COORD Cur= {0, 0};
    unsigned long dwLen;

    FillConsoleOutputCharacter(STD_HANDLE, ' ', 80*25, Cur, &dwLen);
}
