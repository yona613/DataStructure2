#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <list>
#include <string>
using namespace std;

class letter
{
public:
	string ltr;
	int  frq;
	string binCode;
	letter()
	{
		ltr = " ";
		frq = 0;
		binCode = " ";
	}

};

//a node of a leave or a node of a subtree.
class HNode
{
public:
	string ltr = "";
	int frq;
	HNode* left;
	HNode* right;

	HNode();
	HNode(string s, int n);

};

class compareNode
{
public:
	HNode*n;
	bool operator()(HNode* const& n1, HNode* const& n2)
	{
		return(n1->frq > n2->frq);
	}
};

class HuffmanTree
{
	HNode* root;
public:
	//string text;
	void buildTree(int* frTable);
	int* buildTableOfFreq(string word);

	void codeOfLetters(HNode* p, string partCode, string *table);
	string encode(string*table, string t);

	string decode(HNode *p, string binaryCode, string partCode, int i);
	void encodeTree(string* code);
	void endodeTreeRec(string* code, HNode* root);
	void buildTableCode(string *table);
	void buildTableCodeRecur(string* table, HNode* root, string code);
	string decode(string binaryCode);
	
	
	//void printToFile(ofstream& of, string binaryCode);  //print tree to file
	//void readFromFile(ifstream& ifs, string &binaryCode); //read tree from file
	//void printToFileRec(ofstream& of, HNode *p); //print tree to file
	//void readFromFileRec(ifstream& ifs, HNode *&p, string str, string letters, int &currS, int& currL); //read tree from file
};