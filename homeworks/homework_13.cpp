#include <iostream>
#include <string>

using namespace std;

// Варіант 1: Функція повертає новий рядок
string shiftCipher_new(string s) {
    string result = s;
    for (int i = 0; i < result.length(); ++i) {
        char c = result[i];

        // Обробка малих літер
        if (c >= 'a' && c <= 'z') {
            if (c == 'z') result[i] = 'a';
            else result[i] = c + 1;
        }
        // Обробка великих літер
        else if (c >= 'A' && c <= 'Z') {
            if (c == 'Z') result[i] = 'A';
            else result[i] = c + 1;
        }
    }
    return result;
}

// Варіант 2: Функція змінює рядок, що є аргументом
void shiftCipher_inplace(string& s) {
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = (c == 'z') ? 'a' : c + 1;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c == 'Z') ? 'A' : c + 1;
        }
    }
}

int main() {

    string input;
    cout << "Введіть рядок (латиницею): ";
    getline(cin, input);

    cout << "\n--- Результати обробки ---" << endl;

    // Демонстрація першого варіанту
    string encrypted = shiftCipher_new(input);
    cout << "Новий рядок (версія А): " << encrypted << endl;

    // Демонстрація другого варіанту
    shiftCipher_inplace(input);
    cout << "Змінений оригінал (версія Б): " << input << endl;

    return 0;
}