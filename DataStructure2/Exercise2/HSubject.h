#pragma once
#include <list>
#include <string>
#include "HashTable.h"

class HSubject : public HashTable<list<string>,string>
{
public:
	HSubject(int number = 0) : HashTable(number) {};
	void PrintTitle(string title);
	void addSubjectAndTitle(string discussion, string title);
	void PrintNDiscussion(string title, int n);
	void startNewTable(int tmpSize=0);
	void Print() override;
	
private:
	int h1(string k)override;
	int h2(string k)override;
};
