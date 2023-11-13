#include <iostream>
using namespace std;

int main()
{
	int level;

	cout << "Welcome user...this haunted code will spook you.\n";

	do
	{
		cout << "\nChoose a scare level (1 to 6): ";

		while (!(cin >> level))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You dare to try to break this haunted code?? How about I break you!!\n";
			cout << "\nChoose a scare level (1 to 6): ";
		}
		switch (level)
		{
		default:
			cout << "You dare to try to break this haunted code?? How about I break you!!\n";
			break;
		case 0:
			cout << "MWHAHAHA!!! I hope you had a fun time being spooked LOL. Come again soon...HEHEHE...HAHAHAHAHAHA!!\n";
			break;
		case 1:
			cout << "You feel a chill down your spine as you sense an unseen presence in the darkness...\n";
			break;
		case 2:
			cout << "The shadows seem to whisper your name, sending shivers through your entire being...\n";
			break;
		case 3:
			cout << "A ghostly figure appears for a fleeting moment, leaving you questioning your sanity...\n";
			break;
		case 4:
			cout << "Eerie footsteps echo in the distance, and the air becomes thick with an unsettling energy...\n";
			break;
		case 5:
			cout << "The room is engulfed in darkness, and unsettling whispers surround you, making your heart race...\n";
			break;
		case 6:
			cout << "You suddenly find yourself in a nightmarish dreamscape, with phantoms and specters closing in...\n";
			break;
		}

	} while (level != 0);

	return 0;
}