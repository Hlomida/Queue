#include <iostream>
using namespace std;

template<typename T>
class queue
{
public:
	queue();
	~queue();
	queue(const queue &orig)
	{
		this->clear();
		Node<T>* current = orig.head;
		for (int i = 0; i < orig.size; i++)
		{

			this->push_back(current->data);
			current = current->pNext;
		}
	}
	void push_back(T data); // добавляет элемент в начало очереди
	int GetSize() // возвращает размер очереди
	{
		return size;
	}
	T Top(); // выводит значение конца очереди
	T Back(); // выводит значение начала очереди
	void pop_front(); // убирает элемент из конца очереди
	void clear(); // отчищает очередь последовательно
	bool isEmpty(); // проверяет очередь на пустоту

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head; //первый добавленый элемент, первый убранный
	Node<T>* tail; // последний добавленный элемент
};

template<typename T>
queue<T>::queue() //  при создании очереди изначально она пуста и указатели на начало и конец пусты
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
queue<T>::~queue()
{
	clear();
}
template<typename T>
void queue<T>::push_back(T data) // проверяет начало и конец на пустоту и заполняет их, либо добавляет значение в начало очереди 
{
	if (head == nullptr) 
	{
		head = new Node<T>(data);
	}
	else if (tail == nullptr) 
	{
		tail = new Node<T>(data);
		head->pNext = tail;
	}
	else
	{
		Node<T>* current = tail;
		tail = new Node<T>(data);
		current->pNext = tail;
	}
	size++;
}

template<typename T>
T queue<T>::Top()
{
	if (head == nullptr) { cout << "nullptr"; }
	else {
		return head->data;
	}
}

template<typename T>
T queue<T>::Back()
{
	if (tail == nullptr)
	{
		cout << "nullptr";
	}
	else {
		return tail->data;
	}
}

template<typename T>
void queue<T>::pop_front()
{
	if (head == nullptr) { cout << "nullptr" << endl; }
	else {
		Node<T>* temp = head;

		head = head->pNext;

		delete temp;

		size--;
	}
}

template<typename T>
void queue<T>::clear() // вызывает функцию удаления первого элемента последовательно для каждого элемента в очереди 
{
	if (size != 0)
	{
		pop_front();
	}
}

template<typename T>
bool queue<T>::isEmpty()
{
	if (size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

