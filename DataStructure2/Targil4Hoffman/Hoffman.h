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

	~HNode();
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
	void buildTreeFromLetters(int* frTable);
	void builTreeFromCode(string code, string letters);
	void builTreeFromCodeRec(string& code, string& letters, HNode* root);
	int* buildTableOfFreq(string word);

	string encode(string*table, string t, int &numOfLetters);

	string decode(int frq, string letters, string treeCode, string encodedText);
	void encodeTree(string* code);
	void encodeTreeRec(string* code, HNode* root);
	void buildTableCode(string *table);
	void buildTableCodeRecur(string* table, HNode* root, string code);
	//string decode(string binaryCode);
	string OrderOflettersinTree(HNode* node);
	
	
	//void printToFile(ofstream& of, string binaryCode);  //print tree to file
	//void readFromFile(ifstream& ifs, string &binaryCode); //read tree from file
	//void printToFileRec(ofstream& of, HNode *p); //print tree to file
	//void readFromFileRec(ifstream& ifs, HNode *&p, string str, string letters, int &currS, int& currL); //read tree from file
	~HuffmanTree();
};