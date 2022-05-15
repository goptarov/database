#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string userInput;
int entries = -1;
bool listNotEmpty = false;
bool edited = false;
string entryNumber;
struct entry
{
	vector<string> name;
	vector<string> age;
	vector<string> address;
}e;
string na, ag, ad;
string fieldToEdit;
string newVal;

bool isStringANumber(string str);
void main();

void addEntry()
{
	entries++;

	cout << "Name: ";
	getline(cin, na);
	e.name.push_back(na);
	cout << "Age: ";
	getline(cin, ag);
	e.age.push_back(ag);
	cout << "Address: ";
	getline(cin, ad);
	e.address.push_back(ad);
	cout << "\n";

	cout << "New entry added!\n";
	listNotEmpty = true;

	cout << "Press 'b' to go back\n";

	getline(cin, userInput);
	if (userInput == "b")
	{
		system("cls");
		main();
	}

	else
	{
		system("cls");
		cout << "Please enter a valid input.\n\n";
		addEntry();
	}
}

void editEntry()
{
	if (edited)
	{
		cout << "Type 'edit' if you want to continue editing or 'b' if you want to go back\n";
		getline(cin, userInput);
	}

	edited = false;

	if (userInput == "b")
	{
		system("cls");
		main();
	}
	else 
	{
		cout << "Which entry do you want to edit? (entry number)\n";
		getline(cin, entryNumber);
		if (!isStringANumber(entryNumber))
		{
			system("cls");
			cout << "Please enter a valid input\n\n";
			editEntry();
		}
		else
		{
			if (stoi(entryNumber) > entries + 1)
			{
				system("cls");
				cout << "There is no entry corelated with that number\n\n";
				editEntry();
			}
			cout << "Which field do you want to edit? (Name, Age, Address)\n";
			getline(cin, fieldToEdit);

			if (fieldToEdit == "Name" || fieldToEdit == "name");
			{
				system("cls");
				cout << "What should the new name be?\n";
				getline(cin, newVal);
				e.name[stoi(entryNumber) - 1] = newVal;
				cout << "Succesfully changed the name!\n\n";
				edited = true;
				cout << "Press 'b' to go back\n";
				getline(cin, userInput);
				if (userInput == "b")
				{
					system("cls");
					editEntry();
				}
			}

			if (fieldToEdit == "Age" || fieldToEdit == "age");
			{
				system("cls");
				cout << "What should the new age be?\n";
				getline(cin, newVal);
				e.age[stoi(entryNumber) - 1] = newVal;
				cout << "Succesfully changed the age!\n\n";
				edited = true;
				cout << "Press 'b' to go back\n";
				getline(cin, userInput);
				if (userInput == "b")
				{
					system("cls");
					editEntry();
				}
			}

			if (fieldToEdit == "Address" || fieldToEdit == "address")
			{
				system("cls");
				cout << "What should the new address be?\n";
				getline(cin, newVal);
				e.address[stoi(entryNumber) - 1] = newVal;
				cout << "Succesfully changed the address!\n\n";
				edited = true;
				cout << "Press 'b' to go back\n";
				getline(cin, userInput);
				if (userInput == "b")
				{
					system("cls");
					editEntry();
				}
			}
		}
	}
}

void removeEntry()
{
	cout << "Which entry do you want to remove? (entry number)\n";
	getline(cin, entryNumber);
	if (!isStringANumber(entryNumber))
	{
		system("cls");
		cout << "Please enter a valid input\n\n";
		removeEntry();
	}
	else
	{
		if (stoi(entryNumber) > entries + 1)
		{
			system("cls");
			cout << "There is no entry corelated with that number\n\n";
			removeEntry();
		}
		else
		{
			e.name.erase(e.name.begin() + stoi(entryNumber) - 1);
			e.age.erase(e.age.begin() + stoi(entryNumber) - 1);
			e.address.erase(e.address.begin() + stoi(entryNumber) - 1);
			entries--;
			cout << "\nEntry removed!\n";
		}
	}


	if (entries == -1)
		listNotEmpty = false;

	cout << "Press 'b' to go back\n";

	getline(cin, userInput);
	if (userInput == "b")
	{
		system("cls");
		main();
	}

	else
	{
		system("cls");
		cout << "Please enter a valid input.\n\n";
		removeEntry();
	}
}

void showList()
{
	if (listNotEmpty)
	{
		for (int i = 0; i <= entries; i++)
		{
			cout << "Entry[" << i + 1 << "]\n";
			cout << "    Name: " << e.name[i] << "\n";
			cout << "    Age: " << e.age[i] << "\n";
			cout << "    Address: " << e.address[i] << "\n\n";
		}
	}

	else
		cout << "List is empty!\n";

	cout << "Press 'b' to go back\n";

	getline(cin, userInput);
	if (userInput == "b")
	{
		system("cls");
		main();
	}

	else
	{
		system("cls");
		cout << "Please enter a valid input.\n\n";
		showList();
	}
}

bool isStringANumber(string str)
{
	for (int i = 0; i <= str.length() - 1; i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void main()
{
	cout << "Type 'list' to view the database entries;\n";
	cout << "Type 'add entry' to add a new entry to the database;\n";
	cout << "Type 'remove entry' to remove an entry from the database;\n";
	cout << "Type 'edit entry' to edit an entry from the database\n";
	cout << "Type 'exit' to exit the program;\n";

	getline(cin, userInput);

	if (userInput == "list")
	{
		system("cls");
		showList();
	}

	if (userInput == "add entry")
	{
		system("cls");
		addEntry();
	}

	if (userInput == "remove entry")
	{
		if (entries == -1)
		{
			system("cls");
			cout << "No database entries.\n\n";
			main();

		}
		else
		{
			system("cls");
			removeEntry();
		}
	}

	if (userInput == "edit entry")
	{
		if (entries == -1)
		{
			system("cls");
			cout << "No database entries.\n\n";
			main();
		}
		else
		{
			system("cls");
			editEntry();
		}
	}

	if (userInput == "exit")
		system("exit");

	else
	{
		system("cls");
		cout << "Please enter a valid input.\n\n";
		main();
	}

}
