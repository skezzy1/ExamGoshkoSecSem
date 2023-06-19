#pragma once
#include <iostream>
using namespace std;
template<typename NumType>
class RNumber {
private:
	NumType base_x;
	NumType base_y;
	NumType base_c;
public:
	RNumber() : base_x(0), base_y(0), base_c(0) {}
	RNumber(NumType x, NumType y, NumType c) : base_x(x), base_y(y), base_c(c) {}
	NumType get_base_x() const {
		return base_x;
	}
	NumType get_base_y() const {
		return base_y;
	}
	NumType get_base_c() const {
		return base_c;
	}
	template<typename NumType>
	bool operator+(const RNumber& other) {
		return (base_x + other.base_x) && (base_y + other.base_y) && (base_c + other.base_c);
	}
	template<typename NumType>
	bool operator-(const RNumber& other) {
		return (base_x - other.base_x) && (base_y - other.base_y) && (base_c - other.base_c);
	}
	template<typename NumType>
	bool operator*(const RNumber& other) {
		return (base_x * other.base_x) && (base_y * other.base_y) && (base_c * other.base_c);
	}
	template<typename NumType>
	bool operator/(const RNumber& other) {
		return (base_x / other.base_x) && (base_y / other.base_y) && (base_c / other.base_c);
	}
	template<typename NumType>
	bool operator==(const RNumber& other) {
		return (base_x == other.base_x) && (base_y == other.base_y) && (base_c == other.base_c);
	}
	template<typename NumType>
	bool operator!=(const RNumber& other) {
		return (base_x != other.base_x) && (base_y != other.base_y) && (base_c != other.base_c);
	}
	virtual void input(istream& istr) {
		istr >> x >> y >> c;
	}
	virtual void output(ostream& ostr) const{
		ostr << "base x: " << x <<"base y: " << y << "base c: " << c;
	}
};
template<typename NumType>
class MxNumber : public RNumber<NumType> {
private:
public:

};