#include <iostream>    // Input/Output operations
#include <fstream>     // File stream operations
#include <iomanip>     // Formatting output with setw, setprecision, etc.
#include <limits>      // Numeric limits for streams and other operations
#include <random>      // Random number generation facilities
#include <algorithm>   // Algorithms that operate on ranges of elements
#include <cstdlib>     // General-purpose C library functions
#include <ctime>       // Functions for working with time
#include <string>      // String manipulation functions and the string class

using namespace std;

// Constants for game guessing range
const int MIN_GUESS = 1;
const int MAX_GUESS = 10;
// Constant representing the maximum allowed credit
const double MAX_ALLOWED = 20.00;
// Constant representing the amount of credit added when credits are successfully added to the account
const double CREDIT_ADDED = 1.0;
// Constant representing the amount of credit won when the user makes a correct guess in the game
const double CREDIT_WON = 2.0;
// Constant representing the amount of credit lost when the user makes an incorrect guess in the game
const double CREDIT_LOST = 1.0;

// Function prototype declarations

void programIntro(string& playerName);
// programIntro - Ask the user for their name
// @param string& - playerName is the name of the user

void clearScreen();
// clearScreen - Clears the console screen

void displayMenu();
// displayMenu - Displays the main menu options and handles user input

void displayMainMenu();
// displayMainMenu - Displays the main menu header

int getUserChoice();
// getUserChoice - Gets the user's choice from the menu, handles user invalid input
// @return int - The user's valid choice

void handleMenuChoice(int choice, double& balance, double& amount, int& correctGuesses, int& missedGuesses, string& playerName, tm& localTime);
// handleMenuChoice - Handles the user's menu choice
// @param int - choice is the user's menu choice
// @param double& - balance is the user's account balance
// @param double& - amount is the amount to be added to the balance
// @param int& - correctGuesses is the count of correct guesses in the game
// @param int& - missedGuesses is the count of missed guesses in the game
// @param string& - playerName is the name of the user
// @param tm& - localTime is a struct representing the current local time

void displayBalance(double balance);
// displayBalance - Displays the user's available balance
// @param double - balance is the user's account balance

void addCredits(double& balance, double& amount, const double MAX_ALLOWED);
// addCredits - Adds credits to the user's account
// @param double& - balance is the user's account balance
// @param double& - amount is the amount to be added to the balance
// @param const double - MAX_ALLOWED is the maximum allowed credit

int generateRandomNumber(int min, int max);
// generateRandomNumber - Generates a random integer within a specified range
// @param int min - The minimum value (inclusive) for the generated random number
// @param int max - The maximum value (inclusive) for the generated random number
// @return int - The randomly generated number within the specified range [min, max]

void playGame(double& balance, int& correctGuesses, int& missedGuesses);
// playGame - Plays the guessing game
// @param double& - balance is the user's account balance
// @param int& - correctGuesses is the count of correct guesses in the game
// @param int& - missedGuesses is the count of missed guesses in the game

void displayGameMenu(double balance);
// displayGameMenu - Displays information for the guessing game
// @param double - balance is the user's account balance

int getUserGuess();
// getUserGuess - Gets the user's guess for the game
// @return int - The user's valid guess

void handleCorrectGuess(double& balance, int& correctGuesses);
// handleCorrectGuess - Handles correct guesses in the game
// @param double& - balance is the user's account balance
// @param int& - correctGuesses is the count of correct guesses in the game

void handleIncorrectGuess(double& balance, int& missedGuesses);
// handleIncorrectGuess - Handles incorrect guesses in the game
// @param double& - balance is the user's account balance
// @param int& - missedGuesses is the count of missed guesses in the game

void playAgainPrompt(char& playAgain);
// playAgainPrompt - Prompts the user if they want to play the game again
// @param char& - playAgain is the user's response to playing again

void displayStatistics(tm& localTime, const string& playerName, double balance, int correctGuesses, int missedGuesses);
// displayStatistics - Displays user statistics
// @param tm& - localTime is a struct representing the current local time
// @param const string& - playerName is the name of the user
// @param double - balance is the user's account balance
// @param int - correctGuesses is the count of correct guesses in the game
// @param int - missedGuesses is the count of missed guesses in the game

void saveStatistics(tm& localTime, const string& playerName, double balance, int correctGuesses, int missedGuesses);
// saveStatistics - Saves user statistics
// @param tm& - localTime is a struct representing the current local time
// @param const string& - playerName is the name of the user
// @param double - balance is the user's account balance
// @param int - correctGuesses is the count of correct guesses in the game
// @param int - missedGuesses is the count of missed guesses in the game

void returnToMainMenu();
// returnToMainMenu - Informs the user about returning to the main menu

void exitProgram();
// exitProgram - Exits the program with a farewell message

// Function for the program introduction, asking the user for their name
void programIntro(string& playerName)
{
	// Code for clearing the console screen based on the operating system
	cout << "Welcome to our program! What's your name? ";
	getline(cin, playerName);
	cout << endl;
}

// Function to attempt clearing the console screen
void clearScreen()
{
	// Code for clearing the console screen based on the operating system
#ifdef _WIN32
	// For Windows
	system("cls");
#else
	// For Unix-like systems (Linux, macOS)
	cout << "\033[2J\033[1;1H";
#endif
}

// Function to display the main menu options and handle user input
void displayMenu() {
	// Code for initializing variables, getting user input, and handling choices
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

	// Get current time
	time_t currentTime;
	time(&currentTime);
	tm localTime;

#ifdef _WIN32
	localtime_s(&localTime, &currentTime);
#else
	localtime_r(&currentTime, &localTime);
#endif

	// Main program loop
	do {
		// Display the main menu
		displayMainMenu();

		// Get the user's choice from the menu
		choice = getUserChoice();

		// If the choice is valid, handle it
		if (choice != -1) {
			handleMenuChoice(choice, balance, amount, correctGuesses, missedGuesses, playerName, localTime);
		}

	} while (choice != 6);
}

// Function to display the main menu header
void displayMainMenu() {
	// Code for displaying the main menu header
	cout << "*** C++ Primer Squad ***" << endl;
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
	// Code for getting and validating user input
	int choice;
	cout << "\nEnter your choice: ";

	// Validate user input
	if (!(cin >> choice) || cin.peek() != '\n' || choice == -1) {
		cout << "=> Error: Input is not a valid integer option.\n";
		cout << "=> Please enter a valid integer option and try again.\n" << endl;

		// Clear input buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
	}
	return choice;
}

// Function to handle the user's menu choice
void handleMenuChoice(int choice, double& balance, double& amount, int& correctGuesses, int& missedGuesses, string& playerName, tm& localTime) {
	// Code for handling different menu choices
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
		displayStatistics(localTime, playerName, balance, correctGuesses, missedGuesses);
		break;
	case 5:
		// Save user statistics to a file
		cout << "You entered 5: Save My Statistics" << endl;
		saveStatistics(localTime, playerName, balance, correctGuesses, missedGuesses);
		break;
	case 6:
		// Exit the program
		exitProgram();
		break;
	}
}

// Function to display the user's available balance
void displayBalance(double balance) {
	// Code for displaying the user's available balance
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
void addCredits(double& balance, double& amount, const double MAX_ALLOWED)
{
	// Code for adding credits to the user's account
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
		if (amount == CREDIT_ADDED || amount < 0.0 || amount < CREDIT_ADDED) {
			cout << "=> Credit added successfully. Your new balance is $" << fixed << setprecision(2) << balance << ".\n";
		}
		else {
			cout << "=> Credits added successfully. Your new balance is $" << fixed << setprecision(2) << balance << ".\n";
		}

		// Return to the main menu
		returnToMainMenu();
	}
}

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max)
{
	// Code for generating a random number
	// Random number generator setup
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribution(min, max);

	// Distribution for random number between 1 and 10
	return distribution(gen);
}


// Function to play the guessing game
void playGame(double& balance, int& correctGuesses, int& missedGuesses)
{
	// Code for the main game loop
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
		int randomNumber = generateRandomNumber(MIN_GUESS, MAX_GUESS);
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
	// Code for displaying information about the guessing game
	cout << "=> Guess a number between 1 and 10. Your available balance: $" << fixed << setprecision(2) << balance << ".\n";
}

// Function to get the user's guess for the game
int getUserGuess() {
	// Code for getting and validating the user's guess
	int userGuess;

	// Input validation loop
	while (true) {
		cout << "=> Enter your guess: ";
		cin >> userGuess;

		// Validate user input
		if (cin.fail() || cin.peek() != '\n' || userGuess < 1 || userGuess > 10) {
			cout << "=> Invalid input. Please enter a number between 1 and 10.\n";

			// Clear input buffer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break; // Break out of the loop if input is valid
		}
	}
	return userGuess;
}


// Function to handle correct guesses in the game
void handleCorrectGuess(double& balance, int& correctGuesses) {
	// Code for handling correct guesses
	// Update balance and correct guesses count
	balance += CREDIT_WON;
	correctGuesses++;
}

// Function to handle incorrect guesses in the game
void handleIncorrectGuess(double& balance, int& missedGuesses) {
	// Code for handling incorrect guesses
	// Update balance and missed guesses count
	balance -= CREDIT_LOST;
	missedGuesses++;
}

// Function to prompt the user if they want to play the game again
void playAgainPrompt(char& playAgain) {
	// Code for prompting the user to play again
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
void displayStatistics(tm& localTime, const string& playerName, double balance, int correctGuesses, int missedGuesses) {
	// Code for displaying user statistics
	cout << "-------------------------\n";

	// Display current date and time
	cout << put_time(&localTime, "%Y-%m-%d %I:%M %p") << endl;

	// Display user statistics
	cout << playerName << endl;
	cout << "Available credit: $" << fixed << setprecision(2) << balance << endl;
	cout << "Games Played: " << (correctGuesses + missedGuesses) << endl;
	cout << "Correct Guesses: " << correctGuesses << endl;
	cout << "Missed Guesses: " << missedGuesses << endl;

	// Calculate and display money won and lost
	double moneyWon = correctGuesses * 2;
	double moneyLost = missedGuesses * 1;

	cout << "Money you won: $" << fixed << setprecision(2) << moneyWon << endl;
	cout << "Money you lost: $" << fixed << setprecision(2) << moneyLost << endl;

	cout << "-------------------------\n";

	// Return to the main menu
	returnToMainMenu();
}

// Function to write user statistics to a text file
void saveStatistics(tm& localTime, const string& playerName, double balance, int correctGuesses, int missedGuesses)
{
	// Create a filename based on the user's name (without spaces)
	string FILENAME = playerName;
	FILENAME.erase(remove_if(FILENAME.begin(), FILENAME.end(), isspace), FILENAME.end());
	FILENAME += ".txt";

	// Use ofstream with automatic resource management
	ofstream outputFile(FILENAME, ios::app);

	// Check if the file is successfully opened
	if (!outputFile.is_open()) {
		cout << "Error: Could not open file for writing." << endl;
		returnToMainMenu();
		return;
	}

	// Write user statistics to the file
	outputFile << put_time(&localTime, "%Y-%m-%d %I:%M %p") << endl;
	outputFile << playerName << endl;
	outputFile << "Available credit: $" << fixed << setprecision(2) << balance << endl;
	outputFile << "Games Played: " << (correctGuesses + missedGuesses) << endl;
	outputFile << "Correct Guesses: " << correctGuesses << endl;
	outputFile << "Missed Guesses: " << missedGuesses << endl;

	// Calculate and write money won and lost
	double moneyWon = correctGuesses * 2;
	double moneyLost = missedGuesses * 1;

	outputFile << "Money you won: $" << fixed << setprecision(2) << moneyWon << endl;
	outputFile << "Money you lost: $" << fixed << setprecision(2) << moneyLost << endl;

	outputFile << endl;

	// File is automatically closed when 'outputFile' goes out of scope

	cout << "=> User statistics saved to file: " << FILENAME << endl;

	// Return to the main menu
	returnToMainMenu();
}


// Function to inform the user about returning to the main menu
void returnToMainMenu() {
	// Code for informing the user about returning to the main menu
	cout << "=> Returning to the main menu.\n" << endl;
}

// Function to exit the program with a farewell message
void exitProgram() {
	// Code for exiting the program with a farewell message
	cout << "Thank you for using our C++ Primer Squad software. Good bye!";
	exit(0);
}

// Main function to start the program
int main() {
	// Call the main menu function to start the program loop
	displayMenu();
	return 0;
}