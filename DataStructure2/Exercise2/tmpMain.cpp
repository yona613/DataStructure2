#include <iostream>

#include <string>
#include "HashInt.h"

using namespace std; // hi! yona

enum choice { ADD = 1, DELETE, FIND, EXIT = 0 };

int main()
{
	Item<int, int> tmpItem;
	int tmp;
	int choice = 0;
	HashInt tmpHash(4);
	do
	{
		cout << "Enter your choice :" << endl << "Add - 1 / Delete - 2 / Find - 3 / Exit - 0 " << endl;
		cin >> choice;
		switch (choice)
		{
		case ADD:
			cout << "Enter Object Key :" << endl;
			cin >> tmp;
			tmpItem.key = tmp;
			cout << "Enter Object Data :" << endl;
			cin >> tmp;
			tmpItem.data = tmp;
			tmpItem.flag = FULL;
			tmpHash.Add(tmpItem);
			break;
		case DELETE:
			cout << "Enter Object Key :" << endl;
			cin >> tmp;
			tmpHash.Delete(tmp);
			break;
		case FIND:
			cout << "Enter Object Key :" << endl;
			cin >> tmp;
			cout << "Object found at " << tmpHash.Find(tmp) << " index" << endl;
			break;
		case EXIT:
			cout << "GoodBye" << endl;
			break;
		default:
			break;
		}

	} while (choice != 0);
	system("pause");
}