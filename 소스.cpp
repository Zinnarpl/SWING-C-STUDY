#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;


void main()
{
	cout << "********** SWING �ڻ���� ���� ************\n";
	
	int hana = 5000;
	int	uri = 4000;
	int shinhan = 0;
	int kukmin = 10;

	cout << "----------- ���� �� ���� ���� ----------\n";
	cout << " �ϳ�    |    �츮    |    ����    |    ����    |\n";
	cout << " " << hana << "    |    " << uri << "    |      " << shinhan << "     |     " << kukmin << "     |\n";
	cout << "-----------------------------------------\n";
	
	int total = hana + uri + shinhan + kukmin;
	cout << "���� SWING �ڻ���� ���񽺿� ��ϵ� ȸ������ �� �ڻ��� " << total << "�Դϴ�. \n";
}