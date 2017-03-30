// Прога.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
	Stack<char> Char;
	Stack<int> Int;
	string st;
	// Считывание
	ifstream ReadSt("example.txt");
	ReadSt >> st;
	while (ReadSt.get() != EOF)
	{
		ReadSt >> st;
	}
	cout << st << endl;
	// Запись
	int k = 0;
	char rec = st[k];
	while (k != st.size())
	{
		switch (rec)
		{
		case 'T':
			Int.push(1);
			break;
		case 'F':
			Int.push(0);
			break;
		case 'N':
			Char.push('N');
			break;
		case 'A':
			Char.push('A');
			break;
		case 'X':
			Char.push('X');
			break;
		case 'O':
			Char.push('O');
			break;
		case '.':
			Char.push('.');
			break;
		case '(':
			Char.push(')');
			break;
		case ')':
			Char.push('(');
			break;
		}
		k++;
		rec = st[k];
	}
	Int.print();
	Char.print();
	// Упрощение логических выражений
	char buf = Char.pop();
	int StBuf = Int.pop();
	int ibuf = StBuf;
	while (buf != '.')
	{
		if (buf == '(')
		{
			while (buf != ')')
			{
				buf = Char.pop();
				if (buf == 'N')
				{
					switch (StBuf)
					{
					case 1: StBuf = 0; break;
					case 0: StBuf = 1; break;
					default: break;
					}
					buf = Char.pop();
					ibuf = StBuf;
				}
				else if (buf == 'A')
				{
					StBuf = Int.pop();
					if ((ibuf == 1) && (StBuf == 1))
						ibuf = 1;
					else if ((ibuf == 0) && (StBuf == 1))
						ibuf = 0;
					else if ((ibuf == 1) && (StBuf == 0))
						ibuf = 0;
					else if ((ibuf == 0) && (StBuf == 0))
						ibuf = 0;
					buf = Char.pop();
				}
				else if (buf == 'O')
				{
					StBuf = Int.pop();
					if ((ibuf == 1) && (StBuf == 1))
						ibuf = 1;
					else if ((ibuf == 0) && (StBuf == 1))
						ibuf = 1;
					else if ((ibuf == 1) && (StBuf == 0))
						ibuf = 1;
					else if ((ibuf == 0) && (StBuf == 0))
						ibuf = 0;
					buf = Char.pop();
				}
				else if (buf == 'X')
				{
					StBuf = Int.pop();
					if ((ibuf == 1) && (StBuf == 1))
						ibuf = 0;
					else if ((ibuf == 0) && (StBuf == 1))
						ibuf = 1;
					else if ((ibuf == 1) && (StBuf == 0))
						ibuf = 1;
					else if ((ibuf == 0) && (StBuf == 0))
						ibuf = 0;
					buf = Char.pop();
				}
			}
			buf = Char.pop();
		}
		else
		{
			if (buf == 'N')
			{
				switch (StBuf)
				{
				case 1: StBuf = 0; break;
				case 0: StBuf = 1; break;
				default: break;
				}
				buf = Char.pop();
				ibuf = StBuf;
				cout << ibuf << endl;
			}
			else if (buf == 'A')
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 0;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 0;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				buf = Char.pop();
			}
			else if (buf == 'O')
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				cout << ibuf << endl;
				buf = Char.pop();
			}
			else if (buf == 'X')
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 0;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				buf = Char.pop();
			}
		}
	}
	if (ibuf == 0)
		cout << "False" << endl;
	else
		cout << "True" << endl;
	system("pause");
}

