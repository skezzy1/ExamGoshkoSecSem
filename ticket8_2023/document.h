#include <iostream>
using namespace std;

template<class NumType>
class TravelDocument {
protected:
    NumType cost;
    string nameOfTravelPost;
    double duration; //in hours
    NumType lengthOfTrip;
public:
    TravelDocument() :
        cost(0.0), nameOfTravelPost(""), duration(0.0), lengthOfTrip(0.0) {}

    TravelDocument(NumType cost, string nameOfTravelPost, double duration, NumType lengthOfTrip) :
        cost(cost), nameOfTravelPost(nameOfTravelPost), duration(duration), lengthOfTrip(lengthOfTrip) {}

    NumType get_cost() const {
        return cost;
    }

    string get_nameOfTravelPost() const {
        return nameOfTravelPost;
    }

    double get_duration() const {
        return duration;
    }

    NumType get_lengthOfTrip() const {
        return lengthOfTrip;
    }

    double hourlyPayment() const {
        return static_cast<double>(cost) / duration;
    }

    TravelDocument<NumType> operator+(NumType value) const {
        return TravelDocument<NumType>(cost + value, nameOfTravelPost, duration, lengthOfTrip);
    }

    bool operator<(const TravelDocument<NumType>& other) const {
        return hourlyPayment() < other.hourlyPayment();
    }

    bool operator>(const TravelDocument<NumType>& other) const {
        return hourlyPayment() > other.hourlyPayment();
    }

    virtual void input(istream& is) {
        is >> cost >> nameOfTravelPost >> duration >> lengthOfTrip;
    }

    virtual void print(ostream& os) const {
        os << "Cost: " << cost << " Name of Travel Post: " << nameOfTravelPost << " Duration: " << duration << " Length of trip: " << lengthOfTrip << endl;
    }
};
template<class NumType>
class BusinessTicket : public TravelDocument<NumType> {
private:
    string businessService;
    double priceIncreasePercentage;

public:
    BusinessTicket() :
        businessService(""), priceIncreasePercentage(10.0) {}

    BusinessTicket(NumType cost, string nameOfTravelPost, double duration, NumType lengthOfTrip, string businessService) :
        TravelDocument<NumType>(cost, nameOfTravelPost, duration, lengthOfTrip),
        businessService(businessService), priceIncreasePercentage(10.0) {}

    string get_businessService() const {
        return businessService;
    }

    double get_priceIncreasePercentage() const {
        return priceIncreasePercentage;
    }

    double calculateTotalCost() const {
        double baseCost = TravelDocument<NumType>::get_cost();
        double increaseAmount = baseCost * (priceIncreasePercentage / 100.0);
        return baseCost + increaseAmount;
    }

    virtual void print(ostream& os) const {
        os << "Cost: " << TravelDocument<NumType>::get_cost() << " Name of Travel Post: " << TravelDocument<NumType>::get_nameOfTravelPost()
            << " Duration: " << TravelDocument<NumType>::get_duration() << " Length of trip: " << TravelDocument<NumType>::get_lengthOfTrip()
            << " Business Service: " << businessService << " Price Increase Percentage: " << priceIncreasePercentage << "%" << "\nCost after increase: " << calculateTotalCost() << endl;
    }
};
template<class NumType>
inline istream& operator>>(istream& is, TravelDocument<NumType>& other) {
    other.input(is);
    return is;
}

template<class NumType>
inline ostream& operator<<(ostream& os, const TravelDocument<NumType>& other) {
    other.print(os);
    return os;
}
