#pragma once

using namespace std;

template <typename NumType>
class QPyramid {
protected:
	NumType base_a;
	NumType base_b;
	NumType height;

public:
	QPyramid() :
		base_a(0), base_b(0), height(0) {}

	QPyramid(NumType a, NumType b, NumType height) :
		base_a(a), base_b(b), height(height) {}

	NumType get_base_a() const {
		return base_a;
	}

	NumType get_base_b() const {
		return base_b;
	}

	NumType get_height() const {
		return height;
	}

	double base_area() {
		return double(base_a) * double(base_b);
	}

	double volume() const {
		return (1.0 / 3.0) * double(base_a) * double(base_b) * double(height);
	}

	void scale(double scalar) {
		base_a = double(base_a) * scalar;
		base_b = double(base_b) * scalar;
		height = double(height) * scalar;
	}

	bool operator<(const QPyramid& other) const {
		return (this->volume() < other.volume());
	}

	bool operator>(const QPyramid& other) const {
		return (this->volume() > other.volume());
	}

	bool operator==(const QPyramid& other) const {
		return (this->volume() == other.volume());
	}

	bool operator!=(const QPyramid& other) const {
		return (this->volume() != other.volume());
	}

	virtual void input(istream& istr) {
		istr >> base_a >> base_b >> height;
	}

	virtual void print(ostream& ostr) const {
		ostr << "side_a = " << base_a << " side_b = " << base_b << " height = " << height;
	}
};
template <typename NumType>
class RQPyramid : public QPyramid<NumType> {
public:
	RQPyramid(NumType base_side, NumType height) :
		QPyramid<NumType>(base_side, base_side, height) {}

	NumType apophema() const {
		return sqrt(this->height * this->height + (this->base_a * this->base_a) / 4);
	}

	void input(istream& istr) override {
		istr >> this->base_a >> this->height;
		this->base_b = this->base_a;
	}

	void print(ostream& ostr) const override {
		ostr << "side = " << this->base_a << "h = " << this->height;
	}
};
template<typename NumType>
istream& operator>>(istream& istr, QPyramid<NumType>& pyramid) {
	pyramid.input(istr);

	return istr;
}

template<typename NumType>
ostream& operator<<(ostream& istr, const QPyramid<NumType>& pyramid) {
	pyramid.print(istr);

	return istr;
}
