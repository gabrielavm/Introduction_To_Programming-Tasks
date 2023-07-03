#include <iostream>
using namespace std;

int main()
{
    //From the one-digit numbers 9 is the biggest square (3*3=9)
    //9 is the biggest one-digit number, so the biggest squared number is 81
    const short int highestDigitDegree = 9;
    int const lowerBound = 1;
    int const upperBound = 1000000;
    long N;

    cout << "Enter N: ";
    cin >> N;

    if (N >= lowerBound && N <= upperBound)
    {
        long long M = 0;
        long long newM = 0;
        long reversedN = 0;

        // Loop to reverse the given number N 
        // For example if N = 92 -> reversedN = 29
        while (N)
        {
            unsigned lastDigit = N % 10;
            (reversedN *= 10) += lastDigit;
            N /= 10;
        }

        // Now reversedN = 29, so we take the last digit from the reversedN (lastDigit = 9) 
        // after that we check if 9*9 > highestDigitDegree 
        // if it is true -> M *= 100
        // while the loop is running for the first time M = 81
        // while the loop is running for the second time M = 81 * 10 = 810 + 4 = 814
        // because 2*2 < highestDigitDegree

        while (reversedN)
        {
            unsigned int lastDigit = reversedN % 10;
            if (lastDigit * lastDigit > highestDigitDegree)
            {
                M *= 100;
            }
            else
            {
                M *= 10;
            }

            M += (lastDigit * lastDigit);
            reversedN /= 10;
        }

        // After the loop Ì = 814
        // Now we have to receive the reverced newM = 418
        while (M)
        {
            unsigned int lastDigit = M % 10;
            (newM *= 10) += lastDigit;
            M /= 10;
        }

        cout << newM + 1;

    }
    else
    {
        cout << "Incorrect input";
    }

    return 0;
}


