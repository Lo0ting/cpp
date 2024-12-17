#include <iostream>     // Для вводу та виводу
#include <vector>       // Для збереження списку точок
#include <algorithm>    // Для пошуку мінімуму та максимуму
#include <cmath>        // Для математичних операцій
#include <windows.h>    // Для налаштування кодування в Windows

using namespace std;

// Функція для побудови графіка
void drawGraph(vector<pair<double, double>> points, double xMin, double xMax, double yMin, double yMax) {
    int width = 50;  // Ширина графіка у символах
    int height = 20; // Висота графіка у символах

    for (int y = height; y >= -height; y--) {
        for (int x = -width; x <= width; x++) {
            // Нормалізуємо координати
            double scaledX = xMin + (xMax - xMin) * (x + width) / (2.0 * width);
            double scaledY = yMin + (yMax - yMin) * (height - y) / (2.0 * height);

            // Перевіряємо, чи є точка поблизу цієї позиції
            bool isPoint = false;
            for (const auto& point : points) {
                if (fabs(point.first - scaledX) < (xMax - xMin) / width &&
                    fabs(point.second - scaledY) < (yMax - yMin) / height) {
                    isPoint = true;
                    break;
                }
            }

            if (isPoint)
                cout << "*"; // Позначаємо точку
            else if (x == 0 && y == 0)
                cout << "+"; // Точка перетину осей
            else if (x == 0)
                cout << "|"; // Вертикальна вісь
            else if (y == 0)
                cout << "-"; // Горизонтальна вісь
            else
                cout << " "; // Порожнє місце
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);         // Кодування вводу Windows-1251
    SetConsoleOutputCP(1251);   // Кодування виводу Windows-1251
    setlocale(LC_ALL, "ukr");   // Українська локаль

    int n; // Кількість точок
    cout << "Введіть кількість точок для побудови графіка: ";
    cin >> n;

    vector<pair<double, double>> points; // Вектор пар (x, y)
    double x, y;

    // Введення точок користувачем
    for (int i = 0; i < n; i++) {
        cout << "Введіть координати для точки " << i + 1 << " (x y): ";
        cin >> x >> y;
        points.push_back({x, y});
    }

    // Знаходження мінімальних та максимальних значень для осей
    double xMin = points[0].first, xMax = points[0].first;
    double yMin = points[0].second, yMax = points[0].second;

    for (const auto& point : points) {
        if (point.first < xMin) xMin = point.first;
        if (point.first > xMax) xMax = point.first;
        if (point.second < yMin) yMin = point.second;
        if (point.second > yMax) yMax = point.second;
    }

    // Додаємо невеликий запас для кордонів осей
    xMin -= 1; xMax += 1;
    yMin -= 1; yMax += 1;

    // Побудова графіка
    drawGraph(points, xMin, xMax, yMin, yMax);

    return 0;
}

