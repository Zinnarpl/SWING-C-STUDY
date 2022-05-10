#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(void)
{
	cout << "랜덤한 수 : ";
	srand(time(NULL));
	int random = rand() % 100 + 1;
    cout << random << endl;

	int count;
	cout << "특정배수 개수 : ";
	cin >> count;

	int i = 0;
	int baesu;
	while (i<count)
    {
        cout <<"\n\n"<< i << "번째 특정 배수 : ";
        cin >> baesu;
        cout << "<특정배수만 출력하는 프로그램>\n";
        int num = 0;
        int j;
        for (num = 1; num <= random; num++)
            if (num % baesu == 0) cout << " "<< num;
        cout << "\n<특정배수 제외 출력하는 프로그램>\n";
        for (num = 1; num <= random; num++)
        {
            if (num % baesu == 0)
                continue;
            else
                cout << " " << num;
        }
        i++;                            
    }


}