#include "Matrix.h"
#include <iostream>

class A
{
	int value;
public:

	friend ostream& operator <<(ostream& os, const A& obj);

	A() {
		value = 0;
	}

	A(int v)
	{
		value = v;
	}

	A& operator=(int v)
	{
		value = v;
		return *this;
	}

	A& operator+(int v)
	{
		A res;
		res.value = value + v;
		return res;
	}

	A& operator+(A v)
	{
		A res;
		res.value = value + v.value;
		return res;
	}

};

ostream& operator<<(ostream& os, const A& obj)
{
	os << obj.value;
	return os;
}


int main()
{
	Matrix<A> matrix1(3,3);
	matrix1.Random();
	cout << "Matrix1:" << endl;
	matrix1.Print();

	Matrix<A> matrix2 = matrix1 + 10;
	cout << "Matrix2 (matrix1 + 10):" << endl;
	matrix2.Print();

	Matrix<A> matrix3 = matrix1 + matrix2;
	cout << "Matrix3 (matrix1 + matrix2):" << endl;
	matrix3.Print();



}
