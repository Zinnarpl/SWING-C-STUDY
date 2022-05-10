#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#define ROW_SIZE 3
#define COL_SIZE 10
class Seat
{
	int arr[ROW_SIZE][COL_SIZE];
public:
	Seat()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				arr[i][j] = 0;
			}
		}
	}

	void printSeat()
	{
		printf("\n1 2 3 4 5 6 7 8 9 10\n");
		printf("--------------------------------\n");
		for (int k = 0; k < ROW_SIZE; k++)
		{
			for (int i = 0; i < COL_SIZE; i++)
			{
				cout << arr[k][i] << " ";
			}
			cout << endl;
		}
	}

	void reservation()
	{
		int row, col;
		cout << "예약할 좌석의 줄을 입력하세요:";
		cin >> row;
		cout << "예약할 좌석의 열을 입력하세요:" << endl;
		cin >> col;

		if (ROW_SIZE > row - 1 && COL_SIZE > col - 1)
		{
			if (arr[row - 1][col - 1] == 0)
			{
				arr[row - 1][col - 1] = 1;
				cout << "\n예약되었습니다." << endl;
			}
			else
			{
				cout << "이미 예약된 자리입니다." << endl;
			}
		}
		else
		{
			cout << "입력오류." << endl;
		}
	}
};

int main(void)
{
	Seat s;

		int yorn;
		cout << "좌석을 예약하시겠습니까?(0과1중에 선택) : .";
		cin >> yorn;
		if (yorn == 1)
		{
			while (1)
			{
				s.printSeat();
				s.reservation();
			}
		}
		else
		{
			cout << "\n좌석예약종료";
		}
		return 0;
}