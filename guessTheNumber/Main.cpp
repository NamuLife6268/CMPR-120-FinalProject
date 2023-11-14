#include <iostream>
using namespace std;

int main()
{
	int choice;

	cout << "*** C++ Primer ***\n";

	do
	{
		cout << "\n*** MAIN MENU ***\n";
		cout << "\nPlease select one of the following:\n\n";
		cout << "    1: Display my available credit\n";
		cout << "    2: Add credits to my account\n";
		cout << "    3: Play The Guessing game\n";
		cout << "    4: Display My Statistics\n";
		cout << "    5: Save My Statistics\n";
		cout << "    6: To exit\n";
		cout << "\nEnter your choice: ";

		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice. Please try again and enter a valid option this time.\n";
		}
		else
		{
			switch (choice)
			{
			default:
				cout << "Invalid choice. Please try again and enter a valid option this time.\n";
				break;
			case 1:
				cout << "You Entered 1: Display my available credit\n";
				break;
			case 2:
				cout << "You Entered 2: Add credits to my account\n";
				break;
			case 3:
				cout << "You Entered 3: Play The Guessing game\n";
				break;
			case 4:
				cout << "You Entered 4: Display My Statistics\n";
				break;
			case 5:
				cout << "You Entered 5: Save My Statistics\n";
				break;
			case 6:
				cout << "Thank you for using C++ Primer software. Good bye!\n";
				return 0;
			}
		}
	} while (true);

	return 0;
}