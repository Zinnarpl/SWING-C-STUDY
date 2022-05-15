#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void total(int* bank, int* total_money)
{
	int i;
	int tot = 0;
	for (i = 0; i < 4; i++)
		tot += bank[i];
	*total_money = tot; 
}

void myaccounts(char* bank_name[], int* bank)
{
	int i;

	printf("********** SWING 자산관리 서비스 ***********\n");
	printf("------------ 은행 별 계좌정보 --------------\n");

	for (i = 0; i < 4; i++)
		printf("   %s   |", bank_name[i]);
	printf("\n");

	for (i = 0; i < 4; i++)
		printf(" %6d   |", bank[i]);
	printf("\n");
	printf("--------------------------------------------\n");
}
int main()
{
	char* bank_name[4] = { "하나","우리","신한","국민" };
	int bank[4] = { 5000, 4000, 0, 10 };
	int total_money = 0;

	myaccounts(bank_name, bank);
	total(bank, &total_money);  // 주소(address)를 매개변수로 사용

	printf("현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 %d원 입니다.\n", total_money);
}"현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 " << total << "입니다. \n";
}