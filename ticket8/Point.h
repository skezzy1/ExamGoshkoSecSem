#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Point {
protected:
	T base_x;
	T base_y;
public:
	Point() :
		base_x(0), base_y(0) {}
	Point(T x, T y) :
		base_x(x), base_y(y) {}
	T get_base_x() const {
		return x;
	}
	T get_base_y() const {
		return y;
	}
	double l(const Point<T>& other) const {
		return sqrt(pow(double(base_x - other.base_x, 2)) + pow(double(base_y - other.base_y, 2)));
	}
	double q(const Point<T>& other) const {
		return sqrt((base_x * base_x) + (base_y * base_y));

	}
	double corner(const Point<T>& other) const {
		return (atan(base_y / base_x));
	}
	Point<T> operator+(const Point<T>& other) {
		T sum_x = base_x + other.base_x;
		T sum_y = base_y + other.base_y;
		return Point<T>(sum_x, sum_y);
	}
	Point operator-(const Point<T>& other) {
		T minus_x = base_x - other.base_x;
		T minus_y = base_y - other.base_y;
		return Point<T>(minus_x, minus_y);
	}
	virtual void input(istream & is) {
		is >> this->base_x >> this->base_y;
	}
	virtual void print(ostream& os) {
		os << "Base x: " << this->base_x << " Base y: " << this->base_y;
		return os;
	}
};

template<class T>
class NPoint : public Point<T> {
private:
	char unknownSymbol;
public:
	NPoint(T base_x, T base_y, char symbol) :
		unknownSymbol(symbol) {
		this->x = base_x;
		this->y = base_y;
		this->unknownSymbol = symbol;
	}
	virtual void print(ostream& os) const {
		NPoint<T>::print(os);
		os << "Символ невідомого: " << this->unknownSymbol << endl;
	}
};
template<class T>
inline istream& operator>>(istream& is, Point<T>& other) {
	other.input(is);
	return is;
}

template<class T>
inline ostream& operator<<(ostream& os, const Point<T>& other) {
	other.print(os);
	return os;
}