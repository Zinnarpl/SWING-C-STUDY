#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


void main()
{
	cout << "********** SWING 자산관리 서비스 ************\n";
	
	int hana = 5000;
	int	uri = 4000;
	int shinhan = 0;
	int kukmin = 10;

	cout << "----------- 은행 별 계좌 정보 ----------\n";
	cout << " 하나    |    우리    |    신한    |    국민    |\n";
	cout << " " << hana << "    |    " << uri << "    |      " << shinhan << "     |     " << kukmin << "     |\n";
	cout << "-----------------------------------------\n";
	
	int total = hana + uri + shinhan + kukmin;
	cout << "현재 SWING 자산관리 서비스에 등록된 회원님의 총 자산은 " << total << "입니다. \n";
}