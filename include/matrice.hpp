#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;


class Matrice {
private:
    vector<vector<int>> matrice;
    int w, h;

public:
    Matrice();
    Matrice(int side);
    Matrice(int w, int h);
    Matrice(const Matrice &other);
    ~Matrice();

    Matrice& operator=(const Matrice &other);
    Matrice operator+(const Matrice &other);
    Matrice operator-(const Matrice &other);

    void insertCol(int count);
    void insertRow(int count);

    void removeCol(int count);
    void removeRow(int count);

    vector<int> getCol(int index) const;
    vector<int> getRow(int index) const;

    void fill(int value);
    int at(int x, int y) const;
    int& at(int x, int y);

    int getWidth() const;
    int getHeight() const;

    void print();
};
