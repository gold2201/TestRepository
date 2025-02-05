#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "Task12.h"
#include "Task7.h"
 
void main()
{
    system("chcp 1251");
    system("cls");

    int task = 0, num = 0;;

    while (1)
    {
        system("cls");

        printf("Введите номер задачи (Для выхода введите 0): ");
        scanf("%d", &task);

        switch (task)
        {
        case 12:
            system("cls");
            printf("Введите уменьшаемое в 8 раз число: ");
            scanf("%d", &num);
            decrease(num);
            break;

        case 7:
            system("cls");
            task7();
            break;

        default:
            exit(0);
            printf("Программа закрыта");
            break;
        }
    }
}



































//struct testStruct
//{
//	unsigned m: 4;
//};
//
//union byte
//{
//	unsigned number;
//	struct testStruct bit;
//};
//
//int main()
//{
//	union byte x;
//	
//	//unsigned n;
//	//unsigned m = 0;
//	while (1)
//	{
//		scanf("%u", &x.number);
//		x.bit.m = 0;
//		//m = 0;
//		//scanf("%u", &n);
//
//		for (unsigned b8 = 8, b1 = 1; b8 != 0; b8 += b8, b1 += b1)
//		{
//			if ((b8 & x.number) != 0)
//			{
//				x.bit.m |= b1;
//			}
//		}
//		printf("%u\n", x.bit.m);
//	}
//}
