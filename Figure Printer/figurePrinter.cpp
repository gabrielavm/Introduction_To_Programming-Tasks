#include <iostream>
using namespace std;

int main()
{
	int const lowerBound = 1;
	int const upperBound = 9;
	int rows, i, p, j, k, l, q;

	cin >> rows;

	if (rows >= lowerBound && rows <= upperBound)
	{
		// Length centering loop
		for (p = 2; p <= (25 - ((rows * 2) - 1)) / 2; p++)
		{
			cout << endl;
		}
		// Loop for the upper part of the figure
		for (i = 1; i <= rows; i++)
		{
			// Width centering loop
			for (q = 1; q <= ((80 - (3 * rows)) / 2); q++)
			{
				cout << " ";
			}
			for (j = 1; j < i; j++)
			{
				cout << j;
			}
			for (k = i * 2; k <= rows * 3 + 1 ; k++)
			{
				cout << " ";
			}
			for (l = i - 1 ; l >= 1; l--)
			{
				cout << l;
			}
			cout << "\n";
		}
		//Loops for the middle row
		for (q = 1; q <= ((80 - (3 * rows)) / 2); q++)
		{
			cout << " ";
		}
		for (i = 1 ; i <= rows ; i++)
		{
			cout << i;
		} 
		for (k = i * 2; k <= rows * 3 + 1; k++)
		{
			cout << "-";
		}
		for (i = rows; i >= 1; i--)
		{
			cout << i;
		}
		cout << endl;

		// Loop for the bottom part of the figure
		for (i = rows; i >= 1; i--)
		{
			// Width centering loop
			for (q = 1; q <= ((80 - (3 * rows)) / 2); q++)
			{
				cout << " ";
			}
			for (j = 1; j < i; j++)
			{
				cout << j;
			}
			for (k = i * 2; k <= rows * 3 + 1 ; k++)
			{
				cout << " ";
			}
			for (l = i - 1; l >= 1; l--)
			{
				cout << l;
			}
			cout << "\n";
		}
		// Length centering loop
		for (p = 2 ; p <= (25 - ((rows * 2) - 1)) / 2; p++)
		{
			cout << endl;
		}

	}
	else
	{
		cout << "Incorrect input";
	}

	return 0;
}


