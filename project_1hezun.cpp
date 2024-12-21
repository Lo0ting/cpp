#include <iostream>  
#include <algorithm>//<==== фікс проблеми *min_element(yValues.begin() тобто потрібна бібліотека
#include <cmath>
#include <string>
#include <vector>
#include <functional>
#include <windows.h> // Для встановлення кодування

using namespace std;

// Функція для виведення графіка на основі обчислених значень
void drawGraph(vector<double> values, double minY, double maxY) {
    int width = 50;  // ширина графіка
    int height = 20; // висота графіка

    for (int y = height; y >= -height; y--) {
        for (int x = -width; x <= width; x++) {
            double normalizedY = minY + ((height - y) / (2.0 * height)) * (maxY - minY);
            if (fabs(normalizedY - values[x + width]) < (maxY - minY) / height)
                cout << "*"; // Точка функції
            else if (x == 0)
                cout << "|"; // Вертикаль
            else if (y == 0)
                cout << "-"; // Горизонталь
            else
                cout << " "; // Порожнє місце
        }
        cout << endl;
    }
}

// Основна програма
int main() {
    //кодування для української мови у Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "ukr"); // Українська локаль

    int choice;
    cout << "=== Графік функції ===\n";
    cout << "1. sin(x)\n";
    cout << "2. cos(x)\n";
    cout << "3. sqrt(abs(x))\n";
    cout << "4. pow(x, 2)\n";
    cout << "5. Введіть свою функцію: a * x + b\n";
    cout << "Виберіть функцію (1-5): ";
    cin >> choice;

    double xMin = -10, xMax = 10; // Межі значень X
    vector<double> yValues(101);  // Вектор значень Y (для 101 точки)

    double a = 0, b = 0; // Змінні для коефіцієнтів користувацької функції

    // Обчислення значень Y залежно від вибору функції
    for (int i = 0; i <= 100; i++) {
        double x = xMin + (xMax - xMin) * i / 100.0;
        switch (choice) {
        case 1:
            yValues[i] = sin(x);
            break;
        case 2:
            yValues[i] = cos(x);
            break;
        case 3:
            yValues[i] = sqrt(fabs(x));
            break;
        case 4:
            yValues[i] = pow(x, 2);
            break;
        case 5:
            // Зчитування параметрів a та b для функції a * x + b
            if (i == 0) { // Зчитати a і b лише один раз
                cout << "Введіть коефіцієнт a: ";
                cin >> a;
                cout << "Введіть коефіцієнт b: ";
                cin >> b;
            }
            yValues[i] = a * x + b; // Обчислення значення функції
            break;
        default:
            cout << "Неправильний вибір!" << endl;
            return 1;
        }
    }

    // Знаходження меж Y для правильного масштабування
    double minY = *min_element(yValues.begin(), yValues.end());
    double maxY = *max_element(yValues.begin(), yValues.end());

    // Виведення графіка
    drawGraph(yValues, minY, maxY);

    return 0;
}
