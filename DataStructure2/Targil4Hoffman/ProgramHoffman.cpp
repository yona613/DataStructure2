#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "Hoffman.h"


int main()
{
	int choice;
	string word;
	string codedWord;
	string encodedText;
	string code;
	string letters;
	int frq;
	string* table = new string[256];
	HuffmanTree* t = NULL;
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	do
	{
		if (t != NULL)
		{
			delete t;
			t = new HuffmanTree();
		}
		else t = new HuffmanTree();
		cin >> choice;
		switch (choice)
		{
		case 1:

			cout << "enter the original text" << endl;
			cin >> word;
			codedWord = t->encode(table, word);
			//Build Huffman tree given the data inside "word".
			//Then find the code of each letter.
			//Then print the output - number of leaves, order of letters, tree structure and the encoded text - according to the explanation in the exercise.
			cout << "The encoded string is:" << endl << codedWord << endl;
			break;
		case 2:
			//input the number of leaves, the  order of letters, tree structure and the encoded text.
			//build the Huffman Tree according to the tree strcture. put the letters in the leaves according to the given order. 
			//Given the Huffman Tree and the encoded text, find the original text, and print it. 

			cout << "enter n ";
			cin >> frq;
			cout << "enter the letters ";
			cin >> letters;
			cout << "enter the encoded structure ";
			cin >> code;
			cout << "enter the encoded text ";
			cin >> encodedText;
			cout << "The decoded string is: " << t->decode(frq, letters, code, encodedText) << endl;

			break;
		case 3:
			break;
		}

	} while (choice != 3);
	delete[] table;
	delete t;
	return 0;
}