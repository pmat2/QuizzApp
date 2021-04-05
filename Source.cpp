#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int numberOfOptions = 3;

struct GameData {
	string question;
	string array[numberOfOptions];
	int rightAnswerIndex;
};

void printQuestion(GameData data) {
	cout << data.question << endl;
}

void printOptions(GameData data, int numberOfOptions) {
	int i;
	for (i = 0; i < numberOfOptions; ++i) {
		cout << i+1 << ". " <<  data.array[i] << endl;
	}
}

bool checkAnswer(GameData data, int answer) {
	if (data.rightAnswerIndex == (answer - 1)) { return true; }
	return false;
}

int game(int numberOfQuestions, GameData arr[]) {
	int i, correct;
	correct = 0;
	for (i = 0; i < numberOfQuestions; ++i) {
		int answer;
		printQuestion(arr[i]);
		printOptions(arr[i], numberOfOptions);
		cin >> answer;
		if (checkAnswer(arr[i], answer)) {
			cout << "Thats correct!" << endl << endl;
			++correct;
		}
		else {
			cout << "Sorry, you are wrong." << endl << endl;
		}
	}
	return correct;
}

void resolution(int correct, int numberOfQuestions) {
	system("cls");
	if (correct == numberOfQuestions) {
		cout << "You have it all right! " << correct
			<< '\\' << numberOfQuestions << endl;
	}
	else {
		cout << "Correct answers: " << correct <<
			", incorrect: " << (numberOfQuestions - correct) << endl;
	}
}

int main() {

	// prepare game data
	const int numberOfQuestions = 5;
	GameData gameArr[numberOfQuestions];
	gameArr[0] = GameData{ "Which country is smallest?",
		{"USA","Canada","Vatican city"},
		2 };
	gameArr[1] = GameData{ "Which animal is biggest?",
		{"Elephant","Blue whale","Ant"},
		1 };
	gameArr[2] = GameData{ "How many legs does a healthy dog have?",
		{"4","3","5"},
		0 };
	gameArr[3] = GameData{ "What is the fastest animal?",
		{"Snail", "Hedgehog", "Tiger"},
		2 };
	gameArr[4] = GameData{ "What is the boiling point of water(C)?",
		{"273C", "100C", "212C"},
		1 };


	int correct = game(numberOfQuestions, gameArr);

	resolution(correct, numberOfQuestions);
	
}