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

	cout << "********** SWING 자산관리 서비스 ***********" << endl;
	cout << "------------ 은행 별 계좌정보 --------------" << endl;

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
	const char* bank_name[4] = { "하나","우리","신한","국민" };
	int bank[4] = { 5000, 4000, 0, 10 };
	int total_money = 0;

	myaccounts(bank_name, bank);
	total(bank, &total_money);  // 주소(address)를 매개변수로 사용

	cout << "현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 ";
	cout << total_money << "원 입니다." << endl;
}
