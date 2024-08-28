#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "dynamicArray.h"

/*
    DynArr - Dynamic array struct
    data - pointer to the data array of type double
    size - number of elements currently stored in the array
    capacity - capacity of the array
*/
struct DynArr {
	double *data;
	int size;
	int capacity;
};

/* ------------------Dynamic Array Functions--------------------- */

/* 	initDynArr: initialize (including allocation of data array) dynamic array
	param: d is the pointer to the dynamic array
	param: cap is the capacity of the dynamic array
	pre: d is not null
	pre: capacity is greater than 0
	post: memory has been allocated for d->data to store capacity elements
	post: size is 0
	post: capacity is cap
*/
void initDynArr(DynArr *d, int cap) {
	assert(cap > 0);
	assert(d!= 0);
	d->data = malloc(sizeof(double) * cap);
	assert(d->data != 0);
	d->size = 0;
	d->capacity = cap;
}

/* 	createDynArr: allocate and initialize dynamic array
	param: cap is the desired capacity for the dynamic array
	ret: a pointer to a dynArr of cap capacity
	pre: cap is greater than 0
	post: memory has been dynamically allocated for a dynArray
*/
DynArr* createDynArr(int cap) {
	DynArr *dyn;
	assert(cap > 0);
	dyn = (DynArr *)malloc(sizeof( DynArr));
	if(!dyn) {
		printf("Failed to allocate memory \n");
	}
	initDynArr(dyn,cap);
	return dyn;
}

/* 	freeDynArr: deallocate data array in dynamic array
	param: d is the pointer to the dynamic array
	pre: d is not null
	post: size and capacity are 0
	post: the memory used by d->data is freed
    post: d->data points to null
*/
void freeDynArr(DynArr *d) {
	if(d->data != 0) {
		free(d->data);
		d->data = 0;
	}
	d->size = 0;
	d->capacity = 0;
}

/* 	deleteDynArr: deallocate memory from the array
	param: d is the pointer to the dynamic array
	pre: d is not null
	post: freeDynArr() is called
	post: the memory used by d is freed
*/
void deleteDynArr(DynArr *d) {
	freeDynArr(d);
	free(d);
}

/* 	sizeDynArr: get the size of the dynamic array
	param: d is the pointer to the dynamic array
	ret: the size of the dynamic array
	pre: d is not null
	post: no changes to the dynArray
*/
int sizeDynArr(DynArr *d) {
    assert(d != 0);
	return d->size;
}

/* 	addDynArr: adds an element to the end of the dynamic array
	param: d is the pointer to the dynamic array
	param: val is the value to add to the end of the dynamic array
	pre: the dynArry is not null
	post: size increases by 1
	post: if reached capacity, capacity is doubled
	post: val is in the last utilized position in the array
*/
void addDynArr(DynArr *d, double val) {
	/*FIX ME: You will write this function*/
    assert(d != 0);

    if(d -> size == d -> capacity) {
        d -> capacity *= 2;
        d -> data = realloc(d -> data, sizeof(double)*d -> capacity);
    }
    d -> data[d -> size] = val;
    d -> size++;
}

/*	getDynArr: get an element from the dynamic array from a specified position
	param: d is the pointer to the dynamic array
	param: pos is the index position to get the element from
	ret: value stored at index pos
	pre: d is not null
	pre: 0 <= pos <= size of the dyn array
	post: no changes to the dynArray
*/
double getDynArr(DynArr *d, int pos) {
	/*FIX ME: You will write this function*/
    assert(d != 0);
    assert(0 <= pos);
    assert(pos < d -> size);

	/*FIX ME: you must change this return value*/
	return d -> data[pos];
}

/*	putDynArr: put an item into the dynamic array at the specified location, overwriting the element that was there
	param: d is the pointer to the dynamic array
	param: pos is the index position where val will be inserted
	param: val the value to insert
	pre: d is not null
	pre: pos >= 0 and pos < size of the array
	post: index pos contains new value, val
*/
void putDynArr(DynArr *d, int pos, double val) {
	/*FIX ME: You will write this function*/
    assert(d != 0);
    assert(0 <= pos);
    assert(pos < d -> size);

    d -> data[pos] = val;
}

/*	swapDynArr: swap two specified elements in the dynamic array
	param: d is the pointer to the dynamic array
	param: i, j are the elements to be swapped
	pre: d is not null
	pre: i & j are greater than or equal to 0
	pre: i & j are less than the size of the dynamic array
	post: index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *d, int i, int  j) {
    /*FIX ME: You will write this function*/
    assert(d != 0);
    assert(i >= 0);
    assert(j >= 0);
    assert(i < d -> size);
    assert(j < d -> size);

    int temp = 0;
    temp = d -> data[i];
    d -> data[i] = d -> data[j];
    d -> data[j] = temp;
}

/*	removeAtDynArr: remove the element at the specified location from the array, shifts other elements back one to fill the gap
	param: d is the pointer to the dynamic array
	param: pos is the location of element to remove
	pre: d is not null
	pre: pos <= size and pos >= 0
	post: the element at pos is removed
	post: the elements past pos are shifted
	post: size is decremented
*/
void removeAtDynArr(DynArr *d, int pos) {
	/*FIX ME: You will write this function*/
    assert(d != 0);
    assert(pos < d -> size);
    assert(pos >= 0);

    int i = pos;
    while(i < d -> size-1) {
        d -> data[i] = d -> data[i+1];
        i++;
    }
    d -> size--;
}



/* ------------------Bag Interface Functions------------------ */

/*	addBag: adds an element to the bag
	param: bag pointer to the dynamic array
	param: val the value to add to the bag
	pre: bag is not null
	post: size is incremented by 1
	post: bag contains one more element in last position
*/
void addBag(DynArr *bag, double val) {
	/*FIX ME: You will write this function*/
	/*HINT - Call a function that you already wrote*/
    assert(bag != 0);

    addDynArr(bag, val);
}

/*	containsDynArr: determines whether the bag has anything on it (encoded in an int)
	param: bag pointer to the dynamic array
	param: val the value to look for in the bag
	ret: if bag contains val, then 1 is returned, otherwise 0 is returned
	pre: bag is not null
	post: no changes to the bag
*/
int containsBag(DynArr *bag, double val) {
	/*FIX ME: You will write this function*/
    assert(bag != 0);

    int i = 0;
    while(i < bag -> size) {
        if(bag -> data[i] == val) {
            return 1;
            break;
        } else {
            i++;
        }
    }
	/*FIX ME: You will change this return value*/
    return 0;
}

/*	removeDynArr: removes the first occurrence of the specified value from the collection (if it occurs)
	param: bag pointer to the dynamic array
	param: val the value to remove from the array
	pre: bag is not null
	post: val has been removed
	post: size of the bag is reduced by 1
*/
void removeBag(DynArr *bag, double val) {
	/*FIX ME: You will write this function*/
    assert(bag != 0);

    int i = 0;
    while(i < bag -> size) {
        if(bag -> data[i] == val) {
            removeAtDynArr(bag, i);
        }
        i++;
    }
}
