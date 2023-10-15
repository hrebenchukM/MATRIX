#pragma once

using namespace std;
#include <iostream>

template<class T> class Matrix
{
	T** array;
	int rows;
	int cols;
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix&);
	~Matrix();
	void Random();
	void Print();
	Matrix<T> operator+(int n);
	Matrix<T> operator+(Matrix<T>& obj);
	

};

template<class T>
inline Matrix<T>::Matrix(int rows, int cols)
{

	this->rows = rows;
	this->cols = cols;
	array = new T * [rows];

	for (int r = 0; r < rows; r++)
   {
	   array[r] = new T[cols];
   }
}
template<class T>
inline Matrix<T>::Matrix(const Matrix& obj )
{
	rows = obj.rows;
	cols = obj.cols;

	array = new T * [rows];
	for (int r = 0; r < rows; r++)
	{
		array[r] = new T[cols];
	}

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			array[r][c] = obj.array[r][c];
		}
	
	}
}




template<class T>
inline Matrix<T>::~Matrix()
{
	for (int r = 0; r < rows; r++)
	{
		delete[] array[r];
	}
	delete[] array;
}
template<class T>
inline void Matrix<T>::Random()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			array[r][c] = rand()%10;
		}
	}

}

template<class T>
inline void Matrix<T>::Print()
{

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << " [" << array[r][c] << "] ";
		}
		cout << endl;
	}
}

template<class T>
inline Matrix<T> Matrix<T>::operator+(int n)
{
	Matrix matrix(*this);
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			matrix.array[r][c] = matrix.array[r][c] + n;
		}
		
	}
	return matrix;
}


template<class T>
inline Matrix<T> Matrix<T>::operator+(Matrix<T>& obj)
{
	Matrix matrix(*this);
	if (matrix.rows == obj.rows && matrix.cols == obj.cols)
	{
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				matrix.array[r][c] = matrix.array[r][c] + obj.array[r][c];
			}

		}
	
	}
	else
	{
		cout << "Matrices have to have same sizes!!!" << endl;
	
	}
	return matrix;
}

