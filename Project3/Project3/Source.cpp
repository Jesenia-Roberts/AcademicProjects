#include "Header.h"
// Author: Jesenia Roberts
// Project 3: allows user to check for frequency of items in a list of groceries
// Due: February 19th 2023


/*
*	Reads in the .txt file and assigns them 
*   Param fileName is a string that is the name of the .txt file
*/
void Inventory::ReadFile(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	string currLine;

	if (inFile.is_open()) {
		highestItemLength = 0;

		while (inFile) {
			getline(inFile, currLine);
			//cout << currLine << '\n';
			if (itemCount.find(currLine) == itemCount.end()) {
				itemCount.emplace(currLine, 1);
			}
			else {
				itemCount[currLine]++;
			}

			if (currLine.size() > highestItemLength) {
				highestItemLength = currLine.size();
			}
		}

		ofstream outFile("frequency.dat");
		for (const auto& kv : itemCount) {
			outFile << kv.first << " " << kv.second << endl;
		}
		outFile.close();
	}
	else {
		std::cout << "Couldn't open file\n";
	}
}


/*
*	Finds the frequency of a given word
*/
void Inventory::FrequencyOfWord()
{
	cin.ignore();
	cout << "Enter an  item name: ";
	string item = "";
	getline(cin, item);
	if (itemCount.find(item) == itemCount.end()) {
		cout << item << ": 0" << endl;
	}
	else {
		cout << item << ": " << itemCount[item] << endl;
	}
}
/*
* Shows a numeric count of all items in the txt file
*/
void Inventory::FrequencyOfAllWords()
{
	for (const auto& kv : itemCount) {
		cout << kv.first << ": " << kv.second << endl;
	}
}

/*
	Prints out histogram of item frequency
*/
void Inventory::Histogram()
{
	for (const auto& kv : itemCount) {
		for (int i = 0; i < highestItemLength - kv.first.size(); ++i) {
			cout << " ";
		}
		cout << kv.first << " ";
		for (int i = 0; i < kv.second; ++i) {
			cout << "*";
		}
		cout << endl;
	}
}

/*
	Prints out menu options for user to select preferred option
*/
void Inventory::Menu()
{
	int choice = 0;

	while (choice != 4) {
		cout << "Choose an option below by pressing the corresponding number:" << endl;
		cout << "1. Search for the number of times a specific item was bought" << endl;
		cout << "2. Print how many times all items were bought" << endl;
		cout << "3. Print a histogram representing how many times all items were bought" << endl;
		cout << "4. Exit the program" << endl;

		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				FrequencyOfWord();
				break;
			case 2:
				FrequencyOfAllWords();
				break;
			case 3:
				Histogram();
				break;
		}

		cout << endl;
		if (choice != 4) {
			choice = 0;
		}
	}
}

int main()
{
	auto inventoryRequest = std::make_unique<Inventory>();
	inventoryRequest->ReadFile("CS210_Project_Three_Input_File.txt");
	inventoryRequest->Menu();
	cout << "Thank you for using this service!" << endl;
	return 0;
}