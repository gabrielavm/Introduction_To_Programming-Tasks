#include <iostream>
using namespace std;

//Char array encryption function
void encryptionByKey(char* array, char keyForEncryption)
{
	for (int i = 0; i < array[i] != '\0'; ++i)
	{
		array[i] = array[i] ^ keyForEncryption;
		cout << array[i];
	}
}
int main()
{
	char keyForEncryption;
	cin >> keyForEncryption;

	const int CHAR_ARRAY_SIZE = 1024;
	char array[CHAR_ARRAY_SIZE] = { '\0' };
	cin >> array;

	encryptionByKey(array, keyForEncryption);

	return 0;
}

