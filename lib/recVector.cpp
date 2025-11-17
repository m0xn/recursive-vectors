#include <iostream>
#include <ctime>
#include "recVector.h"

using namespace std;

bool seeded = false;

// ------- Reset functions -------
void endProcessing(RecVOV &v, int count) {
	v.i = 0;
	v.count = count;
}

// ------- Init functions -------
void init(RecVOV &v) {
	v.count = v.i = 0;
}

// ------- Fill functions -------
void fill(RecVOV &v, int count, int val) {
	if (v.i < count) {
		v.vector[v.i] = val;
		v.i++;
		fill(v, count, val);
	}
	else endProcessing(v, count);
}

void fillRand(RecVOV &v, int count, int max) {
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	if (v.i < count) {
		v.vector[v.i] = rand() % max + 1;
		v.i++;
		fillRand(v, count, max);
	}
	else endProcessing(v, count);
}

// ------- Output functions -------
void show(RecVOV &v) {
	if (v.i == 0) cout << "{ ";
	if (v.i < v.count) {
		cout << v.vector[v.i] << " ";
		v.i++;
		show(v);
	}
	else {
		endProcessing(v, v.count);
		cout << "}" << endl;
	}
}

// ------- Shift functions (helper functions) -------
void shiftRight(RecVOV &v, int startPos) {
	if (v.i < v.count - startPos) {
		v.vector[v.count - v.i] = v.vector[v.count - v.i - 1];
		v.i++;
		shiftRight(v, startPos);
	}
	else endProcessing(v, v.count);
}

void shiftLeft(RecVOV &v, int startPos) {
	if (v.i < startPos) {
		v.vector[v.i] = v.vector[v.i + 1];
		v.i++;
		shiftLeft(v, startPos);
	} else endProcessing(v, v.count);
}

// ------- Insert functions -------
void pushFront(RecVOV &v, int val) {
	shiftRight(v, v.count);
	v.vector[0] = val;
	endProcessing(v, v.count + 1);
}

void pushBack(RecVOV &v, int val) {
	v.vector[v.count] = val;
	v.count++;
}

void insert(RecVOV &v, int pos, int val) {
	shiftRight(v, pos);
	v.vector[pos] = val;
	endProcessing(v, v.count + 1);
}

// ------- Erase functions -------
<<<<<<< HEAD
void erase(RecVOV &v, int val) {
	if (v.i == v.count) {
		endProcessing(v, v.count);
	}
	if (v.i<v.count) {
		if (v.vector[v.i] != val) {
			v.i++;
			erase(v, val);
		}
		if (v.vector[v.i] == val) {
			shiftLeft(v, v.i);
			endProcessing(v, v.count - 1);
		}
	}
}
void eraseAt(RecVOV& v, int pos) {
	shiftLeft(v, pos);
	endProcessing(v, v.count - 1);
}
void eraseAll(RecVOV&v, int val) {
	if(v.i==v.count){
	endProcessing(v, v.count);
	}
	if (v.i < v.count) {
		if (v.vector[v.i] != val) {
			v.i++;
			erase(v, val);
		}
		if (v.vector[v.i] == val) {
			shiftLeft(v, v.i);
			endProcessing(v, v.count - 1);
			erase(v, val);
		}
}
}
// ------- Search functions -------
bool search(RecVOV &v, int val, int& pos);

// ------- Arithmetic functions -------
void add(RecVOV &v, RecVOV &w, RecVOV &r) {
	if (r.i < v.count) {
		r.vector[r.i] = v.vector[r.i] + w.vector[r.i];
		r.i++;
		add(v, w, r);
	} else endProcessing(r, v.count);
}

void substract(RecVOV &v, RecVOV &w, RecVOV &r) {
	if (r.i < v.count) {
		r.vector[r.i] = v.vector[r.i] - w.vector[r.i];
		r.i++;
		substract(v, w, r);
	} else endProcessing(r, v.count);
}

void mult(RecVOV &v, RecVOV &w, RecVOV &r) {
	if (r.i < v.count) {
		r.vector[r.i] = v.vector[r.i] * w.vector[r.i];
		r.i++;
		mult(v, w, r);
	} else endProcessing(r, v.count);
}

void divide(RecVOV &v, RecVOV &w, RecVOV &r) {
	if (r.i < v.count) {
		r.vector[r.i] = v.vector[r.i] / w.vector[r.i];
		r.i++;
		divide(v, w, r);
	} else endProcessing(r, v.count);
}
