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
			printf("ʹ��͸�Ӻ��㷢����������%lf", n);
			printf("\n");
			printf("���Ƿ���Ҫ�����ƣ���Ҫ��1������Ҫ��2");
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
				printf("ʹ��͸�Ӻ��㷢����������%lf", n);
				printf("\n");
				printf("���Ƿ���Ҫ�����ƣ���Ҫ��1������Ҫ��2");
				printf("\n");
			} while (d == 2);
		}
		

	}
	return n;
	

}