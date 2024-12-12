#include <iostream>
#include <string>
#include <locale>
#include <windows.h> // Додано для вирішення проблеми із символами
#include <cstdlib>
#include <ctime>
using namespace std;

void playGuessWordGame() {
    // Матриця слів
    static char WORDS[][5] = { { 't', 'h', 'i', '\0' }, { 'i', 's', '\0' }, { 'a', '\0' }, { 'w', 'o', 'r', 'd', '\0' } };
    const int WORD_COUNT = 4;
    const int MAX_ATTEMPTS = 5;

    // Ініціалізація випадкового вибору слова
    srand(static_cast<unsigned>(time(0)));
    int randomIndex = rand() % WORD_COUNT;
    char* selectedWord = WORDS[randomIndex];

    // Довжина вибраного слова
    int wordLength = 0;
    while (selectedWord[wordLength] != '\0') {
        wordLength++;
    }

    // Масив для відображення слова
    char displayedWord[5] = { '*', '*', '*', '*', '\0' };

    int attemptsLeft = MAX_ATTEMPTS;
    bool guessed = false;

    cout << "Гра \"Вгадай Слово\". Спробуйте вгадати слово!" << endl;
    while (attemptsLeft > 0 && !guessed) {
        // Вивід поточного стану слова
        cout << "Слово: " << displayedWord << endl;
        cout << "Залишилося спроб: " << attemptsLeft << endl;

        // Введення літери та позиції
        char letter;
        int position;
        cout << "Введіть літеру: ";
        cin >> letter;
        cout << "Введіть позицію (0 - " << wordLength - 1 << "): ";
        cin >> position;

        // Перевірка коректності введення
        if (position < 0 || position >= wordLength) {
            cout << "Некоректна позиція! Спробуйте знову." << endl;
            continue;
        }

        if (selectedWord[position] == letter) {
            displayedWord[position] = letter;
            cout << "Правильно!" << endl;
        }
        else {
            cout << "Неправильно!" << endl;
            attemptsLeft--;
        }

        // Перевірка, чи вгадане слово
        guessed = true;
        for (int i = 0; i < wordLength; i++) {
            if (displayedWord[i] == '*') {
                guessed = false;
                break;
            }
        }
    }

    if (guessed) {
        cout << "Вітаємо! Ви вгадали слово: " << displayedWord << endl;
    }
    else {
        cout << "На жаль, ви програли. Слово було: " << selectedWord << endl;
    }
}

int main() {
    // Встановлення української локалі для уникнення закарлючок
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251); // Встановлюємо кодування вводу
    SetConsoleOutputCP(1251); // Встановлюємо кодування виводу

    playGuessWordGame();
    return 0;
}
