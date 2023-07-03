#include <iostream>
using namespace std;

//Array input function
void inputArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

//Functions that check if a number is less than 1000 , 100 , 10
bool lessThanOneThousand(int number)
{
    if (number < 1000 && number > 100)
    {
        return true;
    }
    return false;
}

bool lessThanOneHundred(int number)
{
    if (number < 100 && number > 10)
    {
        return true;
    }
    return false;
}

bool lessThanTen(int number)
{
    if (number < 10)
    {
        return true;
    }
    return false;
}

//Function that swaps numbers
void swapNumbers(int& number1, int& number2)
{
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

//Function that checks if the elements are correct
bool checkElements(int* arr , int size)
{
    for (int i = 0; i < size ; ++i)
    {
        int hours = arr[i] / 100;
        int minutes = arr[i] % 100;
        if (hours > 23 || minutes > 59)
        {
            return false;
        }
    }
    return true;
}

//Function that return the expected results
void planeFlights(int* arr1, int* arr2, int* newArray, int* counterArr, int size)
{
    //Merging two arrays into one
    int i;
    int temp;
    for (i = 0; i < size; ++i)
    {
        newArray[i] = arr1[i];
    }
    temp = i;
    for (i = 0; i < size; ++i)
    {
        newArray[temp] = arr2[i];
        ++temp;
    }

    //Arrange the elements of the new array in ascending order
    for (int k = 0; k < (size * 2) - 1; ++k)
    {
        for (int t = 0; t < (size * 2) - k - 1; ++t)
        {
            if (newArray[t] > newArray[t + 1])
            {
                swapNumbers(newArray[t], newArray[t + 1]);
            }
        }
    }

    //Loops creating the new array which elements are the count of the planes 
    int counter = 0;
    for (int l = 0; l < size * 2; ++l)
    {
        for (int i = 0; i < size; ++i)
        {
            if (newArray[l] == arr1[i])
            {
                ++counter;
                counterArr[l] = counter;
                break;
            }
            else if (newArray[l] == arr2[i])
            {
                --counter;
                counterArr[l] = counter;
                break;
            }
        }
    }

    //Loop finding the biggest element of the counter array which is actually the count of the needed fields
    int maxElement = counterArr[0];
    for (int p = 0; p < size * 2; ++p)
    {
        if (maxElement < counterArr[p])
        {
            maxElement = counterArr[p];
        }
    }
    cout << maxElement << endl;

    //Loop creating new array which collect the index of the biggest element of the counter array
    const int ARRAYSIZE = 2000;
    int indexArr[ARRAYSIZE] = {};
    int counter1 = 0;
    for (int i = 0; i < size * 2; ++i)
    {
        if (counterArr[i] == maxElement)
        {
            indexArr[i] = i;
        }
    }

    //Loop printing the busiest periods - when the count of the planes is the biggest
    for (int i = 0; i < size * 2; ++i)
    {
        if (indexArr[i] != 0)
        {
            if (lessThanOneThousand(newArray[i]) == true && lessThanOneThousand(newArray[i + 1]) == false)
            {
                cout << "0" << newArray[i] << "-" << newArray[i + 1] << endl;
            }
            else if (lessThanOneThousand(newArray[i]) == false && lessThanOneThousand(newArray[i + 1]) == true)
            {
                cout << newArray[i] << "-" << "0" << newArray[i + 1] << endl;
            }
            else if (lessThanOneThousand(newArray[i]) == true && lessThanOneThousand(newArray[i + 1]) == true)
            {
                cout << "0" << newArray[i] << "-" << "0" << newArray[i + 1] << endl;
            }
            else if (lessThanOneHundred(newArray[i]) == true && lessThanOneHundred(newArray[i + 1]) == false)
            {
                cout << "00" << newArray[i] << "-" << newArray[i + 1] << endl;
            }
            else if (lessThanOneHundred(newArray[i]) == false && lessThanOneHundred(newArray[i + 1]) == true)
            {
                cout << newArray[i] << "-" << "00" << newArray[i + 1] << endl;
            }
            else if (lessThanOneHundred(newArray[i]) == true && lessThanOneHundred(newArray[i + 1]) == true)
            {
                cout << "00" << newArray[i] << "-" << "00" << newArray[i + 1] << endl;
            }
            else if (lessThanTen(newArray[i]) == true && lessThanTen(newArray[i + 1]) == false)
            {
                cout << "000" << newArray[i] << "-" << newArray[i + 1] << endl;
            }
            else if (lessThanTen(newArray[i]) == false && lessThanTen(newArray[i + 1]) == true)
            {
                cout << newArray[i] << "-" << "000" << newArray[i + 1] << endl;
            }
            else if (lessThanTen(newArray[i]) == true && lessThanTen(newArray[i + 1]) == true)
            {
                cout << "000" << newArray[i] << "-" << "000" << newArray[i + 1] << endl;
            }
            else
            {
                cout << newArray[i] << "-" << newArray[i + 1] << endl;
            }
        }
    }
}

int main()
{
    int numberOfFlights;
    cin >> numberOfFlights;

    int* arrive = new int[numberOfFlights];
    int* takeOff = new int[numberOfFlights];
    int* newArray = new int[numberOfFlights * 2];
    int* counterArray = new int[numberOfFlights * 2];

    inputArray(arrive, numberOfFlights);
    inputArray(takeOff, numberOfFlights);

    if (checkElements(arrive, numberOfFlights) == true && checkElements(takeOff, numberOfFlights) == true)
    {
        planeFlights(arrive, takeOff, newArray, counterArray, numberOfFlights);
    }
    else
    {
        cout << "Incorrect input";
    }

    delete[] arrive;
    delete[] takeOff;
    delete[] newArray;
    delete[] counterArray;

    return 0;
}
