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
	// printf("%d\n",array->typeSize);
	// printf("%d\n",array->length);
	// printf("%d\n",array[1]);
	// printf("%d %d %d\n", array[0], array[1], array[2]);
	return *array;
};

void insert(int *array, int length){
	for (int i = 0; i < length; i++){
		scanf("%d",&array[i]);
	}
};

int areEqual(ArrayUtil array_a, ArrayUtil array_b){
	int * array1 = (int *)array_a.base;
	int * array2 = (int *)array_b.base;
	insert(array1, array_a.length);
	insert(array2, array_b.length);
	int length;
	if (array_a.length > array_b.length){
		length = array_a.length;
	}
	length = array_b.length;
	int compared_value = memcmp(array1, array2, length);
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
	insert(array,util.length);
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
	MatchFunc even = *match;
	for (int i = 0; i < util.length; i++){
		unsigned char *item = (unsigned char *)util.base+i *util.typeSize;
		if (even(&hint,item)){
			return item;
		}
	}
	return NULL;
};

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	MatchFunc even = *match;
	for (int i = util.length; i >= 0; i--){
		unsigned char *item = (unsigned char *)util.base+i *util.typeSize;
		if (even(&hint,item)){
			return item;
		}
	}
	return NULL;
};

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int count = 0;
	MatchFunc even = *match;
	for (int i = 0; i < util.length; i++){
		unsigned char *item = (unsigned char *)util.base+i *util.typeSize;
		if (even(&hint,item)){
			count++;
		}
	}
	return count;

};

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems){
	MatchFunc even = *match;
	int count = 0;
	unsigned char ** dest = (unsigned char **)destination;
	for (int i = 0; i < util.length; i++){
		unsigned char *item = (unsigned char *)util.base+i *util.typeSize;
		if (even(&hint,item)){
			for (int i = 0; i < maxItems; i++){
				dest[i] = item; 	
			}
		}
	}
	int dest_length = sizeof(dest)/util.typeSize;
	return dest_length;
};



















