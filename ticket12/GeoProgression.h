#pragma once
using namespace std;
template<class NumType>
class GeoProgression {
protected:
	NumType b1;
	NumType q;
	NumType n;
public:
	GeoProgression() :
		base_x(0), base_y(0), base_z(0) {}
	GeoProgression(T first, T ratio) : b1(first), q(ratio) {
		if (b1 == 0 || q == 0 || q == 1) {
			throw invalid_argument("Invalid progression parameters");
		}
	}
	NumType get_b1() const {
		return b1;
	}
	NumType get_q() const {
		return q;
	}
	NumType get_n() const {
		return n;
	}
	double Sn() const {
		auto 
	}
	friend istream& operator>>(ostream& is, const GeoProgression<NumType>& vec) {
		is >> ;
		return is;
	}
	friend ostream& operator<<(ostream& os, const GeoProgression<NumType>& vec) {
		os <<
		return os;
	}
};