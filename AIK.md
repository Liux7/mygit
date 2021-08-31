# 数据结构

## STL标准库

### 常用函数

#### qsort快排

``` c++
qsort(NAME, NUMBLE, SIZE, CMP);//qsort(students, 7, sizeof(student), cmp);
int cmp(const void a, const void b){
    Student* pa = (Student*)a;
    Student* pb = (Student*)b;
    int num1 = pa->Chinese;
    int num2 = pb->Chinese;
    return num2 - num1;
}
```

> 在cmp函数中：
>
> a-b 排序结果：小 - > 大
>
> b-a 排序结果：大 - > 小



#### 1.2 lower_bound&upper_bound

**有序！！！**

```c++
//查找[first, last)区域中第一个大于 val 的元素。
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                             const T& val);
//查找[first, last)区域中第一个不符合 comp 规则的元素
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                             const T& val, Compare comp);
```

```c++
//在 [first, last) 区域内查找不小于 val 的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val);
//在 [first, last) 区域内查找第一个不符合 comp 规则的元素
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                             const T& val, Compare comp);
```

``` c++
cmp greater<int> 
```



###  map

####  map的储存结构

``` c++
#include<bits/stdc++.h>
using namespace std;
int main (){
	int n;
	cin >> n;
	map<int, int>m;
	m[6] = 3;
	m[5] = 8;
	m[4] = 9;
	for (auto tmp : m) {
		cout << tmp.first << " " << tmp.second << endl;
	}
	return 0;
}
```

> **输出：**
>
> 4 9
>
> 5 8
>
> 6 3

#### 迭代器

``` c++
string::iterator it
(typename) 
    for(auto it=m.begin();it!=m.end();it++)
	cout<<it->first<<" "<<it->second<<endl;
for(auto tmp:m){
	cout<<tmp.first<<" "<<tmp.second<<endl;
}
```

#### map中的查找

``` c++
iter = m.find("123");

if(iter != mapStudent.end())
       cout<<"Find, the value is"<<iter->second<<endl;
else
   cout<<"Do not Find"<<endl;
```

####  map转vector排序（pair）

``` c++
//经测试map无法直接排序
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    unordered_map<int,int> m;//无序的，哈希结构（底层）
    m[6]=3;
    m[5]=8;
    m[4]=9;
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    for(auto tmp:v){
        cout<<tmp.first<<tmp.second<<endl;
    }
    return 0;
}

```

### string

#### 读入一行

``` c++
string s;
getline(cin, s);
```



####  读入一个单词

``` c++
string s;
cin >> s;
```

#### 读入一个字母

``` c++
char s;
cin >>s;
```

#### count

``` c++
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	getline(cin, s);
	n = count(s.begin(), s.end(), ' ');
	cout << n;
	return 0;
}
```

> 输入：
>
> 121212 12122 2
>
> 输出：
>
> 2

#### 3.5 find()

``` c++
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int n;
	getline(cin, s);
	int i = s.find('i');
	cout <<i;
	return 0;
}
```

> 若找不到则返回-1

#### 3.6 统计一个子字符串在另一个字符串中出现的次数

``` c++
int proc(char* str, char* sub)
{
	int n;
	char* p, * r;
	n = 0;
	while (*str){
		p = str;
		r = sub;
		while (*r){
			if (*p == *r){
				p++;
				r++;
			}
			else
				break;
		}
		if (*r == '\0') n++;
		str++;
	}
	return n;
}

```

#### 3.7 数字转字符

``` c++
 string s="1234";
 int i;
 stringstream ss;
 ss<<s;
 ss>>i;
 cout<<i;

ss.str("");
ss.clear();
```

***\*atoi函数（将字符串转换成整型数）\****

**atof（将字符串转换成浮点型数）** 

***\*itoa（把一整数转换为字符串 ）\****

` #include<stdlib.h>`

#### 3.8 substr

``` c++
/**begin是头迭代器，end是尾迭代器*/
string s="5418340";
s=s.substr(1,3);//取418,取索引为1，往后截断3个
s=s.substr(1,-1);//索引为1，截断到最后
cout<<s;
```

#### 3.9 大小写

| tolower(c) | 如果c是大写字母，则返回其小写字母形式，否则直接返回c |
| ---------- | ---------------------------------------------------- |
| toupper(c) | 如果c是小写字母，则返回其大写字母形式，否则直接返回c |

#### 3.10  strcmp()

(const char *s1,const char * s2)

strcmp(字符串1，字符串2)

当s1<s2时，返回为负数

当s1=s2时，返回值= 0

当s1>s2时，返回正数

#### 3.11 一个字符串按字典序排序

``` c++
#include<iostream>
#include<cstring>
using namespace std;

int cmp(const void* a, const void* b) {
	return strcmp((const char*)a, (const char*)b);
}

int main() {
	char ss[105];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ss;
		qsort(ss, strlen(ss), sizeof(char), cmp);
		ss[0] = toupper(ss[0]);
		cout << ss;
		cout << endl;
	}
}
```

#### 3.12 一组字符串按字典序排序

``` c++
//my
#include<iostream>
#include<cstring>
using namespace std;

int cmp(const void* a, const void* b) {
	return strcmp((const char*)a, (const char*)b);
}

int main() {
	char ss[105][105];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ss[i];
		for (int j = 0; j < strlen(ss[i]); j++) {
			
			ss[i][j] = tolower(ss[i][j]);
			
		}
		ss[i][0] = toupper(ss[i][0]);
		
	}
	qsort(ss, n, sizeof(ss[0]), cmp);
	for (int i = 0; i < n; i++) {
		cout << ss[i]<<endl;
	}
	return 0;
}
```

``` c++
//lhc's code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char* ss[105], mm[105][105], * tmp;

int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void check_s(const char* p) {
    while (*p) {
        if (*p == ' ') {
            puts("YES");
            return;
        }
        ++p;
    }
    puts("NO");
}

int main(int argc, char** argv) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mm[i]);
        tmp = mm[i];
        while (*tmp) {
            if (*tmp == 'x' || *tmp == 'X') *tmp = ' ';
            ++tmp;
        }
        ss[i] = mm[i];
    }
    qsort(ss, n, sizeof(ss[0]), cmp);
    for (int i = 0; i < n; ++i) {
        printf("%s", ss[i]);
        check_s(ss[i]);
    }
    return 0;
}
```

#### 3.13 反转

```c++
reverse(str.begin(), str.end());
```

#### 3.14 进制

```c++
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(void)
{
	string s="20";
	int a;
	stringstream ss;
	ss<<hex<<s;    //以16进制读入流中
	ss>>a;        //10进制int型输出
	cout<<a<<endl;
        return 0;
}
//输出：32
```

```c++
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(void)
{
	string s1,s2;
	int a=30;
	stringstream ss;
	ss<<oct<<a;        //10进制转成八进制读入流中，再以字符串输出
	ss>>s1;			
	cout<<s1<<endl;        //输出：36
	ss.clear();		//不清空可能会出错。
	ss<<hex<<a;		 //10进制转成十六进制读入流中，，再以字符串输出
	ss>>s2;			
	cout<<s2<<endl;        //输出：1e
    return 0;
}
```



### 4. priority_queue

#### 4.1 定义

``` c++
//升序队列 top最小
priority_queue <int,vector<int>,greater<int> > q;
//降序队列 top最大
priority_queue <int,vector<int>,less<int> >q;
```

#### 4.2 pair在priority_queue中

**先比较第一个元素当第一个相等时再比较第二个**

### 5. deque

```c++
deque<int>	d;
d.push_back(n);					//从尾部插入元素 
d.push_front(n);				//从头部插入元素
d.insert(d.begin()+set,n); 		//在set位置后插入元素n

d.pop_front();					//头部删除元素
d.pop_back();					//尾部删除元素
d.erase(d.begin()+set);			//中间删除元素(下表从0开始)

/*清空队列*/
d.clear();
 
/*返回元素个数*/
d.size();

```



## 2. 链表

### 1. 普通链表

``` c++
#include <stdio.h>
#include <stdlib.h>
/// 链表数据结构-开始
typedef struct listNode { /// 链表节点
	int value;
	struct listNode* next;
} listNode;

typedef struct list { /// 链表
	listNode* head, * end;
	int total;
} list;

listNode* newListNode() { /// 创建新的链表节点
	listNode* res = (listNode*)malloc(sizeof(listNode));
	return res;
}

list* newList() { /// 创建新的链表
	list* res = (list*)malloc(sizeof(list));
	res->head = res->end = newListNode();
	res->total = 0;
	return res;
}
void push_back(list* ls, int value) { /// 在链表尾部添加节点
	ls->end->next = newListNode();
	ls->end->next->value = value;
	ls->end = ls->end->next;
	++ls->total;
}
void deleteList(list* ls) { /// 释放链表内存
	while (ls->head != ls->end) {
		listNode* tmp = ls->head;
		ls->head = ls->head->next;
		free(tmp);
	}
	free(ls->end);
	free(ls);
}
/// 链表数据结构-结束
```



------

*以下代码*

*水平有限*

*理解不能*

``` c++
#include <iostream>
#include <vector>
using namespace std;
int n, m, r, x, y;
vector<int>* childs[105];
int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= m; ++i) {
		cin >> x;
		if (not childs[x]) childs[x] = new vector<int>;
		childs[x]->push_back(i);
	}
	for (int i = 1; i <= r; ++i) {
		cin >> x >> y;
		swap(childs[x], childs[y]);
	}
	for (int i = 1; i <= n; ++i) {
		if (not childs[i]) cout << "0\n";
		else {
			cout << childs[i]->size();
			for (auto& v : *childs[i]) cout << ' ' << v;
			cout << '\n';
		}
		delete childs[i];
	}
	return 0;
}
```

### 2. 类链表

**类的链表模板：**

```c++
//Node.h
#ifndef NODE_H
#define NODE_H
//类模板的定义
template <class T>
class Node {
private:
    Node<T> *next;  //指向后继结点的指针
public:
    T data; //数据域
    Node (const T &data, Node<T> *next = 0);    //构造函数
    void insertAfter(Node<T> *p);   //在本结点之后插入一个同类结点p 
    Node<T> *deleteAfter(); //删除本结点的后继结点，并返回其地址
    Node<T> *nextNode();            //获取后继结点的地址
    const Node<T> *nextNode() const;     //获取后继结点的地址
};

//类的实现部分
//构造函数，初始化数据和指针成员
template <class T>
Node<T>::Node(const T& data, Node<T> *next = 0 ) : data(data), next(next) { }
//返回后继结点的指针
template <class T>
Node<T> *Node<T>::nextNode() {
    return next;
}
//返回后继结点的指针
template <class T>
const Node<T> *Node<T>::nextNode() const {
    return next;
} 
//在当前结点之后插入一个结点p 
template <class T>
void Node<T>::insertAfter(Node<T> *p) {
    p->next = next; //p结点指针域指向当前结点的后继结点
    next = p;    //当前结点的指针域指向p 
}
//删除当前结点的后继结点，并返回其地址
template <class T> Node<T> *Node<T>::deleteAfter() {
    Node<T> *tempPtr = next;//将欲删除的结点地址存储到tempPtr中
    if (next == 0)  //如果当前结点没有后继结点，则返回空指针
        return 0;
    next = tempPtr->next;//使当前结点的指针域指向tempPtr的后继结点
    return tempPtr;         //返回被删除的结点的地址
}
#endif //NODE_H
```

```c++
//LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template <class T>
class LinkedList {
private:
    //数据成员：
    Node<T> *front, *rear;  //表头和表尾指针
    Node<T> *prevPtr, *currPtr;   //记录表当前遍历位置的指针，由插入和删除操作更新
    int size;   //表中的元素个数
    int position;   //当前元素在表中的位置序号。由函数reset使用

    //函数成员：
    //生成新结点，数据域为item，指针域为ptrNext
    Node<T> *newNode(const T &item,Node<T> *ptrNext=NULL);

    //释放结点
    void freeNode(Node<T> *p);

    //将链表L 拷贝到当前表（假设当前表为空）。
    //被拷贝构造函数、operator = 调用
    void copy(const LinkedList<T>& L);

public:
    LinkedList();   //构造函数
    LinkedList(const LinkedList<T> &L);  //拷贝构造函数
    ~LinkedList();  //析构函数
    LinkedList<T> & operator = (const LinkedList<T> &L); //重载赋值运算符

    int getSize() const;    //返回链表中元素个数
    bool isEmpty() const;   //链表是否为空

    void reset(int pos = 0);//初始化游标的位置
    void next();    //使游标移动到下一个结点
    bool endOfList() const; //游标是否到了链尾
    int currentPosition() const;    //返回游标当前的位置

    void insertFront(const T &item);    //在表头插入结点
    void insertRear(const T &item);     //在表尾添加结点
    void insertAt(const T &item);       //在当前结点之前插入结点
    void insertAfter(const T &item);    //在当前结点之后插入结点

    T deleteFront();    //删除头结点
    void deleteCurrent();   //删除当前结点

    T& data();              //返回对当前结点成员数据的引用
    const T& data() const;   //返回对当前结点成员数据的常引用

    //清空链表：释放所有结点的内存空间。被析构函数、operator= 调用
    void clear();
};

template <class T> //生成新结点
Node<T> *LinkedList<T>::newNode(const T& item, Node<T>* ptrNext)
{
    Node<T> *p;
    p = new Node<T>(item, ptrNext);
    if (p == NULL)
    {
        cout << "Memory allocation failure!\n";
        exit(1);
    }
    return p;
}

template <class T>
void LinkedList<T>::freeNode(Node<T> *p) //释放结点
{
    delete p;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L) //链表复制函数
{
    Node<T> *p = L.front;   //P用来遍历L 
    int pos;
    while (p != NULL)   //将L中的每一个元素插入到当前链表最后
    {
        insertRear(p->data);
        p = p->nextNode();
    }
    if (position == -1) //如果链表空,返回
        return;
    //在新链表中重新设置prevPtr和currPtr
    prevPtr = NULL;
    currPtr = front;
    for (pos = 0; pos != position; pos++)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
    }
}

template <class T>  //构造一个新链表，将有关指针设置为空，size为0，position为-1
LinkedList<T>::LinkedList() : front(NULL), rear(NULL),
prevPtr(NULL), currPtr(NULL), size(0), position(-1)
{}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)  //拷贝构造函数
{
    front = rear = NULL;
    prevPtr = currPtr = NULL;
    size = 0;
    position = -1;
    copy(L);
}

template <class T>
LinkedList<T>::~LinkedList()    //析构函数
{
    clear();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L)//重载"="
{
    if (this == &L) // 不能将链表赋值给它自身
        return *this;
    clear();
    copy(L);
    return *this;
}

template <class T>
int LinkedList<T>::getSize() const  //返回链表大小的函数
{
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const //判断链表为空否
{
    return size == 0;
}

template <class T>
void LinkedList<T>::reset(int pos)  //将链表当前位置设置为pos 
{
    int startPos;
    if (front == NULL)  // 如果链表为空，返回
        return;
    if (pos < 0 || pos > size - 1)  // 如果指定位置不合法，中止程序
    {
        std::cerr << "Reset: Invalid list position: " << pos << endl;
        return;
    }
    // 设置与遍历链表有关的成员
    if (pos == 0)   // 如果pos为0，将指针重新设置到表头
    {
        prevPtr = NULL;
        currPtr = front;
        position = 0;
    }
    else    // 重新设置 currPtr, prevPtr, 和 position 
    {
        currPtr = front->nextNode();
        prevPtr = front;
        startPos = 1;
        for (position = startPos; position != pos; position++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
        }
    }
}

template <class T>
void LinkedList<T>::next()  //将prevPtr和currPtr向前移动一个结点
{
    if (currPtr != NULL)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
        position++;
    }
}

template <class T>
bool LinkedList<T>::endOfList() const   // 判断是否已达表尾
{
    return currPtr == NULL;
}

template <class T>
int LinkedList<T>::currentPosition() const  // 返回当前结点的位置
{
    return position;
}

template <class T>
void LinkedList<T>::insertFront(const T& item)   // 将item插入在表头
{
    if (front != NULL)  // 如果链表不空则调用Reset 
        reset();
    insertAt(item); // 在表头插入
}

template <class T>
void LinkedList<T>::insertRear(const T& item)   // 在表尾插入结点
{
    Node<T> *nNode;
    prevPtr = rear;
    nNode = newNode(item);  // 创建新结点
    if (rear == NULL)   // 如果表空则插入在表头
        front = rear = nNode;
    else
    {
        rear->insertAfter(nNode);
        rear = nNode;
    }
    currPtr = rear;
    position = size;
    size++;
}

template <class T>
void LinkedList<T>::insertAt(const T& item) // 将item插入在链表当前位置
{
    Node<T> *nNode;
    if (prevPtr == NULL)    // 插入在链表头，包括将结点插入到空表中
    {
        nNode = newNode(item, front);
        front = nNode;
    }
    else    // 插入到链表之中. 将结点置于prevPtr之后
    {
        nNode = newNode(item);
        prevPtr->insertAfter(nNode);
    }
    if (prevPtr == rear)    //正在向空表中插入，或者是插入到非空表的表尾
    {
        rear = nNode;   //更新rear 
        position = size;    //更新position 
    }
    currPtr = nNode;    //更新currPtr
    size++; //使size增值
}

template <class T>
void LinkedList<T>::insertAfter(const T& item)  // 将item 插入到链表当前位置之后
{
    Node<T> *p;
    p = newNode(item);
    if (front == NULL)   // 向空表中插入
    {
        front = currPtr = rear = p;
        position = 0;
    }
    else    // 插入到最后一个结点之后
    {
        if (currPtr == NULL)
            currPtr = prevPtr;
        currPtr->insertAfter(p);
        if (currPtr == rear)
        {
            rear = p;
            position = size;
        }
        else
            position++;
        prevPtr = currPtr;
        currPtr = p;
    }
    size++;              // 使链表长度增值
}

template <class T>
T LinkedList<T>::deleteFront()  // 删除表头结点
{
    T item;
    reset();
    if (front == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    item = currPtr->data;
    deleteCurrent();
    return item;
}

template <class T>
void LinkedList<T>::deleteCurrent() // 删除链表当前位置的结点
{
    Node<T> *p;
    if (currPtr == NULL)    // 如果表空或达到表尾则出错
    {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    if (prevPtr == NULL)    // 删除将发生在表头或链表之中
    {
        p = front;  // 保存头结点地址
        front = front->nextNode();  //将其从链表中分离
    }
    else    //分离prevPtr之后的一个内部结点，保存其地址
        p = prevPtr->deleteAfter();

    if (p == rear)  // 如果表尾结点被删除
    {
        rear = prevPtr; //新的表尾是prevPtr 
        position--; //position自减
    }
    currPtr = p->nextNode();    // 使currPtr越过被删除的结点
    freeNode(p);    // 释放结点，并
    size--; //使链表长度自减
}

template <class T>
T& LinkedList<T>::data()    //返回一个当前结点数值的引用
{
    if (size == 0 || currPtr == NULL)   // 如果链表为空或已经完成遍历则出错
    {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}

template <class T>
void LinkedList<T>::clear() //清空链表
{
    Node<T> *currPosition, *nextPosition;
    currPosition = front;
    while (currPosition != NULL)
    {
        nextPosition = currPosition->nextNode(); //取得下一结点的地址
        freeNode(currPosition); //删除当前结点
        currPosition = nextPosition;    //当前指针移动到下一结点
    }
    front = rear = NULL;
    prevPtr = currPtr = NULL;
    size = 0;
    position = -1;
}
#endif  //LINKEDLIST_H
```



## 3. 树

### 1. 前序中序后序

``` c++
#include<stdio.h>
#include<bits/stdc++.h>
typedef char ElemType;

typedef struct BiNode{
	ElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;

BiTree preOrderCreateBiTree(){  //先序建立二叉树方法一
	char ch;
	BiTree T;
	scanf("%c",&ch);
	if (ch=='#'){
		T = NULL;
	}
	else{
		T = (BiTree)malloc(sizeof(BiNode));//!!!是指针类型的节点
		T->data = ch;
		T->lchild = preOrderCreateBiTree();
		T->rchild = preOrderCreateBiTree();
		
	}
	return T;
}
 
void preOrderCreateTree2(BiTree *T){  //这里传进去的是指针的指针，就是指向树根的指针的地址，那 么（*T）就 是 指针的地址了，（*T）是 指针
	char ch;
	scanf("%c", &ch);
	if ('#' == ch){
		*T = NULL;
	}
	else{
		*T = (BiTree)malloc(sizeof(BiNode));
		(*T)->data = ch;
		preOrderCreateTree2(&((*T)->lchild));//根据函数定义这里要传地址
		preOrderCreateTree2(&((*T)->rchild));
	}
}
 
void preOrderTraverse(BiTree T){//这里传入的T是指针！！！；定义*BiTree的时候就是指针类型的别名，那么BiTree定义的都是指针
	printf("%c",T->data);
	preOrderTraverse(T->lchild);
	preOrderTraverse(T->rchild);
}
```

## 4. 线段树

[【数据结构】线段树（Segment Tree）](https://www.bilibili.com/video/BV1cb411t7AM?from=search&seid=14253232898459760290)

## 5.  图

### **图的实现：**

* 邻接矩阵 **数组**

* 邻接表

``` c++
vector<vector<int> > G(n+1, vector<int>());
```

## 6. 迭代器

- 迭代器是算法和容器的桥梁

- - 迭代器用作访问容器中的元素
  - 算法不直接操作容器中的数据，而是通过迭代器间接操作

- 算法和容器独立

- - 增加新的算法，无需影响容器的实现
  - 增加新的容器，原有的算法也能适用

- STL为每个可逆容器都提供了逆向迭代器，逆向迭代器可以通过下面的成员函数得到：

- - rbegin() ：指向容器尾的逆向迭代器
  - rend()：指向容器首的逆向迭代器

```c++
//10_2.cpp
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

//求平方的函数
double square(double x) {
    return x * x;
}
int main() {
    //从标准输入读入若干个实数，分别将它们的平方输出
    transform(istream_iterator<double>(cin), istream_iterator<double>(),
        ostream_iterator<double>(cout, "\t"), square);
    cout << endl;
    return 0;
}
```

### 顺序容器的接口（不包含单向链表（forward_list）和数组（array））

- 构造函数

- 赋值函数

- - assign

- 插入函数

- - insert， push*front（只对list和deque）， push*back，emplace，emplace_front
  - 删除函数
  - erase，clear，pop*front（只对list和deque） ，pop*back，emplace_back

- 首尾元素的直接访问

- - front，back

- 改变大小

- - resize

```c++
set<double>::iterator iter1=s.begin();
copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
map<string, int>::iterator iter = courses.find(name);

 for (map<char, int>::iterator iter = s.begin(); iter != s.end(); ++iter)
        cout << iter->first << " " << iter->second << "  ";
```



10. 日期（ctime）

```c++
#include<iostream>  
#include <ctime>
 
using namespace std;
 
int main() {
 
	struct tm t1 = { 0 };
	struct tm t2 = { 0 };
	double seconds;
 
	t1.tm_year = 2016 - 1900; t1.tm_mon = 10; t1.tm_mday = 21;//现在时间2016,11,21
	t2.tm_year = 2017 - 1900; t2.tm_mon = 5; t2.tm_mday = 7;//高考时间2017,6,7
 
	seconds = difftime(mktime(&t2), mktime(&t1));//转换结构体为time_t,利用difftime,计算时间差
 
	cout << seconds / 86400 << endl;//最后输出时间,因为一天有86400秒(60*60*24)
	system("pause");
	return 0;
}
```

```c++
  struct tm

       {

           int tm_sec;    //秒，[0,59]

           int tm_min；//分钟，[0,59]

           int tm_hour；//小时，[0,23]

           int tm_year；//年，用的时候要加1900

           int tm_mon；//月，用的时候加1，因为范围是[0,11] 

           int tm_mday;  //日，[0,31]

           int tm_wday；//表示星期几，[0,6]

           int tm_isdst； //没用过，也没查过

       }
```



```c++
struct tm *localtime(const time_t *time);
```

该函数将 time_t 转换为本地时间，本地时间是我们经常使用的

```c++
time_t mktime(struct tm *time);
```

该函数用于将日历时间转换为 time_t 格式(自 1970 年 1 月 1 日以来经过的秒数)





# 编程环境

## 1. VS环境

### 1.1 忽略报错

```c++
#pragma warning(disable:4996)
```

### 1.2 文件IO加快debug

```c++
freopen("NAME.in", "r", stdin);
freopen("NAME.out", "w", stdout);

ifstream O("inx.in");
ofstream T("outx.out");

void loading(vector<Acount>& data) {
	ifstream fs("data.txt");
	Acount tmp;
	while (fs >> tmp) {
		data.push_back(tmp);
	}
	fs.close();
}

void write(vector<Acount>& data) {
	ofstream fs("data.txt");

	for (int i = 0; i < data.size(); i++) {
		fs << data[i];
	}
	fs.close();
}


```

## 2. 取消cin与stdin同步

```c++
std::ios::sync_with_stdio(false);
```

这样就可以取消cin于stdin的同步了。

## 3. 多文件结构

* 一个工程可以划分为多个源文件：

  类声明文件（.h文件）

  类实现文件（.cpp文件）

  类的使用文件（main()所在的.cpp文件）

* 利用工程来组合各个文件。

## 4. 生成发布程序

> 生成 - > 清理解决方案 - > 将Debug转为release - > 生成解决方案

## 5. main函数的参数

将此程序的exe文件与in文件放在一个文件夹下。

argc	c count 

argv	v vector

```c++
#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
ifstream O;
int main(int argc,char* argv[]) {
	int x;
	O.open(argv[1]);
	O >> x;
	cout << x << endl;

	return 0;
}
```

## 6. DOS命令

常见的dos命令

* exit 退出；
* cls 清屏；
* 复制 右键 标记 右粘贴键；
* dir 列出所有子文件；
* cd+目标目录（change directory） 切换目录；
* cd 回到上级目录
* cd \ 回到根目录
* c: d:切换盘符
*  ipconfig 查看本机ip

## 7. Linux命令

### 需要知道的

* 挂起操作；

* 系统快照

* Vmx的格式

* Linux的root目录

* Linux的权限机制

* 文本编辑器创建文件

* Root用户首次使用时，需要设置密码

* 用户组

* 文件的权限，修改

* 脚本程序

* 环境变量

### 命令：

* **ls** = list（只有/即根目录）；
* **-l** 详细的 -l /home/liux7;
* Tab 自动补全，箭头 切换历史代码
* **Pwd** print working dircectory 显示当前目录
* **Cd** change directory 切换目录
* **~** 用户的主目录
* **.** 当前目录
* **..** 上一个目录
* **mkdir** 创建目录；
* **mkdir -p abc/123/test** 创建多层目录
* **rmdir** 删除空目录
* **rm -rf abc r** = recursive f = force 强制删除目录和子项
* **cp -rf doc1 doc2**; 复制一个doc2
* **mv doc1 doc2** 重命名
* **tar -cvf xxx.tar file1 file2** 档案打包
* **tar** = tape archive
* **cvf** = creat versbose file 
* **tar -xvf xxx.tar** (-C home) C是指定目录 解档
* ​    x = extact
* -cvf 改成 -xzvf 
* tar -zcvf xxx.tar.gz (-C home 压缩 
* tar -zxvf xxx.tar.gz (-C home 解压缩 
* ln -s sorce link (-s =soft 软链接
* sudo useradd -m test1 添加用户（sudo管理员执行
* sudo passwd test1 设置密码
* sudo userdel test1  删除用户
* sudo rm -rf test1 删除目录
* su root 切换到root用户（su = switch user   
* exit 退出root（记得及时退出
* groupadd boys 创建组
* useradd -m -g boy ming （-g 表示在添加用户，并加到boys组中
* usermod -g boys shapfa （修改现有用户到新的组
* ls -l simple.txt 查看一个文件权限
* **chmod** change file mode 修改文件权限
* chmod o+w test.txt a = all u = user o = other 
* chown (change owner) 修改属主
* chmod +x hello.py 添加权限

###### 

![image-20210303195709028](D:\typora\pic\AIK\image-20210303195709028.png)

## 8.异常处理

```c++
//12_1.cpp
#include <iostream>
using namespace std;
int divide(int x, int y) {
    if (y == 0)
        throw x;
    return x / y;
}
int main() {
    try {
        cout << "5 / 2 = " << divide(5, 2) << endl;
        cout << "8 / 0 = " << divide(8, 0) << endl;
        cout << "7 / 1 = " << divide(7, 1) << endl;
    } catch (int e) {
        cout << e << " is divided by zero!" << endl;
    }
    cout << "That is ok." << endl;
    return 0;
}
```

### 异常接口声明

- 一个函数显式声明可能抛出的异常，有利于函数的调用者为异常处理做好准备

- 可以在函数的声明中列出这个函数可能抛掷的所有异常类型。

  ```c++
  例如：void fun() throw(A，B，C，D);
  ```

- 若无异常接口声明，则此函数可以抛掷任何类型的异常。

- 不抛掷任何类型异常的函数声明如下：

  ```c++
  void fun() throw();
  ```

###  带析构语义的类的C++异常处理

```c++
//12_2.cpp
#include <iostream>
#include <string>
using namespace std;
class MyException {
public:
    MyException(const string &message) : message(message) {}
    ~MyException() {}
    const string &getMessage() const { return message; }
private:
    string message;
};

class Demo {
public:
    Demo() { cout << "Constructor of Demo" << endl; }
    ~Demo() { cout << "Destructor of Demo" << endl; }
};
void func() throw (MyException) {
    Demo d;
    cout << "Throw MyException in func()" << endl;
    throw MyException("exception thrown by func()");
}

int main() {
    cout << "In main function" << endl;
    try {
        func();
    } catch (MyException& e) {
        cout << "Caught an exception: " << e.getMessage() << endl;
    } 
    cout << "Resume the execution of main()" << endl;
    return 0;
}
运行结果：
In main function
Constructor of Demo
Throw MyException in func()
Destructor of Demo
Caught an exception: exception thrown by func()
Resume the execution of main()
```

## 9. 函数申明后加const

```c++
// test1107.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class aa{
    int num;
public:
    aa(){
        int b =10;
        num = b;
    };
    void out1(){
        cout<<num<<endl;
    }
    void out2() const{
        cout<<num<<endl;
    }
    void out3() const{
        num+=10; //出错，const函数不能修改其数据成员
        cout<<num<<endl;
    }

};
int _tmain(int argc, _TCHAR* argv[])
{
    aa a1;
    a1.out1();
    a1.out2();
    a1.out3();
    const aa a2;
    a2.out1(); // 错误，const的成员 不能访问非const的函数
    a2.out2();
    a2.out3();
    return 0;
}
```



# c++



**软件 = 程序 + 文档**

## 2. 简单程序设计

### 2.2 进制

> 八进制：0+若干个0~7的数字
>
> 十六进制：0x+若干个字符

### 2.3 运算符

<< 流插入运算符

### 2.4 操纵符

| 操纵符名          | 含义                               |
| ----------------- | ---------------------------------- |
| setfill()         | 填充                               |
| dec               | 数值数据采用十进制表示             |
| hex               | 数值数据采用十六进制表示           |
| oct               | 数值数据采用八进制表示             |
| ws                | 提取空白符                         |
| endl              | 插入换行符，并刷新流               |
| ends              | 插入空字符                         |
| setprecision(int) | 设置浮点数的小数位数（包括小数点） |
| setw(int)         | 设置域宽                           |

### 2.5 自定义类型

> using NAME = double;
>
> 等价于
>
> typedef double NAME;

#### 2.5.1 枚举类型

> * 定义方式：
>
> 将全部可取值一一列举出来。
>
> * 语法形式：
>
> enum 枚举类型名 {变量值列表};
>
> 例：enum Weekday {SUN, MON, TUE, WED, THU, FRI, SAT};
>
> 默认情况下
>
> SUN=0，MON=1，TUE=2，......，SAT=6

``` c++
/*设某次体育比赛的结果有四种可能：胜（WIN）、负（LOSE）、平局（TIE）、比赛取消（CANCEL），编写程序顺序输出这四种情况。
比赛结果只有四种可能，可以声明一个枚举类型。
*/
#include <iostream>

using namespace std;

enum GameResult {WIN, LOSE, TIE, CANCEL};

int main() {

      GameResult result;

      enum GameResult omit = CANCEL;

      for (int count = WIN; count <= CANCEL; count++) {

        result = GameResult(count);

        if (result == omit)

          cout << "The game was cancelled" << endl;

        else {

          cout << "The game was played ";

          if (result == WIN)      cout << "and we won!";

          if (result == LOSE)       cout << "and we lost.";

          cout << endl;

        }

      }

      return 0;

}
```

#### 2.5.2 auto类型与decltype类型

> * auto：编译器通过初始值自动推断变量的类型
>
> n 例如：auto val = val1 + val2;
>
> 如果val1+val2是int类型，则val是int类型；
>
> 如果val1+val2是double类型，则val是double类型。
>
> * decltype：定义一个变量与某一表达式的类型相同，但并不用该表达式初始化变量
>
>   例如：decltype(i) j = 2;

### 2.6 静态

**用static申明有静态生存期**

#### 2.6.1 静态数据成员：

* 用关键字static声明

* 为该类的所有对象共享，静态数据成员具有静态生存期。

* 必须在类外定义和初始化，用(::)来指明所属的类。

``` c++
#include <iostream>

using namespace std;

class Point {     //Point类定义
public:       //外部接口
       Point(int x = 0, int y = 0) : x(x), y(y) { //构造函数
          //在构造函数中对count累加，所有对象共同维护同一个count
           count++;
       }

       Point(Point &p) {    //复制构造函数
           x = p.x;
           y = p.y;
           count++;
       }

       ~Point() {  count--; }
       int getX() { return x; }
       int getY() { return y; }
      void showCount() {           //输出静态数据成员
           cout << "  Object count = " << count << endl;
       }

private:      //私有数据成员
       int x, y;
       static int count;       //静态数据成员声明，用于记录点的个数
};

int Point::count = 0;//静态数据成员定义和初始化，使用类名限定
int main() {       //主函数
       Point a(4, 5);     //定义对象a，其构造函数回使count增1
       cout << "Point A: " << a.getX() << ", " << a.getY();
       a.showCount(); //输出对象个数
       Point b(a); //定义对象b，其构造函数回使count增1
       cout << "Point B: " << b.getX() << ", " << b.getY();

       b.showCount();       //输出对象个数

       return 0;

}


运行结果：

 Point A: 4, 5  Object count=1

 Point B: 4, 5  Object count=2
```

#### 2.6.2 静态函数成员

* **静态成员函数**主要用于处理该类的**静态数据成员**，可以直接调用静态成员函数

* 静态函数属于整个类

``` c++
#include <iostream>

using namespace std;

class Point {    

public:      
       Point(int x = 0, int y = 0) : x(x), y(y) {  count++; }//构造函数                  
       Point(Point &p) {    //复制构造函数

           x = p.x;
           y = p.y;
           count++;

       }

       ~Point() {  count--; }
       int getX() { return x; }
       int getY() { return y; }

       static void showCount() {   
      cout << "  Object count = " << count << endl;
       }
 

private:     
       int x, y;
       static int count;       //静态数据成员声明，用于记录点的个数
};

int Point::count = 0;//静态数据成员定义和初始化，使用类名限定

int main() {      
       Point a(4, 5);     //定义对象a，其构造函数回使count增1
       cout << "Point A: " << a.getX() << ", " << a.getY();
       Point::showCount();       //输出对象个数
       Point b(a); //定义对象b，其构造函数回使count增1
       cout << "Point B: " << b.getX() << ", " << b.getY();
       Point::showCount();       //输出对象个数
       return 0;

}
```

### 2.7 动态内存分配

动态申请内存操作符 new

- new 类型名T（初始化参数列表）

- 功能：在程序执行期间，申请用于存放T类型对象的内存空间，并依初值列表赋以初值。

- 结果值：成功：T类型的指针，指向新分配的内存；失败：抛出异常。

  delete 指针名

new 类型名T [数组长度]

delete[] 数组名

### 2.8 重载运算符

运算符重载是对已有的运算符赋予多重含义，使同一个运算符作用于不同类型的数据时导致不同的行为。C++ 几乎可以重载全部的运算符，而且只能够重载C++中已经有的。不能重载的运算符：“.”、“.*”、“::”、“?:”

#### 重载为类的非静态成员函数；

**双目运算符：**

- 如果要重载 B 为类成员函数，使之能够实现表达式 *oprd1 B oprd2*，其中 oprd1 为A 类对象，则 B 应被重载为 A 类的成员函数，形参类型应该是 oprd2 所属的类型。
- 经重载后，表达式 oprd1 B oprd2 相当于 oprd1.operator B(oprd2)

```c++
#include <iostream>
using namespace std;
class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }
    //运算符+重载成员函数
  Complex operator + (const Complex &c2) const;
    //运算符-重载成员函数
  Complex operator - (const Complex &c2) const;
    void display() const;   //输出复数
private:
    double real;    //复数实部
    double imag;    //复数虚部
};
例8-1复数类加减法运算重载为成员函数
Complex Complex::operator+(const Complex &c2) const{
  //创建一个临时无名对象作为返回值 	
  return Complex(real+c2.real, imag+c2.imag); 
}

Complex Complex::operator-(const Complex &c2) const{
 //创建一个临时无名对象作为返回值
    return Complex(real-c2.real, imag-c2.imag); 
}

void Complex::display() const {
    cout<<"("<<real<<", "<<imag<<")"<<endl;
}
例8-1复数类加减法运算重载为成员函数
int main() {
    Complex c1(5, 4), c2(2, 10), c3;
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    c3 = c1 - c2;   //使用重载运算符完成复数减法
    cout << "c3 = c1 - c2 = "; c3.display();
    c3 = c1 + c2;   //使用重载运算符完成复数加法
    cout << "c3 = c1 + c2 = "; c3.display();
    return 0;
}
```

**单目运算符：**

- 如果要重载 U 为类成员函数，使之能够实现表达式 U oprd，其中 oprd 为A类对象，则 U 应被重载为 A 类的成员函数，无形参。
- 经重载后，表达式 U oprd 相当于 oprd.operator U()

```c++
#include <iostream>
using namespace std;
class Clock {//时钟类定义
public: 
    Clock(int hour = 0, int minute = 0, int second = 0);
    void showTime() const;
  //前置单目运算符重载
    Clock& operator ++ ();
  //后置单目运算符重载
    Clock operator ++ (int);    
private:
    int hour, minute, second;
};

Clock::Clock(int hour, int minute, int second) {    
    if (0 <= hour && hour < 24 && 0 <= minute && minute < 60
        && 0 <= second && second < 60) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    } else
        cout << "Time error!" << endl;
}
void Clock::showTime() const {  //显示时间
    cout << hour << ":" << minute << ":" << second << endl;
}

例8-2重载前置++和后置++为时钟类成员函数
Clock & Clock::operator ++ () { 
    second++;
    if (second >= 60) {
        second -= 60;  minute++;
        if (minute >= 60) {
          minute -= 60; hour = (hour + 1) % 24;
        }
    }
    return *this;
}

Clock Clock::operator ++ (int) {
    //注意形参表中的整型参数
    Clock old = *this;
    ++(*this);  //调用前置“++”运算符
    return old;
}
例8-2重载前置++和后置++为时钟类成员函数
int main() {
    Clock myClock(23, 59, 59);
    cout << "First time output: ";
    myClock.showTime();
    cout << "Show myClock++:    ";
    (myClock++).showTime();
    cout << "Show ++myClock:    ";
    (++myClock).showTime();
    return 0;
}
```



#### 重载为非成员函数：

有些运算符不能重载为成员函数，例如二元运算符的左操作数不是对象，或者是不
能由我们重载运算符的对象

- 双目运算符 B重载后，

表达式oprd1 B oprd2

等同于operator B(oprd1,oprd2 )

- 前置单目运算符 B重载后，

表达式 B oprd

等同于operator B(oprd )

- 后置单目运算符 ++和--重载后，

表达式 oprd B

等同于operator B(oprd,0 )





• 将+、-（双目）重载为非成员函数，并将其声明为复数类的友元，两个操作数都是复数类的常引用。 • 将<<（双目）重载为非成员函数，并将其声明为复数类的友元，它的左操作数是std::ostream引用，右操作数为复数类的常引用，返回std::ostream引用，用以支持下面形式的输出：

```c++
cout << a << b;
```

该输出调用的是：

```c++
operator << (operator << (cout, a), b);
istream& operator >> (istream& in, Student& s) {
    in >> s.id >> s.name >> s.grade;
    return in;
}
ostream& operator << (ostream& out, Student& s) {
    out << s.id << " " << s.name << " " << s.grade << endl;
    return out;
}
```

```c++
 //8_3.cpp
    #include <iostream>
    using namespace std;

    class Complex {
    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }  
        friend Complex operator+(const Complex &c1, const Complex &c2);
        friend Complex operator-(const Complex &c1, const Complex &c2);
        friend ostream & operator<<(ostream &out, const Complex &c);
    private:    
        double real;  //复数实部
        double imag;  //复数虚部
    };

    Complex operator+(const Complex &c1, const Complex &c2){
        return Complex(c1.real+c2.real, c1.imag+c2.imag); 
    }
    Complex operator-(const Complex &c1, const Complex &c2){
        return Complex(c1.real-c2.real, c1.imag-c2.imag); 
    }

    ostream & operator<<(ostream &out, const Complex &c){
        out << "(" << c.real << ", " << c.imag << ")";
        return out;
    }

    int main() {    
        Complex c1(5, 4), c2(2, 10), c3;    
        cout << "c1 = " << c1 << endl;
        cout << "c2 = " << c2 << endl;
        c3 = c1 - c2;   //使用重载运算符完成复数减法
        cout << "c3 = c1 - c2 = " << c3 << endl;
        c3 = c1 + c2;   //使用重载运算符完成复数加法
        cout << "c3 = c1 + c2 = " << c3 << endl;
        return 0;
    }
```

```c++
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Complex
{
    double real,imag;   
public:
    Complex( double r=0, double i=0):real(r),imag(i){ };
    friend ostream & operator<<( ostream & os,const Complex & c);
    friend istream & operator>>( istream & is,Complex & c);
};
ostream & operator<<( ostream & os,const Complex & c)
{
    os << c.real << "+" << c.imag << "i"; //以"a+bi"的形式输出
    return os;
}
istream & operator>>( istream & is,Complex & c)
{
    string s;
    is >> s;  //将"a+bi"作为字符串读入, "a+bi" 中间不能有空格
    int pos = s.find("+",0);
    string sTmp = s.substr(0,pos); //分离出代表实部的字符串
    c.real = atof(sTmp.c_str());//atof库函数能将const char*指针指向的内容转换成 float
    sTmp = s.substr(pos+1, s.length()-pos-2);   //分离出代表虚部的字符串
    c.imag = atof(sTmp.c_str());
    return is;
}
int main()
{
    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    return 0;
}
```



### 2.9 保留小数

- 如果不指定fixed或scientific，精度值表示有效数字位数。
- 如果设置了ios*base::fixed或ios*base::scientific精度值表示小数点之后的位数。

保留6位小数

```c++
cout <<fixed<< setprecision(6) << i;
```

1.普通格式：独立使用*setprecision(n)*表示有效位数n

2.定点表示格式：fixed与setprecision(n)配合，表示小数精度n位

3.科学表示格式：scientific与setprecision(n)配合，表示小数精确度n位

#### **控制输出精度——指定fixed**

```c++
cout << setiosflags(ios_base::fixed);   
for (int i=0;i<4;i++)
cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//清除左对齐设置
        << setw(10) << setprecision(1) << values[i] << endl;
    
输出结果：
Zoot         1.2
Jimmy       35.4
Al         653.7
Stan      4358.2
```

#### 控制输出精度——指定scientific

```c++
cout << setiosflags(ios_base::scientific);
for (int i=0;i<4;i++)
cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//清除左对齐设置
        << setw(10) << setprecision(1) << values[i] << endl;

输出结果：
Zoot    1.2e+000
Jimmy   3.5e+001
Al      6.5e+002
Stan    4.4e+003
```

### 2.10  基于范围的for循环

``` c++
int main()
{
	int array[3] = {1,2,3};
	for(int & e : array)
	{
  	  e += 2;
  	  std::cout<<e<<std::endl;
	}
return 0;
}
```



### 2.11 流类库

- 当程序与外界环境进行信息交换时，存在着两个对象：程序中的对象、文件对象。 流，一种抽象，负责在数据的生产者和数据的消费者之间建立联系，并管理数据的流动。



#### 最重要的三个输出流

- ostream
- ofstream
- ostringstream

#### 预先定义的输出流对象

- cout 标准输出
- cerr 标准错误输出，没有缓冲，发送给它的内容立即被输出。
- clog 类似于cerr，但是有缓冲，缓冲区满时被输出。

#### 构造输出流对象

- ofstream类支持磁盘文件输出

- 如果在构造函数中指定一个文件名，当构造这个文件时该文件是自动打开的

  ```c++
  ofstream myFile("filename");
  ```

- 可以在调用默认构造函数之后使用open成员函数打开文件

  ```c++
  ofstream myFile; //声明一个静态文件输出流对象
  myFile.open("filename");   //打开文件，使流对象与文件建立联系
  ```

- 在构造对象或用open打开文件时可以指定模式

  ```c++
  ofstream myFile("filename", ios_base::out | ios_base::binary);
  ```

#### 文件输出流成员函数

- open函数

把流与一个特定的磁盘文件关联起来。
需要指定打开模式。

- put函数

把一个字符写到输出流中。

- write函数

把内存中的一块内容写到一个文件输出流中

- seekp和tellp函数

操作文件流的内部指针

- close函数

关闭与一个文件输出流关联的磁盘文件

- 错误处理函数

在写到一个流时进行错误处理

#### 设置对齐方式

```
//11_3.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)//左对齐
           << setw(6) << names[i]
           << resetiosflags(ios_base::left)
           << setw(10) << values[i] << endl;
    return 0;
}
输出结果:
Zoot        1.23
Jimmy      35.36
Al         653.7
Stan     4358.24
```

#### setiosflags的参数（流的格式标识）

- ios_base::skipws 在输入中跳过空白 。
- ios_base::left 左对齐值，用填充字符填充右边。
- ios_base::right 右对齐值，用填充字符填充左边（默认对齐方式）。
- ios_base::internal 在规定的宽度内，指定前缀符号之后，数值之前，插入指定的填充字符。
- ios_base::dec 以十进制形式格式化数值（默认进制）。
- ios_base::oct 以八进制形式格式化数值 。
- ios_base::hex 以十六进制形式格式化数值。
- ios_base::showbase 插入前缀符号以表明整数的数制。
- ios_base::showpoint 对浮点数值显示小数点和尾部的0 。
- ios_base::uppercase 对于十六进制数值显示大写字母A到F，对于科学格式显示大写字母E 。
- ios_base::showpos 对于非负数显示正号（“+”）。
- ios_base::scientific 以科学格式显示浮点数值。
- ios_base::fixed 以定点格式显示浮点数值（没有指数部分） 。
- ios_base::unitbuf 在每次插入之后转储并清除缓冲区内容。

## 3. 函数

### 3.1 可变参数

> - 如果所有的实参类型相同，可以传递一个名为initializer_list的标准库类型；
> - 如果实参的类型不同，我们可以编写可变参数的模板（第9章）。

### 3.2 内联函数

* 声明时使用关键字 inline。

* 编译时在调用处用函数体进行替换，节省了参数传递、控制转移等开销。

**注意：**

* 内联函数体内不能有循环语句和switch语句；

* 内联函数的定义必须出现在内联函数第一次被调用之前；

* 对内联函数不能进行异常接口声明。

``` c++
#include <iostream>
using namespace std;
const double PI = 3.14159265358979;
inline double calArea(double radius) {
          return PI * radius * radius;
}
int main() {
          double r = 3.0;
          double area = calArea(r);
          cout << area << endl;
          return 0;
}
```

### 3.3 constexpr函数

> * constexpr修饰的函数在其所有参数都是constexpr时，一定返回constexpr；
>
> * 函数体中必须有且仅有一条return语句。
>
> **Eaxmple:**
>
> * constexpr int get_size() { return 20; }
>
> * constexpr int foo = get_size();  //正确：foo是一个常量表达式

### 3.4 默认参数值的函数

> **默认参数值:**可以预先设置默认的参数值，调用时如给出实参，则采用实参值，否则采用预先设置的默认参数值。

**默认参数值的说明次序:**

```c++
int add(int x, int y = 5, int z = 6);//正确

int add(int x = 1, int y = 5, int z);//错误

int add(int x = 1, int y, int z = 6);//错误
```

> **申明和定义的要求：**
>
> 如果一个函数有原型声明，且原型声明在定义之前，则默认参数值应在函数原型声明中给出；如果只有函数的定义，或函数定义在前，则默认参数值可以函数定义中给出。

### 3.5 函数重载

> C++允许功能相近的函数在相同的作用域内以相同函数名声明，从而形成重载。方便使用，便于记忆。
>
> **ps：**
>
> - 重载函数的形参必须不同:*个数不同*或*类型不同*。
> - 编译程序将根据实参和形参的类型及个数的最佳匹配来选择调用哪一个函数。

```c++
\#include <iostream>
using namespace std;
int sumOfSquare(int a, int b) {
  return a * a + b * b;
}
double sumOfSquare(double a, double b) {
  return a * a + b * b;
}
int main() {
  int m, n;
  cout << "Enter two integer: ";
  cin >> m >> n;
  cout<<"Their sum of square: "<<sumOfSquare(m, n)<<endl;
  double x, y;
  cout << "Enter two real number: ";
  cin >> x >> y;
  cout<<"Their sum of square: "<<sumOfSquare(x, y)<<endl;
  return 0;
}
```

> 运行结果：
> Enter two integer: 3 5
> Their sum of square: 34
> Enter two real number: 2.3 5.8
> Their sum of square: 38.93



### 3.7 指针函数和函数指针

**指针函数**：避免将局部指针作为返回值。

**函数指针**

- 定义形式

存储类型 数据类型 (*函数指针名)();

- 含义

- - 函数指针指向的是程序代码存储区。

``` c++
int compute(int a, int b, int(*func)(int, int))

{ return func(a, b);}
compute(a, b, & max);
int max(int a, int b) // 求最大值

{ return ((a > b) ? a: b);}
```

### 3.8  对象指针

对象指针定义形式

类名 *对象指针名；

> Point a(5,10);
>
> Piont *ptr;
>
> ptr=&a;

通过指针访问对象成员

对象指针名->成员名

例：**ptr->getx()** 相当于 **(*ptr).getx();**

### 3.9 函数模板和类模板

语法形式：

template <模板参数表>

1. template<typename T>与template<class T>一般情况下这两个通用，但有一个特例，就是当 T 是一个类，而这个类又有子类(假设名为 innerClass) 时，应该用 template<typename>:
2. typename T::innerClass myInnerObject;这里的 typename 告诉编译器，T::innerClass 是一个类，程序要声明一个 T::innerClass 类的对象，而不是声明 T 的静态成员，而 typename 如果换成 class 则语法错误。

- 模板参数表的内容

- - 类型参数：class（或typename） 标识符
  - 常量参数：类型说明符 标识符
  - 模板参数：template <参数表> class标识符



```c++
//9_1.cpp
#include <iostream>
using namespace std;

template <class T>  //定义函数模板
void outputArray(const T *array, int count) {
    for (int i = 0; i < count; i++)
        cout << array[i] << " "; //如果数组元素是类的对象，需要该对象所属类重载了流插入运算符“<<”
    cout << endl;
}

int main() {     
    const int A_COUNT = 8, B_COUNT = 8, C_COUNT = 20;
    int a [A_COUNT] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    double b[B_COUNT] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
    char c[C_COUNT] = "Welcome!";

    cout << " a array contains:" << endl;
    outputArray(a, A_COUNT);    
    cout << " b array contains:" << endl;
    outputArray(b, B_COUNT);    
    cout << " c array contains:" << endl;
    outputArray(c, C_COUNT);    
    return 0;
}

```

运行结果如下：
a array contains:
1 2 3 4 5 6 7 8
b array contains:
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 
c array contains:
W e l c o m e!



- **自定义的类，需要重载模板中的运算符，才能作为类型实参**



```c++
#include <iostream>
#include <cstdlib>
using namespace std;
struct Student {
  int id;       //学号
  float gpa;    //平均分
}; 
template <class T>
class Store {//类模板：实现对任意类型数据进行存取
private:
    T item; // item用于存放任意类型的数据
    bool haveValue;  // haveValue标记item是否已被存入内容
public:
    Store();
    T &getElem();   //提取数据函数
    void putElem(const T &x);  //存入数据函数
};

template <class T>  
Store<T>::Store(): haveValue(false) { } 
template <class T>
T &Store<T>::getElem() {
    //如试图提取未初始化的数据，则终止程序
    if (!haveValue) {   
        cout << "No item present!" << endl;
        exit(1);    //使程序完全退出，返回到操作系统。
    }
    return item;        // 返回item中存放的数据 
}
template <class T>
void Store<T>::putElem(const T &x) {
    // 将haveValue 置为true，表示item中已存入数值   
    haveValue = true;   
    item = x;           // 将x值存入item
}

int main() {
    Store<int> s1, s2;  
    s1.putElem(3);  
    s2.putElem(-7);
    cout << s1.getElem() << "  " << s2.getElem() << endl;

    Student g = { 1000, 23 };
    Store<Student> s3;
    s3.putElem(g); 
    cout << "The student id is " << s3.getElem().id << endl;

    Store<double> d;
    cout << "Retrieving object D... ";
    cout << d.getElem() << endl;
   //d未初始化，执行函数D.getElement()时导致程序终止
    return 0;
}
```

### 3.10 函数适配器



## 4. 类与对象

### 1.4 面向对象的基本概念

> *类与对象*的关系好比*类型与实例*的关系

### 4.1 类定义的语法形式

> class 类名称
>
> {
>
> public:
>
> ​           公有成员（外部接口）
>
> private:
>
> ​           私有成员
>
> protected:
>
> ​           保护型成员
>
> };

> * **公有类型成员**
>
>   在关键字public后面声明，它们是类与外部的接口，任何外部函数都可以访问公有类型数据和函数。
>
> * **私有类型成员**
>
>   在关键字private后面声明，只允许本类中的函数访问，而类外部的任何函数都不能访问。
>
>   如果紧跟在类名称的后面声明私有成员，则关键字private可以省略。
>
> * **保护类型成员**
>
>   与private类似，其差别表现在继承与派生时对派生类的影响不同，详见第七章。

### 4.2 对象定义的语法

>  类名 对象名；
>
>  例：Clock myClock

### 4.3 类成员的访问权限

> * 类中成员互相访问
>
>   直接使用成员名访问
>
> * 类外访问
>
>   使用“对象名.成员名”方式访问 public 属性的成员

### 4.4 联合体

``` c++
#include <iostream>
using namespace std;
class ExamInfo {
private:
	string name;	//课程名称
	enum { GRADE, PASS, PERCENTAGE } mode;//计分方式
	union {
		char grade;	//等级制的成绩
		bool pass;	//只记是否通过课程的成绩
		int percent;	//百分制的成绩
	};
public:
	//三种构造函数，分别用等级、是否通过和百分初始化
	ExamInfo(string name, char grade)
		: name(name), mode(GRADE), grade(grade) { }
	ExamInfo(string name, bool pass)
		: name(name), mode(PASS), pass(pass) { }
	ExamInfo(string name, int percent)
		: name(name), mode(PERCENTAGE), percent(percent) { }
	void show();
}

void ExamInfo::show() {
	cout << name << ": ";
	switch (mode) {
	  case GRADE: cout << grade;  break;
	  case PASS: cout << (pass ? "PASS" : "FAIL"); break;
	  case PERCENTAGE: cout << percent; break;
	}
	cout << endl;
}

int main() {
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}

```

> 运行结果：
> English: B
> Calculus: PASS
> C++ Programming: 85

### 4.5 枚举类

> 语法：
>
> enum class 枚举类型名: 底层类型 {枚举值列表};

``` c++
#include<iostream>
using namespace std;
enum class Side{ Right, Left };
enum class Thing{ Wrong, Right };  //不冲突
int main()
{
    Side s = Side::Right;
    Thing w = Thing::Wrong;
    cout << (s == w) << endl;  //编译错误，无法直接比较不同枚举类
    return 0;
}
```

### 4.6 继承和派生

继承的基本概念和语法

**继承与派生概述**

- 继承与派生是同一过程从不同的角度看

- - 保持已有类的特性而构造新类的过程称为继承
  - 在已有类的基础上新增自己的特性而产生新类的过程称为派生。

- 被继承的已有类称为基类（或父类）

- 派生出的新类称为派生类（或子类）

- 直接参与派生出某类的基类称为直接基类

- 基类的基类甚至更高层的基类称为间接基类

**继承与派生的目的**

- 继承的目的：实现设计与代码的重用。
- 派生的目的：当新的问题出现，原有程序无法解决（或不能完全解决）时，需要对原有程序进行改造。

**单继承时派生类的定义**

- 语法

```c++
class 派生类名：继承方式 基类名

{

成员声明；

}
```



- 例

```c++
class Derived: public Base

{

public:

Derived ();

~Derived ();

};
```

**多继承时派生类的定义**

- 语法

```c++
class 派生类名：继承方式1 基类名1，继承方式2 基类名2，...

{

成员声明；

}
```

注意：每一个“继承方式”，只用于限制对紧随其后之基类的继承。

- 例

```c++
class Derived: public Base1, private Base2
{
public:
Derived ();
~Derived ();
};


```

#### 继承的构造函数

```c++
#include<bits/stdc++.h>
using namespace std;
class base {
public:
	int baseData;
	base(int b):baseData(b){}
};
class derived : public base {
public:
	derived(int b,int d):base(b),derivedData(d){}//继承类的构造函数
	int derivedData;
};
void fun(base& a) {
	cout << a.baseData << endl;
	
}
int main() {
	derived a(1,9);//子类的类型包含基类
	fun(a);

}
```



### 4.7 虚基类

- 虚基类声明

- - 以virtual说明基类继承方式
  - 例：class B1:virtual public B

### 4.8 抽象类

- 带有纯虚函数的类称为抽象类:

  class 类名 { virtual 类型 函数名(参数表)=0; //其他成员…… }



- 抽象类为抽象和设计的目的而声明
- 将有关的数据和行为组织在一个继承层次结构中，保证派生类具有要求的行为。
- 对于暂时无法实现的函数，可以声明为纯虚函数，留给派生类去实现。



**抽象类只能作为基类来使用。不能定义抽象类的对象。**

举例：

```c++
//8_6.cpp
#include <iostream>
using namespace std;

class Base1 { 
public:
    virtual void display() const = 0;   //纯虚函数
};

class Base2: public Base1 { 
public:
    virtual void display() const; //覆盖基类的虚函数
};
void Base2::display() const {
    cout << "Base2::display()" << endl;
}

class Derived: public Base2 { 
public:
     virtual void display() const; //覆盖基类的虚函数
};
void Derived::display() const {
    cout << "Derived::display()" << endl;
} 
void fun(Base1 *ptr) { 
    ptr->display(); 
}
int main() {    
    Base2 base2;    
    Derived derived;    
    fun(&base2);    
    fun(&derived);  
    return 0;
}
```

### 4.9 override

- 多态行为的基础：基类声明虚函数，继承类声明一个函数覆盖该虚函数
- 覆盖要求： 函数签名（signatture）完全一致
- 函数签名包括：函数名 参数列表 const



-　C++11 引入显式函数覆盖，在编译期而非运行期捕获此类错误。 - 在虚函数显式重载中运用，编译器会检查基类是否存在一虚拟函数，与派生类中带有声明override的虚拟函数，有相同的函数签名（signature）；若不存在，则会回报错误。

### 4.10 final

- C++11提供的final，用来避免类被继承，或是基类的函数被改写 例： struct Base1 final { };

  struct Derived1 : Base1 { }; // 编译错误：Base1为final，不允许被继承

  struct Base2 { virtual void f() final; };

  struct Derived2 : Base2 { void f(); // 编译错误：Base2::f 为final，不允许被覆盖 };

## 5. 类与函数

### 5.1 类的成员函数

> * 在类中说明函数原型；
>
> * 可以在类外给出函数体实现，并在函数名前使用类名加以限定；
>
> * 也可以直接在类中给出函数体，形成内联成员函数；
>
> * 允许声明重载函数和带默认参数值的函数。

### 5.2 内联成员函数

> * 为了提高运行时的效率，对于较简单的函数可以声明为内联形式。
>
> * 内联函数体中不要有复杂结构（如循环语句和switch语句）。
>
> * 在类中声明内联成员函数的方式：
>
>   将函数体放在类的声明中。
>
>   使用inline关键字。

### 5.3 类和对象的程序举例

```c++
//类的定义

#i5nclude<iostream>
using namespace std;
class Clock{
public:     
   void setTime(int newH = 0, int newM = 0, int newS = 0);
   void showTime();
private: 
   int hour, minute, second;
};

//成员函数的实现
void Clock::setTime(int newH, int newM, int newS) {
  hour = newH;
  minute = newM;
  second = newS;
}

void Clock::showTime() {
  cout << hour << ":" << minute << ":" << second;
}

//对象的使用

int main() {
   Clock myClock;
   myClock.setTime(8, 30, 30);
   myClock.showTime();
   return 0;
}
```

### 5.4 构造函数

> * 函数名与类名相同
>
> * 无返回值类型，无return
>
> * 形式参数可有可无
>
> * 允许是内联函数
>
> * 允许重载
>
> * 允许带默认值
>
>   *构造函数在定义对象是自动被调用*

* *以下两种情况不能同时出现*

``` c++
Clock();
Clock(int newH=0, int newM=0, int newS=0);
```

* 若未定义构造函数，编译器将自动生成。此时如果类内定义了初始值则使用，否则初始值不定。

* 定义构造函数，编译器不会自动生成。若要强行生成可以使用：

  ``` c++
  Clock() = default;//生成默认的构造函数
  ```


``` c++
class Clock {

public:
     Clock(int newH,int newM,int newS);//构造函数 
     Clock(); //默认构造函数
     void setTime(int newH, int newM, int newS);
     void showTime();
    
private:
     int hour, minute, second;
};


//构造函数的实现：
Clock::Clock(): hour(0),minute(0),second(0) { }//默认构造函数
Clock::Clock(int newH,int newM,int newS): hour(newH),minute(newM),  second(newS) {
     }

//其它函数实现同例4_1

int main() {

  Clock c(0,0,0); //自动调用构造函数

  c.showTime();

     return 0;

}
```

### 5.5 委托构造函数

``` c++
Clock::Clock(): hour(0),minute(0),second(0) { }//默认构造函数
Clock::Clock(int newH,int newM,int newS): hour(newH),minute(newM),  second(newS) {
     }

Clock::Clock(int newH,int newM,int newS): hour(newH),minute(newM),  second(newS) {
     }
Clock::Clock():Clock(0,0,0){}
```

### 5.6 复制构造函数

* 作用是用一个已存在的对象去初始化同类型的新对象。

``` c++
class Point {   //Point 类的定义

public:

    Point(int xx=0, int yy=0) { x = xx; y = yy; }    //构造函数，内联

    Point(const Point& p) =delete;  //指示编译器不生成默认复制构造函数

private:

    int x, y; //私有数据

};
Point::Point(const Point& p){}
```

* 定义时
* 作参数时
* return时



### 5.7 析构函数

**没有参数**

**没有返回类型**

``` c++
#include <iostream>
using namespace std;
class Point {     
public:
  Point(int xx,int yy);
  ~Point();
  //...其他函数原型
private:
  int x, y;
};
```

### 5.8 类组合程序举例

**类的组合，线段（Line）类**

``` c++
//4_4.cpp
#include <iostream>
#include <cmath>
using namespace std;
class Point { //Point类定义
public:
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}

	Point(Point& p);
	int getX() { return x; }
	int getY() { return y; }

private:
	int x, y;
};

Point::Point(Point& p) { //复制构造函数的实现
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}
//类的组合
class Line { //Line类的定义
public: //外部接口
	Line(Point xp1, Point xp2);
	Line(Line& l);
	double getLen() { return len; }

private: //私有数据成员
	Point p1, p2; //Point类的对象p1,p2
	double len;
};

//组合类的构造函数
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}
Line::Line(Line& l) : p1(l.p1), p2(l.p2) {//组合类的复制构造函数
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}
//主函数

int main() {
	Point myp1(1, 1), myp2(4, 5); //建立Point类的对象
	Line line(myp1, myp2); //建立Line类的对象
	Line line2(line); //利用复制构造函数建立一个新对象
	cout << "The length of the line is: ";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getLen() << endl;
	return 0;
}
```

### 5.9 前向引用声明

> 如果需要在某个类的声明之前，引用该类，则应进行前向引用声明。

``` c++
class B;  //前向引用声明
class A {
public:
  void f(B b);
}; 	

class B {
public:
  void g(A a);
};
```

> 在提供一个完整的类声明之前，不能声明该类的对象，也不能在内联成员函数中使用该类的对象。
>
> 当使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。\
>
> -
>
> **只能使用此标识符**



``` c++
class Fred; //前向引用声明
class Barney {
   Fred x; //错误：类Fred的声明尚不完善
};

class Fred {
   Barney y;
};
```

### 5.10 友元函数

> 在类中申明一个函数（以friend作关键字）授予其权限能够访问private的成员数据

``` c++
#include <iostream>

#include <cmath>

using namespace std;

class Point { //Point类声明

public: //外部接口

Point(int x=0, int y=0) : x(x), y(y) { }

int getX() { return x; }

int getY() { return y; }

friend float dist(Point &a, Point &b);

private: //私有数据成员

int x, y;

};



float dist( Point& a, Point& b) {

double x = a.x - b.x;

double y = a.y - b.y;

return static_cast<float>(sqrt(x * x + y * y));

}

int main() {

Point p1(1, 1), p2(4, 5);

cout <<"The distance is: ";

cout << dist(p1, p2) << endl;

return 0;

}
```

### 5.11 友元类

给类授权使其能访问本类的私有成员（注意其单向性）

``` c++
class A {
friend class B;
public:
void display() {
cout << x << endl;
}

private:
int x;
};

class B {
public:
void set(int i);
void display();
private:
A a;
};

void B::set(int i) {
a.x=i;
}

void B::display() {
a.display();
};
```



### 5.12 移动构造函数

函数返回含有指针成员的对象（版本2）

- 使用移动构造函数

将要返回的局部对象转移到主调函数，省去了构造和删除临时对象的过程。

注意：

* &&是右值引用
* 函数返回的临时变量是右值

```c++
#include<iostream>

using namespace std;

class IntNum {

public:

IntNum(int x = 0) : xptr(new int(x)){ //构造函数

cout << "Calling constructor..." << endl;

}

IntNum(const IntNum & n) : xptr(new int(*n.xptr)){//复制构造函数

cout << "Calling copy constructor..." << endl;

注：

•&&是右值引用

•函数返回的临时变量是右值



}

 IntNum(IntNum && n): xptr( n.xptr){ //移动构造函数

 n.xptr = nullptr;

cout << "Calling move constructor..." << endl;

}

~IntNum(){ //析构函数

delete xptr;

cout << "Destructing..." << endl;

}

private:

int *xptr;

};



//返回值为IntNum类对象

IntNum getNum() {

IntNum a;

return a;

}

int main() {

cout << getNum().getInt() << endl; return 0;

}
```

运行结果：

Calling constructor...

Calling move constructor...

Destructing...

0



Destructing...

### 5.13 虚函数

- 虚函数的声明

  virtual 函数类型 函数名（形参表）;

- 虚函数声明只能出现在类定义中的函数原型声明中，而不能在成员函数实现的时候。

- 在派生类中可以对基类中的成员函数进行覆盖。

- 虚函数一般不声明为内联函数，因为对虚函数的调用需要动态绑定，而对内联函数的处理是静态的。

- 一般习惯于在派生类的函数中也使用virtual关键字，以增加程序的可读性。

**未使用虚函数：**

```c++
#include <iostream>
using namespace std;
class Base1 { //基类Base1定义
public:
    void display() const {
        cout << "Base1::display()" << endl;
    }
};
class Base2: public Base1 { //公有派生类Base2定义
public:
    void display() const {
        cout << "Base2::display()" << endl;
    }
};
class Derived: public Base2 { //公有派生类Derived定义
public:
    void display() const {
        cout << "Derived::display()" << endl;
    }
};

void fun(Base1 *ptr) {  //参数为指向基类对象的指针
    ptr->display();     //"对象指针->成员名"
}
int main() {    //主函数
    Base1 base1;    //声明Base1类对象
    Base2 base2;    //声明Base2类对象
    Derived derived;    //声明Derived类对象

    fun(&base1);    //用Base1对象的指针调用fun函数
    fun(&base2);    //用Base2对象的指针调用fun函数
    fun(&derived);     //用Derived对象的指针调用fun函数

    return 0;
}
```

**使用虚函数：**

```c++
#include <iostream>
using namespace std;

class Base1 {
public:
    virtual void display() const;  //虚函数
};
void Base1::display() const {
    cout << "Base1::display()" << endl;
}

class Base2::public Base1 { 
public:
     virtual void display() const;
};
void Base2::display() const {
    cout << "Base2::display()" << endl;
}
class Derived: public Base2 {
public:
     virtual void display() const; 
};
void Derived::display() const {
    cout << "Derived::display()" << endl;
}

void fun(Base1 *ptr) { 
    ptr->display(); 
}

int main() {    
    Base1 base1;
    Base2 base2;
    Derived derived;    
    fun(&base1);
    fun(&base2);
    fun(&derived);
    return 0;
}
```

### 5.14 纯虚函数

- 纯虚函数是一个在基类中声明的虚函数，它在该基类中没有定义具体的操作内容，要求各派生类根据实际需要定义自己的版本，纯虚函数的声明格式为：

  virtual 函数类型 函数名(参数表) = 0;

- 带有纯虚函数的类称为抽象类



# web前端

## HTML

### HTML框架

<img src="D:\typora\pic\AIK\image-20210606131424291.png" alt="image-20210606131424291" style="zoom: 50%;" />

### 标题

<img src="D:\typora\pic\AIK\image-20210606133035910.png" alt="image-20210606133035910" style="zoom:50%;" />

### 段落（p）

<img src="D:\typora\pic\AIK\image-20210606133107253.png" alt="image-20210606133107253" style="zoom:50%;" />

### 换行（br）

<img src="D:\typora\pic\AIK\image-20210606133146654.png" alt="image-20210606133146654" style="zoom:50%;" />

### 空格（nbsp）

<img src="D:\typora\pic\AIK\image-20210606133205364.png" alt="image-20210606133205364" style="zoom:50%;" />

### 预留格式（pre）

<img src="D:\typora\pic\AIK\image-20210606133234881.png" alt="image-20210606133234881" style="zoom:50%;" />

### 行内组合（span）

<img src="D:\typora\pic\AIK\image-20210606133251479.png" alt="image-20210606133251479" style="zoom:50%;" />

### 水平线（hr）

<img src="D:\typora\pic\AIK\image-20210606133309381.png" alt="image-20210606133309381" style="zoom:50%;" />

### 注释

<img src="D:\typora\pic\AIK\image-20210606133322982.png" alt="image-20210606133322982" style="zoom:50%;" />

### 超链接（a)

<img src="D:\typora\pic\AIK\image-20210606151452415.png" alt="image-20210606151452415" style="zoom:50%;" />

### 图像（img）

<img src="D:\typora\pic\AIK\image-20210606151949511.png" alt="image-20210606151949511" style="zoom:50%;" />

### 无序列表（ul，li）



<img src="D:\typora\pic\AIK\image-20210606155623836.png" alt="image-20210606155623836" style="zoom:50%;" />

### 有序列表（ol，li）

<img src="D:\typora\pic\AIK\image-20210606155648987.png" alt="image-20210606155648987" style="zoom:50%;" />

### 表格（table，tr，td，th）

<img src="D:\typora\pic\AIK\image-20210606155710079.png" alt="image-20210606155710079" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606155734654.png" alt="image-20210606155734654" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606155744453.png" alt="image-20210606155744453" style="zoom:50%;" />

### 文本框，密码框（input）



<img src="D:\typora\pic\AIK\image-20210606163006057.png" alt="image-20210606163006057" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163043782.png" alt="image-20210606163043782" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163105711.png" alt="image-20210606163105711" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163125794.png" alt="image-20210606163125794" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163144190.png" alt="image-20210606163144190" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163205672.png" alt="image-20210606163205672" style="zoom:50%;" />

<img src="D:\typora\pic\AIK\image-20210606163226960.png" alt="image-20210606163226960" style="zoom:50%;" />

## CSS

![image-20210606203310159](D:\typora\pic\AIK\image-20210606203310159.png)

![image-20210606203331328](D:\typora\pic\AIK\image-20210606203331328.png)

![image-20210606203350024](D:\typora\pic\AIK\image-20210606203350024.png)

![image-20210606203402672](D:\typora\pic\AIK\image-20210606203402672.png)

![image-20210606204104010](D:\typora\pic\AIK\image-20210606204104010.png)

![image-20210606204322566](D:\typora\pic\AIK\image-20210606204322566.png)

## 实例

### 8-1 8-2

![image-20210609191221057](D:\typora\pic\AIK\image-20210609191221057.png)

### 8-3

![image-20210611125935610](D:\typora\pic\AIK\image-20210611125935610.png)

# PS

### 自由变换

CTRL + T

### shift



等比变换

加选区

### alt

减选区

### 复制图层

CTRL + J

alt 拖动

### 抠图

矩形选择工具->拷贝到图层通道

### 快捷填充前景颜色

alt + delete

### 取消选区

ctrl + D

### 空格

使用套索时按空格拖动图

### 半径的大小

alt 右键 左右划

### 放大图像

alt 鼠标滚轮



jpg有背景

png可以透明无背景



蒙版，盖住智能对象

剪切蒙版

![P4](D:\typora\pic\AIK\image-20210501195525323.png)

# 算法

## 1. 递归

### 1.1 N苹果放N盘子

``` c++
#include<iostream>
using namespace std;

int f2(int m, int n)
{
	if (m == 0 || n == 1)
	{
		return 1;
	}
	else if (m < n)
	{
		return f2(m, m);
	}
	else if (m >= n)
	{
		return f2(m, n - 1) + f2(m - n, n);
	}
}

int f(int i, int k) {
	if (k > i) return f(i, i);
	if (k == 1) return 1;
	if (i == 0) return 1;
	return f(i, k - 1) + f(i - k, k);
}

int main() {
	int i, k;
	cin >> i >> k;
	cout << f(i, k)<<endl;
	cout << f2(i, k);

}
```

### 1.2 波兰表达式

``` c++
#include<iostream>
using namespace std;

double bolan() {
	int ans;
	char s[10];
	cin >> s;
	if(s[0] >= '0'&& s[0] <= '9') return atof(s); 
	else {
		if (s[0] == '*') return bolan() * bolan();
		if (s[0] == '+') return bolan() + bolan();
		if (s[0] == '-') return bolan() - bolan();
		if (s[0] == '/') return bolan() / bolan();
	}
	
}

int main() {
	char a[100];
	cout << bolan();
}
```

### 1.3 记忆递归（路径和）

``` c++
#include<iostream>
#include<algorithm>
using namespace std;
int a[100][100] = {0};
int dp[100][100] = {0};
int n;
int f(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == n) {
		return a[i][j];}
	else {
		return dp[i][j] = max(f(i + 1, j), f(i + 1, j + 1)) + a[i][j];}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			dp[i][j] = -1;
		}
	} cout <<f(1,1)<<endl;
}
```

### 1.4 汉洛塔

``` c++
#include<stdio.h>
#include<iostream>
using namespace std;
void hlt(int n,char k1 ,char k2,char k3){
	if(n == 1)
	{
		cout<<k1<<"->"<<k3<<endl;
	}
	else
	{
		hlt(n-1,k1,k3,k2);
		cout<<k1<<"->"<<k3<<endl;
		hlt(n-1,k2,k1,k3);
	}
}
```

### 1.5 2次幂指数分解

```c++
#include <iostream>
using namespace std;

void fun(short i)
{
	int j = 0;
	if (i == 0)
	{
		printf("0");  //0位是1时，配合调用前的2()正好组成2(0)，即1
		return;
	}
	if (i == 1)
	{

		printf("2(0)"); //1位是0，即2(2(0)),也就是2，只有2()，括号内的数拆分时有1才会用到
		return;
	}
	if (i == 2)
	{
		printf("2");  //2（2）
		return;
	}

	for (; i != 0; j++)
	{
		if (i & 1)   //位运算
		{
			if (j == 1)  //2位为1直接打印2，不再递归
				printf("2");
			else
			{
				printf("2(");
				fun(j);
				printf(")");
			}
			i = i >> 1;
			if (i != 0)
				printf("+"); //看情况打印“+”号
			continue;

		}
		i = i >> 1;
	}
}


int main(int argc, char* argv[])
{
	short i;
	cin >> i;
	fun(i);
	return 0;
}
```



## 2. 排序算法

### 2.1 堆排序

底层实现：完全二叉树

[堆排序(heapsort)bilibili链接](https://www.bilibili.com/video/BV1Eb41147dK?from=search&seid=5281747329959496452)

## 3. 二分法

``` c++
#include<iostream>
using namespace std;
const double N = 1e-7;
int main() {
	double L = 0, R = 100, mid, value;
	while (L < R) {
		mid = L + (R - L) / 2;
		value = mid * mid * mid - 5 * mid * mid + 10 * mid - 80;
		if (value > 0) {
			R = (R + mid) / 2;
		}
		else {
			L = (L + mid) / 2;
		}
		
		if (abs(value) < N) break;
	}
	printf("%.8f",mid);
}
```

## 4. 环算法（判断环）

[leetcode原题](https://leetcode.com/problems/friend-circles/)

``` c++
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int a[1000];
        int cnt = 0,p,q;
        for (int i = 0; i < M.size();i++){
            a[i] = i;
        }
        for(int i = 0; i < M.size();i++){
            for(int j = 0; j < M.size();j++){
                
                if (i >= j) continue;
                if(M[i][j]==1){
                    p = i;
                    q = j;
                    while(a[p]!=p){
                        p = a[p];
                    }
                     while(a[q]!=q){
                        q = a[q];
                    }
                    a[q] = p;
                }
            }
        }
        for (int i = 0; i < M.size();i++){
            if(a[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};
```

## 5. 数学

### 5.1 异或

1. k 个相同的数的异或和，当 k为奇数时，结果是这个数本身，否则结果是 0。
2. 任何数与0的异或值是它本身。
3. 任何数与1的异或值是它的反。

``` c++
a^b //异或的符号
```

### 5.2 负进制

``` c++
#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<int> n;
	int a, b;
	cin >> a>>b;
	cout << a << "=";
	while (a!=0) {
		if (a%b < 0) {
			n.push(a % b - b);
			a = a / b + 1;
		}//将余数变成正数
		else {
			n.push(a % b);
			a = a / b;
		}
	}
	while (!n.empty()) {
		if (n.top() < 10) {
			cout << n.top();
		}
		else {
			printf("%c", n.top() - 10 + 65);
		}
		n.pop();
	}
	cout << "(base" << b << ")";
	return 0;
}
```

### 5.3 组合数

*递推公式：*

![img](D:%5C%E7%A0%81%E5%AD%A6%5CAIK.assets%5Cclip_image002-1611456715294-1611748650900.png)

*杨辉三角打表：*

``` c++
#include<bits/stdc++.h>
using namespace std;
int c[2001][2001] = { 0 };
void persovel() {
    for (int i = 0; i <= 2000; i++) c[i][0] = 1;
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
        }
    }
}
int main() {
    persovel();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << c[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}
```





### 5.4 高精度

``` c++
//题目描述
//楼梯有 NN 阶，上楼可以一步上一阶，也可以一步上二阶。
//
//编一个程序，计算共有多少种不同的走法。
//
//输入格式
//一个数字，楼梯数。
//
//输出格式
//输出走的方式总数。
#include<stdio.h>
#include<iostream>
using namespace std;
int pa[5001][5001] = { 0 };
int main() {
	pa[0][1] = 1;
	pa[1][1] = 1;
	int n;
	cin >> n;
	if (n == 0) {
		cout << '0';
		return 0;
	}
	int len = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= len; j++) 
			pa[i][j] = pa[i - 1][j] + pa[i - 2][j];
		for (int j = 1; j <= len; j++) {
			if (pa[i][j] >= 10) {
				pa[i][j + 1] += pa[i][j] / 10;
				pa[i][j] %= 10;
				if (pa[i][len + 1]) {
					len++;
				}
			}
		}
	}
	for (int i = len; i > 0; i--) {
		cout << pa[n][i];
	}

	return 0;
}
```

### 5.5 前缀和

|            | 定义式                                                       | 递推式                                                       |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 一维前缀和 | ![b[i]=\sum_{j=0}^{i}a[j]](https://private.codecogs.com/gif.latex?b%5Bi%5D%3D%5Csum_%7Bj%3D0%7D%5E%7Bi%7Da%5Bj%5D) | ![b[i]=b[i-1]+a[i]](https://private.codecogs.com/gif.latex?b%5Bi%5D%3Db%5Bi-1%5D&plus;a%5Bi%5D) |
| 二维前缀和 | ![b[x][y]=\sum_{i=0}^{x}\sum_{j=0}^{y}a[i][j]](https://private.codecogs.com/gif.latex?b%5Bx%5D%5By%5D%3D%5Csum_%7Bi%3D0%7D%5E%7Bx%7D%5Csum_%7Bj%3D0%7D%5E%7By%7Da%5Bi%5D%5Bj%5D) | ![b[x][y]=b[x-1][y]+b[x][y-1]-b[x-1][y-1]+a[x][y]](https://private.codecogs.com/gif.latex?b%5Bx%5D%5By%5D%3Db%5Bx-1%5D%5By%5D&plus;b%5Bx%5D%5By-1%5D-b%5Bx-1%5D%5By-1%5D&plus;a%5Bx%5D%5By%5D) |

![img](https://img2018.cnblogs.com/blog/1674973/201907/1674973-20190710110625195-1169353097.png)

*此图能解释二维前缀和的递推公式*

``` c++
//二维前缀和数组的构建以及元素查询
#include<iostream>
#include<cstring>
using namespace std;
int dp[2000][2000],map[2000][2000];
int main()
{
    int m,n,k;//所给的矩阵是n*m的,有k组查询 
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >>map[i][j];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)//预处理一波 
        for(int j=1;j<=m;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+map[i][j];
    for(int i=1;i<=k;i++)//接受查询 
    {
        int x1,x2,y1,y2;
        cin >>x1>>y1>>x2>>y2;
        cout <<(dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1])<<endl;//O（1）查询 
    }
    return 0;
}
```

### 5.6 公因数公倍数

``` c++
int gcd(int a, int b){
    return b? gcd(b, a%b):a;
}
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
```

### 5.7 约瑟夫环

```c++
#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, c, pos=0;
	cin >> m >> c;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		a[i] = i;
	}
	while (a.size() > 1) {
		pos = (pos + c - 1)%a.size();
		a.erase(a.begin() + pos);
	}
	cout << a[0] + 1<< endl;
}
```



## 6. 图论

### 6.1 并查集

``` c++
#include<bits/stdc++.h>
using namespace std;
int pep[5001];
int findRoot(int m) {
	return pep[m] == m ? m : findRoot(pep[m]);
}
int findRoot2(int m){//于上一个findRoot相比，在搜索后顺便修改了pep[m]，以便下次搜索
    if(pep[m] != m) pep[m] = findRoot2(pep[m]);
    return pep[m];
}
int union_set(int m1, int m2) {
	int x = findRoot(m1);
	int y = findRoot(m2);
	if (x != y) {
		pep[y] = pep[x];
	}
}

int main() {
	int n, m, p, m1, m2;
	cin >> n >> m >> p;
	for (int i = 0; i <= n; i++) {
		pep[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> m1 >> m2;
		union_set(m1, m2);
	}
	while (p--) {
		int a1, a2;
		cin >> m1 >> m2;
		if (findRoot(m1) == findRoot(m2)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
```



## 7. BFS

``` c++
元素a;
入队q;
while(!q.empty()){
	//........
    遍历的任务
    //........
    for(子元素){
        if(未访问){
            标记；
            入队q；
        }
    }
}
```

## 8. DFS

``` c++
dfs(int i){
    if(已标记){return；}
    标记i；
	//.......
    任务
    //.......
    for(子元素){
        dfs();//深入DFS
    }
}

dfs(i);//调用函数

```

```c++
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > G;
vector<int> visited;
int n, m;
void dfs(int x, int count) {
	
	if (visited[x] == 1) {
		if (x == 0 && count == n) {
			cout << "Yes" << endl;
			exit(0);
		}
		return;
	}
	visited[x] = 1;
	for (int i = 0; i < G[x].size(); i++) {
		int v = G[x][i];
		count++;	
		dfs(v, count);
		count--;
	}
	visited[x] = 0;
}
int main() {
	cin >> n >> m;
	G = vector<vector<int> >(n + 1, vector<int>());
	visited = vector<int>(n + 1, 0);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	dfs(0, 0);
	cout << "No" << endl;
	return 0;
}
```



## 9. dp

最大区间和

```c++
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (ans < 0){
			ans = 0;
		}
		ans += a[i];
		max = ans > max ? ans : max;
	}
	cout << max;
	

}
```

### 二进制

统计二进制中1的个数



```c++
#include<bits/stdc++.h>
using namespace std;


int bitcount(int x) {
	return x == 0 ? 0 : bitcount(x / 2) + (x & 1);//x&1加括号 
}

int main() {
	int n, b, d;
	vector<int> a;	
	int cnt = 0;
	cin >> n >> b >> d;
	for (int i = 0; i <= (1 << b) - 1; i++) {
		int flag = 1;
		for (int j = 0; j < a.size(); j++) {
			if ((bitcount(a[j] ^ i) < d)) {
				flag = 0;
				break;
			}
		}
		
		if (flag == 1) {
			a.push_back(i);
			
			
			cnt++;
			if (cnt % 10 == 0) {
				cout << i;
				cout << endl;
			}
			else {
				cout << i << " ";
			}
		}
		if (cnt == n) {
			break;
		}
	}
	
}
```



## 

连通 岛屿 最短

```c++
#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define ReFor(i,l,r) for(int i=(l);i>=(r);i--)
#define INF 0x7fffffff
#define lowbit(x) (x)&-(x)
#define ll long long
#define N 110
using namespace std;
char a[N][N];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool u[N][N], flag;
int n, sx, sy, ex, ey, ans, cnts, cnte;
struct nod {
	int x, y;
}s[N * N], e[N * N];
void dfs(int x, int y) {
	if (flag) return;
	s[++cnts] = { x,y };
	u[x][y] = 1;
	if ((x == ex) && (y == ey)) {
		flag = 1;
		return;
	}
	For(i, 0, 3) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && a[dx][dy] == '0' && !u[dx][dy])
			dfs(dx, dy);
	}
}
void dfs2(int x, int y) {
	e[++cnte] = { x,y };
	u[x][y] = 1;
	For(i, 0, 3) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && a[dx][dy] == '0' && !u[dx][dy])
			dfs2(dx, dy);
	}
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &ex, &ey);
		For(i, 1, n)
			scanf("%s", a[i] + 1);
		memset(u, false, sizeof(u));
		flag = false;
		cnts = 0;
		dfs(sx, sy);//求起点的连通块 
		if (flag) {
			printf("0\n");
			continue;
		}
		cnte = 0;
		dfs2(ex, ey);//求终点的连通块 
		ans = INF;
		For(i, 1, cnts)
			For(j, 1, cnte) {
			int tmp = (s[i].x - e[j].x) * (s[i].x - e[j].x) + (s[i].y - e[j].y) * (s[i].y - e[j].y);
			//			cout<<"s[i]="<<s[i].x<<" "<<s[i].y<<endl;
			//			cout<<"e[j]="<<e[j].x<<" "<<e[j].y<<endl<<endl;
			ans = min(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
```

求A^{B^{C}} A^B^C

```c++
#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int qpow(int a,int b,int p){

    int res=1;

    for(;b;b>>=1){

        if(b&1){

            res=1ll*res*a%p;

        }

        a=1ll*a*a%p;

    }

    return res;

}

int get(int a,int b,int c,int p){

    if(a%p==0){

        return 0;

    }

    return qpow(a,qpow(b,c,p-1),p);

}

int main(){

    int a,b,c;cin>>a>>b>>c;

    int x=get(a,b,c,2);
	
    int y=get(a,b,c,5);

    int res=(x*5+y*6)%10;

    cout<<res<<endl;

}

```

A * B * C < K 的个数

```c++
#include<bits/stdc++.h>

using namespace std;

int main()

{

    int k,cnt=0;

    cin>>k;

    for(int i=1;i<=k;i++){

        for(int j=1;j*i<=k;j++){

            cnt+=k/(i*j);

        }

    }

    cout<<cnt;

    return 0; 

 } 
```

双dfs

```c++
#include<iostream>

#include<vector>

using namespace std;

typedef pair<int, int> node;

int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

vector<vector<int> > G;

int cnt = 0;

bool judge(node d) {
	if (d.first < 1 || d.first > 5 || d.second < 1 || d.second > 5 ) {
		return false;
	}
	if (G[d.first][d.second] == 0) {
		return false;
	}

	return true;

}

void prt() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(node b, node m,  int tot) {
	//cout << b.first << " " << b.second << " " << m.first << " " << m.second << " " << tot << endl;
	//prt();
	if (tot == -1 && b == m) {
		cnt++;
		return;
	}
	if (tot == -1 || b == m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
 			node b2(b.first + dir[i][0], b.second + dir[i][1]);
			node m2(m.first + dir[j][0], m.second + dir[j][1]);
			if (!judge(b2)) {
				break;
			}
			if (!judge(m2)) {
				continue;
			}
			
	
				G[b2.first][b2.second] = 0;
				G[m2.first][m2.second] = 0;
				dfs(b2, m2, tot - 2);
				G[b2.first][b2.second] = 1;
				G[m2.first][m2.second] = 1;
			
			
		}
	}
}

int main() {
	int n;
	cin >> n;
	G = vector<vector<int> >(5+1,vector<int>(5 + 1,1));
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		G[x][y] = 0;
	}
	node b(1, 1);
	node m(5, 5);
	G[1][1] = 0;
	G[5][5] = 0;
	dfs(b,m, 25 - n - 2);

	cout << cnt << endl;
}
```

dijkstra

```c++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1 << 30;
vector<vector<int> > G;//临界矩阵
vector<int> djk;
vector<int> vis;
vector<int> P;
int n;

void path(int e) {
	int k = P[e];
	cout << e;
	while (k != 0) {
		cout <<"->"<< k;
		k = P[k];
	}
	cout << " ";
}

void in() {
	int m;
	cin >> n >> m;
	G = vector<vector<int> >(n+1,vector<int>(n+1,INF));
	djk = vector<int>(n + 1,INF);
	vis = vector<int>(n + 1, 0);
	P = vector<int>(n + 1, 0);
	int x, y, dis;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> dis;
		G[x][y] = dis;
		
	}
	for (int i = 1; i <= n; i++) {
		G[i][i] = 0;
	}
	
}

int main() {
	
	in();
	
	
	djk[1] = 0;
	vis[1] = 1;
	int now = 1;
	for (int k = 1; k <= n; k++) {
		int min = INF;
		for (int i = 1; i <= n; i++) {
			if (G[now][i] == INF || vis[i] == 1) continue;
			
			if (djk[i] > djk[now] + G[now][i]) {
				djk[i] = djk[now] + G[now][i];
				P[i] = now;//to i pass now
			}
		}

		int flg = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0 && djk[i] < min) {
				min = djk[i];
				flg = i;
			}
		}
		if (min == INF) break;
		now = flg;
		vis[flg] = 1;
			
	}
	for (int i = 1; i <= n; i++) {
		path(i);
	
		cout << djk[i] << endl;
	}

	
}
```

SPFA

```c++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1 << 30;
vector<vector<int> > G;//临界矩阵
vector<int> d;
vector<int> inq;
vector<int> P;
int n;

void in() {
	int m;
	cin >> n >> m;
	G = vector<vector<int> >(n + 1, vector<int>(n + 1, INF));
	inq = vector<int>(n + 1, 0);
	d = vector<int>(n + 1, INF);
	P = vector<int>(n + 1, 0);
	int x, y, dis;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> dis;
		G[x][y] = dis;

	}
	for (int i = 1; i <= n; i++) {
		G[i][i] = 0;
		
	}

}

void path(int e) {
	int k = P[e];
	cout << e;
	while (k != 0) {
		cout << "->" << k;
		k = P[k];
	}
	cout << " ";
}
int main() {
	in();

	queue<int> q;
	int src = 1;
	q.push(src);
	d[src] = 0;
	inq[src] = 1;
	while (!q.empty()) {
		int now = q.front();

		q.pop();
		inq[now] = 0;

		for (int i = 1; i <= n; i++) {

			if (G[now][i] != INF && d[i] > d[now] + G[now][i]) {

				d[i] = d[now] + G[now][i];
				P[i] = now;
				if (inq[i] == 0) {
					q.push(i);
					inq[i] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		path(i);

		cout << d[i] << endl;
	}
}
```

Floyd

```c++
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1 << 29;
vector<vector<int> > G;//临界矩阵
vector<vector<int> > P;
/*
矩阵P记录顶点间最小路径中的中转点
例如P[0][3]= 1 说明，0 到 3的最短路径轨迹为：0 -> 1 -> 3。
*/
int n;

void path(int s, int e) {
	int k = P[s][e];
	cout << s<<"->";
	while (k != e) {
		cout << k << "->";
		k = P[k][e];
	}
	cout << e;
}

void in() {
	int m;
	cin >> n >> m;
	G = vector<vector<int> >(n + 1, vector<int>(n + 1, INF));
	P = vector<vector<int> >(n + 1, vector<int>(n + 1, INF));
	int x, y, dis;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> dis;
		G[x][y] = dis;

	}
	for (int i = 1; i <= n; i++) {
		G[i][i] = 0;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			P[i][j] = j;
		}
	}
}


int main() {
	in();

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << G[1][i]<<" ";
		path(1, i);
		cout << endl;
		

	}
}
```

四位数组 dp 两条路径和最大

```c++
#include<iostream>
#include<vector>
using namespace std;
int dp[53][53][53][53];
int main() {
	int n, m;
	cin >> m >> n;
	vector<vector<int> > a(m + 1, vector<int>(n + 1, 0));
	
	
	int ans = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				for (int l = 1; l <= n; l++) {
					dp[i][j][k][l] = a[i][j]+a[k][l] + max(max(dp[i-1][j][k-1][l], dp[i - 1][j][k][l-1]),
						max(dp[i][j-1][k-1][l], dp[i][j - 1][k][l-1]));
					if (i == k && j == l) {
						dp[i][j][k][l] -= a[i][j];
					}
				}
			}
			
		}
	}
	
	cout << dp[m][n][m][n] <<endl;

	return 0;
}
```

最长上升子序列

```
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	vector<int> dp(n,1);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int mx = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);

				mx = max(mx, dp[i]);
			}
		}
	}
	cout << mx << endl;

}
```

