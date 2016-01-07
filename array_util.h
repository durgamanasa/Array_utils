typedef struct array{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (*MatchFunc)(void*, void*);
typedef void (ConvertFunc)(void*, void*, void *);
typedef void (OperationFunc)(void*, void*);
typedef void* (ReducerFunc)(void*, void*, void*);

ArrayUtil create(int typeSize, int length);
int areEqual(ArrayUtil array_a, ArrayUtil array_b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil util);
int isEven(void* hint, void* item);
void* findFirst(ArrayUtil util, MatchFunc*, void* hint);
void* findLast(ArrayUtil util, MatchFunc*, void* hint);
int count(ArrayUtil util, MatchFunc*, void* hint);
int filter(ArrayUtil util, MatchFunc*, void* hint, void** destination, int maxItems);
void get_square(void* hint, void* sourceItem, void* destinationItem);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc*, void* hint);
void increment_by_10(void* hint, void* item);
void forEach(ArrayUtil util, OperationFunc*, void* hint);
