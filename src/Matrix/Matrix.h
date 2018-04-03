#ifndef DEF_MATRIX
#define DEF_MATRIX

#include <vector>
#include <iostream>

template <class T>
class Matrix
{
public:

    Matrix();
    Matrix(int height, int width);
    Matrix(std::vector<std::vector<double> > const &array);

    Matrix<T> multiply(double const &value); // scalar multiplication

    Matrix<T> add(Matrix<T> const &m) const; // addition
    Matrix<T> subtract(Matrix<T> const &m) const; // subtraction
    Matrix<T> multiply(Matrix<T> const &m) const; // hadamard product

    Matrix<T> dot(Matrix<T> const &m) const; // dot product
    Matrix<T> transpose() const; // transposed matrix

    int getHeight() const;
    int getWidth() const;
    int get(int const &h, int const &w);

    Matrix<T> applyFunction(double (*function)(double)) const; // to apply a function to every element of the matrix

    void print(std::ostream &flux) const; // pretty print of the matrix

    void put(int const &h, int const &w, int const &v);

private:
    std::vector<std::vector<double> > array;
    int height;
    int width;
};

template <class T>
std::ostream& operator<<(std::ostream &flux, Matrix<T> const &m); // overloading << operator to print easily

#include "Matrix.cpp"

#endif
