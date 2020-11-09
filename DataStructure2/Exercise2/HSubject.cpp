#include "HSubject.h"
#include <iostream>

using namespace std;

void HSubject::PrintTitle(string title)
{
	int index = Find(title);
	if (index != -1)
	{
		for (list<string>::iterator it = myArray[index].data.begin(); it != myArray[index].data.end() ; it++)
		{
			cout << (*it) << " ";
		}
		cout << endl;
	}
}

void HSubject::addSubjectAndTitle(string discussion, string title)
{
	int i = 0;
	for(int i =0 ; i < size ; i++)
	{
		if(myArray[i].key == title)
			break;
	}

	if(i != 0)
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
		for (list<string>::iterator it = myArray[index].data.begin(); (it != myArray[index].data.end()) && (i < n); it++ , i++)
		{
			cout << (*it) << " ";
		}
		cout << endl;
	}
}

void HSubject::startNewTable(int tmpSize)
{
	if (myArray)
	{
		delete[] myArray;
	}
	int i = tmpSize;
	for (; i > 1; i--)
	{
		bool flag = true;
		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			break;
		}
	}
	int count1 = tmpSize - i;
	i = tmpSize;
	while (true)
	{
		bool flag = true;
		for (int j = 2; j < i; j++)
		{
			if ((i % j) == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			break;
		}
		i++;
	}
	int count2 = i - tmpSize;
	if (count2 > count1)
	{
		myArray = new Item<list<string>,string>[tmpSize - count1];
		size = tmpSize - count1;
	}
	else
	{
		myArray = new Item<list<string>, string>[i];
		size = i;
	}
}

void HSubject::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (myArray[i].flag == FULL)
		{
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
	int sum = 0;
	for (int i = 0; i < k.size() ; i++)
	{
		sum += ((int)k[i]) * pow(128, i);
	}
	return sum % size;
}

int HSubject::h2(string k)
{
	int sum = 0;
	for (int i = 0; i < k.size(); i++)
	{
		sum += ((int)k[i]) * pow(128, i);
	}
	return ((sum*15)%(size))+1;
}
