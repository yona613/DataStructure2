#include "Hoffman.h"
#include <vector>
#include <queue>

HNode::HNode()
{
}

HNode::HNode(string s, int n)
{
}

void HuffmanTree::buildTree(int* frTable)
{
	HNode* tmpNode;
	priority_queue<HNode*, vector<HNode*>, compareNode> pQueue;
	for (int i = 0; i < 256; i++)
	{
		if (frTable[i] != 0)
		{
			tmpNode = new HNode();
			tmpNode->frq = frTable[i];
			tmpNode->ltr += (char)i;
			pQueue.push(tmpNode);
		}
	}
	while (pQueue.size() > 1)
	{
		tmpNode = new HNode();
		tmpNode->right = pQueue.top();
		pQueue.pop();
		tmpNode->left = pQueue.top();
		pQueue.pop();
		tmpNode->frq = tmpNode->right->frq + tmpNode->left->frq;
		pQueue.push(tmpNode);
	}
	root = pQueue.top();
	pQueue.pop();
}

int* HuffmanTree::buildTableOfFreq(string word)
{
	int* frArray = new int[256]{0};
	for (int i = 0; i < word.length(); i++)
	{
		frArray[(int)word[i]]++;
	}
	return frArray;
}

void HuffmanTree::codeOfLetters(HNode* p, string partCode, string* table)
{

}

string HuffmanTree::encode(string* table, string t)
{
	return string();
}

string HuffmanTree::decode(HNode* p, string binaryCode, string partCode, int i)
{
	return string();
}

void HuffmanTree::encodeTree(string* code)
{
	*code = "";
	endodeTreeRec(code, root);
}

void HuffmanTree::endodeTreeRec(string* code, HNode* root)
{
	if (root->left == NULL && root->right == NULL) 
	{
		code += '1';
		return;
	}
	if (root->left != NULL)
	{
		code += '0';
		endodeTreeRec(code, root->left);
	}
	endodeTreeRec(code, root->right);
}

void HuffmanTree::buildTableCode(string* table)
{
	string code = "";
	buildTableCodeRecur(table, root, code);
}


void HuffmanTree::buildTableCodeRecur(string* table, HNode* root, string code)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (root->ltr != "")
		{
			table[(int)root->ltr[0]] = code;
		}
	}
	if (root->left != NULL)
	{
		buildTableCodeRecur(table, root->left, code + '0');
	}
	if (root->right != NULL)
	{
		buildTableCodeRecur(table, root->right, code + '1');
	}
}


string HuffmanTree::decode(string binaryCode)
{
	return string();
}
