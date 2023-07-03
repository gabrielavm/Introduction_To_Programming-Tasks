#include <iostream>
using namespace std;

const int ARRAYSIZE = 1024;
const int MAXSIZE = 255;

void checkStringCorrectness(char array[])
{
	int numberOfOpenScope = 0;
	int numberOfCloseScope = 0;

	for (int i = 0; i < MAXSIZE; ++i)
	{
		if (array[i] == '(')
		{
			++numberOfOpenScope;
		}

		if (array[i] == ')')
		{
			++numberOfCloseScope;
		}
	}

	if (numberOfOpenScope == numberOfCloseScope)
	{
		cout << "correct";
	}
	else
	{
		cout << "incorrect";
	}
}

int main()
{
	char array[ARRAYSIZE] = {};
	cin.getline(array, ARRAYSIZE);

	int countOfChars = 0;
	for (int j = 0; j < ARRAYSIZE; ++j)
	{
		if (array[j] != '\0')
		{
			++countOfChars;
		}
	}

	if (countOfChars <= MAXSIZE)
	{
	     checkStringCorrectness(array);
	}
	else if (countOfChars > MAXSIZE)
	{
		cout << "wrong input";
	}

	return 0;
}
