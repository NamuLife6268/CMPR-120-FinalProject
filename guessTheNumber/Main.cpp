#include <iostream>
using namespace std;

const double MAX_ALLOWED = 20.00;

void displayMenu()
{
	cout << "*** C++ Primer ***" << endl;
	cout << "\n*** MAIN MENU ***" << endl;
	cout << "\nPlease select one of the following:\n" << endl;
	cout << "    1: Display my available credit" << endl;
	cout << "    2: Add credits to my account" << endl;
	cout << "    3: Play The Guessing game" << endl;
	cout << "    4: Display My Statistics" << endl;
	cout << "    5: Save My Statistics" << endl;
	cout << "    6: To exit" << endl;
	cout << "\nEnter your choice: ";
}

int main()
{
	double balance = 0.0;
	double amount = 0.0;
	int correctGuesses = 0;
	int missedGuesses = 0;
	string playerName;

	int choice;

	do
	{
		displayMenu();

		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please enter a valid option.\n" << endl;
		}
		else
		{
			switch (choice)
			{
			default:
				cout << "Invalid choice. Please enter a valid option.\n" << endl;
				break;
			case 1:
				cout << "You Entered 1: Display my available credit\n" << endl;
				break;
			case 2:
				cout << "You Entered 2: Add credits to my account\n" << endl;
				break;
			case 3:
				cout << "You Entered 3: Play The Guessing game\n" << endl;
				break;
			case 4:
				cout << "You Entered 4: Display My Statistics\n" << endl;
				break;
			case 5:
				cout << "You Entered 5: Save My Statistics\n" << endl;
				break;
			case 6:
				cout << "Thank you for using C++ Primer software. Good bye!" << endl;
				return 0;
			}
		}
	} while (true);

	return 0;
}