#include "Matrix.h"
#include <iostream>

class A
{
	int value;
public:

	//friend ostream& operator <<(ostream& os, const A& obj);

	void SetValue(int v) {
		value= v;
	}

	int GetValue() const {
		return value;
	}


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
	A& operator-(int v)
	{
		A res;
		res.value = value - v;
		return res;
	}

	A& operator-(A v)
	{
		A res;
		res.value = value - v.value;
		return res;
	}
	A& operator*(int v)
	{
		A res;
		res.value = value * v;
		return res;
	}

	A& operator*(A v)
	{
		A res;
		res.value = value * v.value;
		return res;
	}

	A& operator/(int v)
	{
		A res;
		res.value = value /v;
		return res;
	}

};

istream& operator >>(istream& is, A& obj)
{

	int value;
	is >> value;
	obj.SetValue(value);
	return is;
}
ostream& operator <<(ostream& os, const A& obj)
{
	os << obj.GetValue();
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

	Matrix<A> matrix4 = matrix1 - matrix2;
	cout << "Matrix4 (matrix1 - matrix2):" << endl;
	matrix4.Print();


	Matrix<A> matrix5 = matrix1 - 10;
	cout << "Matrix5 (matrix1 - 10):" << endl;
	matrix5.Print();

	Matrix<A> matrix6 = matrix1 * 10;
	cout << "Matrix6 (matrix1 * 10):" << endl;
	matrix6.Print();


	Matrix<A> matrix7 = matrix1 * matrix2;
	cout << "Matrix7 (matrix1 * matrix2):" << endl;
	matrix7.Print();

	Matrix<A> matrix8 = matrix2 / 2;
	cout << "Matrix8 (matrix2 / 10):" << endl;
	matrix8.Print();


	Matrix<A> matrix9 = {//иницалайзер лист на 3
	  {1, 2, 3,4},//Иницалайзер лист 1
	  {4, 5, 6,7},//Иницалайзер лист 2
	  {7, 8, 9,9}//Иницалайзер лист 3
	};
	matrix9.Print();
	
	cout << "Count of Matrix: " << Matrix<A>::instanceCount << endl;


	/*Matrix<A> matrixx(3,3);
	matrixx.Input();
	matrixx.Print();*/
}
