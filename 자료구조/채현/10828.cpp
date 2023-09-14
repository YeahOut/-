#include <iostream>

using namespace std;

template <class DT>
class Stack
{
public:
	Stack();
	~Stack();
	void push(int n);
	void pop();
	void size();
	void empty();
	void topp();
private:
	int top;
	DT* dataItems;
};

template <class DT>
Stack<DT>::Stack()
{
	top = -1;
	dataItems = new DT[10000];
}

template <class DT>
Stack<DT>::~Stack()
{
	delete[] dataItems;
}

template <class DT>
void Stack<DT>::push(int n)
{
	dataItems[++top] = n;
}

template <class DT>
void Stack<DT>::pop()
{
	if (top != -1)
		cout << dataItems[top--] << endl;
	else
		cout << "-1" << endl;
}

template <class DT>
void Stack<DT>::size()
{
	if (top == -1)
		cout << '0' << endl;
	else
		cout << top + 1 << endl;
}

template <class DT>
void Stack<DT>::empty()
{
	if (top == -1)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}

template <class DT>
void Stack<DT>::topp()
{
	if (top != -1)
		cout << dataItems[top] << endl;
	else
		cout << "-1" << endl;
}

int main()
{
	Stack<int> stack;
	int n;
	string order;

	cin >> n;

	while (n > 0)
	{
		cin >> order;
		if (order == "push")
		{
			int data;
			cin >> data;
			stack.push(data);
		}
		else if (order == "pop")
			stack.pop();
		else if (order == "size")
			stack.size();
		else if (order == "empty")
			stack.empty();
		else if (order == "top")
			stack.topp();

		n--;
	}

	return 0;
}
