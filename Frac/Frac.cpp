#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename IntType>
IntType GCD(IntType first, IntType second) {
	IntType quotient = first / second, rest = first % second;

	while (rest != 0) {
		first = second;
		second = rest;
		quotient = first / second;
		rest = first % second;
	}

	return second;
}

template <typename IntType>
struct IntTraits {};

template <>
struct IntTraits<short> {
	const static size_t size_in_bytes = 2;
	const static short nominator = 0;
	const static short denominator = 1;
};

template <>
struct IntTraits<int> {
	const static size_t size_in_bytes = 4;
	const static int nominator = 0;
	const static int denominator = 1;
};

template <>
struct IntTraits<long long> {
	const static size_t size_in_bytes = 8;
	const static long long nominator = 0LL;
	const static long long denominator = 1LL;
};

template <typename IntType, typename Traits = IntTraits<IntType>>
struct Fraction {
	IntType nominator;
	IntType denominator;

	Fraction() :
		nominator(Traits::nominator),
		denominator(Traits::denominator) {}

	Fraction(IntType nom, IntType denom) {
		if (nom == Traits::nominator) {
			nominator = Traits::nominator;
			denominator = Traits::denominator;
		}
		else if (denom == Traits::nominator) {
			nominator = nom;
			denominator = Traits::denominator;
		}
		else {
			IntType gcd = GCD(nom, denom);
			nominator = nom / gcd;
			denominator = denom / gcd;
		}
	}

	Fraction operator+(const Fraction& other) const {
		return Fraction(
			this->nominator * other.denominator + other.denominator * this->nominator,
			this->denominator * other.denominator);
	}

	Fraction operator-(const Fraction& other) const {
		return Fraction(
			this->nominator * other.denominator - other.denominator * this->nominator,
			this->denominator * other.denominator);
	}

	Fraction operator*(const Fraction& other) const {
		return Fraction(
			this->nominator * other.nominator,
			this->denominator * other.denominator);
	}

	Fraction operator/(const Fraction& other) const {
		return Fraction(
			this->nominator * other.denominator,
			this->denominator * other.nominator);
	}

	bool operator<(const Fraction& other) const {
		return nominator * other.denominator < other.nominator * denominator;
	}

	bool operator>(const Fraction& other) const {
		return nominator * other.denominator > other.nominator * denominator;
	}

	bool operator==(const Fraction& other) const {
		return nominator * other.denominator == other.nominator * denominator;
	}

	bool operator!=(const Fraction& other) const {
		return nominator * other.denominator != other.nominator * denominator;
	}

	friend istream& operator>>(istream& istr, Fraction& frac) {
		istr >> frac.nominator >> frac.denominator;
		frac = { frac.nominator, frac.denominator };

		return istr;
	}

	friend ostream& operator<<(ostream& ostr, const Fraction& frac) {
		ostr << frac.nominator << "/" << frac.denominator;

		return ostr;
	}
};

template<typename IntType>
struct MixedFrac {
	IntType integer;
	Fraction<IntType> frac;

	MixedFrac() :
		integer(0),
		frac() {}

	MixedFrac(Fraction<IntType> frac) {
		integer = frac.nominator / frac.denominator;
		frac = { frac.nominator % frac.denominator, frac.denominator };
	}

	MixedFrac(IntType integer, Fraction<IntType> frac) {
		this->integer = integer + frac.nominator / frac.denominator;
		this->frac = { frac.nominator % frac.denominator, frac.denominator };
	}

	IntType get_integer() const {
		return integer;
	}

	Fraction<IntType> get_frac() const {
		return frac;
	}

	Fraction<IntType> to_rational() const {
		return Fraction<IntType>(frac.denominator * integer + frac.nominator, frac.denominator);
	}

	MixedFrac operator+(const MixedFrac& other) {
		return MixedFrac(this->to_rational() + other.to_rational);
	}

	MixedFrac operator-(const MixedFrac& other) {
		return MixedFrac(this->to_rational() - other.to_rational);
	}

	MixedFrac operator*(const MixedFrac& other) {
		return MixedFrac(this->to_rational() * other.to_rational);
	}

	MixedFrac operator/(const MixedFrac& other) {
		return MixedFrac(this->to_rational() / other.to_rational);
	}

	friend istream& operator>>(istream& istr, MixedFrac& mfrac) {
		istr >> mfrac.integer >> mfrac.frac;
		mfrac.integer += mfrac.frac.denominator / mfrac.frac.denominator;
		mfrac.frac.nominator %= mfrac.frac.denominator;
		return istr;
	}

	friend ostream& operator<<(ostream& ostr, const MixedFrac& mfrac) {
		ostr << mfrac.integer << "`" << mfrac.frac;
		return ostr;
	}
};

template <typename IntType>
Fraction<IntType> p(
	const Fraction<IntType>& a,
	const Fraction<IntType>& b,
	const Fraction<IntType>& c,
	const Fraction<IntType>& x) {
	Fraction<IntType> res = a * x * x + b * x + c;
	return res;
}

int main() {
	ifstream fin("Info.txt");
	istream_iterator<Fraction<int>> istr_begin(fin), istr_end;
	ostream_iterator<Fraction<int>> ostr(cout, "\t");

	/*Fraction<int> a, b, c, x;
	cin >> a >> b >> c >> x;

	cout << p(a, b, c, x) << "\n";
	cout << p(a, b, c, x - Fraction<int>(2, 3)) << "\n";
	cout << p(a, b, c, x + Fraction<int>(1, 10)) << "\n";*/

	vector<Fraction<int>> fracs;
	copy(istr_begin, istr_end, back_inserter(fracs));
	sort(fracs.begin(), fracs.end());
	copy(fracs.begin(), fracs.end(), ostr);

	Fraction<int> sum;
	for (auto& it : fracs) {
		sum = sum + it;
	}
	cout << "\nSUM = " << sum << "\n";



	vector<MixedFrac<int>> mfracs;
	copy(fracs.begin(), fracs.end(), back_inserter(mfracs));
	int int_sum = accumulate(mfracs.begin(), mfracs.end(), 0, [=](int sum, const MixedFrac<int> mfrac) {
		return sum += mfrac.get_integer();
		});
	cout << "Integers sum = " << int_sum << "\n";

	return 0;
}