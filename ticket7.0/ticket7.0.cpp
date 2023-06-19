#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "VectorTemplate.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //VectorTempl<int> p1, p2;
    //cin >> p1 >> p2;
    ifstream file("vectors.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    vector<VectorTempl<double>> vectors;
    double x, y, z;
    while (file >> x >> y >> z) {
        vectors.push_back(VectorTempl<double>(x, y, z));
    }
    file.close();
    for (const auto& vec : vectors) {
        cout << "Vector: (" << vec.get_base_x() << ", " << vec.get_base_y() << ", " << vec.get_base_z() << ")" << endl;
    }
    int orthogonalCount = 0;
    int angle45Count = 0;
    for (size_t i = 1; i < vectors.size(); i++) {
        if (vectors[i].areVectorsOrthogonalToXAxis(vectors[0], vectors[i])) {
            orthogonalCount++;
        }
        if (vectors[i].ScalarDobutok(vectors[0], vectors[i]) == cos(3.14 / 4.0)) {
            angle45Count++;
        }
    }

    cout << "Number of vectors orthogonal to the first vector: " << orthogonalCount << endl;
    cout << "Number of vectors forming a 45-degree angle with the first vector: " << angle45Count << endl;

    VectorTempl<double> sumVector;
    for (const auto& vec : vectors) {
        sumVector = sumVector + vec;
    }

    cout << "Sum of all vectors: (" << sumVector.get_base_x() << ", " << sumVector.get_base_y() << ", " << sumVector.get_base_z() << ")" << endl;

    return 0;
}