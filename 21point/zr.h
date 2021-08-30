#pragma once
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
void word(int i) {
	switch (i)
	{
	case 1:
		cout << "恭喜你，一张A牌，你就是真正的ACE（王牌）";
		break;
	case 2:
		cout << "做人要做老实人，最好有时有张2";
		break;
	case 3:
		cout << "九除以3还是3，除了你还是你";
		break;
	case 4:
		cout << "花开4季，4季花开花落，但不变的是你永远笑靥若花";
		break;
	case 5:
		cout << "偷袭，年轻人你不讲5德";
		break;
	case 6:
		cout << "一波操作猛如虎，队友高呼 6 6 6";
		break;
	case 7:
		cout << "抬头仰望，不仅有著名的北斗 7 星，还有我们中国人的“北斗”，加油，中国人！";
		break;
	case 8:
		cout << "8 8 的 8 8 叫什么，8 8 的 8 8 叫爷爷";
		break;
	case 9:
		cout << "生活不只有眼前的苟且，而且还有长长 9 9 的苟且";
		break;
	default:
		cout << "愿你的生活 10 全 10 美，少一点有瑕疵，多一点太饱满，10 刚刚好";
	}
}