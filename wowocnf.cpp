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

	printf("********** SWING �ڻ���� ���� ***********\n");
	printf("------------ ���� �� �������� --------------\n");

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
	char* bank_name[4] = { "�ϳ�","�츮","����","����" };
	int bank[4] = { 5000, 4000, 0, 10 };
	int total_money = 0;

	myaccounts(bank_name, bank);
	total(bank, &total_money);  // �ּ�(address)�� �Ű������� ���

	printf("���� SWING �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� %d�� �Դϴ�.\n", total_money);
}"���� SWING �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� " << total << "�Դϴ�. \n";
}