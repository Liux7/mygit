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
		cout << "������ҪͶ��Ǯ��" << "(��" << a <<")"<< endl;
		cin >> c;

		if (c > 100 || c < 1) {
			cout << "�������1~100\n";
			cin >> c;
		}

		if (win()) {
			a += c;
			b -= c;
			cout << "�����ڵ�Ǯ��Ϊ" << a;
			cout << "\n���ֻ���" << b;
			if (a == 800 || b <= 0) {
				cout << "�����Ѿ�ûǮ�ˣ�����" << endl;
				exit(0);
			}
			else
				cout << "\n����" << endl;

		}
		else {//���� 
			a -= c;
			b += c;
			cout << "���ڵ�Ǯ" << a;
			cout << "\n���ֵ�Ǯ" << b;
			system("COLOR f0");
			if (a <= 0 || b >= 800) {
				cout << "����" << endl;
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
	r = randd();//�Լ�����
	;
	cout << "�Լ�����:" << endl;
	huase();
	cout << r << endl;
	
	//i = randd();//���ֵ���
//a:cout << "���ֵ���" << i << endl;
a:cout << "���ֵ���:" << " ??" << endl;
	cout << "�Ƿ�������ƣ�" << endl;
	cout << "--------------�����밴1---�����밴2-------------" << endl;

	cin >> c;
	system("cls");
	chushi();
	while (x) {
		if (c == 1) {
			n = randd();
			printf("ȷ���밴1\n");
			if (ZuoBi(n))
			{
				n = ZuoBi(n);
			}
			cout << "������õ���Ϊ��";
			huase();
				cout<<n<< endl<<endl;
			word(n);
			cout << endl<<endl;
			r += n;
			num_r += 1;
			cout << "��������ܵ���Ϊ��" << r << endl;
			if (r > 21) {
				cout << "����������21"<<endl; goto b;
			}
			goto a;
			break;
		}
		else if (c == 2) {
			system("COLOR f2");
			x = 0;
			cout << "-----�ֵ��Է��Ļغ�----" << endl;
			i = randd();//���ֵ���
			cout << "���ڶԷ��ĵ���Ϊ��" << i <<endl;
			cout << "����������������Ϸ����"<<endl;
			cin >> pause;
			system("cls");
			chushi();
			
			while (i <= 18 && i < r) {
				cout << "��ζԷ���õ���Ϊ:";
				b = randd();
				cout << b << endl;
				i += b;

				num_i++;
				cout << "���ڶԷ��ĵ���Ϊ��" << i<<endl;
				cout << "����������������Ϸ����" << endl;
				cin >> pause;
				system("cls");
				chushi();
			}
			cout << "----���ڿ���----";
		}
		else {
			cout << "error,again";
			cin >> c;
		}
	}
	if ((i > r && i < 21) || (i == r) && (num_i > num_r)) {
	b:cout << "�Է�ȡ�����ⳡ��Ϸ��ʤ��" << endl;
		system("COLOR f1");
		cout << "�Ƿ������" << endl<<endl;
		cout << "��һ����������Ħ�У�y��" << endl <<endl<<
			"ѧҵ��æ�����(n)";
		cin >> d;
		if (d == 'n') {
			cout << "------����------" << endl;
			exit(0);
		}
		else
			return jia;
	}
	else {
		cout << "��ȡ�����ⳡ��Ϸ��ʤ��" << endl;
		cout << "�Ƿ������" << endl;
		cout << "��һ����������Ħ�У�y��" << endl <<
			"ѧҵ��æ�����(n)";
		cin >> d;
		if (d == 'n') {
			cout << "����" << endl;
			exit(0);
		}
		else
			return zhen;
	}
}
