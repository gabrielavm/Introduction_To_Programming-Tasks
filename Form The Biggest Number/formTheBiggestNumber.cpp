#include <iostream>
using namespace std;

//Helper function that swaps two numbers
void swapNumbers(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

//Helper function that finds the number of digits in a given number
int numberOfDigits(int number)
{
    int counter = 0;
    while (number != 0)
    {
        number /= 10;
        ++counter;
    }
    return counter;
}

//Helper functions that finds the first, second, third and fourth digit of a number
int firstDigit(int N)
{
    if (N >= 10)
    {
        while (N >= 10)
        {
            N /= 10;
        }
        return N;
    }
    return N;
}
int secondDigit(int N)
{
    if (numberOfDigits(N) == 2)
    {
        N %= 10;
        return N;
    }
    else if (numberOfDigits(N) == 3)
    {
        N %= 100;
        N /= 10;
        return N;
    }
    else if (numberOfDigits(N) == 4)
    {
        N %= 1000;
        N /= 100;
        return N;
    }
    else if (numberOfDigits(N) < 2)
    {
        N = 0;
        return N;
    }
    return 0;
}
int thirdDigit(int N)
{
    if (numberOfDigits(N) == 3)
    {
        N %= 10;
        return N;
    }
    else if (numberOfDigits(N) == 4)
    {
        N %= 100;
        N /= 10;
        return N;
    }
    else if (numberOfDigits(N) < 3)
    {
        N = 0;
        return N;
    }
    return 0;
}
int fourthDigit(int N)
{
    if (numberOfDigits(N) == 4)
    {
        N %= 10;
        return N;
    }
    else if (numberOfDigits(N) < 4)
    {
        N = 0;
        return N;
    }
    return 0;
}

//Helper function that checks if the elements of the array are in the given range
int checkElements(int arr[], int N, const int LOWER_BOUND, const int UPPER_BOUND)
{
    int counter = 0;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] < LOWER_BOUND || arr[i] > UPPER_BOUND)
        {
            ++counter;
        }
    }
    return counter;
}

//The general function that forms the biggest possible number formed by the elements of a given array
void formTheBiggestPossibleNumber(int arr[], int N)
{
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (firstDigit(arr[j]) == firstDigit(arr[j + 1]))
            {
                if (secondDigit(arr[j]) < secondDigit(arr[j + 1]))
                {
                    if ((secondDigit(arr[j]) < secondDigit(arr[j + 1])) && (numberOfDigits(arr[j]) > 1) && (numberOfDigits(arr[j + 1]) > 1))
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (firstDigit(arr[j]) == secondDigit(arr[j + 1]) && firstDigit(arr[j]) == thirdDigit(arr[j + 1]) && firstDigit(arr[j]) < fourthDigit(arr[j + 1]))
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (firstDigit(arr[j]) > secondDigit(arr[j + 1]))
                    {
                        continue;
                    }
                    else if ((firstDigit(arr[j]) < secondDigit(arr[j + 1])) && numberOfDigits(arr[j]) == 1)
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (firstDigit(arr[j]) == secondDigit(arr[j + 1]) && firstDigit(arr[j]) < thirdDigit(arr[j + 1]))
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (secondDigit(arr[j]) == 0 && numberOfDigits(arr[j]) != 1)
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (secondDigit(arr[j]) != 0)
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if ((firstDigit(arr[j]) == secondDigit(arr[j + 1])) && (numberOfDigits(arr[j]) == 1))
                    {
                        continue;
                    }
                }
                else if (secondDigit(arr[j]) > secondDigit(arr[j + 1]))
                {
                    if (secondDigit(arr[j]) > firstDigit(arr[j + 1]))
                    {
                        continue;
                    }
                    else if ((secondDigit(arr[j]) < firstDigit(arr[j + 1])) && numberOfDigits(arr[j + 1]) == 1)
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                    else if (secondDigit(arr[j]) == firstDigit(arr[j + 1]) && thirdDigit(arr[j]) == firstDigit(arr[j + 1]) && fourthDigit(arr[j]) > firstDigit(arr[j + 1]))
                    {
                        continue;
                    }
                    else if ((secondDigit(arr[j]) > secondDigit(arr[j + 1])) && numberOfDigits(arr[j + 1]) != 1)
                    {
                        continue;
                    }
                    else if ((secondDigit(arr[j]) == firstDigit(arr[j + 1])) && (numberOfDigits(arr[j + 1]) == 1))
                    {
                        swapNumbers(arr[j], arr[j + 1]);
                    }
                }
                else if (secondDigit(arr[j]) == secondDigit(arr[j + 1]))
                {
                    if (thirdDigit(arr[j]) < thirdDigit(arr[j + 1]))
                    {
                        if ((thirdDigit(arr[j]) < thirdDigit(arr[j + 1])) && numberOfDigits(arr[j]) > 2 && numberOfDigits(arr[j + 1] > 2))
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                        else if (secondDigit(arr[j]) == thirdDigit(arr[j + 1]) && secondDigit(arr[j]) > firstDigit(arr[j + 1]))
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                        else if ((firstDigit(arr[j]) > thirdDigit(arr[j + 1])) && (firstDigit(arr[j]) == fourthDigit(arr[j + 1])))
                        {
                            continue;
                        }
                        else if (secondDigit(arr[j]) == thirdDigit(arr[j + 1]) && secondDigit(arr[j]) < fourthDigit(arr[j + 1]))
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                        else if ((numberOfDigits(arr[j]) == 2) && thirdDigit(arr[j + 1]) > secondDigit(arr[j]))
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                        else if ((secondDigit(arr[j]) == thirdDigit(arr[j + 1])) && (numberOfDigits(arr[j]) == 2))
                        {
                            continue;
                        }
                    }
                    else if (thirdDigit(arr[j]) > thirdDigit(arr[j + 1]))
                    {
                        if ((thirdDigit(arr[j]) == secondDigit(arr[j + 1])) && (numberOfDigits(arr[j + 1]) == 2))
                        {
                            if (thirdDigit(arr[j]) > firstDigit(arr[j + 1]))
                            {
                                continue;
                            }
                            else
                            {
                                swapNumbers(arr[j], arr[j + 1]);
                            }
                        }
                        else if ((numberOfDigits(arr[j + 1]) == 1) && (firstDigit(arr[j + 1]) >= thirdDigit(arr[j])) && (secondDigit(arr[j]) < firstDigit(arr[j + 1])))
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                        else if (thirdDigit(arr[j]) < secondDigit(arr[j + 1]) && numberOfDigits(arr[j + 1]) == 2)
                        {
                            swapNumbers(arr[j], arr[j + 1]);
                        }
                    }
                    else if (thirdDigit(arr[j]) == thirdDigit(arr[j + 1]))
                    {
                        if (fourthDigit(arr[j]) < fourthDigit(arr[j + 1]))
                        {
                            if ((thirdDigit(arr[j]) == fourthDigit(arr[j + 1])) && (numberOfDigits(arr[j]) == 3) && thirdDigit(arr[j]) < firstDigit(arr[j + 1]))
                            {
                                continue;
                            }
                            if ((thirdDigit(arr[j]) == fourthDigit(arr[j + 1])) && (numberOfDigits(arr[j]) == 3) && thirdDigit(arr[j]) > firstDigit(arr[j + 1]))
                            {
                                swapNumbers(arr[j], arr[j + 1]);
                            }
                            else if (thirdDigit(arr[j]) > fourthDigit(arr[j + 1]))
                            {
                                continue;
                            }
                            else if ((thirdDigit(arr[j]) != fourthDigit(arr[j + 1])) && (numberOfDigits(arr[j]) == 2))
                            {
                                continue;
                            }
                            else
                            {
                                swapNumbers(arr[j], arr[j + 1]);
                            }
                        }
                        else if (fourthDigit(arr[j]) > fourthDigit(arr[j + 1]))
                        {
                            if ((fourthDigit(arr[j]) == thirdDigit(arr[j + 1])) && (numberOfDigits(arr[j + 1]) == 3) && fourthDigit(arr[j]) < firstDigit(arr[j + 1]))
                            {
                                swapNumbers(arr[j] , arr[j + 1]);
                            }
                            if ((fourthDigit(arr[j]) == thirdDigit(arr[j + 1])) && (numberOfDigits(arr[j + 1]) == 3) && fourthDigit(arr[j]) > firstDigit(arr[j + 1]))
                            {
                                continue;
                            }
                            else if (fourthDigit(arr[j]) < thirdDigit(arr[j + 1]))
                            {
                                swapNumbers(arr[j], arr[j + 1]);
                            }

                        }
                        else if (fourthDigit(arr[j]) == fourthDigit(arr[j + 1]))
                        {
                            continue;
                        }
                    }
                }
            }
            else if (firstDigit(arr[j]) < firstDigit(arr[j + 1]))
            {
                swapNumbers(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 9999;
    const int MIN_ARRAYSIZE = 1;
    const int MAX_ARRAYSIZE = 15;
    int array[MAX_ARRAYSIZE] = {};

    int N;
    cin >> N;

    if (N >= MIN_ARRAYSIZE && N <= MAX_ARRAYSIZE)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> array[i];
        }

        if (checkElements(array, N, LOWER_BOUND, UPPER_BOUND) == 0)
        {
            formTheBiggestPossibleNumber(array, N);

            for (int i = 0; i < N; ++i)
            {
                cout << array[i] << ' ';
            }
        }
        else
        {
            cout << "-1";
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}
