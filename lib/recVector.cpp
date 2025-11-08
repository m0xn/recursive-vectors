#include <iostream>
#include <ctime>
#include "recVector.h"

using namespace std;

bool seeded = false;

// ------- Reset functions -------
void resetIndex(RecVOV& v) {
	v.i = 0;
}

// ------- Init functions -------
void init(RecVOV& v) {
	v.count = v.i = 0;
}
void initRand(RecVOV& v, int count, int max) {
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}
	if (v.i < count) {
		v.vector[v.i] = rand() % max + 1;
		v.i++;
		v.count++;
		initRand(v, count, max);
	}
	else resetIndex(v);
}

// ------- Output functions -------
void show(RecVOV& v) {
	if (v.i == 0) cout << "{ ";
	if (v.i < v.count) {
		cout << v.vector[v.i] << " ";
		v.i++;
	}
	else {
		cout << "}";
		resetIndex(v);
	}
}

// ------- Insert functions -------
void pushFront(RecVOV& v, int val);
void pushBack(RecVOV& v, int val);
void insert(RecVOV& v, int pos, int val);

// ------- Erase functions -------
void erase(RecVOV& v, int val);
void eraseAll(RecVOV& v, int val);
void eraseAt(RecVOV& v, int pos);

// ------- Search functions -------
int search(RecVOV& v, int val, int& pos);

// ------- Arithmetic functions -------
int add(RecVOV& v, RecVOV& w, RecVOV& r);
int substract(RecVOV& v, RecVOV& w, RecVOV& r);
int mult(RecVOV& v, RecVOV& w, RecVOV& r);
int divide(RecVOV& v, RecVOV& w, RecVOV& r);