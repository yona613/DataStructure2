#include "Hoffman.h"
#include <vector>
#include <queue>


void HuffmanTree::buildTreeFromLetters(int* frTable)
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

void HuffmanTree::builTreeFromCode(string code, string letters)
{
	root = new HNode();
	builTreeFromCodeRec(code, letters, root);
}

void HuffmanTree::builTreeFromCodeRec(string &code, string &letters, HNode* root)
{
	if (code.empty())
		return;
	if (code[0] == '1') 
	{
		root->ltr = letters[0];
		letters = letters.substr(1, letters.size() - 1);
		code = code.substr(1, code.size() - 1);
		return;
	}
	if (code[0])
	{
		root->left = new HNode();
		root->right = new HNode();
		code = code.substr(1, code.size() - 1);
		builTreeFromCodeRec(code, letters, root->left);
		builTreeFromCodeRec(code, letters, root->right);
	}
		
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

string HuffmanTree::encode(string* table, string t)
{
	int* frTbl = buildTableOfFreq(t);
	buildTreeFromLetters(frTbl);
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
	delete[] frTbl;
	delete code;
	return coded;
}

string HuffmanTree::decode(int frq , string letters, string treeCode, string encodedText)
{
	string* table = new string[256];
	builTreeFromCode(treeCode, letters);
	buildTableCode(table);
	string decodeText = "";
	int i = 0;
	bool found = false;
	while (!encodedText.empty() && i <= encodedText.size())
	{
		for (int j = 0; j < 256; j++)
		{
			if (encodedText.substr(0, i) == table[j] && table[j] != "")
			{
				decodeText += (char)j;
				encodedText = encodedText.substr(i, encodedText.size() - 1);
				found = true;
				break;
			}
		}
		if (found)
		{
			i = 0;
			found = false;
		}
		else i++;
	}
	delete[] table;
	return decodeText;
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


/*string HuffmanTree::decode(string binaryCode)
{
	return string();
}*/

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

HuffmanTree::~HuffmanTree()
{
	delete root;
}

HNode::~HNode()
{
	if (this->left != NULL)
		delete this->left;
	if (this->right != NULL)
		delete this->right;
}