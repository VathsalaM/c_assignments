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
    int *address_a = a.base;
    int *address_b = b.base;
    if(*(address_a+i) != *(address_b+i))
      return 0;
  }
  return 1;
}

ArrayUtil resize(ArrayUtil util, int length) {
  int new_length = length-util.length;
  util.base = (void *) realloc(util.base,length);
  int *address_a = util.base;
  for (int i = util.length; i < length; i++) {
    *(address_a+i) = 0;
  }
  util.length = length;
  return util;
}

int findIndex(ArrayUtil util, void* element){
  int *address = util.base;
  int *value = element;
  int ele = *value;
  for (int i = 0; i < util.length; i++) {
    if(*(address+i)==ele)
      return i;
  }
  return -1;
}

void dispose(ArrayUtil util){
  free(util.base);
  return ;
}

int isEven(void* hint, void* item){
  int *ele_address = item;
  int ele = *ele_address;
  return (ele)%2==0;
}

int isDivisible(void* hint, void* item){
  int *ele_address = item;
  int ele = *ele_address;
  int *hint_address = hint;
  int hint1 = *hint_address;
  return ele%hint1==0;
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
  void *ele_address = hint;
  void *array = util.base;
  for (int i = 0; i < util.length; i++) {
    if(match(ele_address,(array+i))==1)
      return (array+i);
  }
  return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
  void *array = util.base;
  for (int i = util.length-1; i >=0; i--) {
    if(match(hint,array+i)==1)
      return array+i;
  }
  return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
  int count = 0;
  void *address = util.base;
  for (int i = 0; i < util.length; i++) {
    if(match(hint,address+i)==1)
      count++;
  }
  return count;
}

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems ){
  int count = 0;
  int *address = util.base;
  for (int i = 0; i < maxItems; i++) {
    if(match(hint,address+i)==1){
      destination[count] = (address+i);
      count++;
    }
  }
  return count;
}

void multiply(void* hint, void* sourceItem, void* destinationItem){
  int ele = *(int *)hint;
  int *source_address = sourceItem;
  int *dest_address = destinationItem;
  int value = *source_address;
  *dest_address = value * ele;
}

// void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
//   for (int i = 0; i < source.length; i++) {
//     convert(hint,source.base+(source.typeSize*i),destination.base+(destination.typeSize*i));
//   }
// }
//
// void add(void* hint, void* item){
//   int ele = (int *)hint;
//   int *address = item;
//   int value = *address;
//   *address = value+ele;
// }
//
// void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
//   for (int i = 0; i < util.length; i++) {
//     operation(hint,util.base+(util.typeSize*i));
//   }
// }
//
// void* add_all(void* hint, void* previousItem, void* item){
//   int ele = (int *)hint;
//   int prevItem = (int *)previousItem;
//   int currentItem = (int *)item;
//   return ele+prevItem+currentItem;
// }
//
// void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
//   int *a = (int *)util.base;
//   void* result = (int *)intialValue;
//   for (int i = 0; i < util.length; i++) {
//     void* item = (void *)a[i];
//     result = reducer(hint,result,item);
//   }
//   return result ;
// }
