#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// --- Завдання 1: Рядок між ':' та ',' ---
string task1_new(string s) {
    size_t colon = s.find(':');
    if (colon == string::npos) return s;
    size_t comma = s.find(',', colon);
    if (comma == string::npos) return s.substr(colon + 1);
    return s.substr(colon + 1, comma - colon - 1);
}

void task1_inplace(string& s) {
    s = task1_new(s); // Для зручності використовуємо логіку першої функції
}

// --- Завдання 2: Видалення між першою та останньою крапками ---
string task2_new(string s) {
    size_t first = s.find('.');
    size_t last = s.rfind('.');

    if (first == string::npos) {
        // Крапок немає - видаляємо пробіли на початку
        size_t nonSpace = s.find_first_not_of(' ');
        return (nonSpace == string::npos) ? "" : s.substr(nonSpace);
    }
    if (first == last) {
        // Одна крапка - видалити все до неї
        return s.substr(first + 1);
    }
    // Дві і більше - видалити все між ними
    s.erase(first + 1, last - first - 1);
    return s;
}

void task2_inplace(string& s) {
    s = task2_new(s);
}

// --- Завдання 3: Видалити останню літеру кожного слова ---
string task3_new(string s) {
    string result = "";
    string word = "";
    for (size_t i = 0; i <= s.length(); ++i) {
        if (i < s.length() && s[i] != ' ') {
            word += s[i];
        } else {
            if (!word.empty()) {
                result += word.substr(0, word.length() - 1);
                word = "";
            }
            if (i < s.length()) result += ' ';
        }
    }
    return result;
}

void task3_inplace(string& s) {
    s = task3_new(s);
}

// --- Завдання 6: Найкоротші слова ---
void task6(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;
    size_t minLen = string::npos;

    while (ss >> word) {
        words.push_back(word);
        if (word.length() < minLen) minLen = word.length();
    }

    if (words.empty()) return;

    vector<string> shortestWords;
    for (const string& w : words) {
        if (w.length() == minLen) shortestWords.push_back(w);
    }

    cout << "а) Перше найкоротше: " << shortestWords.front() << endl;
    cout << "б) Останнє найкоротше: " << shortestWords.back() << endl;
    cout << "в) Всі найкоротші: ";
    for (const string& w : shortestWords) cout << w << " ";
    cout << endl;
}

int main() {

    int choice;
    cout << "Оберіть номер завдання (1, 2, 3, 6): ";
    cin >> choice;
    cin.ignore(); // Очищуємо буфер після введення числа

    string input;
    if (choice != 0) {
        cout << "Введіть рядок для обробки: ";
        getline(cin, input);
    }

    cout << "\n--- Результат ---" << endl;
    switch (choice) {
        case 1:
            cout << "Варіант А (новий рядок): " << task1_new(input) << endl;
            task1_inplace(input);
            cout << "Варіант Б (inplace): " << input << endl;
            break;
        case 2:
            cout << "Варіант А (новий рядок): " << task2_new(input) << endl;
            task2_inplace(input);
            cout << "Варіант Б (inplace): " << input << endl;
            break;
        case 3:
            cout << "Варіант А (новий рядок): " << task3_new(input) << endl;
            task3_inplace(input);
            cout << "Варіант Б (inplace): " << input << endl;
            break;
        case 6:
            task6(input);
            break;
        default:
            cout << "Завдання не знайдено." << endl;
    }

    return 0;
}