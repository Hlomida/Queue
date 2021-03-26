#include "Queue.h"

using namespace std;


int main()
{
	queue<int> que;
	que.push_back(1);
	que.push_back(2);
	que.push_back(3);
	que.push_back(4);
	que.push_back(5);
	cout << "queue size:" << que.GetSize() << endl;
	cout << "top: " << que.Top() << endl;
	cout << "back: " << que.Back() << endl;
	cout << "removing element" << endl; que.pop_front();
	cout << "top: " << que.Top() << endl;
	cout << "back: " << que.Back() << endl;
	cout << "queue size:" << que.GetSize() << endl;
	queue<int> que2(que);
	cout << que2.Top() << endl;
	cout << que2.GetSize() << endl;
	for (int i = 0, size = que2.GetSize(); i < size; i++)
	{
		cout << que2.Top() << endl;
		que2.pop_front();
	}
	return 0;

}