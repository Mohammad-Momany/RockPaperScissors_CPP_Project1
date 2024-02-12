#include <iostream>

using namespace std;


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

enum enumGameOptions { Invalid = 0, Rock = 1, Scissors = 2, Paper = 3};

enumGameOptions ConvertStringToEnumGameOptions(string input) {
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
string ReadString(string Message) {

	string Option = "";
	do
	{
		
		cout << Message;
		cin >> Option;

	} while (Option != "");

	return Option;
}

int RandomNumber(int From, int To) {
	// Function to generate a random number
	int randNum = 1 + rand() % (To - From + 1) + From;
	return randNum;
}

int main()
{
	int UserChoose;
	cout << ToLowerCase("MohammaD");
}
