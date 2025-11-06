#ifndef _REC_VECTOR_H_
#define _REC_VECTOR_H_

const int MAX = 10; // Avoid too many recursive calls
typedef int RecVector[MAX];

struct RecVOV {
	RecVector vector;
	int count;
	int i;
};

// ------- Reset functions -------
void resetIndex(RecVOV &v);

// ------- Init functions -------
void init(RecVOV &v);
void initRand(RecVOV &v, int count, int max);

// ------- Output functions -------
void show(RecVOV &v);

// ------- Insert functions -------
void pushFront(RecVOV &v, int val);
void pushBack(RecVOV &v, int val);
void insert(RecVOV &v, int pos, int val);

// ------- Search functions -------
int search(RecVOV &v, int val, int &pos);

// ------- Arithmetic functions -------
int add(RecVOV &v, RecVOV &w, RecVOV &r);
int substract(RecVOV &v, RecVOV &w, RecVOV &r);
int mult(RecVOV &v, RecVOV &w, RecVOV &r);
int divide(RecVOV &v, RecVOV &w, RecVOV &r);

#endif // _REC_VECTOR_H
