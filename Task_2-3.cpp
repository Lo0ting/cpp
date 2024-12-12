// Завдання 1: Демонстрація значень змінних у C++
#include <iostream>
#include <string>
#include <locale>
#include <windows.h> // Додано для вирішення проблеми із символами , були закарлючки в терміналі
using namespace std;

void task1_cpp() {
    int a = 0; // Ініціалізація змінних
    float b = 0.0f;
    char c = '\0';

    cout << "Значення змінних після ініціалізації:" << endl;
    cout << "int a = " << a << endl;
    cout << "float b = " << b << endl;
    cout << "char c = '" << c << "'" << endl;
}

// Завдання 2: Введення та виведення даних для кількох користувачів у C++
void task2_cpp() {
    struct User {
        string firstName;
        string lastName;
        int age;
        bool isStudent;
    };

    int n;
    cout << "Скільки користувачів? ";
    cin >> n;

    User* users = new User[n];

    for (int i = 0; i < n; i++) {
        cout << "\nКористувач " << i + 1 << ":" << endl;
        cout << "Ім'я: ";
        cin >> users[i].firstName;
        cout << "Прізвище: ";
        cin >> users[i].lastName;
        cout << "Вік: ";
        cin >> users[i].age;
        cout << "Студент (1 - так, 0 - ні): ";
        cin >> users[i].isStudent;
    }

    cout << "\nІнформація про користувачів:" << endl;
    for (int i = 0; i < n; i++) {
        cout << users[i].firstName << " " << users[i].lastName << ", "
            << users[i].age << " років, студент: " << (users[i].isStudent ? "так" : "ні") << endl;
    }

    delete[] users;
}

int main() {
    // Встановлення української локалі для уникнення закарлючок
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251); // Встановлюємо кодування вводу
    SetConsoleOutputCP(1251); // Встановлюємо кодування виводу

    cout << "=== Завдання 1 (C++) ===" << endl;
    task1_cpp();
    cout << "\n=== Завдання 2 (C++) ===" << endl;
    task2_cpp();
    return 0;
}
