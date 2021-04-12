#include <iostream>
#include <cstring>
#define N 1000

using namespace std;

/*************************************************
ПЛЮС-МИНУС. Замените в строке каждую четную цифру плюсами, 
а нечетную – минусами в количестве равном значению цифры.
*************************************************/

void enterStr(char str[]);
bool isNumber(char str[], int i);
int getSizeArray(char str[]);
void moveToLeft(char str[], int view, int i);
void completionArray(char str[], int cells, int number, int i, char element);

int main()
{
	char str[N] = " ";
	int size;

	enterStr(str);

	size = getSizeArray(str);

	for (int i = 0, number = 0; i < size; i++)
	{
		if (isNumber(str, i))
		{
			number = str[i] - '0';

			if (number % 2 != 0)
			{
				size += number - 1;
				completionArray(str, size, number, i, '-');
			}
			else if (number == 0)
			{
				size--;
				moveToLeft(str, size, i);
				i--;
			}
			else
			{
				size += number - 1;
				completionArray(str, size, number, i, '+');
			}
		}
		else {}
	}

	cout << "Ready-made matrix with pros and cons: " << endl << str;

	return 0;
}

void enterStr(char str[])
{
	cout << "Enter a string: ";

	cin.getline(str, N);
}

bool isNumber(char str[], int i)
{
	if (str[i] < '0' or str[i] > '9')
	{
		return false;
	}
	else return true;
}

int getSizeArray(char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

void moveToLeft(char str[], int size, int i)
{
	for (int k = i; k < size; k++)
	{
		str[k] = str[k + 1];
	}
	str[size] = 0;
}

void completionArray(char str[], int size, int number, int i, char element)
{
	char strHelp[N] = "";

	for (int h = 0; h <= size - 1; h++)
	{
		if (h < i)
		{
			strHelp[h] = str[h];
		}
		else if (h <= i + number - 1)
		{
			strHelp[h] = element;
		}
		else
		{
			strHelp[h] = str[i + 1];
			i++;
		}
	}

	for (int h = 0; h <= size + number - 2; h++)
	{
		str[h] = strHelp[h];
	}
}