#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << " стержень" << endl;
        return;
    }
    hanoi(n - 1, from, aux, to); // на вспомогательный стержень
    cout << "Переместить диск " << n << " с " << from << " на " << to << " стержень" << endl; // Перемещаем самый большой диск на конечный стержень
    hanoi(n - 1, aux, to, from); // со вспомогательного стержня на конечный
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N, k;
    cout << "Введите количество дисков: ";
    cin >> N;
    int i;
    cout << "Введите номер начального стержня (от 1 до 3): ";
    cin >> i;
    cout << "Введите номер конечного стержня (от 1 до 3): ";
    cin >> k;
    if (i == k) {
        cout << "Башня уже находится на конечном стержне";
        return 0;
    }

    //int i = 1;           // начальный стержень
    int aux = 6 - i - k; // так как сумма всех стержней (1, 2, 3) равна 6

    hanoi(N, i, k, aux);

    cout << "Башня перемещена со стержня " << i << " на стержень" << k;
    return 0;
}