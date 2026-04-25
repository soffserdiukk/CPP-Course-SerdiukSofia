#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// --- Прототипи функцій ---
void task1();
void task2();
void task3();
void task4();
void task5();

int main() {

    int choice;
    cout << "Оберіть номер завдання (1-5) або 0 для виходу: ";
    if (!(cin >> choice)) return 0;

    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 0: return 0;
        default: cout << "Завдання з цим номером немає" << endl;
    }

    return 0;
}

// --- Реалізація функцій ---

void task1() {
    double x, y;
    cout << "Введіть x та y: ";
    cin >> x >> y;
    double res = pow(x, y);
    cout << fixed << setprecision(6) << "Десяткове: " << res << endl;
    cout << scientific << "Наукове: " << res << endl;
}

void task2() {
    int n;
    cout << "Введіть n: ";
    cin >> n;
    vector<unsigned long long> arr(n);
    unsigned long long sum = 0;
    cout << "Введіть " << n << " чисел (по 10 цифр):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Сума (unsigned long long): " << sum << endl;
}

void task3() {
    int n;
    cout << "Введіть n: ";
    cin >> n;
    string line(n * 7, '+');

    cout << line << endl;
    for (int i = 1; i <= n; i++) cout << setw(6) << i << " ";
    cout << endl << line << endl;

    for (int i = 1; i <= n; i++) {
        double r = sqrt(i);
        // Якщо корінь цілий — виводимо 0 знаків, інакше 2
        if (r == floor(r)) cout << setw(6) << fixed << setprecision(0) << r << " ";
        else cout << setw(6) << fixed << setprecision(2) << r << " ";
    }
    cout << endl << line << endl;
}

void task4() {
    int n;
    cout << "Введіть n: ";
    cin >> n;

    // Динамічний масив цілих чисел
    int* m = new int[n];
    cout << "Введіть " << n << " цілих чисел m_i: ";
    for (int i = 0; i < n; i++) cin >> m[i];

    // Читання дійсних чисел x_i з файлу
    ifstream inFile("input_12_4.txt");
    if (!inFile) {
        cout << "Помилка: файл input_12_4.txt не знайдено!" << endl;
        delete[] m;
        return;
    }

    vector<double> x(n);
    for (int i = 0; i < n; i++) inFile >> x[i];
    inFile.close();

    // Запис результатів x_i^m_i у файл
    ofstream outFile("output_12_4.txt");
    for (int i = 0; i < n; i++) {
        outFile << pow(x[i], m[i]) << (i == n - 1 ? "" : " ");
    }
    outFile.close();

    cout << "Успішно! Результати в output_12_4.txt" << endl;
    delete[] m;
}

void task5() {
    ifstream file("input_12_5.txt");
    if (!file) {
        cout << "Помилка: файл input_12_5.txt не знайдено!" << endl;
        return;
    }

    unsigned long long val;
    vector<double> roots;
    while (file >> val) {
        roots.push_back(sqrt((double)val));
    }
    file.close();

    cout << "Результати у зворотному порядку:" << endl;
    for (int i = roots.size() - 1; i >= 0; i--) {
        cout << fixed << setprecision(3) << roots[i] << endl;
    }
}