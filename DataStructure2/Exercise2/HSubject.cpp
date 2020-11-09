#include "HSubject.h"
#include <cmath>
#include <iostream>

using namespace std;

void HSubject::PrintTitle(string title)
{
	int index = Find(title);
	if (index != -1)
	{
		for (list<string>::iterator it = myArray[index].data.begin(); it != myArray[index].data.end(); it++)
		{
			cout << (*it) << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "ERROR";
	}
}

void HSubject::addSubjectAndTitle(string title, string discussion)
{
	bool flag = false;
	int i = 0;
	for (; i < size; i++)
	{
		if (myArray[i].key == title)
		{
			flag = true;
			break;
		}
	}

	if (flag)
	{
		myArray[i].data.push_front(discussion);
	}
	else
	{
		Item<list<string>, string> tmpItem;
		tmpItem.key = title;
		tmpItem.flag = FULL;
		tmpItem.data.push_front(discussion);
		Add(tmpItem);
	}

}

void HSubject::PrintNDiscussion(string title, int n)
{
	int index = Find(title);
	if (index != -1)
	{
		int i = 0;
		for (list<string>::iterator it = myArray[index].data.begin(); (it != myArray[index].data.end()) && (i < n); it++, i++)
		{
			cout << (*it) << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "ERROR";
	}
}

void HSubject::startNewTable()
{
	if (myArray)
	{
		delete[] myArray;
	}
	myArray = new Item<list<string>, string>[size];
}

void HSubject::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (myArray[i].flag == FULL)
		{
			cout << myArray[i].key << ":";
			for (list<string>::iterator it = myArray[i].data.begin(); it != myArray[i].data.end(); it++)
			{
				cout << (*it) << " ";
			}
			cout << endl;
		}
	}
}

int HSubject::h1(string k)
{
	//int sum = 0;
		//for (int i = 0; i < k.size() ; i++)
		//{
		//	sum += ((int)k[i]) * pow(128, i);
		//}
	return k[1] % size;
}

int HSubject::h2(string k)
{
	//int sum = 0;
	//for (int i = 0; i < k.size() ; i++)
	//{
	//	sum += ((int)k[i]) * pow(128, i);
	//}
	return k[1] % size + 1;
}
