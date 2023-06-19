#pragma once
#include <iostream>
using namespace std;
template<class NumType>
class QTrinomial {
protected:
	NumType a, x, xb, yb;
public:
	QTrinomial() :
		a(0), x(0), xb(0), yb(0) {}
	QTrinomial(NumType base_a, NumType base_x, NumType base_xb, NumType base_yb) :
		a(base_a), x(base_x), xb(base_xb), yb(base_yb) {
		if (a == 0) {
			throw invalid_argument("Коефіцієнт a не може бути рівним нулю.");
		}
	}
	NumType get_a() const {
		return a;
	}
	NumType get_x() const {
		return x;
	}
	NumType get_xb() const {
		return xb;
	}
	NumType get_yb() const {
		return yb;
	}
	double formula() const {
		return double(a) * double(x - xb) * double(x - xb) + double(yb);
	}
	void way(NumType a) const{
		if(a>0){
			cout << "Нарямок вітки вгору(+)" << endl;
		}
		else {
			cout << "Напрямок вітки вниз(-)" << endl;
		}
	}
	bool hasRealRoots() const {
		return a > 0;
	}

	bool isOnOppositeSides(const QTrinomial& other) const {
		return (x < other.x && xb > other.x) || (x > other.x && xb < other.x);
	}

	int moveVertexAndGetRoots(const QTrinomial& other) {
		this->xb = other.x;
		return hasRealRoots() ? 2 : 0;
	}

	bool isSpecial() const {
		return xb == 0 && yb == 0;
	}
	void scale(double scalar) {
		yb = static_cast<NumType>(static_cast<double>(yb) * scalar);
		xb = static_cast<NumType>(static_cast<double>(xb) * scalar);
	}
	virtual void input(istream& is) {
		is >> this->a >> this->x >> this->xb >> this->yb;
	}
	virtual void print(ostream& os) const{
		os << "Координати вершини: (" << this->xb << ", " << this->yb << ")" << endl;	
		os << "Значення за формулою: " << formula() << endl;
		way(a);
	}
};
template<class NumType>
class FSquare : public QTrinomial<NumType> {
protected:
	char unknownSymbol;
public:
	FSquare(NumType base_a, NumType base_x, NumType base_xb, NumType base_yb, char symbol) :
		unknownSymbol(symbol) {
		this->a = base_a;
		this->x = base_x;
		this->xb = base_xb;
		this->yb = 0;
		if (this->yb != 0) {
			throw invalid_argument("Коефіцієнт yb не є рівним нулю.");
		}
	}
	virtual void print(ostream& os) const {
		FSquare<NumType>::print(os);
		os << "Символ невідомого: " << this->unknownSymbol << endl;
		os << "Значення за формулою: " << this->formula() << endl;
	}
};
template<class NumType>
inline ostream& operator<<(ostream& os, const QTrinomial<NumType>& trinomial) {
	trinomial.print(os);
	return os;
}
template<class NumType>
inline ostream& operator<<(ostream& os, const FSquare<NumType>& square) {
	square.print(os);
	return os;
}