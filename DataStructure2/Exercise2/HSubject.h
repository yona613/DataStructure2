#pragma once
#include <list>
#include <string>
#include "HashTable.h"

/// <summary>
/// use HashTable and Initializing the func
/// </summary>
class HSubject : public HashTable<list<string>, string>
{
public:
	HSubject(int number = 0) : HashTable(number) {};
	void PrintTitle(string title);
	void addSubjectAndTitle(string discussion, string title);
	void PrintNDiscussion(string title, int n);
	void startNewTable();
	void Print();

private:
	int h1(string k);
	int h2(string k);
};
