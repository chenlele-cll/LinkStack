#include<iostream>
using namespace std;

template<class datatype>
class LinkStack;

template<class datatype>
class node
{
public:
	friend class LinkStack<datatype>;
	datatype val;
	node<datatype> *next;
	node(datatype x) : val(x), next(NULL) {};
};

template<class datatype>
class LinkStack
{
private:
	node<datatype> *S;
	int len;
public:
	LinkStack();
	LinkStack(datatype a[],int n);//将数组a的元素压入栈
	~LinkStack();
	void push(datatype value);//入栈
	void pop();//出栈
	datatype top();//获取栈顶元素
	bool empty1();//判空
	bool empty2();//判空
	friend ostream &operator<<(ostream &output, const LinkStack &D)
	{
		if (D.len==0)
		{
			cout << "LinkStack is empty" << endl;
		}
		else
		{
			node<datatype> *p = D.S;
			for (int i = 0; i < D.len; i++)
			{
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
		return output;
	}
};

template<class datatype>
LinkStack<datatype>::LinkStack()
{
	S = NULL;
	len = 0;
}

template<class datatype>
LinkStack<datatype>::LinkStack(datatype a[],int n)
{
	S = NULL;
	int i = 0;
	for (; i < n; i++)
	{
		if (a[i] != 0)
			push(a[i]);
		else break;
	}
	len = i ;
}

template<class datatype>
LinkStack<datatype>::~LinkStack()
{
	if (len != 0)
	{
		node<datatype> *p = S,*k;
		for (int i = 0; i < len; i++)
		{
			k = p->next;
			delete p;
			p = k;
		}
	}
}

template<class datatype>
void LinkStack<datatype>::push(datatype value)
{
	node<datatype> *p=S;
	S = new node<datatype>(value);
	S->next = p;
	len++;
}

template<class datatype>
void LinkStack<datatype>::pop()
{
	node<datatype> *p = S;
	S = S->next;
	len--;
	delete p;
}

template<class datatype>
datatype LinkStack<datatype>::top()
{
	return S->val;
}

template<class datatype>
bool LinkStack<datatype>::empty1()
{
	return !len;
}

template<class datatype>
bool LinkStack<datatype>::empty2()
{
	if (S == NULL)
		return true;
	else return false;
}
int main()
{
	int a[10] = { 1,3,4,2 };
	LinkStack<int> A;
	LinkStack<int> B(a,5);
	cout << B;
	//cout << A.empty1() << " " <<A.empty2() << endl;
	A.push(1);
	//cout << A.empty1() << " " << A.empty2() << endl;
	A.push(2);
	cout << A;
	A.pop();
	cout << A;
	cout << A.top()<<endl;
	system("pause");
	return 0;
}