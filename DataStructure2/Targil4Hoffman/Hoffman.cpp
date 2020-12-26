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
		tmpNode->left = pQueue.top();
		pQueue.pop();
		tmpNode->right = pQueue.top();
		pQueue.pop();
		tmpNode->frq = tmpNode->right->frq + tmpNode->left->frq;
		if (tmpNode->right->frq == tmpNode->left->frq)
		{
			HNode* tmpPtr = tmpNode->right;
			tmpNode->right = tmpNode->left;
			tmpNode->left = tmpPtr;
		}
		pQueue.push(tmpNode);
	}
	root = pQueue.top();
	pQueue.pop();
}

int* HuffmanTree::buildTableOfFreq(string word)
{
	int* frArray = new int[256]{ 0 };
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
	int* frTbl = buildTableOfFreq(t);
	buildTree(frTbl);
	buildTableCode(table);
	string* code = new string;
	encodeTree(code);
	int numOfLetters = 0;
	string coded = "";
	for (int i = 0; i < 256; i++)
	{
		if (frTbl[i] != 0)
		{
			numOfLetters++;
		}
	}
	coded.insert(0, 1, (char)(numOfLetters + 48));
	coded.insert(1, 1, '\n');
	coded += OrderOflettersinTree(root);
	coded += '\n';
	coded += *code;
	coded += '\n';
	for (int i = 0; i < t.length(); i++)
	{
		coded += table[(int)t[i]];
	}
	return coded;
}

string HuffmanTree::decode(HNode* p, string binaryCode, string partCode, int i)
{
	return string();
}

void HuffmanTree::encodeTree(string* code)
{
	*code += "";
	encodeTreeRec(code, root);
}

void HuffmanTree::encodeTreeRec(string* code, HNode* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		*code += '1';
		return;
	}
	if (root->left != NULL)
	{
		*code += '0';
		encodeTreeRec(code, root->left);
	}
	encodeTreeRec(code, root->right);
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

//string HuffmanTree::OrderOflettersinTree()
//{
//	return OrderOflettersinTree(root);
//}


string HuffmanTree::OrderOflettersinTree(HNode* node)
{
	if (node->left == NULL && node->right == NULL)
		return node->ltr;

	string tmpString = "";

	/* first recur on left child */
	tmpString += OrderOflettersinTree(node->left);

	tmpString += OrderOflettersinTree(node->right);

	return tmpString;
}
