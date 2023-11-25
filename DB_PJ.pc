
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

// 한번에 보여줄 페이지의 크기
#define OFFSET_SIZE 10

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
void delete_post();
int get_post_info(int post_id, char* title, char* id, int* del);
void delete_id();
void pw_update();
void Post_Inquiry(int offset);
void Post_Inquiry_Display();
void rtrim();
void search_post_inquiry(int offset);
void search_post();
void deletePostInPost(int post_id);


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
// 게시글 목록 정보
int g_offset = 0;
int prevOffset = 0;
// 검색된 게시물 목록 정보
int s_offset = 0;
int prev_s_offset = 0;
// 검색어 정보
char keyword[100];


void main() {
    // 인코딩 설정
    _putenv("NLS_LANG=American_America.KO16KSC5601");
    DB_connect();
    while (true) {
        system("cls"); // 콘솔화면 초기화
        // 가로 80, 세로 24
        printf("--------------------------------------------------------------------------------\n");
        printf("                                    메인화면\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                                   [ 명령어 ]\n");
        printf("\n\n\n");
        printf("                                  1. post\n");
        printf("\n");
        // 여기까지 9라인
        if(login_state){
            printf("                                  2. logout\n");
            printf("\n");
            printf("                                  3. pwupdate\n");
            printf("\n");
            printf("                                  4. withdraw\n");
        }
        else{
            printf("                                  2. login\n");
            printf("\n");
            printf("                                  3. signup\n");
            printf("\n\n");
        }
        // 여기까지 14라인
        printf("\n\n\n\n\n\n\n\n");
        // 여기까지 22라인
        if (login_state) { gotoxy(0, 22); printf("%s\n", user.id); }
        else { printf("\n"); }
        printf("--------------------------------------------------------------------------------\n");
        printf("> ");
        char op[20];
        gotoxy(2, 24);
        scanf("%s", op);


        if ((strcmp(op, "post") == 0) || (strcmp(op, "1") == 0)) {
            Post_Inquiry_Display();
        }
        // 로그인 상태인 경우
        if(login_state){
            if ((strcmp(op, "logout") == 0) || (strcmp(op, "2") == 0)) {
                login_state = false;
                user.id[0] = '\0';
                user.pw[0] = '\0';
            }
            else if ((strcmp(op, "pwupdate") == 0) || (strcmp(op, "3") == 0)) {
                pw_update();
            }
            else if ((strcmp(op, "withdraw") == 0) || strcmp(op, "4") == 0) {
                delete_id();
            }
        }
        else{
            if ((strcmp(op, "login") == 0) || (strcmp(op, "2") == 0)) {
                login();
            }   
            else if ((strcmp(op, "signup") == 0) || (strcmp(op, "3") == 0)) {
                signup();
            }
        }
    }
}

int get_post_info(int post_id, char* title, char* id, int* del) {
    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
       varchar v_title[128];
       varchar v_id[20];
        int v_del;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    v_post_id = post_id;
    /* 실행시킬 SQL 문장*/
    EXEC SQL SELECT title, id, del INTO :v_title, :v_id, :v_del
              FROM post 
              WHERE post_id = :v_post_id; 

    /* 가져온 값이 있으면 1, 없으면 0 반환 */
    if (sqlca.sqlcode == 0) {
        /* 가져온 값을 C 문자열에 복사 */
        strncpy(title, (char*)v_title.arr, v_title.len);
        title[v_title.len] = '\0';

        strncpy(id, (char*)v_id.arr, v_id.len);
        id[v_id.len] = '\0';    
        *del = v_del;
        return 1;  // 가져온 값이 있음
    } else {
        return 0;  // 가져온 값이 없음
    }
}

// 게시글안에서 게시글을 삭제할 때 사용할 함
void deletePostInPost(int post_id){
    while(true){
        char op[5];
        printf("                            삭제하시겠습니까?(y,n): ");    
        scanf("%s",op);
        if (strcmp(op, "y") == 0 || strcmp(op, "Y") == 0) {
            // 'y' 또는 'Y'를 입력하면 루프 종료
            break;
        } else if (strcmp(op, "n") == 0 || strcmp(op, "N") == 0) {
            // 'n' 또는 'N'을 입력하면 함수 종료
            return;
        }
    }  

    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 매개변수 post_id 값을 Oracle 변수에 복사 */
    v_post_id = post_id;

    /* 실행시킬 SQL 문장*/
    EXEC SQL UPDATE post SET del = 1 WHERE post_id = :v_post_id;

    EXEC SQL COMMIT;
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                   게시물 삭제\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 [ 게시물 정보 ]\n\n\n\n");;
    printf("                              삭제가 완료되었습니다!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
}

// 게시글 삭제 처리
void delete_post(){
    system("cls"); // 콘솔화면 초기화
    printf("--------------------------------------------------------------------------------\n");
    printf("                                   게시물 삭제\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 [ 게시물 정보 ]\n");
    printf("\n\n\n");
    printf("               삭제할 게시물 ID :\n");
    printf("\n\n");
    printf("                             ID :\n");
    printf("\n\n");
    printf("                           제목 :\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("나가려면 exit를 입력하세요.");
    
    int post_id;
    while(true){
        gotoxy(0, 7);
        printf("               삭제할 게시물 ID :                  ");
        gotoxy(34, 7);
        char cpost_id[20];
        scanf("%s",cpost_id);
        if (strcmp(cpost_id, "exit") == 0){
            return;
        }
        post_id = atoi(cpost_id);
        // 정보를 가져온다
        char title[128];  // 가져온 게시물의 제목을 저장할 변수
        char id[20];  // 가져온 게시물의 작성자 ID를 저장할 변수    
        int del = -1;

        if (get_post_info(post_id, title, id, &del)){
            if (del){
                gotoxy(0, 5);
                printf("                           이미 삭제된 게시물이 입니다.");    
            }else{
                gotoxy(34, 10);
                printf("%s",id);
                gotoxy(34, 13);
                printf("%s",title);
                if (strcmp(user.id, id) != 0) {
                    gotoxy(0, 5);
                    printf("                             삭제할 권한이 없습니다.");
                }else{
                    char op[5];
                    gotoxy(0, 5);
                    printf("                                                                               ");
                    gotoxy(0, 17);
                    printf("                            삭제하시겠습니까?(y,n):            ");    
                    gotoxy(52, 17);
                    scanf("%s",op);
                    if (strcmp(op, "y") == 0 || strcmp(op, "Y") == 0) {
                        // 'y' 또는 'Y'를 입력하면 루프 종료
                        break;
                    } else if (strcmp(op, "n") == 0 || strcmp(op, "N") == 0) {
                        // 'n' 또는 'N'을 입력하면 함수 종료
                        return;
                    }
                }
            }
        } else{
            gotoxy(0, 5);
            printf("                                게시물이 없습니다.                       ");    
        }
    }  

    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    /* 매개변수 post_id 값을 Oracle 변수에 복사 */
    v_post_id = post_id;

    /* 실행시킬 SQL 문장*/
    EXEC SQL UPDATE post SET del = 1 WHERE post_id = :v_post_id;

    EXEC SQL COMMIT;
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                   게시물 삭제\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 [ 게시물 정보 ]\n\n\n\n");;
    printf("                              삭제가 완료되었습니다!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
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
    
    // /* 확인용: 오류 코드 출력 */
    // printf("SQLCODE: %d\n", sqlca.sqlcode);
    free(pStr);
}

void text_input(){
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("제목:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                     [ 본문 ]\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("작성을 취소하려면 exit를, 글을 저장하려면 Esc 키를 누르세요.\n");

    char title[128];
    // 제목 입력단.
    gotoxy(6, 1);
    scanf("%s",title);
    if (strcmp(title, "exit") == 0){
        return;
    }

    // 본문 입력단.
    gotoxy(0, 4);
    _setmode(_fileno(stdout), _O_U16TEXT); // 유니코드 출력을 위한 모드 설정
    _setmode(_fileno(stdin), _O_U16TEXT);  // 유니코드 입력을 위한 모드 설정

    wchar_t inputBuffer[2000]; // 충분한 크기의 배열로 설정
    memset(inputBuffer, 0, sizeof(inputBuffer)); // 배열 초기화
    int index = 0;
    int h = 0;
    wchar_t ch;

    while (1) {
        ch = _getwch(); // _getwch() 함수를 사용하여 유니코드 키 입력을 받음

        if (ch == 27) { // 27은 Esc 키의 ASCII 코드
            inputBuffer[index] = L'\0';
            _setmode(_fileno(stdout), _O_TEXT); // 텍스트 출력 모드로 전환
            _setmode(_fileno(stdin), _O_TEXT);  // 텍스트 입력 모드로 전환
            if (wcscmp(inputBuffer, L"exit") == 0) {
                return;
            }
            input_post(title, inputBuffer);
            return;  // text_input 함수를 종료하고 main 함수의 while 루프로 돌아감
        }
        else if (ch == 8) {
            if (index > 0) {
                wprintf(L"\b \b"); // 백스페이스 효과
                if (inputBuffer[index - 1] == L'\n'){
                    h--;
                }
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
            if(h < 18){
                h++;
                wprintf(L"\n");
                inputBuffer[index++] = '\n';
            }
        }
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
    printf("나가려면 exit를 입력하세요.");

    while (true){
        gotoxy(34, 7);
        scanf("%s", temp_id);
        if (strcmp(temp_id, "exit") == 0){
            return;
        }

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
        if (strcmp(temp_pw, "exit") == 0){
            return;
        }
        gotoxy(34, 13);
        pw_input(temp_pw2);
        if (strcmp(temp_pw2, "exit") == 0){
            return;
        }
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
        printf("나가려면 exit를 입력하세요.");

    while(1){
        gotoxy(34, 9);
        scanf("%s", user.id);
        if (strcmp(user.id, "exit") == 0){
            strcpy(user.id, "");
            return;
        }
        gotoxy(34, 13);
        pw_input(user.pw);
        if (strcmp(user.pw, "exit") == 0){
            strcpy(user.pw, "");
            return;
        }

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

// 회원정보 삭제 처리
void delete_id() {

    system("cls"); // 콘솔화면 초기화
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 회원정보 삭제\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 [ 회원정보 ]\n");
    printf("\n\n\n");
    printf("                               ID : %s\n", user.id);
    printf("\n\n");
    printf("                          PW 확인 :\n");
    printf("\n\n");
    printf("                        PW 재확인 :\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("나가려면 exit를 입력하세요.");

    char temp_pw[20];
    char temp_pw2[20];

    while (true) {
        gotoxy(36, 10);
        pw_input(temp_pw);

        if (strcmp(temp_pw, "exit") == 0) {
            return;
        }

        gotoxy(36, 13);
        pw_input(temp_pw2);


        if ((strcmp(temp_pw, user.pw) == 0) && (strcmp(temp_pw2, user.pw) == 0)) {
            login_state = false;
            user.id[0] = '\0';
            user.pw[0] = '\0';
            break;
        }
        else {
            gotoxy(26, 5);
            printf("비밀번호가 일치하지 않습니다.");
        }

    }

    EXEC SQL BEGIN DECLARE SECTION;
        varchar v_user_id[20];
    EXEC SQL END DECLARE SECTION;


    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    // v_user_id에 user.id를 복사
    strncpy((char*)v_user_id.arr, user.id, 20);
    v_user_id.len = strlen((char*)v_user_id.arr);

    /* 실행시킬 SQL 문장*/
    EXEC SQL DELETE FROM user_info WHERE id = :v_user_id;

    EXEC SQL COMMIT;


    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 회원정보 삭제\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 [ 회원정보 ]\n\n\n\n");;
    printf("                             삭제가 완료되었습니다!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
}

// 비밀번호 변경 처리
void pw_update() {

    system("cls"); // 콘솔화면 초기화
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 비밀번호 변경\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n\n\n");
    printf("                          현재 PW :\n");
    printf("\n\n");
    printf("                        수정할 PW :\n");
    printf("\n\n");
    printf("                 수정할 PW 재확인 :\n");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("나가려면 exit를 입력하세요.");

    char temp_pw[20];
    char temp_pw2[20];
    char temp_pw3[20];

    while (true) {
        gotoxy(36, 7);
        pw_input(temp_pw);

        if (strcmp(temp_pw, "exit") == 0) {
            return;
        }

        gotoxy(36, 10);
        pw_input(temp_pw2);

        gotoxy(36, 13);
        pw_input(temp_pw3);


        if ((strcmp(temp_pw, user.pw) == 0) && (strcmp(temp_pw2, temp_pw3) == 0)) {
            break;
        }
        else {
            gotoxy(26, 5);
            printf("현재 비밀번호가 일치하지 않습니다.");
        }

    }

    EXEC SQL BEGIN DECLARE SECTION;
        varchar v_user_id[20];
        varchar v_user_pw[20];
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    // v_user_pw에 temp_pw2를 복사
    strncpy((char*)v_user_pw.arr, temp_pw2, 20);
    v_user_pw.len = strlen((char*)v_user_pw.arr);

    // v_user_id에 user.id를 복사
    strncpy((char*)v_user_id.arr, user.id, 20);
    v_user_id.len = strlen((char*)v_user_id.arr);


    /* 실행시킬 SQL 문장*/
    EXEC SQL UPDATE user_info SET pw = :v_user_pw WHERE id = :v_user_id;

    EXEC SQL COMMIT;

    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("                                 비밀번호 변경\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n\n\n\n");
    printf("                             변경이 완료되었습니다!\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
}

void search_post_inquiry(int offset) {
    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
        varchar v_title[128];
        varchar v_id[20];
        int v_del;
        int v_row_count;
        int v_offset = 0;
        varchar v_keyword[100];  // 검색어를 담을 변수 추가
    EXEC SQL END DECLARE SECTION;

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    v_offset = offset;

    // 검색어를 Oracle 변수에 복사
    strncpy((char*)v_keyword.arr, keyword, sizeof(v_keyword.arr));
    v_keyword.len = strlen((char*)v_keyword.arr);
    
    // 현재 10개의 행을 건너뛰고 다음 10개의 행을 조회하는 쿼리
    EXEC SQL DECLARE cur_search CURSOR FOR
    SELECT POST_ID, TITLE, ID, DEL
    FROM (
        SELECT POST_ID, TITLE, ID, DEL, ROWNUM AS RN
        FROM (
            SELECT POST_ID, TITLE, ID, DEL
            FROM POST
            WHERE DEL = 0 AND TITLE LIKE '%' || :v_keyword || '%'
            ORDER BY POST_ID DESC
        ) 
        WHERE ROWNUM <= :v_offset + 10
    )
    WHERE RN > :v_offset;

    EXEC SQL OPEN cur_search;
    printf("   POST_ID   |                       TITLE                          |     ID   \n");
	printf("-------------------------------------------------------------------------------\n");
    int row_count = 0;
    
    /* Fetch rows and display */
    while (1) {
        EXEC SQL FETCH cur_search INTO :v_post_id, :v_title, :v_id, :v_del;
        if (sqlca.sqlcode != 0)
            break;

        row_count++;    
        if (sqlca.sqlcode != 0)
            break;

        int title_length = v_title.len;
        int id_length = v_id.len;

        // Oracle VARCHAR 변수의 길이를 직접 사용하여 공백 제거
        while (title_length > 0 && v_title.arr[title_length - 1] == ' ') {
            title_length--;
        }
        v_title.arr[title_length] = '\0';

        while (id_length > 0 && v_id.arr[id_length - 1] == ' ') {
            id_length--;
        }
        v_id.arr[id_length] = '\0';

        if (strlen((char *)v_title.arr) > 50) {
            printf("   %-10d| %-50.50s...| %-20s\n", v_post_id, (char *)v_title.arr, (char *)v_id.arr);
        } else {
            printf("   %-10d| %-53s| %-20s\n", v_post_id, (char *)v_title.arr, (char *)v_id.arr);
        }
    }  
    
    if(row_count == 0 && s_offset != 0){
        s_offset = prev_s_offset;
        system("cls"); // 콘솔화면 초기화
    	printf("-------------------------------------------------------------------------------\n");
       	printf("                                    [검색 목록]\n");
    	printf("-------------------------------------------------------------------------------\n");
        search_post_inquiry(s_offset);
        return; // 함수 종료
    }
    
    for(int i=0; i<(10-row_count);i++){
        printf("             |                                                      |                    \n");
    }
    EXEC SQL CLOSE cur_search;
}

//게시물 검색
void search_post(){
    // 처음에 처음 10개의 행을 가져오도록 Post_Inquiry() 호출
    s_offset = 0;
    prev_s_offset = 0;
    while (1) {
        system("cls"); // 콘솔화면 초기화
    	printf("-------------------------------------------------------------------------------\n");
       	printf("                                    [검색 목록]\n");
    	printf("-------------------------------------------------------------------------------\n");
        // 여기까지 3라인
        // search_post_inquiry();
        search_post_inquiry(s_offset);
        // 여기까지 13라인
        printf("-------------------------------------------------------------------------------\n");
        // 여기까지 14라인
        char input[10];
        printf("1. 글 보기\n2. 이전페이지\n3. 다음페이지\n");
        printf("0. 나가기\n\n\n\n\n");
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) { 
            // 글 보기 기능
        }
        else if (strcmp(input, "2") == 0) {
            if ((s_offset - OFFSET_SIZE) > -1){
                prev_s_offset = s_offset;
                s_offset -= OFFSET_SIZE;
            }
        } 
        else if (strcmp(input, "3") == 0) {
            prev_s_offset = s_offset;
            s_offset += OFFSET_SIZE;
	    }
        else if ((strcmp(input, "0") == 0) || (strcmp(input, "exit") == 0)){
            break;
        }
        else {
            printf("입력이 올바르지 않습니다.\n");
        }
    }
}

//게시물 목록
void Post_Inquiry_Display()
{
    g_offset = 0;
    // 처음에 처음 10개의 행을 가져오도록 Post_Inquiry() 호출
    while (1) {
        system("cls"); // 콘솔화면 초기화
    	printf("-------------------------------------------------------------------------------\n");
       	printf("                                   [게시물 목록]\n");
    	printf("-------------------------------------------------------------------------------\n");
        // 여기까지 3라인
        Post_Inquiry(g_offset);
        // 여기까지 13라인
        printf("-------------------------------------------------------------------------------\n");
        // 여기까지 14라인
        char input[10];
        printf("1. 글 보기\n2. 이전페이지\n3. 다음페이지\n4. 검색\n");
        // 여기까지 18라인
        if (login_state){
            printf("5. 게시글작성\n6. 게시글 삭제\n0. 나가기\n\n");
        }
        else{
            printf("0. 나가기\n\n\n\n");
        }
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            // 글 보기 기능
        }else if (strcmp(input, "2") == 0) {
            if ((g_offset - OFFSET_SIZE) > -1){
                prevOffset = g_offset;
                g_offset -= OFFSET_SIZE; // 10개씩 건너뛰기
            }
        } else if (strcmp(input, "3") == 0) {
            prevOffset = g_offset;
            g_offset += OFFSET_SIZE; // 10개씩 건너뛰기
	    } else if (strcmp(input, "4") == 0) {
            // 검색기능
            gotoxy(0,24);
            printf("검색어를 입력하세요: ");
            getchar();
            fgets(keyword, sizeof(keyword), stdin);
            size_t len = strlen(keyword);
            if (len > 0 && keyword[len - 1] == '\n') {
                keyword[len - 1] = '\0';
            }
            search_post();
        } else if ((strcmp(input, "5") == 0) && login_state){
            text_input();
        }
        else if ((strcmp(input, "6") == 0) && login_state){
            delete_post();
        }
        else if ((strcmp(input, "0") == 0) || (strcmp(input, "exit") == 0)){
            break;
        }
        else {
            printf("입력이 올바르지 않습니다.\n");
        }
        // EXEC SQL COMMIT WORK RELEASE ;
    }

	
}

//게시물 목록 가져오기
void Post_Inquiry(int offset) {

    EXEC SQL BEGIN DECLARE SECTION;
        int v_post_id;
        varchar v_title[128];
        varchar v_id[20];
        int v_del;
        int v_row_count;
        int v_offset = 0; /* :offset 변수 선언 */
    EXEC SQL END DECLARE SECTION;   

    /* Register sql_error() as the error handler. */
    EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n");

    v_offset = offset;
    
    // 현재 10개의 행을 건너뛰고 다음 10개의 행을 조회하는 쿼리
    EXEC SQL DECLARE cur CURSOR FOR
    SELECT POST_ID, TITLE, ID, DEL 
    FROM (
        SELECT POST_ID, TITLE, ID, DEL, ROWNUM AS RN
        FROM (
            SELECT POST_ID, TITLE, ID, DEL
            FROM POST
            WHERE DEL = 0
            ORDER BY POST_ID DESC /* 여기에 ORDER BY 추가 */
        ) 
        WHERE ROWNUM <= :v_offset + 10 /* offset부터 10개의 행을 가져옴 */
    )
    WHERE RN > :v_offset;


    EXEC SQL OPEN cur;
    printf("   POST_ID   |                       TITLE                          |     ID   \n");
	printf("-------------------------------------------------------------------------------\n");
    int row_count = 0;

    /* Fetch rows and display */
    while (1) {
        EXEC SQL FETCH cur INTO :v_post_id, :v_title, :v_id, :v_del;

        if (sqlca.sqlcode != 0)
            break;

        row_count++;    
        if (sqlca.sqlcode != 0)
            break;

        int title_length = v_title.len;
        int id_length = v_id.len;

        // Oracle VARCHAR 변수의 길이를 직접 사용하여 공백 제거
        while (title_length > 0 && v_title.arr[title_length - 1] == ' ') {
            title_length--;
        }
        v_title.arr[title_length] = '\0';

        while (id_length > 0 && v_id.arr[id_length - 1] == ' ') {
            id_length--;
        }
        v_id.arr[id_length] = '\0';

        if (strlen((char *)v_title.arr) > 50) {
            printf("   %-10d| %-50.50s...| %-20s\n", v_post_id, (char *)v_title.arr, (char *)v_id.arr);
        } else {
            printf("   %-10d| %-53s| %-20s\n", v_post_id, (char *)v_title.arr, (char *)v_id.arr);
        }
    }

    if (row_count == 0) {
        g_offset = prevOffset;
        system("cls"); // 콘솔화면 초기화
    	printf("-------------------------------------------------------------------------------\n");
       	printf("                                   [게시물 목록]\n");
    	printf("-------------------------------------------------------------------------------\n");
        Post_Inquiry(g_offset);
        return; // 함수 종료
    }
    for (int i = row_count; i < 10; ++i) {
        printf("\n"); // 빈 줄 출력
    }


    EXEC SQL CLOSE cur;
}

void rtrim(char temp[])
{
	int i;

	i = strlen(temp)-1;
	
	while (temp[i] == ' ' && i > 0 ){
		i--;
        }
	temp[i+1]='\0';
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
