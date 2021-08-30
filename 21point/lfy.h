#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include "ymz.h"
double ZuoBi(double n)
{
	char a;
	int b;
	int d;
	scanf("%c", &a);
	if (a == 'H')
	{
		scanf("%d", &b);
		if (b == 6404)
		{
			printf("使用透视后你发现这张牌是%lf", n);
			printf("\n");
			printf("你是否想要这张牌，想要按1，不想要按2");
			printf("\n");
			do {
				scanf("%d", &d);
				system("cls");
				chushi();
				if (d == 1)
					break;
				if (d == 2)
				{
					n = randd();
				}
				printf("使用透视后你发现这张牌是%lf", n);
				printf("\n");
				printf("你是否想要这张牌，想要按1，不想要按2");
				printf("\n");
			} while (d == 2);
		}
		

	}
	return n;
	

}