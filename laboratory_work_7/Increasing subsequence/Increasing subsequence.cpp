#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(0, "rus");

	int countNumbers;

	while (true) {
		cout << "Введите длину последовательности: ";

		cin >> countNumbers;

		if (countNumbers <= 0) {
			cout << "\nДлинной может быть только положительное число!\n" << endl;

			cin.clear();
			cin.ignore(32767, '\n');

			continue;
		}
		else break;
	}

	vector <int> sequence(countNumbers);
	vector<int> maxLen(countNumbers);
	vector<int> next(countNumbers);

	cout << "Введите элементы последовательности:" << endl;

	while (true) {
		int i = 0;

		for (; i < countNumbers; i++) {
			cout << "Элемент #" << i + 1 << ": ";

			cin >> sequence[i];

			if (cin.get() != (int)'\n') {
				cout << "\nЭлементом этой последовательности могут быть только целые числа!\n" << endl;
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
			else continue;
		}
		if (i == countNumbers) break;
	}

	for (int i = countNumbers - 1; i >= 0; i--)
	{
		int maxNextLen = 0;
		int bestNext = -1;

		for (int j = i + 1; j < countNumbers; j++)
			if (sequence[j] > sequence[i]) {
				if (maxLen[j] > maxNextLen) {
					maxNextLen = maxLen[j];
					bestNext = j;
				}
			}

		next[i] = bestNext;
		maxLen[i] = maxNextLen + 1;
	}

	int max = 0;
	int bestStart = -1;

	for (int i = 0; i < countNumbers; i++) {
		if (maxLen[i] > max) {
			max = maxLen[i];
			bestStart = i;
		}
	}

	cout << "Максимальная длина подпоследовательности: " << max << endl;

	for (int i = bestStart; i != -1; i = next[i])
		cout << sequence[i] << " ";

	return 0;
}