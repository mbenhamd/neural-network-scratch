#include "Matrix.h"
#include <assert.h>
#include <sstream>

template <class T>
Matrix<T>::Matrix(){}

template <class T>
Matrix<T>::Matrix(int height, int width)
{
    this->height = height;
    this->width = width;
    this->array = std::vector<std::vector<double> >(height, std::vector<double>(width));
}

template <class T>
Matrix<T>::Matrix(std::vector<std::vector<double> > const &array)
{
    assert(array.size()!=0);
    this->height = array.size();
    this->width = array[0].size();
    this->array = array;
}

template <class T>
Matrix<T> Matrix<T>::multiply(double const &value)
{
	Matrix result(height, width);
    int i,j;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            result.array[i][j] = array[i][j] * value;
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::add(Matrix const &m) const
{
    assert(height==m.height && width==m.width);

    Matrix result(height, width);
    int i,j;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            result.array[i][j] = array[i][j] + m.array[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::subtract(Matrix const &m) const
{
	assert(height==m.height && width==m.width);

    Matrix result(height, width);
    int i,j;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            result.array[i][j] = array[i][j] - m.array[i][j];
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::multiply(Matrix const &m) const
{
    assert(height==m.height && width==m.width);

    Matrix<T> result(height, width);
    int i,j;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            result.array[i][j] = array[i][j] * m.array[i][j];
        }
    }
    return result;
}

template <class T>
Matrix<T> Matrix<T>::dot(Matrix const &m) const
{
    assert(width==m.height);

    int i,j,h, mwidth = m.width;
    double w=0;

    Matrix<T> result(height, mwidth);

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<mwidth ; j++)
        {
            for (h=0 ; h<width ; h++)
            {
                w += array[i][h]*m.array[h][j];
            }
            result.array[i][j] = w;
            w=0;
        }
    }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::transpose() const // ij element becomes ji element
{
    Matrix result(width, height);
    int i,j;

    for (i=0 ; i<width ; i++){
        for (j=0 ; j<height ; j++){
            result.array[i][j] = array[j][i];
        }
    }
    return result;
}


template <class T>
Matrix<T> Matrix<T>::applyFunction(double (*function)(double)) const // takes as parameter a function which prototype looks like : double function(double x)
{
    Matrix result(height, width);
    int i,j;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++){
            result.array[i][j] = (*function)(array[i][j]);
        }
    }

    return result;
}

template <class T>
int Matrix<T>::getHeight() const
{
  return this->height;
}

template <class T>
int Matrix<T>::getWidth() const
{
  return this->width;
}

template <class T>
int Matrix<T>::get(int const &h, int const &w)
{
  return this->array[h][w];
}

template <class T>
void Matrix<T>::print(std::ostream &flux) const // pretty print, taking into account the space between each element of the matrix
{
    int i,j;
    int maxLength[width] = {};
    std::stringstream ss;

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            ss << array[i][j];
            if(maxLength[j] < ss.str().size())
            {
                maxLength[j] = ss.str().size();
            }
            ss.str(std::string());
        }
    }

    for (i=0 ; i<height ; i++)
    {
        for (j=0 ; j<width ; j++)
        {
            flux << array[i][j];
            ss << array[i][j];
            for (int k=0 ; k<maxLength[j]-ss.str().size()+1 ; k++)
            {
                flux << " ";
            }
            ss.str(std::string());
        }
        flux << std::endl;
    }
}

template <class T>
void Matrix<T>::put(int const &h, int const &w, int const &v)
{
  this->array[h][w] = v;
}


template <class T>
std::ostream& operator<<(std::ostream &flux, Matrix<T> const &m)
{
    m.print(flux);
    return flux;
}
