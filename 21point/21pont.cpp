#include<iostream>
#include<math.h>
#include<time.h>
#include"ymz.h"
#include"lfy.h"
#include"yhf.h"
#include"zr.h"

using namespace std;
int x = 1;
bool win();
void money();


int main() {
	system("COLOR fc");
	chushi();
	money();

	return 0;
}

void money() {
	int a = 400, b = 400, c = 0;
	for (;;) {
		cout << "输入您要投的钱数" << "(余额：" << a <<")"<< endl;
		cin >> c;

		if (c > 100 || c < 1) {
			cout << "最多输入1~100\n";
			cin >> c;
		}

		if (win()) {
			a += c;
			b -= c;
			cout << "您现在的钱数为" << a;
			cout << "\n对手还有" << b;
			if (a == 800 || b <= 0) {
				cout << "对手已经没钱了，结束" << endl;
				exit(0);
			}
			else
				cout << "\n继续" << endl;

		}
		else {//输了 
			a -= c;
			b += c;
			cout << "现在的钱" << a;
			cout << "\n对手的钱" << b;
			system("COLOR f0");
			if (a <= 0 || b >= 800) {
				cout << "结束" << endl;
				exit(0);
			}
			else
				cout << "continue" << endl;
		}
	}
}
bool win() {
	bool zhen = true; bool jia = false; int z; char d; int num_i = 0, num_r = 0, c;
	double r, n, i = 0, b;
	int ni = 0, pause;
	r = randd();//自己的牌
	;
	cout << "自己的牌:" << endl;
	huase();
	cout << r << endl;
	
	//i = randd();//对手的牌
//a:cout << "对手的牌" << i << endl;
a:cout << "对手的牌:" << " ??" << endl;
	cout << "是否继续抽牌？" << endl;
	cout << "--------------继续请按1---开牌请按2-------------" << endl;

	cin >> c;
	system("cls");
	chushi();
	while (x) {
		if (c == 1) {
			n = randd();
			printf("确定请按1\n");
			if (ZuoBi(n))
			{
				n = ZuoBi(n);
			}
			cout << "这次你获得点数为：";
			huase();
				cout<<n<< endl<<endl;
			word(n);
			cout << endl<<endl;
			r += n;
			num_r += 1;
			cout << "现在你的总点数为：" << r << endl;
			if (r > 21) {
				cout << "点数超过了21"<<endl; goto b;
			}
			goto a;
			break;
		}
		else if (c == 2) {
			system("COLOR f2");
			x = 0;
			cout << "-----轮到对方的回合----" << endl;
			i = randd();//对手的牌
			cout << "现在对方的点数为：" << i <<endl;
			cout << "输入任意数来让游戏继续"<<endl;
			cin >> pause;
			system("cls");
			chushi();
			
			while (i <= 18 && i < r) {
				cout << "这次对方获得点数为:";
				b = randd();
				cout << b << endl;
				i += b;

				num_i++;
				cout << "现在对方的点数为：" << i<<endl;
				cout << "输入任意数来让游戏继续" << endl;
				cin >> pause;
				system("cls");
				chushi();
			}
			cout << "----现在开牌----";
		}
		else {
			cout << "error,again";
			cin >> c;
		}
	}
	if ((i > r && i < 21) || (i == r) && (num_i > num_r)) {
	b:cout << "对方取得了这场游戏的胜利" << endl;
		system("COLOR f1");
		cout << "是否继续？" << endl<<endl;
		cout << "搏一搏，单车变摩托（y）" << endl <<endl<<
			"学业繁忙，告辞(n)";
		cin >> d;
		if (d == 'n') {
			cout << "------结束------" << endl;
			exit(0);
		}
		else
			return jia;
	}
	else {
		cout << "你取得了这场游戏的胜利" << endl;
		cout << "是否继续？" << endl;
		cout << "搏一搏，单车变摩托（y）" << endl <<
			"学业繁忙，告辞(n)";
		cin >> d;
		if (d == 'n') {
			cout << "结束" << endl;
			exit(0);
		}
		else
			return zhen;
	}
}
