/*
Authors:
Ravi Sinha :)
Ajay Kumar :'(
Neha Shah <3
Purpose: Encryption and decryption using Hill Cipher
*/
#include <windows.h>
#pragma comment(lib, "Winmm.lib")
#include "coder.h"

int main()
{
	PlaySoundA("skyrim.wav", NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//Play Music 
	string choice;//choice
	while (1)//infinite loop
	{
		cout << "Team RAN (Ravi :) , Ajay :'( , Neha <3)" << endl << endl;
		cout << "Song: Elder Scrolls V: Skyrim Theme" << endl << endl;
		cout << "Would you like to encode or decode a phrase?" << endl << "'E' for Encoding" << endl << "'D' for Decoding" << endl << "'QQ' to Quit" << endl;
		getline(cin, choice);//get whole line
		if (choice == "E" || choice == "e")//call ENCODE
			ENCODE();
		else if (choice == "D" || choice == "d")//call DECODE
			DECODE();
		else if (choice == "QQ" || choice == "qq" || choice == "Qq" || choice == "qQ")//QUIT
		{
			cout << "Thank you for using this program!" << endl;
			system("pause");
			break;
		}
		else
			cout << "INVALID RESPONSE" << endl << endl;//if none of the others
		system("pause");
		system("CLS");//clears screen
	}
	return 0;
}
