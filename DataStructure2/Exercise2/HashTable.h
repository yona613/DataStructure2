#pragma once
#include <iostream>

using namespace std;

enum state { EMPTY, FULL, DELETED };
template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item()
	{
		flag = EMPTY;
	}
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};

template <class T, class K>
class HashTable
{
public:
	HashTable(int size = 0);
	~HashTable();
	int Find(K k);
	bool Add(Item<T, K> tmpItem);
	bool Delete(K k);
	bool Update(Item<T, K> tmpItem);
	virtual void Print() = 0;

protected:
	Item<T, K>* myArray;
	int size;
	int Hash(K k, int i);
	virtual int h1(K k) = 0;
	virtual int h2(K k) = 0;
};

template<class T, class K>
HashTable<T, K>::HashTable(int tmpSize)
{
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
		myArray = new Item<T, K>[tmpSize - count1];
		size = tmpSize - count1;
	}
	else
	{
		myArray = new Item<T, K>[i];
		size = i;
	}

}

template <class T, class K>
HashTable<T, K>::~HashTable()
{
	delete[] myArray;
}

template<class T, class K>
int HashTable<T, K>::Hash(K k, int i)
{
	return (h1(k) + i * h2(k)) % size;
}

template<class T, class K>
int HashTable<T, K>::Find(K k)
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = Hash(k, i);
		if ((myArray[index].key == k) && (myArray[index].flag != DELETED))
		{
			return index;
			if (myArray[index].flag == EMPTY)
			{
				return -1;
			}
		}
	}
	return -1;
}

template<class T, class K>
bool HashTable<T, K>::Add(Item<T, K> tmpItem)
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = Hash(tmpItem.key, i);
		if ((myArray[index].flag == EMPTY) || (myArray[index].flag == DELETED))
		{
			myArray[index] = tmpItem;
			return true;
		}
	}
	return false;
}

template<class T, class K>
bool HashTable<T, K>::Delete(K k)
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = Hash(k, i);
		if (myArray[index].key == k)
		{
			myArray[index].flag = DELETED;
			return true;
		}
	}
	return false;
}

/// <summary>
/// update th
/// </summary>
/// <typeparam name="T">the data</typeparam>
/// <typeparam name="K">the key</typeparam>
template<class T, class K>
bool HashTable<T, K>::Update(Item<T, K> tmpItem)
{
	int index;
	for (int i = 0; i < size; i++)
	{
		index = Hash(tmpItem.key, i);
		if (myArray[index].flag == FULL)
		{
			myArray[index] = tmpItem;
			return true;
		}
	}
	return false;
}

/// <summary>
/// print all the array
/// </summary>
/// <typeparam name="T">the data</typeparam>
/// <typeparam name="K">the key</typeparam>
//template<class T, class K>
//void HashTable<T, K>::Print()
//{
//	for (int i = 0; i < size; i++)
//	{
//		if (myArray[i].flag == FULL)
//		{
//			cout << myArray[i].data << endl;
//		}
//	}
//}
