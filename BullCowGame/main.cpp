// # means that executes before compile time, is a pre-processor directive. It simply copies-and-pastes code just before compilation.
// Chevrons are by standard C stuff and " for custom libraries and own external files
#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Namespace is a place where objects and properties live inside a group
//using namespace std;

// Declare the function
void PrintIntro();
void PlayGame();
void PrintGuess(std::string &Guess);
std::string GetGuess();
bool AskToPlayAgain();

// initialize a game
FBullCowGame BCGame; // Instantiate a new FBullCowGame object

// Entry point of our application
int main() 
{

	// verify bool expresion
	// std::cout << std::boolalpha << (((true || false) && true) || false);

	bool bKeepPlaying = false;

	do
	{
		PrintIntro();

		PlayGame();

		// TODO: Add a game summary

		bKeepPlaying = AskToPlayAgain();

	} while (bKeepPlaying);
		
	return 0; // exit the application

}

void PlayGame()
{
		
	BCGame.Reset();

	//std::cout << "Number of tries now: " << BCGame.GetMaxTries();

	int MaxTries = BCGame.GetMaxTries();
		
	// loop for number of turns
	//constexpr int NUMBER_OF_TURNS = 5;

	// TODO: change from FOR to WHILE loop once we are validating rules
	for (int i = 1; i <= MaxTries; i++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid
				
		PrintGuess(Guess);

		// TODO increment the number of tries if it is not the correct answer
		// Submit valid guess to the game
		// Print number of bulls and cows

		// TODO break the loop once the input is the correct answer

	}
}

void PrintGuess(std::string &Guess)
{
	// repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;

	// TODO summarize game

}


// Print the advice to the player
void PrintIntro()
{
	// this can be evaluated right now, at compile time
	// is a strong form of constant and can keep you out of trouble
	constexpr int WORD_LENGTH = 5;

	// Before export namespace
	// std::cout << "Welcome to Bulls and Cows" << std::endl;

	// introduce the game
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;

}

// Get a guess from the player
std::string GetGuess() 
{

	int CurrentTry = BCGame.GetCurrentTry();
	
	// get a guess from the player
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Please enter your guess: ";
	//cin >> Guess; // this does not accept spaces
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	
	return (tolower(Response[0]) == 'y');
}
