#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(void)
{
	cout << "������ �� : ";
	srand(time(NULL));
	int random = rand() % 100 + 1;
    cout << random << endl;

	int count;
	cout << "Ư����� ���� : ";
	cin >> count;

	int i = 0;
	int baesu;
	while (i<count)
    {
        cout <<"\n\n"<< i << "��° Ư�� ��� : ";
        cin >> baesu;
        cout << "<Ư������� ����ϴ� ���α׷�>\n";
        int num = 0;
        int j;
        for (num = 1; num <= random; num++)
            if (num % baesu == 0) cout << " "<< num;
        cout << "\n<Ư����� ���� ����ϴ� ���α׷�>\n";
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