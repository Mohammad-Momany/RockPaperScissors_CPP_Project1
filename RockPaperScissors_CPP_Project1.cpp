#include <iostream>
#include <windows.h>
using namespace std;


enum enumGameOptions { Invalid = 0, Rock = 1, Scissors = 2, Paper = 3};

struct structGameResult { 
	int DrawTimes;
	int WinTimes;
	int LoseTimes;
};

string ToLowerCase(string word) {

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
		{
			word[i] = word[i] + 32;
			continue;
		}
	}

	return word;
}
int RandomNumber(int From, int To) {
	// Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int ReadFromToPositiveNumber(string Message, int From, int To) 
{
	int InputNumber = 0;
	do
	{
		cout << Message;
		cin >> InputNumber;
	} while (InputNumber < From || InputNumber > To);

	return InputNumber;
}


enumGameOptions ConvertInputToEnumGameOptions(string input) {

	input = ToLowerCase(input);


	if (input == "1" || ToLowerCase(input) == "rock") {
		return enumGameOptions::Rock;
	}
	else if (input == "2" || ToLowerCase(input) == "scissors") {
		return enumGameOptions::Scissors;
	}
	else if (input == "3" || ToLowerCase(input) == "paper") {
		return enumGameOptions::Paper;
	}
	else {
		return enumGameOptions::Invalid; 
	}

}

enumGameOptions ReadGameOptions(string Message) {

	string Option = "";
	enumGameOptions GameOption;
	do
	{
		cout << Message;
		cin >> Option;
		GameOption = ConvertInputToEnumGameOptions(Option);

	} while (GameOption == enumGameOptions::Invalid);

	return GameOption;
}


void CountGameResult(enumGameOptions UserChoose, int ComputerChoose, structGameResult &GameResult) {

	if (UserChoose == ComputerChoose)
	{
		system("Color 60");
		cout << "Draw";
		GameResult.DrawTimes++;
	}
	else if (UserChoose > ComputerChoose)
	{
		system("Color 20");
		cout << "You Win!";
		GameResult.WinTimes++;
	}
	else
	{
		system("Color 40");
		cout << "Game Over!";
		GameResult.LoseTimes++;
	}
}

structGameResult GameCompetition(int GameTimes)
{
	structGameResult GameResult;

	for (int i = 0; i < GameTimes; i++)
	{
		enumGameOptions UserChoose = ReadGameOptions("Plase Enter your choose: [1] Rock, [2] Paper, [3] Scissors\n");

		int RandomNum = RandomNumber(1, 3);

		CountGameResult(UserChoose, RandomNum, GameResult);
	}
	return GameResult;
}
int main()
{
	srand((unsigned)time(NULL));

	int GameTimes = ReadFromToPositiveNumber("Please enter the game time from 1 to 10\n", 1, 10);

	structGameResult GameResult = GameCompetition(GameTimes);

	cout << "WinTimes: " << GameResult.WinTimes << "\n";
	cout << "DrawTimes: " << GameResult.DrawTimes << "\n";
	cout << "LoseTimes: " << GameResult.LoseTimes << "\n";

}
