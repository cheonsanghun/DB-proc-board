// win32 Visual C 컴파일시 추가
// 프로그램 가장 첫 줄에 추가할 것
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

// 콘솔 작업을 위한 헤더
#include <windows.h>

// 텍스트 입력 헤더
#include <locale.h>
#include <io.h>
#include <fcntl.h>

/* for oracle */
#include <sqlda.h>
#include <sqlca.h>
#include <sqlcpr.h>


void DB_connect();
void Get_tuple();
void sql_error(char *msg) ;
void login();
int check_user_info(struct UserInfo *user);
void signup();
int check_id(const char *id);
void pw_input(char *pw);
void save_user_info(char *id, char *pw);
void text_input();

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


void input_text(const wchar_t* inputBuffer) {
    int strSize = WideCharToMultiByte(CP_ACP, 0,inputBuffer,-1, NULL, 0,NULL, NULL);
    char* pStr;
    
    pStr = (char *)malloc(strSize);

    WideCharToMultiByte(CP_ACP, 0, inputBuffer, -1, pStr, strSize, 0,0);
    
    EXEC SQL BEGIN DECLARE SECTION;
        varchar id_var[2000]; // Use sqlnchar for Unicode strings
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 사용자가 입력한 데이터를 Oracle 변수에 복사 */
    strncpy((char *)id_var.arr, pStr, 2000);
    id_var.len = strlen((char *)id_var.arr);

    printf("%s", (char *)id_var.arr);
    fgetc(stdin);  // getchar() 대신 fgetc(stdin)을 사용

    /* 실행시킬 SQL 문장*/
    EXEC SQL INSERT INTO test VALUES (:id_var);

    EXEC SQL COMMIT;
    
    /* 확인용: 오류 코드 출력 */
    printf("SQLCODE: %d\n", sqlca.sqlcode);
    free(pStr);
}


void main()
{
    // 유저 정보 
    struct UserInfo user;
	DB_connect();

	// getch();
    while(1){
        system("cls"); // 콘솔화면 초기화
        if (login_state){
            printf("%s\n",user.id);
        }
        printf("***********************************\n");
        printf("*           메인 화면             *\n");
        printf("***********************************\n");
        // Get_tuple();
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "login") == 0) {
            if (!login_state)
                login(&user);
            else{
                printf("이미 로그인한 상태입니다.\n");
                getch(); 
            }
        } else if (strcmp(op, "signup") == 0) {
            signup();
        } else if(strcmp(op, "logout") == 0){
            login_state = false;
            user.id[0] = '\0';
            user.pw[0] = '\0';
            printf("로그아웃합니다.\n");
            getch(); 
        } else if(strcmp(op, "write") == 0){
            text_input();
        } else if(strcmp(op, "a") == 0){
            get_text();
        }
         else {
            printf("명령어가 없습니다.\n");
            getch(); 
        }
    }
}

void text_input(){
    system("cls");
    _setmode(_fileno(stdout), _O_U16TEXT); // 유니코드 출력을 위한 모드 설정
    _setmode(_fileno(stdin), _O_U16TEXT);  // 유니코드 입력을 위한 모드 설정

    wprintf(L"종료하려면 Esc 키를 누르세요.\n");

    wchar_t inputBuffer[2000]; // 충분한 크기의 배열로 설정
    memset(inputBuffer, 0, sizeof(inputBuffer)); // 배열 초기화
    int index = 0;
    wchar_t ch;

    while (1) {
        ch = _getwch(); // _getwch() 함수를 사용하여 유니코드 키 입력을 받음

        if (ch == 27) { // 27은 Esc 키의 ASCII 코드
            wprintf(L"\nEsc 키를 눌러 종료합니다.\n");
            inputBuffer[index] = L'\0';
            _setmode(_fileno(stdout), _O_TEXT); // 텍스트 출력 모드로 전환
            _setmode(_fileno(stdin), _O_TEXT);  // 텍스트 입력 모드로 전환
            input_text(inputBuffer);
            return;  // text_input 함수를 종료하고 main 함수의 while 루프로 돌아감
        }
        else if (ch == 8) {
            if (index > 0) {
                wprintf(L"\b \b"); // 백스페이스 효과
                inputBuffer[--index] = L'\0';
                system("cls");
                wprintf(L"종료하려면 Esc 키를 누르세요.\n");
                wprintf(L"%ls", inputBuffer);
            }
        }
        else if (ch == L'\r') {
            wprintf(L"\n");
            inputBuffer[index++] = '\n';
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

    system("cls");
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
    int i = 0;
    int id_pass = 0;
    while (1){  
        system("cls"); // 콘솔화면 초기화
        printf("***********************************\n");
        printf("*            회원가입 화면        *\n");
        printf("***********************************\n");
        if (id_pass == 0){
            if (i>=1)
                printf("ID가 중복됩니다!\n");
            printf("ID: ");
            scanf("%s", temp_id);
            
            if (check_id(temp_id) == 0){
                id_pass = 1;
            }
            i++;
        }
        else{
            printf("PW: ");
            pw_input(temp_pw);
            printf("\n");
            printf("Confirm your PW: ");
            pw_input(temp_pw2);
            if (strcmp(temp_pw, temp_pw2) == 0) {
                break;
            } else {
                printf("\n비밀번호가 일치하지 않습니다.\n");
                getch(); 
            }
            //break;
        }
    }
    
    save_user_info(temp_id, temp_pw);
    printf("\n회원가입이 완료되었습니다!\n");
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

    printf("%s, %s", id_var.arr, pw_var.arr);
    getch();

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

void login(struct UserInfo *user) {
    while(1){
        system("cls"); // 콘솔화면 초기화
        printf("***********************************\n");
        printf("*            로그인 화면          *\n");
        printf("***********************************\n");
        printf("ID: ");
        scanf("%s", user->id);

        printf("PW: ");
        int i = 0;
        while (1) {
            char ch = getch();  // 사용자 입력을 받음
            if (ch == '\r' || ch == '\n') {
                // Enter 키가 입력되면 종료
                break;
            } else if (ch == 8 && i > 0) {
                // Backspace 키가 입력되면 이전 문자 삭제
                printf("\b \b");
                user->pw[--i] = '\0';
            } else if (ch != 8) {
                // 비밀번호를 배열에 저장하고 '*' 출력
                user->pw[i++] = ch;
                printf("*");
            }
        }

        // NULL 문자를 추가하여 문자열 완성
        user->pw[i] = '\0';
        printf("%s\n",user->pw);

        if (check_user_info(user) == 0) {
            printf("ID나 PW를 확인해주세요.\n");
            getch();
        } else {
            login_state = true;
            break;
        }
    }
}

int check_user_info(struct UserInfo *user) {
    EXEC SQL BEGIN DECLARE SECTION;
        varchar  id[20];
        varchar pw[20];
        int result_count;
    EXEC SQL END DECLARE SECTION;

   /* Register sql_error() as the error handler. */
   EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

   /* 사용자가 입력한 ID와 PW를 Oracle 변수에 복사 */
   strcpy((char *)id.arr, user->id);
   id.len = strlen((char *)id.arr);

   strcpy((char *)pw.arr, user->pw);
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
   strcpy((char *)uid.arr,"a20193209@//sedb.deu.ac.kr:1521/orcl");
   uid.len = (short) strlen((char *)uid.arr);
   /* 본인 계정 암호로 바꾸어 쓸 것 */
   strcpy((char *)pwd.arr,"20193209");
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

