
#include <iostream>    
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ofstream outfile;
	outfile.open("meFile.txt");
	int number;
	double balence = 0;
	double amount;
	double notanswer;
	int correctGuess = 0;
	int missedGuess = 0;
	int games = 0;
	do
	{
		int random = rand() % 10 + 1;


		cout << "\n***teamname***";
		cout << endl;

		cout << "\n***Main Menu***\n";

		cout << endl;


		cout << "1: Display My available credits\n";

		cout << "2: Add Credits to my account\n";

		cout << "3: Play the guessing game\n";

		cout << "4: Display My statistics\n";

		cout << "5: Save my statistics\n";

		cout << "6: To Exit\n";

		cout << "\n(Please do not use any decimal numbers here)";
		cout << "\nPlease Select one of the following:";
		cin >> number;


		switch (number)
		{
		case 1:
			cout << "\nYou Entered 1: Display My available credits\n";
			cout << "\nYour available balcence is: $" << balence << "\n\n";
			break;

		case 2:
			cout << "\nYou Entered 2: Add Credits to my account\n";
			cout << "\nPlease enter the amount you would like to add: ";
			cin >> amount;
			balence = balence + amount;
			if (balence > 20.00)
			{
				cout << "\nError: Maximum allowable credit is $20.00 \nPlease enter a different amount and try again";
				balence = balence - amount;
			}
			break;
		case 3:
			cout << "\nYou Entered 3: Play the guessing game\n";
			cout << "\nGuess a number between 1 and 10: ";

			cin >> notanswer;
			if (notanswer <= 0 || notanswer >= 11)
			{
				cout << "\n\nYou typed a number not in between 1-10\n\n";
			}
			else
			{
				if (balence < 1)
				{
					cout << "\n\nyou do not have enough in balence to play the game\n\n";
				}
				else if (balence >= 1)
				{
					if (notanswer == random)
					{
						cout << "\n\nyou guess correctly\nyou gained $2\n";
						balence = balence + 2;
						correctGuess++;

					}
					else if (notanswer != random)
					{
						cout << "\n\nyou guessed wrong\nYou lost 1$\n";
						balence = balence - 1;
						missedGuess++;
					}
					games++;
				}
			}
			break;
		case 4:
			cout << "\nYou Entered 4: Display My statistics\n";
			cout << __DATE__ << endl;
			cout << __TIME__ << endl;
			cout << "wrongly guessed=" << missedGuess << endl;
			cout << "correctly guessed=" << correctGuess << endl;
			cout << "games played=" << games << endl;
			cout << "amount lost= $" << missedGuess << endl;
			cout << "amount won= $" << correctGuess * 2 << endl;
			break;
		case 5:



			cout << "\nYou Entered 5: Save my statistics\n" << endl;
			outfile << __DATE__ << endl;
			outfile << __TIME__ << endl;
			outfile << "Balence Left= $" << balence << endl;
			outfile << "wrongly guessed=" << missedGuess << endl;
			outfile << "correctly guessed=" << correctGuess << endl;
			outfile << "games played=" << games << endl;
			outfile << "amount lost= $" << missedGuess << endl;
			outfile << "amount won= $" << correctGuess * 2 << endl;
			outfile.close();
			break;
		case 6:
			cout << "Thank You for using _____  software. Goodbye!";
			break;
		default:
			cout << "you entered a number not in the scope\n";


		}
	} while (number != 6);
	return 0;
}