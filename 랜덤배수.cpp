#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main() {
	
	printf("������ �� : ");
	srand(time(NULL));
    int random = rand() % 100 + 1;
	printf("%d\n", rand() % 100 + 1);

    int count;

    printf("Ư����� ���� : ");
    scanf("%d", &count);    // ���� �Է¹���

    int i = 0;
    int baesu;
    while (i < count)                      // i�� count���� ���� �� �ݺ�
    {
        printf("\n%d��° Ư�� ��� : ", i); 
        scanf("%d", &baesu);
        printf("<Ư������� ����ϴ� ���α׷�>\n");
        int num = 0;
        int j;
        for (num = 1; num <= random; num++)
            if(num%baesu==0) printf("%d ", num);
        printf("\n<Ư����� ���� ����ϴ� ���α׷�>\n");
        for (num = 1; num <= random; num++)
        {
            if (num % baesu == 0)
                continue;
            else
                printf("%d ", num);
        }
        i++;                               // i�� 1�� ������Ŵ
    }
}