
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[11];
};
static const struct sqlcxp sqlfpn =
{
    10,
    ".\\DB_PJ.pc"
};


static unsigned int sqlctx = 65355;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {13,5};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0001 = 
"select text  from test            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,34,0,9,75,0,0,0,0,0,1,0,
20,0,0,1,0,0,13,79,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,1,0,0,15,87,0,0,0,0,0,1,0,
54,0,0,2,47,0,4,165,0,0,1,0,0,1,0,2,3,0,0,
73,0,0,3,73,0,3,214,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
108,0,0,4,0,0,29,216,0,0,0,0,0,1,0,
123,0,0,5,54,0,4,330,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
146,0,0,6,39,0,3,419,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
169,0,0,7,0,0,29,421,0,0,0,0,0,1,0,
184,0,0,8,67,0,4,502,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
211,0,0,0,0,0,27,519,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
242,0,0,10,59,0,4,546,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
265,0,0,11,0,0,31,575,0,0,0,0,0,1,0,
};



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

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

	/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 


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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar text[2000]; */ 
struct { unsigned short len; unsigned char arr[2000]; } text;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* Cursor 선언 */
    /* EXEC SQL DECLARE text_cursor CURSOR FOR
        SELECT text FROM test; */ 


    /* Cursor 열기 */
    /* EXEC SQL OPEN text_cursor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0001;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



    /* 결과 읽기 */
    while (1) {
        /* EXEC SQL FETCH text_cursor INTO :text; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )20;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)&text;
        sqlstm.sqhstl[0] = (unsigned int  )2002;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


        if (sqlca.sqlcode != 0) break;  // No more rows

        text.arr[text.len] = '\0';
        printf("%s\n", text.arr);
    }

    /* Cursor 닫기 */
    /* EXEC SQL CLOSE text_cursor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )39;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int max_post_id;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* 실행시킬 SQL 문장*/
    /* EXEC SQL SELECT NVL(MAX(post_id), 0) INTO :max_post_id FROM post; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(max(post_id),0) into :b0  from post ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )54;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&max_post_id;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



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
    
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int v_post_id;
        /* varchar v_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_id;

        /* varchar v_title[128]; */ 
struct { unsigned short len; unsigned char arr[128]; } v_title;

        /* varchar v_text[2000]; */ 
struct { unsigned short len; unsigned char arr[2000]; } v_text;
 
        int v_del;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


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
    /* EXEC SQL INSERT INTO post (post_id, id, title, text, del) VALUES (:v_post_id, :v_id, :v_title, :v_text, :v_del); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into post (post_id,id,title,text,del) values (:b0,\
:b1,:b2,:b3,:b4)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )73;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&v_post_id;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&v_id;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&v_title;
    sqlstm.sqhstl[2] = (unsigned int  )130;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&v_text;
    sqlstm.sqhstl[3] = (unsigned int  )2002;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqhstv[4] = (         void  *)&v_del;
    sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[4] = (         int  )0;
    sqlstm.sqindv[4] = (         void  *)0;
    sqlstm.sqinds[4] = (         int  )0;
    sqlstm.sqharm[4] = (unsigned int  )0;
    sqlstm.sqadto[4] = (unsigned short )0;
    sqlstm.sqtdso[4] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )108;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


    
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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar id_var[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } id_var;

        int result_count;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* 사용자가 입력한 ID를 Oracle 변수에 복사 */
    strcpy((char *)id_var.arr, id);
    id_var.len = strlen((char *)id_var.arr);

    /* 실행시킬 SQL 문장*/
    /* EXEC SQL SELECT count(id)
             INTO :result_count
             FROM user_info
             WHERE id = :id_var; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(id) into :b0  from user_info where id=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )123;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&result_count;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&id_var;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar id_var[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } id_var;

        /* varchar pw_var[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pw_var;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* 사용자가 입력한 ID와 PW를 Oracle 변수에 복사 */
    strcpy((char *)id_var.arr, id);
    id_var.len = strlen((char *)id_var.arr);

    strcpy((char *)pw_var.arr, pw);
    pw_var.len = strlen((char *)pw_var.arr);

    // printf("%s, %s", id_var.arr, pw_var.arr);
    // getch();

    /* 실행시킬 SQL 문장*/
    /* EXEC SQL INSERT INTO user_info VALUES (:id_var, :pw_var); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into user_info  values (:b0,:b1)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )146;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&id_var;
    sqlstm.sqhstl[0] = (unsigned int  )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&pw_var;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )169;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


    
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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar  id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } id;

        /* varchar pw[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pw;

        int result_count;
    /* EXEC SQL END DECLARE SECTION; */ 


   /* Register sql_error() as the error handler. */
   /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


   /* 사용자가 입력한 ID와 PW를 Oracle 변수에 복사 */
   strcpy((char *)id.arr, user.id);
   id.len = strlen((char *)id.arr);

   strcpy((char *)pw.arr, user.pw);
   pw.len = strlen((char *)pw.arr);

   /* 실행시킬 SQL 문장*/
   /* EXEC SQL SELECT count(id)
                   INTO :result_count
            FROM   user_info
            WHERE  id = :id AND pw = :pw; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select count(id) into :b0  from user_info where (id=:b1 an\
d pw=:b2)";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )184;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)&result_count;
   sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&id;
   sqlstm.sqhstl[1] = (unsigned int  )22;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (         void  *)&pw;
   sqlstm.sqhstl[2] = (unsigned int  )22;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         void  *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned int  )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



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

   /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )211;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (         void  *)&uid;
   sqlstm.sqhstl[0] = (unsigned int  )82;
   sqlstm.sqhsts[0] = (         int  )82;
   sqlstm.sqindv[0] = (         void  *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned int  )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (         void  *)&pwd;
   sqlstm.sqhstl[1] = (unsigned int  )22;
   sqlstm.sqhsts[1] = (         int  )22;
   sqlstm.sqindv[1] = (         void  *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned int  )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlstm.sqlcmax = (unsigned int )100;
   sqlstm.sqlcmin = (unsigned int )2;
   sqlstm.sqlcincr = (unsigned int )1;
   sqlstm.sqlctimeout = (unsigned int )0;
   sqlstm.sqlcnowait = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



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
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       /* varchar id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } id;

       /* varchar pw[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pw;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* 실행시킬 SQL 문장*/
    /* EXEC SQL SELECT id, pw 
              INTO :id, :pw 
              FROM user_info 
              WHERE id = 'admin' ; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select id ,pw into :b0,:b1  from user_info where id='admi\
n'";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )242;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&id;
    sqlstm.sqhstl[0] = (unsigned int  )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&pw;
    sqlstm.sqhstl[1] = (unsigned int  )22;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}

 

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

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


    printf("\n%s\n", msg);
    buf_len = sizeof (err_msg);
    sqlglm(err_msg, &buf_len, &msg_len);
    printf("%.*s\n", msg_len, err_msg);
    getch();
    
    /* EXEC SQL ROLLBACK WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )265;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



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
