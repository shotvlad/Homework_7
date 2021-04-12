#include <iostream>
#include <Windows.h>
#define WORD "UFS"
#define SIZE 3
#define QUESTION "Best Mixed Martial Arts Sports Organization"

using namespace std;

/*************************************************
ПОЛЕ ЧУДЕС. Запрограммируйте игру: открываем буквы, 
угадываем слово, в конце - шутка Якубовича.
*************************************************/
void hideScoreboard(char scoreboard[]);
void game(char scoreboard[]);
void appearance(char scoreboard[]);
bool isWordOrLetter();
void clearConsole();
char getLetter(char letter);
bool isWin(char scoreboard[]);
void enterWord(char scoreboard[]);
void enterLetter(char scoreboard[]);
void letterIsThere(char scoreboard[], char letter, int k);

int main()
{
	char scoreboard[SIZE];

	hideScoreboard(scoreboard);

	game(scoreboard);

	return 0;
}

void hideScoreboard(char scoreboard[])
{
	for (int i = 0; i < SIZE; i++)
	{
		scoreboard[i] = '*';
	}
}

void game(char scoreboard[])
{
	appearance(scoreboard);

	if (isWin(scoreboard))
	{
		clearConsole();

		cout << "You WIN!" << endl << "Guessing the letters is your thing;)" << endl;
	}
	else if (isWordOrLetter())
	{
		enterWord(scoreboard);
	}
	else
	{
		enterLetter(scoreboard);
	}
}

void enterLetter(char scoreboard[])
{
	char letter = 0;
	letter = getLetter(letter);

	int k = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (letter == WORD[i])
		{
			scoreboard[i] = letter;
			k++;
		}
		else {}
	}

	letterIsThere(scoreboard, letter, k);
}

void letterIsThere(char scoreboard[], char letter, int k)
{
	if (k == 0)
	{
		clearConsole();
		cout << "There is no such letter!Spin the bar... Oh, he's gone... Then spin as you want)" << endl;
		game(scoreboard);
	}
	else
	{
		clearConsole();
		cout << "Open the letter " << letter << endl;
		game(scoreboard);
	}
}

void enterWord(char scoreboard[])
{
	string str;
	cout << "Enter word (In large letters, otherwise the reel will spin): ";
	cin >> str;

	if (str == WORD)
	{
		clearConsole();

		cout << "You WIN!!!" << endl << "It's good that in the console." << endl <<
			"Otherwise, I would have had to persuade you to win the prize." << endl;
	}
	else
	{
		clearConsole();

		cout << "You're in luck!" << endl << "You're lucky you're not in the studio. So you would have lost!"
			<< endl << "Okay, guess again." << endl << endl;

		game(scoreboard);
	}
}

bool isWin(char scoreboard[])
{
	int win = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (scoreboard[i] != WORD[i])
		{
			win++;
		}
		else {}
	}

	if (win == 0)
	{
		return true;
	}
	else return false;
}

char getLetter(char letter)
{
	while (true) {

		cout << "Enter letter: ";
		cin >> letter;

		if (letter >= 'A' and letter <= 'Z')
		{
			return letter;
		}
		else
		{
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}

bool isWordOrLetter()
{
	char choice = 0;

	while (true) {

		cout << "Do you know the word? Ready to respond? (0 - yes, 1 - no): ";
		cin >> choice;
		
		if (choice == '0')
		{
		    return true;
		}
		else if (choice == '1')
		{
			return false;
		}
		else
		{
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}

void appearance(char scoreboard[])
{
	cout << "     Field of wonders!" << endl;
	cout << "Scoreboard: ";

	for (int i = 0; i < SIZE; i++)
	{
		cout << scoreboard[i];
	}

	cout << endl << "Question: " << QUESTION << endl << endl;
}

void clearConsole() {
	system("CLS");
}