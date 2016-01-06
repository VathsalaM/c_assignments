typedef struct {
  int typeSize;
  int length;
  void *base;
}ArrayUtil;

ArrayUtil create(int typeSize,int length);
int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil resize(ArrayUtil util, int length);
int findIndex(ArrayUtil util, void* element);
void dispose(ArrayUtil util);
typedef int *MatchFunc(void* hint,void* item);
int isEven(void* hint, void* item);
int isDivisible(void* hint, void* item);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void* hint);
int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);
void multiply(void* hint, void* sourceItem, void* destinationItem);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
