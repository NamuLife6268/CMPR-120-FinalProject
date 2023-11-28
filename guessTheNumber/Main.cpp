#include <iostream>	// Standard Input/Output operations
#include <iomanip>	// Formatting output with setw, setprecision, etc.
#include <string>	// String manipulation functions and the string class
#include <fstream>	// File stream operations
#include <cstdlib>	// General-purpose C library functions
#include <ctime>	// Functions for working with time
#include <limits>	// Numeric limits for streams and other operations
#include <random>	// Random number generation facilities

using namespace std;

// Constant representing the maximum allowed credit
const double MAX_ALLOWED = 20.00;

// Function prototype declarations
void programIntro(string& playerName);
void clearScreen();

void displayMenu();
void displayMainMenu();
int getUserChoice();
void handleMenuChoice(int choice, double& balance, double& amount, int& correctGuesses, int& missedGuesses, string& playerName);

void displayBalance(double balance);
void addCredits(double& balance, double& amount, const double MAX_ALLOWED);

void playGame(double& balance, int& correctGuesses, int& missedGuesses);
void displayGameMenu(double balance);
int getUserGuess();
void handleCorrectGuess(double& balance, int& correctGuesses);
void handleIncorrectGuess(double& balance, int& missedGuesses);
void playAgainPrompt(char& playAgain);

void displayStatistics(const string& playerName, double balance, int correctGuesses, int missedGuesses);

void returnToMainMenu();
void exitProgram();

// Function for the program introduction, asking the user for their name
void programIntro(string& playerName)
{
	cout << "Welcome to our program! What's your name? ";
	getline(cin, playerName);
	cout << endl;
}

// Function to attempt clearing the console screen
void clearScreen()
{
	cout << "\033[2J\033[1;1H";
}

// Function to display the main menu options and handle user input
void displayMenu() {
	// Initialize variables for user data and game statistics
	double balance = 0.0;
	double amount = 0.0;
	int correctGuesses = 0;
	int missedGuesses = 0;
	string playerName;

	// Call the program introduction function to get the user's name
	programIntro(playerName);

	// Attempt to clear the console screen
	clearScreen();

	// Initialize variables for random number generation
	int choice;

	// Seed the random number generator
	random_device rd;
	mt19937 gen(rd());

	// Main program loop
	do {
		// Display the main menu
		displayMainMenu();

		// Get the user's choice from the menu
		choice = getUserChoice();

		// If the choice is valid, handle it
		if (choice != -1) {
			handleMenuChoice(choice, balance, amount, correctGuesses, missedGuesses, playerName);
		}

	} while (choice != 6);
}

// Function to display the main menu header
void displayMainMenu() {
	cout << "*** C++ Primer ***" << endl;
	cout << "\n*** MAIN MENU ***" << endl;
	cout << "\nPlease select one of the following:\n" << endl;
	cout << "    1: Display my available credit" << endl;
	cout << "    2: Add credits to my account" << endl;
	cout << "    3: Play The Guessing game" << endl;
	cout << "    4: Display My Statistics" << endl;
	cout << "    5: Save My Statistics" << endl;
	cout << "    6: To exit" << endl;
}

// Function to get the user's choice from the menu, handles invalid input
int getUserChoice() {
	int choice;
	cout << "\nEnter your choice: ";

	// Validate user input
	if (!(cin >> choice) || cin.peek() != '\n' || choice == -1) {
		cout << "=> Error: Input is not a valid integer option.\n";
		cout << "=> Please enter a valid integer option and try again.\n" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
	}
	return choice;
}

// Function to handle the user's menu choice
void handleMenuChoice(int choice, double& balance, double& amount, int& correctGuesses, int& missedGuesses, string& playerName) {
	switch (choice) {
	default:
		// Invalid choice
		cout << "=> Error: Input is not a valid integer option.\n";
		cout << "=> Please enter a valid integer option and try again.\n" << endl;
		break;
	case 1:
		// Display available credit
		cout << "You entered 1: Display my available credit" << endl;
		displayBalance(balance);
		break;
	case 2:
		// Add credits to the account
		cout << "You entered 2: Add credits to my account" << endl;
		addCredits(balance, amount, MAX_ALLOWED);
		break;
	case 3:
		// Play the guessing game
		cout << "You entered 3: Play the Guessing game" << endl;
		playGame(balance, correctGuesses, missedGuesses);
		break;
	case 4:
		// Display user statistics
		cout << "You entered 4: Display My Statistics" << endl;
		displayStatistics(playerName, balance, correctGuesses, missedGuesses);
		break;
	case 5:
		// Save user statistics (not implemented in this version)
		cout << "You entered 5: Save My Statistics" << endl;
		break;
	case 6:
		// Exit the program
		exitProgram();
		break;
	}
}

// Function to display the user's available balance
void displayBalance(double balance) {
	if (balance < 0.0) {
		// Display an error for negative balance
		cout << "=> Error: Negative balance is not allowed.\n";
	}
	else {
		// Display the available balance
		cout << "=> Your available balance is: $" << fixed << setprecision(2) << balance << ".\n";
	}
	returnToMainMenu();
}

// Function to add credits to the user's account
void addCredits(double& balance, double& amount, const double MAX_ALLOWED) {
	cout << "=> Please enter the amount you would like to add: ";

	// Validate the entered amount
	if (!(cin >> amount) || amount < 0.0 || amount > MAX_ALLOWED) {
		cout << "=> Error: Maximum allowable credit is $" << fixed << setprecision(2) << MAX_ALLOWED << ".\n";
		cout << "=> Please enter a different amount and try again.\n" << endl;

		// Clear input buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	else {
		// Update the balance with the added amount
		balance += amount;

		// Display a message based on the added amount
		if (amount == 1.0 || amount < 0.0 || amount < 1.0) {
			cout << "=> Credit added successfully. Your new balance is $" << fixed << setprecision(2) << balance << ".\n";
		}
		else {
			cout << "=> Credits added successfully. Your new balance is $" << fixed << setprecision(2) << balance << ".\n";
		}

		// Return to the main menu
		returnToMainMenu();
	}
}

// Function to play the guessing game
void playGame(double& balance, int& correctGuesses, int& missedGuesses) {
	// Random number generator setup
	random_device rd;
	static mt19937 gen(rd());

	// Distribution for random number between 1 and 10
	uniform_int_distribution<int> distribution(1, 10);

	char playAgain;

	// Game loop
	do {
		// Check if the user has enough balance to play
		if (balance < 1.0) {
			cout << "=> Sorry, you don't have enough money to play the game.\n" << endl;
			break;
		}

		// Display game menu and get user's guess
		displayGameMenu(balance);
		int randomNumber = distribution(gen);
		int userGuess = getUserGuess();

		// Check if the user's guess is correct
		if (userGuess == randomNumber) {
			// Handle correct guess
			handleCorrectGuess(balance, correctGuesses);
			cout << "=> Congrats! You guessed correctly. You win $2!\n";
		}
		else {
			// Handle incorrect guess
			handleIncorrectGuess(balance, missedGuesses);
			cout << "=> Sorry, you guessed incorrectly. The correct number was: " << randomNumber << ". You lose $1.\n";
		}

		// Ask if the user wants to play again
		playAgainPrompt(playAgain);

		// If the user chooses not to play again, exit the loop
		if (playAgain == 'n' || playAgain == 'N') {
			return;
		}
	} while (true);
}

// Function to display information for the guessing game
void displayGameMenu(double balance) {
	cout << "=> Guess a number between 1 and 10. Your available balance: $" << fixed << setprecision(2) << balance << ".\n";
}

// Function to get the user's guess for the game
int getUserGuess() {
	int userGuess;

	// Input validation loop
	do {
		cout << "=> Enter your guess: ";
		cin >> userGuess;

		// Validate user input
		if (cin.fail() || cin.peek() != '\n' || userGuess < 1 || userGuess > 10) {
			cout << "=> Invalid input. Please enter a number between 1 and 10.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (userGuess < 1 || userGuess > 10);

	return userGuess;
}

// Function to handle correct guesses in the game
void handleCorrectGuess(double& balance, int& correctGuesses) {
	// Update balance and correct guesses count
	balance += 2.0;
	correctGuesses++;
}

// Function to handle incorrect guesses in the game
void handleIncorrectGuess(double& balance, int& missedGuesses) {
	// Update balance and missed guesses count
	balance -= 1.0;
	missedGuesses++;
}

// Function to prompt the user if they want to play the game again
void playAgainPrompt(char& playAgain) {
	// User input loop
	while (true) {
		cout << "=> Do you want to play again? (y/n): ";

		// Validate user input
		if (!(cin >> playAgain) || cin.peek() != '\n') {
			cout << "=> Error: Invalid input. Please enter 'y' for Yes or 'n' for No.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (playAgain == 'y' || playAgain == 'Y') {
			break;
		}
		else if (playAgain == 'n' || playAgain == 'N') {
			cout << "=> Thank you for playing our game!\n";
			// Return to the main menu
			returnToMainMenu();
			return;
		}
		else {
			cout << "=> Error: Invalid input. Please enter 'y' for Yes or 'n' for No.\n";
		}
	}
}

// Function to display user statistics
void displayStatistics(const string& playerName, double balance, int correctGuesses, int missedGuesses) {
	cout << "-------------------------\n";

	// Get current time
	time_t currentTime;
	time(&currentTime);
	tm localTime;

#ifdef _WIN32
	localtime_s(&localTime, &currentTime);
#else
	localtime_r(&currentTime, &localTime);
#endif

	// Display current date and time
	cout << put_time(&localTime, "%m-%d-%Y %I:%M:%S %p") << endl;

	// Display user statistics
	cout << playerName << endl;
	cout << "Available credit: $" << fixed << setprecision(2) << balance << endl;
	cout << "Games Played: " << (correctGuesses + missedGuesses) << endl;
	cout << "Correct Guesses: " << correctGuesses << endl;
	cout << "Missed Guesses: " << missedGuesses << endl;

	// Calculate and display money won and lost
	double moneyWon = correctGuesses * 2.0;
	double moneyLost = missedGuesses * 1.0;

	cout << "Money you won: $" << fixed << setprecision(2) << moneyWon << endl;
	cout << "Money you lost: $" << fixed << setprecision(2) << moneyLost << endl;

	cout << "-------------------------\n";

	// Return to the main menu
	returnToMainMenu();
}

// Function to inform the user about returning to the main menu
void returnToMainMenu() {
	cout << "=> Returning to the main menu.\n" << endl;
}

// Function to exit the program with a farewell message
void exitProgram() {
	cout << "Thank you for using our C++ Primer software. Have a great day!";
	exit(0);
}

// Main function to start the program
int main() {
	// Call the main menu function to start the program loop
	displayMenu();
	return 0;
}