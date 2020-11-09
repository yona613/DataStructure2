#pragma once
#include "HashTable.h"


class HashInt : public HashTable<int, int>
{
public:
	HashInt(int tmpSize = 0) : HashTable<int,int>(tmpSize) {};
	int h1(int k) override;
	int h2(int k) override;
};

int HashInt::h1(int k)
{
	return k % size;
}



int HashInt::h2(int k)
{
	return k % (size - 1) + 1;
}
