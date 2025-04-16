#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <numeric>
using namespace std;
bool randomAlgorithm(const vector<int>& boxes) {
    unordered_set<int> found;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for (int i = 1; i <= 100; ++i) {
        found.clear();
        for (int j = 0; j < 50; ++j) {
            int boxIndex = dis(gen) - 1;
            found.insert(boxes[boxIndex]);
        }
        if (found.find(i) == found.end()) {
            return false;
        }
    }
    return true;
}

bool structuredAlgorithm(const vector<int>& boxes) {
    unordered_set<int> found;

    for (int i = 1; i <= 100; ++i) {
        found.clear();
        int currentBox = i - 1;

        for (int j = 0; j < 50; ++j) {
            found.insert(boxes[currentBox]);
            currentBox = boxes[currentBox] - 1;

            if (found.size() == 50) break;
        }

        if (found.find(i) == found.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    int rounds;
    cout << "Введите количество раундов: ";
    cin >> rounds;

    int randomSuccess = 0;
    int structuredSuccess = 0;

    for (int i = 0; i < rounds; ++i) {
        vector<int> boxes(100);
        iota(boxes.begin(), boxes.end(), 1);
        shuffle(boxes.begin(), boxes.end(), std::mt19937{ std::random_device{}() });
        if (randomAlgorithm(boxes)) {
            randomSuccess++;
        }
        if (structuredAlgorithm(boxes)) {
            structuredSuccess++;
        }
    }

    cout << "Случайным способом: " << randomSuccess << endl;
    cout << "Выбором номера в коробке: " << structuredSuccess << endl;

    return 0;
}