#include <stdio.h>
#include "array_util.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil *array = (ArrayUtil *)calloc(length, typeSize);
	array->typeSize = typeSize;
	array->length = length;
	array->base = array;
	return *array;
};

int areEqual(ArrayUtil array_a, ArrayUtil array_b){
	int length;
	if (array_a.length > array_b.length){
		length = array_a.length;
	}
	length = array_b.length;
	int compared_value = memcmp(array_a.base,array_b.base, length);
	if (compared_value == 0 && array_a.typeSize == array_b.typeSize && array_a.length == array_b.length){
		return 1;
	}
	return 0;
};

ArrayUtil resize(ArrayUtil util, int length) {
	util.base = realloc(util.base, length);
	util.length = length;
	return util;
};

void dispose(ArrayUtil util){
	free(util.base);	
};

int findIndex(ArrayUtil util, void*element){
	int * array = (int *)util.base;
	int * value = (int *)element;
	for (int i = 0; i < util.length; i++){
		if (array[i] == *value){
			return i;
		}
	}
	return -1;
};

int isEven(void* hint, void* item){
	int value = *(int *)item;
	if (value % 2 == 0){
		return 1;
	}
	return 0;
};

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	for (int i = 0; i < util.length; i++){
		if ((*match)(hint,util.base+i *util.typeSize)){
			return util.base+i *util.typeSize;
		}
	}
	return NULL;
};

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	for (int i = util.length-1; i >= 0; i--){
		if ((*match)(hint,util.base+i *util.typeSize)){
			return util.base+i *util.typeSize;
		}
	}
	return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int count = 0;
	for (int i = 0; i < util.length; i++){
		if ((*match)(hint,util.base+i *util.typeSize)){
			count++;
		}
	}
	return count;
};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems){
	int count = 0;
	unsigned char ** dest = (unsigned char **)destination;
	for (int i = 0; i < util.length; i++){
		if ((*match)(&hint,util.base+i *util.typeSize) && i < maxItems){
			dest[i] = util.base+i *util.typeSize; 	
			count++;
		}
	}
	return count;
};

void get_square(void* hint, void* sourceItem, void* destinationItem){
	int src_value = *(int *)sourceItem;
	int square = src_value * src_value;
	*(int *)destinationItem = square;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	for (int i = 0; i < source.length; i++){
		(*convert)(&hint, source.base+i *source.typeSize, destination.base+i *destination.typeSize);
	} 	
};

void increment_by_10(void* hint, void* item){
	*(int *)item+= 10;
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	for (int i = 0; i < util.length; i++){
		(*operation)(&hint, util.base+i *util.typeSize);
	}
};

















