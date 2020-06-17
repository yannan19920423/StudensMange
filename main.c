#include"sudent_sysytem.h"

int main() {
BEGIN:
	printf("Please enter the account:");
	char account[USR_NAME_LEN];
	scanf("%s", account);

	pUSR_ACCOUNT phead = NULL, ptemp;
	OPEN_ACCOUNT_INFOR(&phead);
	ptemp = phead;
	while (ptemp) {
		if (strcmp(ptemp->usr_name, account) == 0) {
		pass_word:
			printf("Please enter the password:");
			char paswd[USR_PWD_LEN] = {0};
			char c;
			int i = 0;
			while ((c = getch()) != '\r'&&i < USR_PWD_LEN) {
				if (c == 8) {
					putchar('\b');
					putchar(' ');
					putchar('\b');
					i--;
				}
				else {
					paswd[i] = c;
					i++;
					putchar('*');
				}
			}
			if (strcmp(paswd, ptemp->usr_pwd) == 0) {
				if (ptemp->usr_role == STUDENT) {
					STU();
				}
				else {
					ADM();
				}
			}
			else {
				printf("Sorry!!the password you enter is wrong!!\n");
				goto pass_word;
			}
			break;
		}
		ptemp = ptemp->pNext_Usr_Acount;
	}
	if (ptemp == NULL) {
		printf("The account you enter are not exist!!\n");
		system("pause");
		goto BEGIN;
	}
	//system("pause");
}