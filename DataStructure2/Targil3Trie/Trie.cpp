#pragma once
#include "Trie.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Trie::insert(string str)
{
	if (!search(str))
	{
		insertWord(str, this->root);
	}
}

bool Trie::del(string str)
{
	if (search(str))
	{
		return delWord(str, this->root);
	}
	return false;
}

bool Trie::search(string str)
{
	return searchWord(str, this->root);
}

int Trie::printAutoSuggestions(string str)
{
	TrieNode* myPointer = this->root;
	bool flag = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (myPointer->children[chToInt(str[i])] != NULL)
		{
			myPointer = myPointer->children[chToInt(str[i])];
		}
		else
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printAllWordsFromPrefix(myPointer);
		return 1;
	}
	return 0;
}

void Trie::printAllWordsFromPrefix(TrieNode* node)
{
	string prefix1, prefix;
	TrieNode* myPointer = node;
	while (myPointer->father != NULL)
	{
		for (int i = 0; i < 26; i++)
		{
			if (myPointer->father->children[i] == myPointer)
			{
				prefix1.push_back(i + 'a');
				break;
			}
		}
		myPointer = myPointer->father;
	}
	for (int i = prefix1.size() - 1; i >= 0; i--)
	{
		prefix.push_back(prefix1[i]);
	}
	printAllWordsFromPrefix(node, prefix);
}

void Trie::printAllWordsFromPrefix(TrieNode* node, string str)
{
	if (node->isEndWord == true)
	{
		cout << str << endl;
	}
	for (int i = 0; i < 26; i++)
	{
		if (node->children[i] != NULL)
		{
			str.push_back(i + 'a');
			printAllWordsFromPrefix(node->children[i], str);
			str = str.substr(0, str.size() - 1);
		}
	}
}

bool Trie::searchWord(string str, TrieNode* node)
{
	if (str.size() == 0)
	{
		if (node->isEndWord)
		{
			return true;
		}
		return false;
	}
	if (node->children[chToInt(str[0])] != NULL)
	{
		return searchWord(str.substr(1, str.size() - 1), node->children[chToInt(str[0])]);
	}
	return false;
}

void Trie::insertWord(string str, TrieNode* node)
{
	if (str.size() == 0)
	{
		node->isEndWord = true;
		return;
	}
	else
	{
		if (node->children[chToInt(str[0])] != NULL)
		{
			insertWord(str.substr(1, str.size() - 1), node->children[chToInt(str[0])]);
		}
		else
		{
			node->children[chToInt(str[0])] = new TrieNode();
			node->children[chToInt(str[0])]->father = node;
			node->countChildren++;
			insertWord(str.substr(1, str.size() - 1), node->children[chToInt(str[0])]);
		}
	}
}

bool Trie::delWord(string str, TrieNode* node)
{
	if (str.size() == 0)
	{
		if (node->isEndWord == true)
		{
			bool flag = false;
			for (int i = 0; i < 26; i++)
			{
				if (node->children[i] != NULL)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				node->isEndWord = false;
				return true;
			}
			else
			{
				for (int i = 0; i < 26; i++)
				{
					if (node->father->children[i] == node)
					{
						TrieNode* tmp = node->father;
						node->father->countChildren--;
						delete node->father->children[i];
						tmp->children[i] = NULL;
						return true;
					}
				}
			}
		}
	}
	else
	{
		bool flag = delWord(str.substr(1, str.size() - 1), node->children[chToInt(str[0])]);
		if (flag)
		{
			if (node->countChildren == 0 && node->isEndWord == false)
			{
				for (int i = 0; i < 26; i++)
				{
					if (node->father != NULL)
					{
						if (node->father->children[i] == node)
						{
							TrieNode* tmp = node->father;
							node->father->countChildren--;
							delete node->father->children[i];
							tmp->children[i] = NULL;
							return true;
						}
					}
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		return false;
	}
}
