#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void huase()
{
    srand((unsigned)time(NULL));
    int i;
    i = rand() % 4 + 1;
    if (i == 1)
        printf("����");
    else if (i == 2)
        printf("����");
    else if (i == 3)
        printf("÷��");
    else if (i == 4)
        printf("����");
}