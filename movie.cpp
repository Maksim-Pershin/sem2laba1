#include "movie.h"

Movie::Movie() : duration(0) {}

string Movie::getName() const {
    return name;
}

void Movie::setName(const string& newName) {
    name = newName;
}

string Movie::getGenre() const {
    return genre;
}

void Movie::setGenre(const string& newGenre) {
    genre = newGenre;
}

int Movie::getDuration() const {
    return duration;
}

void Movie::setDuration(int newDuration) {
    duration = newDuration;
}

istream& operator>>(istream& in, Movie& arr) {
    cout << "������� �������� ������: ";
    getline(in >> ws, arr.name);
    cout << "������� ���� ������: ";
    getline(in >> ws, arr.genre);
    cout << "������� ����������������� ������: ";
    in >> arr.duration;
    return in;
}

ostream& operator<<(ostream& out, const Movie& arr) {
    out << "�������� ������: " << arr.name << "; ����: " << arr.genre << "; �����������������: " << arr.duration;
    return out;
}