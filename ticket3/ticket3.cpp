#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "QuadrangularPyramid.h"

int main() {
	QPyramid<float> p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	vector<QPyramid<float>> pyramids = { p1, p2, p3 };
	auto max = max_element(pyramids.begin(), pyramids.end());
	cout << "\n1) MAX pyramid vol is " << *max << "\n";
	sort(pyramids.begin(), pyramids.end());
	cout << "\n2)\n";
	for_each(pyramids.begin(), pyramids.end(), [=](const QPyramid<float>& p) {
		if (p.get_base_a() < max->get_base_a() &&
			p.get_base_b() < max->get_base_b() &&
			p.get_height() < max->get_height()) {
			cout << "Max can contain " << p << "\n";
		}
		else {
			cout << "Max can NOT contain " << p << "\n";
		}
		});

	cout << "\n3)\n";

	for_each(pyramids.begin(), pyramids.end(), [=](const QPyramid<float>& p) {
		if (p.get_base_a() == p.get_base_b()) {
			cout << p << " is special.\n";
		}
		else {
			cout << p << " is NOT special.\n";
		}
		});

	cout << "\n\n5)\n";
	ifstream fin("file.txt");
	istreambuf_iterator<QPyramid<int>> istr_begin(fin),istr_end;
	ostream_iterator<QPyramid<int>> ostr(cout, "\n*******************************\n");
	vector<QPyramid<int>> pyramids2(istr_begin, istr_end);
	copy(pyramids2.begin(), pyramids2.end(), ostr);
}