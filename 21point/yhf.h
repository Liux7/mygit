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
        printf("ºìÌÒ");
    else if (i == 2)
        printf("·½¿é");
    else if (i == 3)
        printf("Ã·»¨");
    else if (i == 4)
        printf("ºÚÌÒ");
}