#pragma once
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
double randd() {
	srand(time(NULL));
	int n = rand() % 13 + 1;
	if (n >= 10) {
		return 0.5;
	}
	else {
		return n;
	}
}
void word2(int i) {
	switch (i)
	{
		case 1:
			cout << "你抽到了A";
			break;
		case 2:
			cout << "22222";
			break;
		case 3:
			cout << "33333";
			break;
		case 4:
			cout << "44444";
			break;
		case 5:
			cout << "55555";
			break;
		case 6:
			cout << "66666";
			break;
		case 7:
			cout << "77777";
			break;
		case 8:
			cout << "88888";
			break;
		case 9:
			cout << "99999";
			break;
		default:
			cout << "10jqk";
	}
}
void color(int a);
void chushi() {
	//color(411);
	cout << "***********欢迎进入21点************\n\n";
	cout << "\t    *游戏规则*\n";
	cout << "\t在点数不超过21的条件下\n\t尽量比对方点数多\n\n";
	cout << "***********欢迎进入21点************\n\n";
}
void color(int a)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}