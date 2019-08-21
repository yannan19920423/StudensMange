#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define USR_NAME_LEN 20
#define USR_PWD_LEN 20
#define USR_ROLE int
#define STUDENT 0
#define TEACHER 1

//账户结构体
typedef struct usr_account_tag {
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE usr_role;
	struct usr_account_tag *pNext_Usr_Acount;
}USR_ACCOUNT,*pUSR_ACCOUNT;
//学生信息结构体
typedef struct usr_infor_tag {
	int usr_id;
	char usr_name[USR_NAME_LEN];
	double usr_english_score;
	double usr_math_score;
	double usr_chinese_score;
	double usr_biology_score;
	double usr_physical_score;
	struct usr_infor_tag*pNext_Usr_Infor;
}USR_INFOR,*pUSR_INFOR;

//创建一个账户输入信息
void CREAT_COUNT(pUSR_ACCOUNT *pnew, USR_ROLE role);
//创建一个学生输入信息
void CREAT_INFOR(pUSR_INFOR *pnew);
//展示管理者菜单
void SHOW_ADM_MENUE();
//展示学生菜单
void SHOW_STU_MENUE();
//打开usr_infor.txt并创建一个链表返回一个头指针
void OPEN_USR_INFOR(pUSR_INFOR*phead);
//从小到大的有序链表
void LIST_LOW_TO_HIGH(pUSR_INFOR*phead);
//打开usr_infor.txt并重新写入
void WRITE_BACK_USR_INFOR(pUSR_INFOR*phead);
void OPEN_ACCOUNT_INFOR(pUSR_ACCOUNT*phead);
void WRITE_BACK_USR_ACCOUNT(pUSR_ACCOUNT *phead);
void UPDATE_USR_ACCOUNT();
void DELE_USR_ACCOUNT();
void SEARCH_USR_ACCOUNT();

//search student information
void SEARCH_STU_INFOR();
//add student information
void ADD_STUDENT_INFOR();
//更新学生信息
void UPDATE_USR_INFOR();
//删除学生信息
void DELE_USR_INFOR();

void ADM();

void STU();