#pragma once

#include <string>

template<class T>
class Stack  // ����� ����
{
public:
	Stack() :_back(0), _head(0) //�����������
	{
	}

	~Stack() // ����������
	{
		while (_head)
		{
			_back = _head->next;
			delete _head;
			_head = _back;
		}
	}

	void push(T val) // ��������� �������� � ����
	{
		Node* Temp;
		Temp = new Node;
		Temp->element = val;
		if (_back == 0)
		{
			_back = Temp;
		}
		else
		{
			Temp->next = _back;
			_back = Temp;
		}
	}

	T pop() // ����� �������� �� ����� � �������������� ��� ������� ������ (���� �������� ���, �� ������ �����)
	{       
		if (_back == 0)
		{
			throw std::string("Stack is empty!");
		}
		else
		{                      
			T tmp = _back->element;
			Node* delptr = _back;
			_back = _back->next;
			delete delptr;
			return tmp; 
		}
	}

	void print() // ������ ��������� ����� 
	{
		if (_back == NULL)
		{
			printf("Error: Stack is empty!\n");
		}
		else
		{
			for (Node* ptr = _back; ptr != 0; ptr = ptr->next)
			{
				std::cout << ptr->element << ' ';
			}
			std::cout << '\n';
		}
	}
private:
	struct Node // ��������� ��� �������� ���������
	{
		Node() :element(0), next(0)
		{
		}
		Node* next;
		T element;
	};
	Node* _head;
	Node* _back;
};

