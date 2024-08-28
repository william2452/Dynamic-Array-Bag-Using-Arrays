/*dynamicArray.h : Dynamic Array implementation*/

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


typedef struct DynArr DynArr;
typedef struct Bag Bag;

/*Dynamic Array Functions*/
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *d);
int sizeDynArr(DynArr *d);
void addDynArr(DynArr *d, double val);
double getDynArr(DynArr *d, int pos);
void putDynArr(DynArr *d, int pos, double val);
void swapDynArr(DynArr *d, int i, int  j);
void removeAtDynArr(DynArr *d, int pos);

/*Bag Interface*/
void addBag(DynArr*, double val);
int containsBag(DynArr*, double val);
void removeBag(DynArr*, double val);

#endif
