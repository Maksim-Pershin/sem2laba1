#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"

namespace MovieFunc {
    void create(Movie** arr, int* n);
    void write(Movie* arr, int n);
    void read(Movie** arr, int* n);
    void search(Movie* arr, int n);
    void add(Movie** arr, int* n);
    void remove(Movie** arr, int* n, int index);
    void edit(Movie* arr, int n);
    bool askToCreateDatabase();
}