#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main() {
	
	printf("랜덤한 수 : ");
	srand(time(NULL));
    int random = rand() % 100 + 1;
	printf("%d\n", rand() % 100 + 1);

    int count;

    printf("특정배수 개수 : ");
    scanf("%d", &count);    // 값을 입력받음

    int i = 0;
    int baesu;
    while (i < count)                      // i가 count보다 작을 때 반복
    {
        printf("\n%d번째 특정 배수 : ", i); 
        scanf("%d", &baesu);
        printf("<특정배수만 출력하는 프로그램>\n");
        int num = 0;
        int j;
        for (num = 1; num <= random; num++)
            if(num%baesu==0) printf("%d ", num);
        printf("\n<특정배수 제외 출력하는 프로그램>\n");
        for (num = 1; num <= random; num++)
        {
            if (num % baesu == 0)
                continue;
            else
                printf("%d ", num);
        }
        i++;                               // i를 1씩 증가시킴
    }
}