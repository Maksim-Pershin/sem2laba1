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
            cout << "���� ��������?\n"
                << "|1. ������� ���� ������\n"
                << "|2. ����������� ���� ������\n"
                << "|3. ����� � ���� ������\n"
                << "|4. �������� ����� �����\n"
                << "|5. ������� �����\n"
                << "|6. ������������� �����\n"
                << "|7. ��������� ���������� � ����\n"
                << "|0. ����� �� ���������\n";
            cin >> key;
        }

        switch (key) {
        case 1: {
            int key2;
            cout << "�� ������:\n"
                << "|1. �������� �����\n"
                << "|2. ��������� ������������ �� �����\n";
            cin >> key2;

            if (key2 == 1) {
                MovieFunc::create(&arr, &n);
                if (!arr) {
                    cout << "ERROR" << endl;
                    stopCycle = 0;
                    break;
                }
                else {
                    cout << "������� " << n << " �������" << endl << endl;
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
                    cout << "��������� " << n << " �������" << endl << endl;
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
                cout << "������� ������ ������, ������� ������ �������: ";
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
                cout << "���������� ������������ ���������� �������." << endl;
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
                cout << "����� ������� ��������." << endl;
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