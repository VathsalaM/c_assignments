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
