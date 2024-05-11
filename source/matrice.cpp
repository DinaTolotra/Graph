#include "matrice.hpp"

Matrice::Matrice() {
    w = h = 0;
}

Matrice::Matrice(int side) {
    matrice.resize(side, v<int>(side, 0));
    this->w = this->h = side;
}

Matrice::Matrice(int w, int h) {
    matrice.resize(h, v<int>(w, 0));
    this->w = w;
    this->h = h;
}

Matrice::Matrice(const Matrice &other) {
    *this = other;
}

Matrice::~Matrice() {}

Matrice &Matrice::operator=(const Matrice &other) {
    if (this == &other)
        return *this;

    if (w < other.w) {
        this->insertCol(other.w - w);
    } else if (w > other.w) {
        this->removeCol(w - other.w);
    }

    if (h < other.h) {
        this->insertRow(other.h - h);
    } else if (h > other.h) {
        this->removeRow(h - other.h);
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            matrice[i][j] = other.at(j, i);
        }
    }

    return *this;
}

Matrice Matrice::operator+(const Matrice &other) {
    if (w != other.w || h != other.h)
        throw std::invalid_argument("Size different matrix");
    
    Matrice result(w, h);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            result.at(j, i) = this->at(j, i) + other.at(j, i);
        }
    }

    return result;
}

Matrice Matrice::operator-(const Matrice &other) {
    if (w != other.w || h != other.h)
        throw std::invalid_argument("Size different matrix");
    
    Matrice result(w, h);

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            result.at(j, i) = this->at(j, i) - other.at(j, i);
        }
    }

    return result;
}

void Matrice::insertCol(int count) {
    if (count<=0)
        return;

    w += count;
    for (v<int> row: matrice)
        row.resize(w, 0);

}

void Matrice::insertRow(int count) {
    if (count<=0)
        return;
    
    h += count;
    matrice.resize(h, v<int>(w, 0));
}

void Matrice::removeCol(int count) {
    if (count<=0)
        return;

    w -= count;
    for (v<int> row: matrice)
        row.resize(w);
}

void Matrice::removeRow(int count) {
    if (count<=0)
        return;

    h -= count;
    matrice.resize(h);
}

void Matrice::fill(int value) {
    for (auto &row: matrice) {
        for (auto &elem: row) {
            elem = value;
        }
    }
}

int Matrice::at(int x, int y) const {
    return matrice.at(y).at(x);
}

int &Matrice::at(int x, int y) {
    return matrice[y][x];
}

void Matrice::print() {
    for (v<int> &row: matrice) {
        for (int elem: row)
            std::cout << elem << ' ';
        std::cout << '\n';
    }
}
