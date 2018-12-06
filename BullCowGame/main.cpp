// # means that executes before compile time, is a pre-processor directive. It simply copies-and-pastes code just before compilation.
// Chevrons are by standard C stuff and " for custom libraries and own external files
#include <iostream>
#include <string>

// Namespace is a place where objects and properties live inside a group
using namespace std;

// Declare the function
void PrintIntro();
void PlayGame();
void PrintGuess(std::string &Guess);
string GetGuess();
bool AskToPlayAgain();

// Entry point of our application
int main() 
{

	bool KeepPlaying = true;

	do
	{
		PrintIntro();

		PlayGame();

		KeepPlaying = AskToPlayAgain();

	} while (KeepPlaying);	
		
	return 0; // exit the application

}

void PlayGame()
{
	// loop for number of turns
	constexpr int NUMBER_OF_TURNS = 5;

	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		string Guess = GetGuess();

		PrintGuess(Guess);
	}
}

void PrintGuess(string &Guess)
{
	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl << endl;
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
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl << endl;

	return;

}

// Get a guess from the player
string GetGuess() 
{
	// get a guess from the player
	string Guess = "";
	cout << "Please enter your guess: ";
	//cin >> Guess; // this does not accept spaces
	getline(cin, Guess);

	return Guess;

}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);
	
	return (tolower(Response[0]) == 'y');
}
