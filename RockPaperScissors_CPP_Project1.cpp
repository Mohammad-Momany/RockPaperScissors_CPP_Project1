#include <iostream>
#include <string>

using namespace std;


enum enumGameOptions { Invalid = 0, Rock = 1, Scissors = 2, Paper = 3};

struct structGameResult { 
	short int DrawTimes;
	short int WinTimes;
	short int LoseTimes;
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


void CountGameResult(enumGameOptions UserChoose, enumGameOptions ComputerChoose, structGameResult &GameResult) {

	bool RockWin = (UserChoose == enumGameOptions::Rock && ComputerChoose == enumGameOptions::Scissors);
	bool PaperWin = (UserChoose == enumGameOptions::Paper && ComputerChoose == enumGameOptions::Rock);
	bool ScissorsWin = (UserChoose == enumGameOptions::Scissors && ComputerChoose == enumGameOptions::Paper);

	if (UserChoose == ComputerChoose)
	{
		system("Color 60");
		cout << "Draw\n";
		GameResult.DrawTimes++;
	}
	else if ( RockWin || PaperWin || ScissorsWin)
	{
		system("Color 20");
		cout << "You Win!\n";
		GameResult.WinTimes++;
	}
	else
	{
		system("Color 40");
		cout << "You Lose!\n";
		GameResult.LoseTimes++;
	}
}

structGameResult GameCompetition(int GameTimes)
{
	structGameResult GameResult;
	GameResult.DrawTimes = 0;
	GameResult.WinTimes = 0;
	GameResult.LoseTimes = 0;

	for (int i = 0; i < GameTimes; i++)
	{
		int RandomNum = RandomNumber(1, 3);
		enumGameOptions UserChoose = ReadGameOptions("Plase Enter your choose: [1] Rock, [2] Scissors , [3] Paper\n");
		enumGameOptions ComputerChoose = ConvertInputToEnumGameOptions(to_string(RandomNum));

		cout << "Computer Choose: " << RandomNum << '\n';
		cout << "User Choose: " << UserChoose << '\n';

		CountGameResult(UserChoose, ComputerChoose, GameResult);
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
