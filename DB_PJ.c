
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

 static const char *sq0015 = 
"select POST_ID ,TITLE ,ID ,DEL  from (select POST_ID ,TITLE ,ID ,DEL ,ROWNUM\
 RN  from (select POST_ID ,TITLE ,ID ,DEL  from POST where DEL=0 order by POST\
_ID desc  ) where ROWNUM<=(:b0+10)) where RN>:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,67,0,4,185,0,0,4,1,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,1,3,0,0,
36,0,0,2,40,0,5,283,0,0,1,1,0,1,0,1,3,0,0,
55,0,0,3,0,0,29,285,0,0,0,0,0,1,0,
70,0,0,4,47,0,4,307,0,0,1,0,0,1,0,2,3,0,0,
89,0,0,5,73,0,3,356,0,0,5,5,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
124,0,0,6,0,0,29,358,0,0,0,0,0,1,0,
139,0,0,7,54,0,4,472,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
162,0,0,8,39,0,3,565,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
185,0,0,9,0,0,29,567,0,0,0,0,0,1,0,
200,0,0,10,67,0,4,657,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
227,0,0,11,36,0,2,725,0,0,1,1,0,1,0,1,9,0,0,
246,0,0,12,0,0,29,727,0,0,0,0,0,1,0,
261,0,0,13,41,0,5,806,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
284,0,0,14,0,0,29,808,0,0,0,0,0,1,0,
299,0,0,15,213,0,9,919,0,0,2,2,0,1,0,1,3,0,0,1,3,0,0,
322,0,0,15,0,0,13,927,0,0,4,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
353,0,0,15,0,0,15,972,0,0,0,0,0,1,0,
368,0,0,0,0,0,27,996,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
399,0,0,17,59,0,4,1023,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
422,0,0,18,0,0,31,1052,0,0,0,0,0,1,0,
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
void delete_post();
int get_post_info(int post_id, char* title, char* id, int* del);
void delete_id();
void pw_update();
void Post_Inquiry(int offset);
void Post_Inquiry_Display();
void rtrim();


/* EXEC SQL BEGIN DECLARE SECTION; */ 

	/* VARCHAR uid[80]; */ 
struct { unsigned short len; unsigned char arr[80]; } uid;

	/* VARCHAR pwd[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } pwd;

/* EXEC SQL END DECLARE SECTION; */ 


/* EXEC SQL BEGIN DECLARE SECTION; */ 

    int offset = 0; /* :offset 변수 선언 */
/* EXEC SQL END DECLARE SECTION; */ 


// win32 Visual C 컴파일시 추가
#define getch() _getch()

/* 사용자 정보를 저장할 구조체 */
struct UserInfo {
    char id[20];
    char pw[20];
};

bool login_state = false;
int msg_state = 0;// 1: 명령어 없음, 2: 이미 로그인 상태, 3: 게스트 상태

// 유저 정보 
struct UserInfo user;

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
        printf("\n");
        if (msg_state == 1) {
            printf("                           명령어를 찾을 수 없습니다.\n");
        }
        else if (msg_state == 2) {
            gotoxy(0, 5);
            printf("                               로그인 상태입니다.\n");
        }
        else if (msg_state == 3) {
            gotoxy(0, 5);
            printf("                               게스트 모드입니다.\n");
        }
        else {
            printf("\n\n");
        }
        printf("                                     login\n");
        printf("\n");
        printf("                                     logout\n");
        printf("\n");
        printf("                                     signup\n");
        printf("\n");
        printf("                                     post\n");
        printf("\n");
        printf("                                     pwupdate\n");
        printf("\n");
        printf("                                     withdraw\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");

        if (login_state) { gotoxy(0, 22); printf("%s\n", user.id); }
        else { printf("\n"); }
        printf("--------------------------------------------------------------------------------\n");
        printf("> ");
        msg_state = 0;
        char op[20];
        gotoxy(2, 24);
        scanf("%s", op);
        if (strcmp(op, "login") == 0) {
            if (!login_state)
                login();
            else {
                msg_state = 2;
            }
        }
        else if (strcmp(op, "signup") == 0) {
            signup();
        }
        else if (strcmp(op, "logout") == 0) {
            login_state = false;
            user.id[0] = '\0';
            user.pw[0] = '\0';
            msg_state = 0;
        }
        else if (strcmp(op, "withdraw") == 0) {
            if (!login_state) {
                msg_state = 3;
            }
            else {
                delete_id();
            }
        }
        else if (strcmp(op, "pwupdate") == 0) {
            if (!login_state) {
                msg_state = 3;
            }
            else {
                pw_update();
            }
        }
        else if (strcmp(op, "post") == 0) {
            if (!login_state) {
                msg_state = 3;
            }
            else {
                Post_Inquiry_Display();
            }
        }
        
        else {
            msg_state = 1;
        }
    }
}

int get_post_info(int post_id, char* title, char* id, int* del) {
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int v_post_id;
       /* varchar v_title[128]; */ 
struct { unsigned short len; unsigned char arr[128]; } v_title;

       /* varchar v_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_id;

        int v_del;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    v_post_id = post_id;
    /* 실행시킬 SQL 문장*/
    /* EXEC SQL SELECT title, id, del INTO :v_title, :v_id, :v_del
              FROM post 
              WHERE post_id = :v_post_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select title ,id ,del into :b0,:b1,:b2  from post where p\
ost_id=:b3";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&v_title;
    sqlstm.sqhstl[0] = (unsigned int  )130;
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
    sqlstm.sqhstv[2] = (         void  *)&v_del;
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)&v_post_id;
    sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
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

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        int v_post_id;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    /* 매개변수 post_id 값을 Oracle 변수에 복사 */
    v_post_id = post_id;

    /* 실행시킬 SQL 문장*/
    /* EXEC SQL UPDATE post SET del = 1 WHERE post_id = :v_post_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update post  set del=1 where post_id=:b0";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )55;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select NVL(max(post_id),0) into :b0  from post ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )70;
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
    sqlstm.offset = (unsigned int  )89;
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
    sqlstm.offset = (unsigned int  )124;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


    
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
    sqlstm.offset = (unsigned int  )139;
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
    sqlstm.offset = (unsigned int  )162;
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
    sqlstm.offset = (unsigned int  )185;
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
   sqlstm.offset = (unsigned int  )200;
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
            msg_state = 0;
            break;
        }
        else {
            gotoxy(26, 5);
            printf("비밀번호가 일치하지 않습니다.");
        }

    }

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar v_user_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_user_id;

    /* EXEC SQL END DECLARE SECTION; */ 



    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    // v_user_id에 user.id를 복사
    strncpy((char*)v_user_id.arr, user.id, 20);
    v_user_id.len = strlen((char*)v_user_id.arr);

    /* 실행시킬 SQL 문장*/
    /* EXEC SQL DELETE FROM user_info WHERE id = :v_user_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "delete  from user_info  where id=:b0";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )227;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&v_user_id;
    sqlstm.sqhstl[0] = (unsigned int  )22;
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



    /* EXEC SQL COMMIT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )246;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}




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

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        /* varchar v_user_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_user_id;

        /* varchar v_user_pw[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_user_pw;

    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    // v_user_pw에 temp_pw2를 복사
    strncpy((char*)v_user_pw.arr, temp_pw2, 20);
    v_user_pw.len = strlen((char*)v_user_pw.arr);

    // v_user_id에 user.id를 복사
    strncpy((char*)v_user_id.arr, user.id, 20);
    v_user_id.len = strlen((char*)v_user_id.arr);


    /* 실행시킬 SQL 문장*/
    /* EXEC SQL UPDATE user_info SET pw = :v_user_pw WHERE id = :v_user_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update user_info  set pw=:b0 where id=:b1";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )261;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&v_user_pw;
    sqlstm.sqhstl[0] = (unsigned int  )22;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&v_user_id;
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
    sqlstm.offset = (unsigned int  )284;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}



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


//게시물 목록
void Post_Inquiry_Display()
{

int offset = 0;

    // 처음에 처음 10개의 행을 가져오도록 Post_Inquiry() 호출


    while (1) {
        system("cls"); // 콘솔화면 초기화
    	printf("--------------------------------------------------------------------------------\n");
       	printf("                                   [게시물 목록]\n");
    	printf("--------------------------------------------------------------------------------\n");
	    
        Post_Inquiry(offset);
        printf("--------------------------------------------------------------------------------\n");
        
        char input[10];
        printf("1. 종료하기\n2. 다음페이지\n3. 이전페이지\n4. 게시글작성\n5. 게시글 삭제\n6. 글 작성\n7. 글 삭제\n입력하세요: ");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            break;
        } else if (strcmp(input, "2") == 0) {
            system("cls");
            printf("--------------------------------------------------------------------------------\n");
            printf("                                   [게시물 목록]\n");
            printf("--------------------------------------------------------------------------------\n");
            offset += 10; // 10개씩 건너뛰기
            Post_Inquiry(offset); // 새로운 offset으로 Post_Inquiry() 호출
            printf("--------------------------------------------------------------------------------\n");
	    } else if (strcmp(input, "3") == 0) {
            system("cls");
            printf("--------------------------------------------------------------------------------\n");
            printf("                                   [게시물 목록]\n");
            printf("--------------------------------------------------------------------------------\n");
            offset -= 10; // 10개씩 건너뛰기
            Post_Inquiry(offset); // 새로운 offset으로 Post_Inquiry() 호출
            printf("--------------------------------------------------------------------------------\n");
        }else if (strcmp(input, "4") == 0){
            text_input();
        }
        else if (strcmp(input, "5") == 0){
            delete_post();
        }
        else if (strcmp(input, "6") == 0) {
            if (!login_state) {
                msg_state = 3;
            }
            else {
                text_input();
            }
        }
        else if (strcmp(input, "7") == 0) {
            delete_post();
        }
        else {
            printf("입력이 올바르지 않습니다.\n");
        }
        // EXEC SQL COMMIT WORK RELEASE ;
    }

	
}


//게시물 목록 가져오기
void Post_Inquiry(int offset) {

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

       int v_post_id;
       /* varchar v_title[128]; */ 
struct { unsigned short len; unsigned char arr[128]; } v_title;

       /* varchar v_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_id;

       int v_del;
       int v_row_count;
    /* EXEC SQL END DECLARE SECTION; */ 


    /* Register sql_error() as the error handler. */
    /* EXEC SQL WHENEVER SQLERROR DO sql_error("\7ORACLE ERROR:\n"); */ 


    // 현재 10개의 행을 건너뛰고 다음 10개의 행을 조회하는 쿼리
    /* EXEC SQL DECLARE cur CURSOR FOR
    SELECT POST_ID, TITLE, ID, DEL 
    FROM (
        SELECT POST_ID, TITLE, ID, DEL, ROWNUM AS RN
        FROM (
            SELECT POST_ID, TITLE, ID, DEL
            FROM POST
            WHERE DEL = 0
            ORDER BY POST_ID DESC /o 여기에 ORDER BY 추가 o/
        ) 
        WHERE ROWNUM <= :offset + 10 /o offset부터 10개의 행을 가져옴 o/
    )
    WHERE RN > :offset; */ 



    /* EXEC SQL OPEN cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0015;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )299;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (         void  *)&offset;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)&offset;
    sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
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



    printf("   POST_ID   |                       TITLE                          |     ID    \n");
	printf("--------------------------------------------------------------------------------\n");
    int row_count = 0;

    /* Fetch rows and display */
    while (1) {
        /* EXEC SQL FETCH cur INTO :v_post_id, :v_title, :v_id, :v_del; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )322;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)&v_post_id;
        sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&v_title;
        sqlstm.sqhstl[1] = (unsigned int  )130;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&v_id;
        sqlstm.sqhstl[2] = (unsigned int  )22;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (         void  *)&v_del;
        sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         void  *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned int  )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
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
        printf("게시물이 없습니다.\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("엔터를 누르십시오...");
        getchar();
        getchar();
        // Post_Inquiry_Display() 함수 호출
        Post_Inquiry_Display();
        return; // 함수 종료
    }
    for (int i = row_count; i < 10; ++i) {
        printf("\n"); // 빈 줄 출력
    }


    /* EXEC SQL CLOSE cur; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )353;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("\7ORACLE ERROR:\n");
}


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

   /* EXEC SQL CONNECT :uid IDENTIFIED BY :pwd; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 5;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )368;
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
    sqlstm.offset = (unsigned int  )399;
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
    sqlstm.offset = (unsigned int  )422;
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
