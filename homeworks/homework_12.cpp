#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Функція для обчислення середнього геометричного.
 * Приймає вектор дійсних чисел.
 */
double calculateGeometricMean(const vector<double>& numbers) {
    if (numbers.empty()) return 0.0;

    double product = 1.0;
    for (double val : numbers) {
        product *= val;
    }

    // Корінь ступеня n від добутку n чисел
    return pow(product, 1.0 / numbers.size());
}

int main() {

    string fileName = "input_12_15.txt";
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Помилка: Не вдалося відкрити файл " << fileName << endl;
        return 1;
    }

    vector<double> numbers;
    double temp;

    // Зчитування чисел: оператор >> автоматично ігнорує пробіли, таби та переноси рядків
    while (file >> temp) {
        numbers.push_back(temp);
    }
    file.close();

    cout << "--- Аналіз файлу " << fileName << " ---" << endl;

    if (numbers.empty()) {
        cout << "Файл порожній або не містить коректних дійсних чисел." << endl;
    } else {
        double result = calculateGeometricMean(numbers);

        cout << "Зчитано чисел: " << numbers.size() << endl;
        cout << "Середнє геометричне: " << fixed << setprecision(5) << result << endl;
    }

    return 0;
}