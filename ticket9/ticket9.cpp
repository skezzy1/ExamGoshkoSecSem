#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include "QTrinomial.h"
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream inputFile("trinomials.txt"); 
    if (!inputFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    vector<QTrinomial<double>> trinomials; 

    double a, x, xb, yb;
    while (inputFile >> a >> x >> xb >> yb) {
        trinomials.push_back(QTrinomial<double>(a, x, xb, yb));
    }

    cout << "Тричлени:" << endl;
    for (const auto& trinomial : trinomials) {
        cout << trinomial << endl;
    }
    int verticesOnXAxis = 0;
    int intersectXAxis = 0;
    for (const auto& trinomial : trinomials) {
        if (trinomial.get_yb() == 0) {
            verticesOnXAxis++;
        }
        if (trinomial.formula() == 0) {
            intersectXAxis++;
        }
    }
    cout << "Вершини на осі абсцис: " << verticesOnXAxis << endl;
    cout << "Тричлени, що перетинають вісь абсцис: " << intersectXAxis << endl;
    for (int i = 0; i < 3 && i < trinomials.size(); i++) {
        FSquare<double> fullSquare(trinomials[i].get_a(), trinomials[i].get_x(), trinomials[i].get_xb(), trinomials[i].get_yb(), 'x');
        trinomials[i] = fullSquare;
    }

    cout << "Тричлени після перетворення на повні квадрати:" << endl;
    for (const auto& Trinomial : trinomials) {
        cout << Trinomial << endl;
    }
    cin.get();
    return 0;
}
