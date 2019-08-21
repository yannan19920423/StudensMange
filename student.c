#include"sudent_sysytem.h"

//辅助函数

//创建一个账户输入信息
void CREAT_COUNT(pUSR_ACCOUNT *pnew, USR_ROLE role) {
	(*pnew)->usr_role = role;
	printf("Please enter the name of the new count:\n");
	char name[USR_NAME_LEN] = { 0 };
	scanf("%s", name);
	strcpy((*pnew)->usr_name, name);
	printf("Your name is:%s\n", (*pnew)->usr_name);
PASS_WORD_limble:
	printf("Please enter the password of the new count:\n");
	char pwd1[USR_PWD_LEN] = { 0 };
	scanf("%s", pwd1);
	//strcpy((*pnew)->usr_pwd, pwd1);
	printf("Please enter the password of the new count agin(ensure two time is same):\n");
	char pwd2[USR_PWD_LEN] = { 0 };
	scanf("%s", pwd2);
	if (strcmp(pwd1, pwd2) == 0) {
		strcpy((*pnew)->usr_pwd, pwd1);
	}
	else {
		printf("two time are different...\n");//两次密码输入不一致则返回继续输入
		goto PASS_WORD_limble;
	}
}
//创建一个学生输入信息
void CREAT_INFOR(pUSR_INFOR *pnew) {
	printf("Please enter the id of the new student;\n");
	int usrid;
	scanf("%d", &usrid);
	rewind(stdin);
	(*pnew)->usr_id = usrid;

	printf("Please enter the name of the new student;\n");
	char name[USR_NAME_LEN] = { 0 };
	scanf("%s", &name);
	strcpy((*pnew)->usr_name, name);

	printf("Please enter the english's score of the new student;\n");
	double english_score = 0.0;
	scanf("%lf", &english_score);
	(*pnew)->usr_english_score = english_score;

	printf("Please enter the math's score of the new student;\n");
	double math_score = 0.0;
	scanf("%lf", &math_score);
	(*pnew)->usr_math_score = math_score;

	printf("Please enter the chinese's score of the new student;\n");
	double chinese_score = 0.0;
	scanf("%lf", &chinese_score);
	(*pnew)->usr_chinese_score = chinese_score;

	printf("Please enter the biology's score of the new student;\n");
	double biology_score = 0.0;
	scanf("%lf", &biology_score);
	(*pnew)->usr_biology_score = biology_score;

	printf("Please enter the physical's score of the new student;\n");
	double physical_score = 0.0;
	scanf("%lf", &physical_score);
	(*pnew)->usr_physical_score = physical_score;
}
//展示管理者菜单
void SHOW_ADM_MENUE() {
	printf("   ********** Student Information Management System **********   \n");
	printf("               1. search student information\n");
	printf("               2. add student information\n");
	printf("               3. update student information\n");
	printf("               4. delete student information\n");
	printf("               5. add user account\n");
	printf("               6. update user account\n");
	printf("               7. delete user account\n");
	printf("               8. search user account\n");
	printf("               9. exit\n");
}
//展示学生菜单
void SHOW_STU_MENUE() {
	printf("   ********** Student Information Management System **********   \n");
	printf("               1. search student information\n");
	printf("               2. exit\n");
}
//打开usr_infor.txt并创建一个链表返回一个头指针
void OPEN_USR_INFOR(pUSR_INFOR*phead) {
	FILE*fp;
	fp = fopen("usr_infor.txt", "r");
	if (fp == NULL) {
		perror("fopen");
	}
	pUSR_INFOR pnew, pcur;
	pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	while (fscanf(fp, "%d %s%lf%lf%lf%lf%lf", &pnew->usr_id, pnew->usr_name, &pnew->usr_english_score, &pnew->usr_math_score, &pnew->usr_chinese_score, &pnew->usr_biology_score, &pnew->usr_physical_score) != EOF) {
		if (*phead == NULL) {
			*phead = pnew;
			//pnew->pNext_Usr_Infor = NULL;
		}
		else {
			pnew->pNext_Usr_Infor = *phead;
			*phead = pnew;
		}
		pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	}
	fclose(fp);
}
//打开usr_account.txt并创建一个链表返回一个头指针
void OPEN_ACCOUNT_INFOR(pUSR_ACCOUNT*phead) {
	FILE*fp;
	fp = fopen("usr_account.txt", "r");
	if (fp == NULL) {
		perror("fopen");
	}
	pUSR_ACCOUNT pnew, pcur;
	pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	while (fscanf(fp, "%s %s %d", &pnew->usr_name, &pnew->usr_pwd,&pnew->usr_role) != EOF) {
		if (*phead == NULL) {
			*phead = pnew;
		}
		else {
			pnew->pNext_Usr_Acount = *phead;
			*phead = pnew;
		}
		pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	}
	fclose(fp);
}
//打开usr_infor.txt并重新写入
void WRITE_BACK_USR_INFOR(pUSR_INFOR *phead) {
	FILE*fp;
	fp = fopen("usr_infor.txt", "w+");
	if (fp == NULL) {
		perror("fopen");
	}
	while (*phead) {
		int ret = 0;
		ret=fprintf(fp, "%d %s %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", (*phead)->usr_id, (*phead)->usr_name, (*phead)->usr_english_score, (*phead)->usr_math_score, (*phead)->usr_chinese_score, (*phead)->usr_biology_score, (*phead)->usr_physical_score);
		*phead = (*phead)->pNext_Usr_Infor;
	}
	fclose(fp);
}
//从小到大的有序链表
void LIST_LOW_TO_HIGH(pUSR_INFOR*phead) {
	pUSR_INFOR phead2 = NULL, ptemp, pcur, ppre;
	ptemp = *phead;
	while (*phead) {
		*phead = (*phead)->pNext_Usr_Infor;
		ptemp->pNext_Usr_Infor = NULL;
		pcur = phead2;
		ppre = phead2;
		if (phead2 == NULL) {
			phead2 = ptemp;
		}
		else {
			if (ptemp->usr_id < phead2->usr_id) {
				ptemp->pNext_Usr_Infor = phead2;
				phead2 = ptemp;
			}
			else {
				while (pcur) {
					if (pcur->usr_id > ptemp->usr_id) {
						ppre->pNext_Usr_Infor = ptemp;
						ptemp->pNext_Usr_Infor = pcur;
						break;
					}
					ppre = pcur;
					pcur = pcur->pNext_Usr_Infor;
				}
				if (pcur == NULL) {
					ppre->pNext_Usr_Infor = ptemp;
				}
			}
		}
		ptemp = *phead;
	}
	*phead = phead2;
}

void WRITE_BACK_USR_ACCOUNT(pUSR_ACCOUNT *phead) {
	FILE*fp;
	fp = fopen("usr_account.txt", "w+"); 
	if(fp==NULL){
		perror("fopen");
	}
	while (*phead) {
		fprintf(fp, "%s  %s  %d\n", (*phead)->usr_name, (*phead)->usr_pwd, (*phead)->usr_role);
		*phead = (*phead)->pNext_Usr_Acount;
	}
	fclose(fp);
}

//主要功能

//search student information
void SEARCH_STU_INFOR() {
	system("cls");
	printf("Please enter the id of the student you want to search:\n");
	int student_id=0;
	scanf("%d", &student_id);
	pUSR_INFOR phead = NULL;
	OPEN_USR_INFOR(&phead);
	while (phead) {
		if (phead->usr_id == student_id) {
			printf("%d  %s %5.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", phead->usr_id, phead->usr_name, phead->usr_english_score, phead->usr_math_score, phead->usr_chinese_score, phead->usr_biology_score, phead->usr_physical_score);
			break;
		}
		phead = phead->pNext_Usr_Infor;
	}
	if (phead == NULL) {
		printf("Sorry!!the id of the student are not exist!\n");
	}
	system("pause");
}
//add student information
void ADD_STUDENT_INFOR() {
	system("cls");
	pUSR_INFOR pnew_student,phead=NULL,ptemp;
re_write_limble:
	pnew_student = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	CREAT_INFOR(&pnew_student);//输入信息
	OPEN_USR_INFOR(&phead);
	ptemp = phead;
	while (ptemp) {
		if (phead->usr_id == pnew_student->usr_id) {
			printf("Sorry!!we have a same id in our student list,please think another id!!!\n");
			goto re_write_limble;
		}
		ptemp = ptemp->pNext_Usr_Infor;
	}
	pnew_student->pNext_Usr_Infor = phead;
	phead = pnew_student;
	LIST_LOW_TO_HIGH(&phead);//重新排序
	WRITE_BACK_USR_INFOR(&phead);
	printf("!!!!!success!!!!!");
	system("pause");
}
//更新学生信息
void UPDATE_USR_INFOR() {
	system("cls");
	pUSR_INFOR phead = NULL,ptemp;
	OPEN_USR_INFOR(&phead);
	printf("Please enter the student'id of you want to search:\n");
	int student_id,tag=0;
	scanf("%d", &student_id);
	ptemp = phead;
	while (ptemp) {
		if (ptemp->usr_id == student_id) {
			CREAT_INFOR(&ptemp);
			break;
			tag = 1;
		}
		ptemp = ptemp->pNext_Usr_Infor;
	}
	if (ptemp == NULL&&tag==0) {
		printf("Sorry!!the id you enter are not exist!\n");
		goto end_limble;
	}
	WRITE_BACK_USR_INFOR(&phead);
	printf("!!!!!success!!!!!");
end_limble:
	system("pause");
}
//删除学生信息
void DELE_USR_INFOR() {
	system("cls");
	pUSR_INFOR phead = NULL, ptemp,ppre;
	OPEN_USR_INFOR(&phead);
	printf("Please enter the student'id of you want to delete:\n");
	int student_id, tag = 0;
	scanf("%d", &student_id);
	ptemp = phead;
	ppre = phead;
	if (phead->usr_id == student_id) {
		phead = phead->pNext_Usr_Infor;
	}
	else {
		while (ptemp->pNext_Usr_Infor!=NULL) {
			if (ptemp->usr_id == student_id) {
				ppre->pNext_Usr_Infor = ptemp->pNext_Usr_Infor;
				free(ptemp);
				ptemp = NULL;
				tag = 1;
				break;
			}
			ppre = ptemp;
			ptemp = ptemp->pNext_Usr_Infor;
		}
		if (ptemp->usr_id == student_id) {
			ppre->pNext_Usr_Infor = NULL;
		}else  {
			printf("the id you enter are not exist!\n");
			goto end_limble;
		}
	}
	WRITE_BACK_USR_INFOR(&phead);
	printf("!!!!!success!!!!!");
end_limble:
	system("pause");
}
//add usr account
void ADD_USR_ACCOUNT() {
	system("cls");
	pUSR_ACCOUNT pnew_usr,phead = NULL,ptemp;
re_write_limble:
	pnew_usr = (pUSR_ACCOUNT)calloc(1, sizeof(USR_INFOR));
	printf("Please enter the kind of the account(0 is student, 1 is teacher):\n");
	int role;
	scanf("%d", &role);
	CREAT_COUNT(&pnew_usr,role);
	OPEN_ACCOUNT_INFOR(&phead);
	ptemp = phead;
	while (ptemp) {
		if ( strcmp(ptemp->usr_name, pnew_usr->usr_name)==0) {
			printf("Sorry!!we have a same id in our account list,please think another id!!!\n");
			goto re_write_limble;
		}
		ptemp = ptemp->pNext_Usr_Acount;
	}
    pnew_usr->pNext_Usr_Acount=phead;
	phead = pnew_usr;
	WRITE_BACK_USR_ACCOUNT(&phead);
	printf("!!!!!success!!!!!");
	system("pause");
}
//update usr account
void UPDATE_USR_ACCOUNT() {
	system("cls");
	pUSR_ACCOUNT phead = NULL,ptemp;
	int tag = 0, role=0;
	OPEN_ACCOUNT_INFOR(&phead);
	char usr_account[USR_NAME_LEN];
	printf("Please enter the account you want to update:\n");
	scanf("%s", &usr_account);
	ptemp = phead;
	while (ptemp) {
		if (strcmp(ptemp->usr_name, usr_account) == 0) {
			role = 0;
			printf("Please enter the kind of the account(0 is student, 1 is teacher):\n ");
			scanf("%d", &role);
			CREAT_COUNT(&ptemp, role);
			tag = 1;
			break;
		}
		ptemp = ptemp->pNext_Usr_Acount;
	}
	if ( ptemp == NULL&&tag==0) {
		printf("the account you enter are not exist!\n");
		goto end_limble;
	}
	WRITE_BACK_USR_ACCOUNT(&phead);
	printf("!!!!!success!!!!!");
end_limble:
	system("pause");
}
//delete usr account
void DELE_USR_ACCOUNT() {
	system("cls");
	pUSR_ACCOUNT phead = NULL,pcur,ppre;
	int tag = 0;
	OPEN_ACCOUNT_INFOR(&phead);
	printf("Please enter the account you want to update:\n");
	char usr_account[USR_NAME_LEN];
	scanf("%s", &usr_account);
	pcur = phead;
	ppre = phead;
	if (strcmp(phead->usr_name, usr_account)==0) {
		phead = phead->pNext_Usr_Acount;
	}
	else {
		while (pcur->pNext_Usr_Acount != NULL) {
			if (strcmp(pcur->usr_name, usr_account) == 0) {
				ppre->pNext_Usr_Acount = pcur->pNext_Usr_Acount;
				free(pcur);
				pcur - NULL;
				tag = 1;
				break;
			}
			ppre = pcur;
			pcur = pcur->pNext_Usr_Acount;
		}
		if (strcmp(pcur->usr_name, usr_account)==0 ){
			ppre->pNext_Usr_Acount = NULL;
		}
		if (pcur == NULL && tag == 0) {
			printf("the account you enter are not exist!\n");
			goto end_limble;
		}
	}
	WRITE_BACK_USR_ACCOUNT(&phead);
	printf("!!!!!success!!!!!");
end_limble:
	system("pause");
}
//search usr accoungt
void SEARCH_USR_ACCOUNT() {
	system("cls");
	pUSR_ACCOUNT phead = NULL,ptemp;
	OPEN_ACCOUNT_INFOR(&phead);
	printf("Please enter the account you want to search:\n");
	char usr_account[USR_NAME_LEN];
	scanf("%s", &usr_account);
	ptemp = phead;
	while (ptemp) {
		if (strcmp(ptemp->usr_name, usr_account) == 0) {
			printf("The name of the account is:%s\n", usr_account);
			if (ptemp->usr_role == STUDENT) {
				printf("the role of the account is student\n");
			}
			else {
				printf("the role of the account is teacher\n");
			}
			break;
		}
		ptemp = ptemp->pNext_Usr_Acount;
	}
	if (ptemp == NULL) {
		printf("the account you enter are not exist!\n");
	}
	system("pause");
}


//管理员账户进入这个函数
void ADM() {
choice_limble:
	system("cls");
	SHOW_ADM_MENUE();
	int choice=0;
	printf("            Please enter the choice( 1-9 ):");
	scanf("%d", &choice);
	switch (choice) {
	case 1:SEARCH_STU_INFOR(); break;
	case 2:ADD_STUDENT_INFOR(); break;
	case 3:UPDATE_USR_INFOR(); break;
	case 4:DELE_USR_INFOR(); break;
	case 5:ADD_USR_ACCOUNT(); break;
	case 6:UPDATE_USR_ACCOUNT(); break;
	case 7:DELE_USR_ACCOUNT(); break;
	case 8:SEARCH_USR_ACCOUNT(); break;
	case 9:goto END;
	default:goto choice_limble;
	}
	goto choice_limble;
END:
	printf("\n\n            Welcome to next time!\n");
}
//学生账户进入这个函数
void STU() {
choice_STU_limble:
	system("cls");
	SHOW_STU_MENUE();
	int choice;
	printf("            Please enter the choice( 1-2 ):");
	scanf("%d", &choice);
	switch (choice) {
	case 1:SEARCH_STU_INFOR(); break;
	case 2:goto STU_END;
	default:goto choice_STU_limble;
	}
	goto choice_STU_limble;
STU_END:
	printf("\n\n            Welcome to next time!\n");
}
