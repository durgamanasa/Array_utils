typedef struct array{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (*MatchFunc)(void*, void*);


ArrayUtil create(int typeSize, int length);
int areEqual(ArrayUtil array_a, ArrayUtil array_b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil util);
void insert(int * ,int);
int isEven(void* hint, void* item);
void* findFirst(ArrayUtil util, MatchFunc*, void* hint);
void* findLast(ArrayUtil util, MatchFunc*, void* hint);
int count(ArrayUtil util, MatchFunc*, void* hint);
int filter(ArrayUtil util, MatchFunc*, void* hint, void** destination, int maxItems);
