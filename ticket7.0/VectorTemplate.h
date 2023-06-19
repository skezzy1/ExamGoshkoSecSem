#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename NumType>
class VectorTempl {
protected:
    NumType base_x;
    NumType base_y;
    NumType base_z;

public:
    VectorTempl() :
        base_x(0), base_y(0), base_z(0) {}

    VectorTempl(NumType x, NumType y, NumType z) :
        base_x(x), base_y(y), base_z(z) {}

    NumType get_base_x() const {
        return base_x;
    }

    NumType get_base_y() const {
        return base_y;
    }

    NumType get_base_z() const {
        return base_z;
    }

    double lengthVect() const {
        auto l = sqrt(double(base_x * base_x) + double(base_y * base_y) + double(base_z * base_z));
        cout << l << endl;
        return l;
    }

    NumType ScalarDobutok(const VectorTempl& v1, const VectorTempl& v2) const {
        return v1.base_x * v2.base_x + v1.base_y * v2.base_y + v1.base_z * v2.base_z;
    }

    VectorTempl<NumType> operator+(const VectorTempl<NumType>& other) {
        NumType sum_x = base_x + other.base_x;
        NumType sum_y = base_y + other.base_y;
        NumType sum_z = base_z + other.base_z;
        return VectorTempl<NumType>(sum_x, sum_y, sum_z);
    }

    VectorTempl<NumType> operator*(const VectorTempl<NumType>& other) {
        NumType sum_x = base_x * other.base_x;
        NumType sum_y = base_y * other.base_y;
        NumType sum_z = base_z * other.base_z;
        return VectorTempl<NumType>(sum_x, sum_y, sum_z);
    }

    VectorTempl operator-(const VectorTempl& other) {
        NumType minus_x = base_x - other.base_x;
        NumType minus_y = base_y - other.base_y;
        NumType minus_z = base_z - other.base_z;
        return VectorTempl(minus_x, minus_y, minus_z);
    }

    void scale(double scalar) {
        base_x = static_cast<NumType>(static_cast<double>(base_x) * scalar);
        base_y = static_cast<NumType>(static_cast<double>(base_y) * scalar);
        base_z = static_cast<NumType>(static_cast<double>(base_z) * scalar);
    }

    double calculateParallelogramPerimeter(const VectorTempl& v1, const VectorTempl& v2) {
        double side1Length = v1.lengthVect();
        double side2Length = v2.lengthVect();
        double perimeter = (side1Length + side2Length) * 2;
        return perimeter;
    }

    bool areVectorsOrthogonalToXAxis(const VectorTempl& v1, const VectorTempl& v2) {
        bool orthogonalToXAxis = (v1.ScalarDobutok(v1, VectorTempl<NumType>(1, 0, 0)) == 0) && (v2.ScalarDobutok(v2, VectorTempl<NumType>(1, 0, 0)) == 0);
        cout << "Is vector 1 orthogonal to the x-axis? " << (v1.ScalarDobutok(v1, VectorTempl<NumType>(1, 0, 0)) == 0 ? "Yes" : "No") << endl;
        cout << "Is vector 2 orthogonal to the x-axis? " << (v2.ScalarDobutok(v2, VectorTempl<NumType>(1, 0, 0)) == 0 ? "Yes" : "No") << endl;
        return orthogonalToXAxis;
    }

    void calculateParallelogramDiagonals(const VectorTempl& v1, const VectorTempl& v2, double& diagonal1Length, double& diagonal2Length) {
        VectorTempl diagonal1 = v1 + v2;
        VectorTempl diagonal2 = v1 - v2;
        diagonal1Length = diagonal1.lengthVect();
        diagonal2Length = diagonal2.lengthVect();
    }

    virtual void input(istream& is) {
        is >> base_x >> base_y >> base_z;
    }

    friend ostream& operator<<(ostream& os, const VectorTempl<NumType>& vec) {
        os << "Base x: " << vec.base_x << " Base y: " << vec.base_y << " Base z: " << vec.base_z;
        return os;
    }

    // Iterator interface
    NumType* begin() {
        return &base_x;
    }

    const NumType* begin() const {
        return &base_x;
    }

    NumType* end() {
        return &base_z + 1;
    }

    const NumType* end() const {
        return &base_z + 1;
    }

    void normalize() {
        double length = lengthVect();
        base_x /= static_cast<NumType>(length);
        base_y /= static_cast<NumType>(length);
        base_z /= static_cast<NumType>(length);
    }
};

template<typename NumType>
class NormVector : public VectorTempl<NumType> {
public:
    NormVector(NumType x, NumType y, NumType z) :
        VectorTempl<NumType>(x, y, z) {
        this->normalize();
    }

    void input(istream& istr) override {
        istr >> this->base_x >> this->base_y >> this->base_z;
    }

    void print(ostream& ostr) const override {
        ostr << "Base x: " << this->base_x << " Base y: " << this->base_y << " Base z: " << this->base_z << " Normalize: ";
        this->normalize();
    }
};

template<typename NumType>
istream& operator>>(istream& istr, VectorTempl<NumType>& myvector) {
    myvector.input(istr);
    return istr;
}

template<typename NumType>
ostream& operator<<(ostream& ostr, const VectorTempl<NumType>& myvector) {
    myvector.print(ostr);
    return ostr;
}
