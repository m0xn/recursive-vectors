#ifndef _REC_VECTOR_H_
#define _REC_VECTOR_H_

const int MAX = 10; // Avoid too many recursive calls
typedef int RecVector[MAX];

struct RecVOV {
	RecVector vector;
	int count; //occupied cells
	int i; //index
};

// ------- Init functions -------

// PRE:
// POST: Initializes the VOV setting both v.i and
// 		 v.count to 0.
void init(RecVOV& v);

// ------- Fill functions -------

// PRE:  v is properly initialized, 0 < count <= MAX
// POST: Fills the first 'count' cells of v with
// 		 'val'.
void fill(RecVOV& v, int count, int val);

// PRE:  v is properly initialized, 0 < count <= MAX
// POST: Fills the first 'count' cells of v with
// 		 a random value going from 1 up to 'max'
void fillRand(RecVOV& v, int count, int max);

// ------- Output functions -------

// PRE:  v is properly initialized
// POST: outputs the contents of v to the console
// 		 using the format { v_0 v_1 ... v_v.count-1 }
void show(RecVOV& v);

// ------- Insert functions -------

// PRE:  v is properly initialized
// POST: shifts all the elements of v to the right, then
// 		 inserts val in the first position
void pushFront(RecVOV& v, int val);

// PRE:  v is properly initialized
// POST: inserts val after the last element of v (in
void pushBack(RecVOV& v, int val);

// PRE:  v is properly initialized
// POST: shifts all the elements to the right from pos,
// 		 then inserts val in pos.
void insert(RecVOV& v, int pos, int val);

// ------- Erase functions -------

// PRE:  v is properly initialized
// POST: erases the first occurence of val in v. If val
// 		 isn't contained in v, 'erase' does nothing
void erase(RecVOV& v, int val);

// PRE:  v is properly initialized, 0 <= pos <= v.count-1
// POST: erases the element at pos, then shifts all the
// 		 elements from pos until v.count
void eraseAt(RecVOV& v, int pos);

// PRE:  v is properly initialized
// POST: erases all occurences of val in v. If val isn't
// 		 contained in v, 'eraseAll' does nothing
void eraseAll(RecVOV& v, int val);

// ------- Search functions -------

// PRE:  v is properly initialized
// POST: searches for val in v. returns true if the search
// 		 was successful and stores the position of the first
// 		 occurence of val in pos. Returns false otherwise.
bool search(RecVOV& v, int val, int& pos);

// ------- Arithmetic functions -------

// PRE:  v, w, r are properly initialized, v.count == w.count
// POST: stores the sum of v and w in r
void add(RecVOV& v, RecVOV& w, RecVOV& r);

// PRE:  v, w, r are properly initialized, v.count == w.count
// POST: stores the difference between v and w in r
void substract(RecVOV& v, RecVOV& w, RecVOV& r);

// PRE:  v, w, r are properly initialized, v.count == w.count
// POST: stores the product of v and w in r
void mult(RecVOV& v, RecVOV& w, RecVOV& r);

// PRE:  v, w, r are properly initialized, v.count == w.count
// POST: stores the quotient between v and w in r
void divide(RecVOV& v, RecVOV& w, RecVOV& r);

#endif // _REC_VECTOR_H
