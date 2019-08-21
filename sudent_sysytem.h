#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#define USR_NAME_LEN 20
#define USR_PWD_LEN 20
#define USR_ROLE int
#define STUDENT 0
#define TEACHER 1

//�˻��ṹ��
typedef struct usr_account_tag {
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	USR_ROLE usr_role;
	struct usr_account_tag *pNext_Usr_Acount;
}USR_ACCOUNT,*pUSR_ACCOUNT;
//ѧ����Ϣ�ṹ��
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

//����һ���˻�������Ϣ
void CREAT_COUNT(pUSR_ACCOUNT *pnew, USR_ROLE role);
//����һ��ѧ��������Ϣ
void CREAT_INFOR(pUSR_INFOR *pnew);
//չʾ�����߲˵�
void SHOW_ADM_MENUE();
//չʾѧ���˵�
void SHOW_STU_MENUE();
//��usr_infor.txt������һ��������һ��ͷָ��
void OPEN_USR_INFOR(pUSR_INFOR*phead);
//��С�������������
void LIST_LOW_TO_HIGH(pUSR_INFOR*phead);
//��usr_infor.txt������д��
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
//����ѧ����Ϣ
void UPDATE_USR_INFOR();
//ɾ��ѧ����Ϣ
void DELE_USR_INFOR();

void ADM();

void STU();