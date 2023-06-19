#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <windows.h>
#include "document.h"
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);;
    list<TravelDocument<int>> documents;
    set<string> travelPosts;

    int numDocuments;
    cout << "Enter the number of travel documents: ";
    cin >> numDocuments;

    for (int i = 0; i < numDocuments; ++i) {
        TravelDocument<int> ticket;
        cout << "Enter ticket details (cost, name of travel post, duration, length of trip): ";
        cin >> ticket;
        documents.push_back(ticket);
        travelPosts.insert(ticket.get_nameOfTravelPost());
    }

    cout << "\nList of Tickets:\n";
    for (const auto& ticket : documents) {
        cout << ticket;
    }

    cout << "\nUnique Travel Posts:\n";
    for (const auto& post : travelPosts) {
        cout << post << endl;
    }
    auto max = max_element(documents.begin(), documents.end());
    cout << "Most Expensive Ticket (based on hourly payment):\n" << *max;
    int totalCost = 0;
    for (const auto& ticket : documents) {
        totalCost += ticket.get_cost();
    }

    cout << "\nTotal Cost for all Tickets: " << totalCost << endl;

    return 0;
}

