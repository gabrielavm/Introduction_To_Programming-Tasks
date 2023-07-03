#include <iostream>
using namespace std;

//Helper function- finding greatest common divisor of two numbers
int greatestCommonDivisor(int number1, int number2)
{
    if (number1 == 0)
    {
        return number2;
    }
    else
    {
        return GreatestCommonDivisor(number2 % number1, number1);
    }
}

//Helper function to find the smaller of two given numbers
int minElement(int number1, int number2)
{
    if (number1 > number2)
    {
        return number2;
    }
    else if (number1 < number2)
    {
        return number1;
    }
    else
    {
        return number1;
    }
}

// The general function that will count the steps that are needed to fill one
//of the basins with the given liters of water
int pouringWaterFromTo(int pouredBasin, int filledBasin, int litersOfWater)
{
    int pourFrom = pouredBasin;
    int pourInto = 0;

    int implementationSteps = 1;
    while (pourFrom != litersOfWater && pourInto != litersOfWater)
    {
        int temp = minElement(pourFrom, filledBasin - pourInto);
        pourInto += temp;
        pourFrom -= temp;
        ++implementationSteps;

        if (pourFrom == litersOfWater || pourInto == litersOfWater)
        {
            break;
        }
        if (pourFrom == 0)
        {
            pourFrom = pouredBasin;
            ++implementationSteps;
        }
        if (pourInto == filledBasin)
        {
            pourInto = 0;
            ++implementationSteps;
        }
    }
    return implementationSteps;
}

int main()
{
    const int LOWERBOUND = 1;
    const int UPPERBOUND = 20;

    int firstBasin;
    cin >> firstBasin;

    int secondBasin;
    cin >> secondBasin;

    int litersOfWater;
    cin >> litersOfWater;

    if (firstBasin >= LOWERBOUND && firstBasin <= UPPERBOUND && secondBasin >= LOWERBOUND && secondBasin <= UPPERBOUND)
    {
        if (litersOfWater > firstBasin)
        {
            cout << "-1";
        }
        else if (litersOfWater > firstBasin && litersOfWater > secondBasin)
        {
            cout << "-1";
        }
        else if ((litersOfWater % GreatestCommonDivisor(firstBasin, secondBasin)) != 0)
        {
            cout << "-1";
        }
        else
        {
            cout << minElement(pouringWaterFromTo(firstBasin, secondBasin, litersOfWater), pouringWaterFromTo(secondBasin, firstBasin, litersOfWater));
        }
    }
    else
    {
        cout << "Incorrect input";
    }

    return 0;
}
