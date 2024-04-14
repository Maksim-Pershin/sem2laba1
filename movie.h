#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Movie {
private:
    string name;
    string genre;
    int duration;

public:
    Movie();

    string getName() const;
    void setName(const string& newName);

    string getGenre() const;
    void setGenre(const string& newGenre);

    int getDuration() const;
    void setDuration(int newDuration);

    friend istream& operator>>(istream& in, Movie& arr);
    friend ostream& operator<<(ostream& out, const Movie& arr);
};