#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int RandomNumber = 1 + rand() % 5;
	cout << "угадай число от 1 до 5:\n";
	int input;
	cin >> input;
		while (input != RandomNumber) {
			cout << "не угадал\n";
			cin >> input;

	}
		cout << "угадал, молодец";
		return 0;
}
