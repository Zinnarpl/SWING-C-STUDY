#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <iomanip>
using namespace std;

void total(int* bank, int* total_money)
{
	int i;
	int tot = 0;
	for (i = 0; i < 4; i++)
		tot += bank[i];
	*total_money = tot;  // *total_money: call by address
}

void myaccounts(const char* bank_name[], int* bank)
{
	int i;

	cout << "********** SWING �ڻ���� ���� ***********" << endl;
	cout << "------------ ���� �� �������� --------------" << endl;

	for (i = 0; i < 4; i++)
		cout << "   " << bank_name[i] << "   |";
	cout << endl;

	for (i = 0; i < 4; i++)
		cout << "  " << std::setw(5) << bank[i] << "   |";
	cout << endl;
	cout << "--------------------------------------------" << endl;
}
int main()
{
	const char* bank_name[4] = { "�ϳ�","�츮","����","����" };
	int bank[4] = { 5000, 4000, 0, 10 };
	int total_money = 0;

	myaccounts(bank_name, bank);
	total(bank, &total_money);  // �ּ�(address)�� �Ű������� ���

	cout << "���� SWING �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� ";
	cout << total_money << "�� �Դϴ�." << endl;
}
