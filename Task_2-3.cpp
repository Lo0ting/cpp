#define NOMINMAX  
// Уникнення конфлікту макросу max з std::max
#include <iostream>
#include <string>
#include <locale>
#include <windows.h> // Додано для вирішення проблеми із символами
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

// Функція для перевірки вводу цілого числа
int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Помилка вводу. Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //<-----
        }
        else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //<----- 
            return value;
        }
    }
}

// Функція для перевірки вводу логічного значення (1 або 0)
bool getValidBool(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || (value != 0 && value != 1)) {
            cout << "Помилка вводу. Введіть 1 (так) або 0 (ні)." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//<--- 
        }
        else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//<--- 
            return value;
        }
    }
}

// Завдання 2: Введення та виведення даних для кількох користувачів у C++
void task2_cpp() {
    struct User {
        string firstName;
        string lastName;
        int age;
        bool isStudent;
    };

    int n = getValidInt("Скільки користувачів? ");

    User* users = new User[n];

    for (int i = 0; i < n; i++) {
        cout << "\nКористувач " << i + 1 << ":" << endl;
        cout << "Ім'я: ";
        getline(cin, users[i].firstName);
        cout << "Прізвище: ";
        getline(cin, users[i].lastName);
        users[i].age = getValidInt("Вік: ");
        users[i].isStudent = getValidBool("Студент (1 - так, 0 - ні): ");
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
