#include <iostream>
#include "movie.h"
#include "func.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Movie* arr = nullptr;
    int n = 0;

    int stopCycle = 1;
    int tempKey = 0;

    while (stopCycle) {
        int key = 0;
        key += tempKey;
        tempKey = 0;

        if (!key) {
            cout << "Ваши действия?\n"
                << "|1. Создать базу данных\n"
                << "|2. Распечатать базу данных\n"
                << "|3. Поиск в базе данных\n"
                << "|4. Добавить новый фильм\n"
                << "|5. Удалить фильм\n"
                << "|6. Редактировать фильм\n"
                << "|7. Сохранить информацию в файл\n"
                << "|0. Выйти из программы\n";
            cin >> key;
        }

        switch (key) {
        case 1: {
            int key2;
            cout << "Вы хотите:\n"
                << "|1. Написать новую\n"
                << "|2. Загрузить существующую из файла\n";
            cin >> key2;

            if (key2 == 1) {
                MovieFunc::create(&arr, &n);
                if (!arr) {
                    cout << "ERROR" << endl;
                    stopCycle = 0;
                    break;
                }
                else {
                    cout << "Найдено " << n << " фильмов" << endl << endl;
                }
            }
            else if (key2 == 2) {
                MovieFunc::read(&arr, &n);
                if (!arr) {
                    cout << "ERROR" << endl;
                    stopCycle = 0;
                    break;
                }
                else {
                    cout << "Загружено " << n << " фильмов" << endl << endl;
                }
            }
            break;
        }
        case 2:
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                for (int i = 0; i < n; i++)
                    cout << arr[i] << endl;
                cout << endl;
            }
            break;
        case 3:
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                MovieFunc::search(arr, n);
            }
            break;
        case 4:
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                MovieFunc::add(&arr, &n);
                break;
            }
        case 5:
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                int index;
                cout << "Введите индекс фильма, который хотите удалить: ";
                cin >> index;
                MovieFunc::remove(&arr, &n, index);
                break;
            }
        case 6:
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                MovieFunc::edit(arr, n);
                break;
            }
        case 7: {
            if (n == 4) {
                cout << "Достигнуто максимальное количество фильмов." << endl;
                break;
            }
            if (!arr) {
                if (!MovieFunc::askToCreateDatabase()) {
                    stopCycle = 0;
                    break;
                }
                tempKey = 1;
                break;
            }
            else {
                MovieFunc::write(arr, n);
                cout << "Фильм успешно добавлен." << endl;
            }
            break;
        }
        default:
            stopCycle = 0;
            break;
        }
    }

    delete[] arr;

    return 0;
}