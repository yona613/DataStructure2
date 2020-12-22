#pragma once

#include <iostream>
#include <string>

using namespace std;

const int ALPHABET = 26;
static int chToInt(char ab) { return (int)ab - (int)'a'; }

class Trie
{
protected:
	class TrieNode
	{
	public:
		TrieNode* children[ALPHABET] = { 0 };
		TrieNode* father = NULL;
		bool isEndWord = false;
		int countChildren = 0;
	public:
		TrieNode() {};
		~TrieNode()
		{
			for (int i = 0; i < 26; i++)
			{
				if (children[i])
				{
					TrieNode* tmp = children[i];
					children[i] = NULL;
					delete tmp;
				}
			}

		}
	};
	TrieNode* root;
public:
	Trie() { root = new TrieNode; }//ctor - initialize root to be "root"
	~Trie()
	{
		if (root != NULL)
		{
			delete root;
		}
	}

	//all functions
	void insert(string str);
	bool del(string str);
	bool search(string str);
	int printAutoSuggestions(string str);
private:
	void printAllWordsFromPrefix(TrieNode* node);
	void printAllWordsFromPrefix(TrieNode* node, string str);
	bool searchWord(string str, TrieNode* node);
	void insertWord(string str, TrieNode* node);
	bool delWord(string str, TrieNode* node);
};
