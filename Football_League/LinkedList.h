#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class Node
{
public:
	Node(const T& t) : data(t), next(nullptr) {}
	~Node()
	{
		delete next; // node delete chain reaction
	}

	T& getData()
	{
		return data;
	}

	Node<T>* getNext()
	{
		return next;
	}

private:
	T data;
	Node<T>* next;

	template<class T> friend class LinkedList;
};

template<class T>
class LinkedList
{
private:
	Node<T>* first;
	Node<T>* last;

public:
	LinkedList() : first(nullptr), last(nullptr) {}

	~LinkedList()
	{
		delete first;
	}

	Node<T>* getFirst()
	{
		return first;
	}

	void insert(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);

		if (last == NULL)
		{
			first = last = newNode;
			return;
		}

		last->next = newNode;
		last = newNode;
	}

	void remove(const T& value)
	{
		Node<T>* curr = first;
		Node<T>* prev = nullptr;

		if (first == curr) // delete first
		{
			if (first == last) // first is also last
				last = nullptr;
			first = first->next;
			curr->next = nullptr; // cancel delete chain reaction
			delete curr;
			return;
		}

		while (curr != nullptr && curr->data != value) // find data
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr == nullptr)  // not found
			return;

		if (curr == last)  // deleting last
			last = prev;

		prev->next = curr->next;
		curr->next = nullptr; // cancel delete chain reaction
		delete curr;
	}

	void print() const
	{
		Node<T>* curr = first;
		while (curr != nullptr)
		{
			cout << curr->data;
			curr = curr->next;
		}
	}
};

#endif