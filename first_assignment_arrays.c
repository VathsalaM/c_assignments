#include <stdlib.h>
#include <stdio.h>
#include "first_assignment_arrays.h"

ArrayUtil create(int typeSize,int length){
  ArrayUtil Array;
  Array.length = length;
  Array.typeSize = typeSize;
  Array.base = calloc(length,typeSize);
  return Array;
};

int areEqual(ArrayUtil a, ArrayUtil b){
  if((a.length!=b.length) || (a.typeSize!=b.typeSize))
    return 0;
  for (int i = 0; i < a.length; i++) {
    int *a1 = (int *)a.base;
    int *b1 = (int *)b.base;
    if(a1[i] != b1[i])
      return 0;
  }
  return 1;
}

ArrayUtil resize(ArrayUtil util, int length) {
  int new_length = length-util.length;
  util.base = (void *) realloc(util.base,length);
  int *address_a = util.base;
  for (int i = util.length; i < length; i++) {
    *(address_a+i*util.typeSize) = 0;
  }
  util.length = length;
  return util;
}

int findIndex(ArrayUtil util, void* element){
  int *address = util.base;
  for (int i = 0; i < util.length; i++) {
    if(*(address+i*util.typeSize)==element)
      return i;
  }
  return -1;
}

void dispose(ArrayUtil util){
  free(util.base);
  return ;
}

int isEven(void* hint, void* item){
  int ele = (int *)item;
  return (ele)%2==0;
}

int isDivisible(void* hint, void* item){
  int item1 = (int *)item;
  int hint1 = (int *)hint;
  return item1%hint1==0;
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
  int *a1 = (int *)util.base;
  for (int i = 0; i < util.length; i++) {
    if(match(hint,a1[i])==1)
      return a1[i];
  }
  return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
  int *a1 = (int *)util.base;
  for (int i = util.length-1; i >=0; i--) {
    if(match(hint,a1[i])==1)
      return a1[i];
  }
  return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
  int count = 0;
  int *a1 = (int *)util.base;
  for (int i = 0; i < util.length; i++) {
    if(match(hint,a1[i])==1)
      count++;
  }
  return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
  int count = 0;
  int *a1 = (int *)util.base;
  int **dest = (int **)destination;
  for (int i = 0; i < maxItems; i++) {
    if(match(hint,a1[i])==1){
      destination[count] = &a1[i];
      count++;
    }
  }
  return count;
}

void multiply(void* hint, void* sourceItem, void* destinationItem){
  int ele = (int *)hint;
  int *source_address = sourceItem;
  int *dest_address = destinationItem;
  int value = *source_address;
  *dest_address = value * ele;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  // int *a = (int *)source.base;
  // int *b = (int *)destination.base;
  // for (int i = 0; i < source.length; i++) {
  //   convert(hint,&a[i],&b[i]);
  // }
  for (int i = 0; i < source.length; i++) {
    convert(hint,source.base+(source.typeSize*i),destination.base+(destination.typeSize*i));
  }
}

void add(void* hint, void* item){
  int ele = (int *)hint;
  int *address = item;
  int value = *address;
  *address = value+ele;
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
  // int *a = (int *)util.base;
  for (int i = 0; i < util.length; i++) {
    // operation(hint,&a[i]);
    operation(hint,util.base+(util.typeSize*i));
  }
}

void* add_all(void* hint, void* previousItem, void* item){
  int ele = (int *)hint;
  int prevItem = (int *)previousItem;
  int currentItem = (int *)item;
  return ele+prevItem+currentItem;
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
  int *a = (int *)util.base;
  void* result = (int *)intialValue;
  for (int i = 0; i < util.length; i++) {
    void* item = (void *)a[i];
    result = reducer(hint,result,item);
  }
  // printf("%d\n",result );
  return result ;
}
