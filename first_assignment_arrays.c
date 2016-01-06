#include <stdlib.h>
#include <stdio.h>
#include "first_assignment_arrays.h"

ArrayUtil create(int typeSize,int length){
  int *base_array = (int *)calloc(length,typeSize);
  ArrayUtil *Array = (ArrayUtil *)malloc(sizeof(ArrayUtil));
  Array->typeSize = typeSize;
  Array->length = length;
  Array->base = base_array;
  return (*Array) ;
};

int areEqual(ArrayUtil a, ArrayUtil b){
  if((a.length!=b.length) || (a.typeSize!=b.typeSize))
    return 0;
  int length = a.length;
  int *array_a = a.base;
  int *array_b = b.base;
  while(length>=0){
    if(array_a[length]!=array_b[length])
      return 0;
    length--;
  }
  return 1;
}

ArrayUtil resize(ArrayUtil util, int length) {
  int new_length = length-util.length;
  int *array = util.base;
  // if(new_length<0){
  //   int count = 0;
  //   for (int i = length; i >util.length ; i--) {
  //     free(&array[count]);
  //     count++;
  //   }
  //   return util;
  // }
  array = (int *) realloc(array,length);
  for (int i = util.length; i < length; i++) {
    array[i] = 0;
  }
  util.length = length;
  return util;
}

int findIndex(ArrayUtil util, void* element){
  int *a1 = (int *)util.base;
  int ele = (int *)element;
  for (int i = 0; i < util.length; i++) {
    if(a1[i]==ele)
      return i;
  }
  return -1;
}

void dispose(ArrayUtil util){
  // int *array = util.base;

  free(util.base);
  // for (int i = 0; i <= util.length ; i--) {
    // free(&array[i]);
  // }
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
