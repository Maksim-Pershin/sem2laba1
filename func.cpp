#include "func.h"

namespace MovieFunc {
    void create(Movie** arr, int* n) {
        cout << "Количество записей: ";
        cin >> *n;

        if (*n <= 0) return;

        *arr = new Movie[*n];

        for (int i = 0; i < *n; i++) {
            cout << "Номер фильма " << i + 1 << ":\n";
            cin >> (*arr)[i];
        }
    }

    void write(Movie* arr, int n) {
        if (n <= 0) return;
        ofstream file("DB.txt");
        if (!file.is_open()) {
            cout << "Не удалось открыть файл." << endl;
            return;
        }

        file << n << endl;
        for (int i = 0; i < n; i++) {
            file << arr[i].getName() << " " << arr[i].getGenre() << " " << arr[i].getDuration() << endl;
        }
        file.close();
    }

    void read(Movie** arr, int* n) {
        ifstream file("DB.txt");
        if (!file.is_open()) {
            cout << "Не удалось открыть файл." << endl;
            return;
        }

        if (!(file >> *n)) {
            file.close();
            return;
        }

        *arr = new Movie[*n];
        for (int i = 0; i < *n; i++) {
            string name, genre;
            int duration;
            file >> name >> genre >> duration;
            (*arr)[i].setName(name);
            (*arr)[i].setGenre(genre);
            (*arr)[i].setDuration(duration);
        }
        file.close();
    }

    void search(Movie* arr, int n) {
        string query;
        cout << "Введите название фильма для поиска: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (arr[i].getName() == query) {
                cout << arr[i] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Фильм не найден." << endl;
        }
    }

    void add(Movie** arr, int* n) {
        *n += 1;
        Movie* newArr = new Movie[*n];

        for (int i = 0; i < *n - 1; ++i) {
            newArr[i] = (*arr)[i];
        }

        cout << "Введите информацию о новом фильме:" << endl;
        cin >> newArr[*n - 1];

        delete[] * arr;
        *arr = newArr;
    }

    void remove(Movie** arr, int* n, int index) {
        if (index < 0 || index >= *n) {
            cout << "Неверный индекс." << endl;
            return;
        }

        Movie* newArr = new Movie[*n - 1];
        int j = 0;
        for (int i = 0; i < *n; ++i) {
            if (i != index) {
                newArr[j++] = (*arr)[i];
            }
        }

        delete[] * arr;
        *arr = newArr;
        *n -= 1;
    }

    void edit(Movie* arr, int n) {
        int index;
        cout << "Введите индекс фильма, который хотите отредактировать: ";
        cin >> index;

        if (index < 0 || index >= n) {
            cout << "Неверный индекс." << endl;
            return;
        }

        cout << "Введите новую информацию о фильме:" << endl;
        cin >> arr[index];
    }

    bool askToCreateDatabase() {
        cout << "Не удалось найти базу данных. Хотите создать новую?\n"
            "|1 - Да\n"
            "|2 - Нет\n";
        int choice;
        cin >> choice;
        return (choice == 1);
    }
}