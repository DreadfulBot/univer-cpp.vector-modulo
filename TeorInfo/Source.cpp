#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void PrintReversed(vector<int> vector) {
	for(int i=0; i<vector.size(); i++) {
		cout << vector[vector.size() - 1 - i] << " ";
	}
	cout << endl;
}

void ClearZeros(vector<int> &vector) {
	while(vector[vector.size() - 1] == 0) {
		vector.erase(vector.end() - 1);
	}
}

void InitVector(vector<int> &vector, int* values, int size) {
	for(int i=0; i<size; i++) {
		vector.push_back(values[i]);
	}
	cout << "Vector Inited:" << endl;
	PrintReversed(vector);
}

void GetModulo(vector<int> &poly1, vector<int> &poly2, vector<int> &result) {
	int offset = 0;

	if(poly1.size() > poly2.size()) {
		for(int i=0; i<(poly1.size()-poly2.size()); i++)
		{
			result.insert(result.begin() + i, poly2[poly2.size() - 1 - i]);
			offset++;
		}
	}

	for(int i=offset++, j=0; i<poly1.size(); i++, j++) {
		result.push_back(poly1[i] ^ poly2[j]);
	}
	ClearZeros(result);

	cout << "Modulo getted:" << endl;
	PrintReversed(result);
}

int main(void) {

	int poly1values[] = {1,0,0,1};
	int poly1size = 4;

	int poly2values[] = {1,1,0,1};
	int poly2size = 4;

	vector<int> poly1;
	vector<int> poly2;
	vector<int> modulo;

	InitVector(poly1, poly1values, poly1size);
	InitVector(poly2, poly2values, poly2size);
	GetModulo(poly1, poly2, modulo);

	return 0;
}