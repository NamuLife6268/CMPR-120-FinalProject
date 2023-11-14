
/*
    Cesar Ramirez

*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

const double  MAX_ALLOWED = 20;  

double amount = 0,
       balance = 0; 

int correctGuesses = 0, 
    guessess = 0;
             
string name;

int save_stats()
{
                     // TO DO 

    return 0;
}

int add_credits()
{
    // need input validation ( characters cause infinite loop )

    cout << "\n=> Please enter the amount you would like to add: ";
    cin >> amount;
    while (amount > MAX_ALLOWED || amount < 0)
    {
      cout << "Please enter a valid number\n";
      cin >> amount;
    }
   
    balance += amount;

    cout << "\n\tAdding " << amount << " to balance!\n";
    cout << "\tYour balance is now $" << balance << ".\n\n";

    return 0;
}

int menu()
{
    int exit = 0;         // Menu will repeat unti exit != 0
  
        cout << "*** Team Name ***\n\n";
    
    do
    {
        int menu;
       
        cout << "*** MAIN MENU ***\n\n";
        cout << "Please select one of the following: \n\n";
        cout << "    1: Display my available credit\n";
        cout << "    2: Add credits to my account\n";
        cout << "    3: Play The Guessing Game\n";
        cout << "    4: Display My Statistics\n";
        cout << "    5: Save My Statistics\n";
        cout << "    6: To exit\n\n";
        cin >> menu;


        switch (menu) 
        {
        case 1: cout << "\nYou entered 1: Display my available credit\n";
            break;

        case 2: cout << "\nYou entered 2: Adding credits to account\n";
                add_credits(); // executes function "int add_credits"
            break;

        case 3: cout << "\nYou entered 3: Let's play the Guessing Game\n";
            break;

        case 4: cout << "\nYou entered 4: Displaying Statistics\n";
            break;

        case 5: cout << "\nYou entered 5: Saving Statistics\n";
            break;

        case 6: cout << "\nThank you for using Team Name software!\n\n";
                exit = 1; // to exit from Menu 
            break;

        default: cout << "\nPlease enter a valid Menu Option\n\n";
            break;
        }

    } while (exit == 0); 

    return 0;
}

int main()
{
    menu();  // To Display Menu 

    return 0;
}