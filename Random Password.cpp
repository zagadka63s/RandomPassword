#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

// Функция для генерации случайного символа из заданного набора символов
char getRandomChar(const char* charSet, int setSize);

// Функция для генерации пароля с заданными параметрами
string generateRandomPassword(int length, bool includeDigits, bool includeSpecialChars)
{
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char specialChars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Создаем набор символов, который будет использоваться для генерации пароля
    const char* charSet = lowercase;
    int charSetSize = 26; // По умолчанию у нас только буквы

    if (includeDigits)
    {
        charSet = lowercase;
        charSetSize += 10;
    }

    if (includeSpecialChars)
    {
        charSet = lowercase;
        charSetSize += 29;
    }

    // Генерируем пароль с заданной длиной, выбирая символы из созданного набора
    string password;
    for (int i = 0; i < length; i++)
    {
        password += getRandomChar(charSet, charSetSize);
    }

    // Возвращаем сгенерированный пароль
    return password;
}

char getRandomChar(const char* charSet, int setSize)
{
    int randomIndex = rand() % setSize;
    return charSet[randomIndex];
}

int main()
{
    setlocale(LC_ALL, "russian");
    // Инициализация генератора случайных чисел на основе текущего времени
    srand(static_cast<unsigned int>(time(0)));

    int passwordLength;
    cout << "Введите длину пароля: ";
    cin >> passwordLength;

    bool includeDigits, includeSpecialChars;
    cout << "Включить цифры (1 - да, 0 - нет): ";
    cin >> includeDigits;

    cout << "Включить специальные символы (1 - да, 0 - нет): ";
    cin >> includeSpecialChars;

    string password = generateRandomPassword(passwordLength, includeDigits, includeSpecialChars);
    cout << "Сгенерированный пароль: " << password << endl;

    return 0;
}
