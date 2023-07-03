#include<iostream>
using namespace std;

void printThousands(int thousands)
{
    switch (thousands)
    {
    case 0:
        cout << "";
        break;

    case 1:
        cout << "M";
        break;

    case 2:
        cout << "MM";
        break;

    }
}
void printHundreds(int hundreds)
{
    switch (hundreds)
    {
    case 0:
        cout << "";
        break;

    case 1:
        cout << "C";
        break;

    case 2:
        cout << "CC";
        break;
    case 3:
        cout << "CCC";
        break;

    case 4:
        cout << "CD";
        break;

    case 5:
        cout << "D";
        break;

    case 6:
        cout << "DC";
        break;

    case 7:
        cout << "DCC";
        break;

    case 8:
        cout << "DCCC";
        break;

    case 9:
        cout << "CM";
        break;
    }
}

void printTens(int tens)
{
    switch (tens)
    {
    case 0:
        cout << "";
        break;

    case 1:
        cout << "X";
        break;

    case 2:
        cout << "XX";
        break;
    case 3:
        cout << "XXX";
        break;

    case 4:
        cout << "XL";
        break;

    case 5:
        cout << "L";
        break;

    case 6:
        cout << "LX";
        break;

    case 7:
        cout << "LXX";
        break;

    case 8:
        cout << "LXXX";
        break;

    case 9:
        cout << "XC";
        break;
    }
}

void printUnits(int units)
{
    switch (units)
    {
    case 0:
        cout << "";
        break;

    case 1:
        cout << "I";
        break;

    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;

    case 4:
        cout << "IV";
        break;

    case 5:
        cout << "V";
        break;

    case 6:
        cout << "VI";
        break;

    case 7:
        cout << "VII";
        break;

    case 8:
        cout << "VIII";
        break;

    case 9:
        cout << "IX";
        break;
    }
}

int main()
{
    int n;
    cin >> n;
    int const lowerBound = 1;
    int const upperBound = 2000;
    if (n >= lowerBound && n <= upperBound)
    {
        /*
        units = n % 10;
        tens = n / 10 % 10;
        hundreds = n / 100 % 10;
        thousands = n / 1000 % 10;
        */
        /*Functions calling*/
        printThousands(n / 1000);
        printHundreds(n / 100 % 10);
        printTens(n / 10 % 10);
        printUnits(n % 10);

    }
    else
    {
        cout << "Incorrect input";
    }

    return 0;
}


