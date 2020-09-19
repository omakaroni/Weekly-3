#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
int RandomNumber = 0;
int GuessedNumber = 0;
int TriesGuessed = 0;
std::vector<int> Highscore;
char answer;
int Dificulity = 0;
int NumberstoGuess = 0;

int main()
{
	do
	{
		std::cout << "Welcome to the Guess a number Game\n\n";
		TriesGuessed = 0;
		std::cout << "Select Dificulity level\n";
		std::cout << "1. Easy\n";
		std::cout << "2. Medium\n";
		std::cout << "3. Hard\n\n";
		std::cin >> Dificulity;

		switch (Dificulity)
		{
			case 1:
			{
				std::cout << "You selected Easy\n\n";
				NumberstoGuess = 5;
			}
			break;
			case 2:
			{
				std::cout << "You selected Medium\n\n";
				NumberstoGuess = 10;
			}
			break;
			case 3:
			{
				std::cout << "You selected Hard\n\n";
				NumberstoGuess = 30;
			}
			break;
			default:
			{
				std::cout << "You selected the secret level, SUPER HARD!\n\n";
				NumberstoGuess = 100;
			}
			break;
		}

		srand((unsigned int)time(0));
		RandomNumber = rand() % NumberstoGuess + 1;

		do
		{
			std::cout << "Enter a number between 1 and " << NumberstoGuess << " : ";
			std::cin >> GuessedNumber;
			TriesGuessed++;

			if (GuessedNumber > RandomNumber)
				std::cout << "Wrong, try a lower number\n\n";
			else if (GuessedNumber < RandomNumber)
				std::cout << "Wrong, try a higher number\n\n";
			else
				std::cout << "\nCorrect! You got it in " << TriesGuessed << " guesses!\n\n";
		} while (GuessedNumber != RandomNumber);
		if (Highscore.size() < 5)
		{
			Highscore.push_back(TriesGuessed);
			std::sort(Highscore.begin(), Highscore.end());
		}
		else
		{
			Highscore.push_back(TriesGuessed);
			std::sort(Highscore.begin(), Highscore.end());
			Highscore.resize(5);
		}

		if (Highscore[0] == TriesGuessed)
			std::cout << "Contratulation you beat the highscore\n";
		

		std::cout << "\t | | | (_) __ _| |__  ___  ___ ___  _ __ ___  ___      \n";
		std::cout << "\t | |_| | |/ _` | '_ \\/ __|/ __/ _ \\| '__/ _ \\/ __|  \n";
		std::cout << "\t |  _  | | (_| | | | \\__ \\ (_| (_) | | |  __/\\__ \\ \n";
		std::cout << "\t |_| |_|_|\\__, |_| |_|___/\\___\\___/|_|  \\___||___/  \n";
		std::cout << "\t          |___/                                        \n";
		std::cout << "\t ------------------------------------------------------------\n";
		for (int i = 0, j = 1; i < Highscore.size(); i++, j++)
		{
			std::cout << "\t" << j << ": " << Highscore[i] << " guesses"<<  std::endl;
		}
		std::cout << "\t ------------------------------------------------------------\n\n";
		

		std::cout << " Do you want to play again? (y/n)\n";
		std::cin >> answer;
		answer = std::toupper(answer);
	} while (answer == 'Y');
	return 0;
}