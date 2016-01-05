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
  util.length = length;
  // if(new_length<0){
  //   int count = 0;
  //   for (int i = length; i >util.length ; i--) {
  //     free(&array[count]);
  //     count++;
  //   }
  //   return util;
  // }
  array = (int *) realloc(array,length);
  return util;
}

int findIndex(ArrayUtil util, void* element){
  int *a1 = (int *)util.base;
  int ele = *(int *)element;
  for (int i = 0; i < util.length; i++) {
    if(a1[i]==ele)
      return i;
  }
  return -1;
}

void dispose(ArrayUtil util){
  int *array = util.base;
  for (int i = 0; i <= util.length ; i--) {
    free(&array[i]);
  }
}
