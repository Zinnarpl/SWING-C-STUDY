#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <iostream>
using namespace std;

#define SIZE
int main(void) {
	char ans1;
	int ans2, ans3;
	int seats[SIZE] = { 0 };
	while (1) {
		printf("좌석을 예약하시겠습니까?(0이나 1선택) ");
		scanf("%c", &ans1);
		if (ans1 == '1') {
			printf("\n1 2 3 4 5 6 7 8 9 10\n");
			printf("--------------------------------\n");
			int arr[3][10] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

			for (int k = 0;k < 3;k++)
			{
				for (int i = 0;i < 10;i++)
				{
					cout << arr[k][i] << " ";
				}
				cout << endl;
			}

			printf("몇열, 몇번째 좌석을 예약하시겠습니까? ");
			scanf("%d" "%d", &ans2, &ans3);
			if (ans2 == 1)
				printf("\n예약되었습니다.\n");

			else
				printf("이미 예약된 자리입니다.\n");
			}
		else;
		print("\n좌석예약종료\n");
		return 0;
	}
}