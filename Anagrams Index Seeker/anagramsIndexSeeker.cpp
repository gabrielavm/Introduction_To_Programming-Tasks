#include <iostream>
using namespace std;

const int UPPERBOUND = 255;

void swapChars(char& number1, char& number2)
{
    char temp = number1;
    number1 = number2;
    number2 = temp;
}

//Helper function to cort char array
void bubbleSort(char* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swapChars(arr[j], arr[j + 1]);
            }
        }
    }
}

//Helper function to find the length of char array
int myStrlenOfCharArray(char* arr)
{
    int counter = 0;
    while (arr[counter] != '\0')
    {
        ++counter;
    }
    return counter;
}

int main()
{
    char* firstArray = new char[UPPERBOUND];
    char* secondArray = new char[UPPERBOUND];
    cin >> firstArray;
    cin >> secondArray;

    int sizeOfFirstArray = myStrlenOfCharArray(firstArray);
    int sizeOfSecondArray = myStrlenOfCharArray(secondArray);

    char* checkAnagrams = new char[sizeOfSecondArray];
    int* indexHolder = new int[sizeOfFirstArray];

    int indexCounter = 0;
    int countOfRepetitions = 0;

    bubbleSort(secondArray, sizeOfSecondArray);

    int countOfIndexValues = 0;
    for (int i = 0; i < sizeOfFirstArray; ++i)
    {
        for (int j = 0; j < sizeOfSecondArray; ++j)
        {
            checkAnagrams[j] = firstArray[indexCounter];
            ++indexCounter;
        }

        bubbleSort(checkAnagrams, sizeOfSecondArray);

        for (int k = 0; k < sizeOfSecondArray; ++k)
        {
            if (secondArray[k] == checkAnagrams[k])
            {
                ++countOfRepetitions;
                continue;
            }
        }

        if (countOfRepetitions == sizeOfSecondArray)
        {
            indexHolder[countOfIndexValues] = indexCounter - sizeOfSecondArray;
            ++countOfIndexValues;
        }
        countOfRepetitions = 0;
        --indexCounter;
    }

    if (countOfIndexValues != 0)
    {
        for (int i = 0; i < countOfIndexValues; ++i)
        {
            cout << indexHolder[i];

            if (i == countOfIndexValues - 1)
            {
                break;
            }
            cout << ", ";
        }
    }
    else
    {
        cout << '"' << "no anagrams" << '"';
    }

    delete[] firstArray;
    delete[] secondArray;
    delete[] checkAnagrams;
    delete[] indexHolder;

    return 0;
}
