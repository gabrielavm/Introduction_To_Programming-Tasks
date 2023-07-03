#include<iostream>
using namespace std;

/*Function to detect if a number is prime*/
bool primeNumber(long long n)
{
    if (n == 1)
        return false;

    for (long long i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/*Function to find the number of digits*/
int numberOfDigits(long long n)
{
    int num = 0;
    for (num ; n > 0; n = n / 10)
        num++;
    return num;
}

/*Function to find if the number have different digits*/
bool differentDigits(long long n, int numberOfDigits)
{
    for (long long position = 1; position < numberOfDigits; position++)
    {
        long long copyOfN = n;
        long long lastDigit = n % 10;
        for (n = n / 10; n > 0; n = n / 10)
        {
            if (lastDigit == n % 10)
                return false;
        }
        n = copyOfN / 10;
    }
    return true;
}

/*Function to print the nearest remarkable number
if there is 2 different remarkable numbers next to the given one ->
print the smaller one*/
long long remarkableNumber(long long n)
{
    bool found = false;
    for (long long i = 0; !found; i++)
    {
        if (primeNumber(n - i) == true && differentDigits(n - i, numberOfDigits(n - i)) == true)
        {
            return n - i;
            found = true;
        }
        if (primeNumber(n + i) == true && differentDigits(n + i, numberOfDigits(n + i)) == true)
        {
            return n + i;
            found = true;
        }
    }
}

int main()
{
    long long n;
    cin >> n;
    int const lowerBound = 1;
    long long const upperBound = 1000000000;

    if (n >= lowerBound && n <= upperBound)
    {
        cout << remarkableNumber(n) << endl;
    }
    else
    {
        cout << "Incorrect input";
    }
    return 0;
}

