#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "first_assignment_arrays.h"

void test_create_array() {
  ArrayUtil a = create(4,5);
  assert(a.length==5);
  assert(a.typeSize==4);
  // int *a1 = (int *)a.base;
  // for (int i = 0; i < a.length; i++) {
  //   a1[i]=11;
  // }
}

void test_areEqual(){
  ArrayUtil a = create(4,9);
  ArrayUtil b = create(4,9);
  ArrayUtil c = create(4,9);
  ArrayUtil d = create(4,9);
  ArrayUtil e = create(4,2);
  ArrayUtil f = create(8,9);
  int *c1 = (int *)c.base;
  int *d1 = (int *)d.base;
  c1[3] = 23;
  d1[3] = 24;
  assert(areEqual(a,b)==1);
  assert(areEqual(c,d)==0);
  assert(areEqual(a,c)==0);
  assert(areEqual(a,d)==0);
  assert(areEqual(a,e)==0);
}

void test_find_Index(){
  ArrayUtil a = create(4,6);
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i]=i+4;
  }
  int element = 2;
  int result1 = findIndex(a,element);
  assert(result1 ==-1);
  int element2 = 7;
  int result2 = findIndex(a,element2);
  assert(result2 == 3);
}

void test_resize(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,3);
  ArrayUtil c = resize(a,12);
  assert(a.length==6);
  assert(b.length==3);
  assert(c.length==12);
  // int *a1 = (int *)a.base;
  // int *b1 = (int *)b.base;
  // int *c1 = (int *)c.base;
}

void test_dispose(){
  ArrayUtil a = create(4,6);
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = i+2;
  }
  int *address = &a1[3];
  assert(a1[1] == 3);
  dispose(a);
}

void test_MatcFunc(){
  MatchFunc *match = isEven;
  int result1 = (match(3,6));
  assert(result1==1);
  result1 = (match(5,7));
  assert(result1==0);
  MatchFunc *func = isDivisible;
  int result2 = (func(3,6));
  assert(result2==1);
  result2 = (func(5,6));
  assert(result2==0);
}

void test_findFirst() {
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int result = (int *)findFirst(a,match,7);
  assert(result==2);
  MatchFunc *func = isDivisible;
  int result1 = (int *)findFirst(a,func,3);
  assert(result1==6);
}

void test_findLast() {
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int result = (int *)findLast(a,match,7);
  assert(result==12);
  MatchFunc *func = isDivisible;
  int result1 = (int *)findLast(a,func,5);
  assert(result1==10);
}

void test_count(){
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int result = count(a,match,7);
  assert(result==6);
}

void test_filter(){
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int **dest = (int **)calloc(a.length,sizeof(int *));
  int result = filter(a,match,7,dest,4);
  assert(result==4);
  assert(*dest[0]==2);
  assert(*dest[1]==4);
  assert(*dest[2]==6);
  assert(*dest[3]==8);
}

void test_convert(){
  ConvertFunc *convert = multiply;
  ArrayUtil source = create(4,6);
  ArrayUtil destination = create(4,6);
  int *a = (int *)source.base;
  int *b = (int *)destination.base;
  for (int i = 0; i < source.length; i++) {
    a[i] = i;
  }
  assert(a[1]==1);
  assert(b[1]==0);
  convert(2,&a[1],&b[1]);
  assert(a[1]==1);
  assert(b[1]==2);
}

void test_map(){
  ConvertFunc *convert = multiply;
  ArrayUtil source = create(4,6);
  ArrayUtil destination = create(4,6);
  int *a = (int *)source.base;
  int *b = (int *)destination.base;
  for (int i = 0; i < source.length; i++) {
    a[i] = i;
  }
  assert(b[0]==0);
  assert(b[1]==0);
  assert(b[2]==0);
  assert(b[3]==0);

  map(source,destination,convert,3);
  assert(b[0]==0);
  assert(b[1]==3);
  assert(b[2]==6);
  assert(b[3]==9);
}

void test_OperationFunc(){
  OperationFunc *operate = add;
  ArrayUtil source = create(4,6);
  int *a = (int *)source.base;
  a[1] = 23;
  assert(a[1]==23);
  operate(2,&a[1]);
  assert(a[1]==25);
}

void test_forEach(){
  OperationFunc *operate = add;
  ArrayUtil source = create(4,6);
  int *a = (int *)source.base;
  for (int i = 0; i < source.length; i++) {
    a[i] = i;
  }
  assert(a[0]==0);
  assert(a[1]==1);
  assert(a[2]==2);
  assert(a[3]==3);
  forEach(source,operate,2);
  assert(a[0]==2);
  assert(a[1]==3);
  assert(a[2]==4);
  assert(a[3]==5);
}
