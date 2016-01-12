#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "first_assignment_arrays.h"

void test_create_array() {
  ArrayUtil a = create(4,5);
  ArrayUtil b = create(4,5);
  assert(a.length==5);
  assert(a.typeSize==4);
  int *address_a = a.base;
  int *address_b = b.base;
  for (int i = 0; i < a.length; i++) {
    assert(*(address_a+i*a.typeSize)==0);
  }
  for (int i = 0; i < b.length; i++) {
    assert(*(address_b+i*b.typeSize)==0);
  }
}

void test_areEqual(){
  ArrayUtil a = create(4,9);
  ArrayUtil b = create(4,9);
  ArrayUtil c = create(4,9);
  ArrayUtil d = create(4,9);
  ArrayUtil e = create(4,2);
  char *c1 = (char *)c.base;
  char *d1 = (char *)d.base;
  c1[3] = 'A';
  d1[3] = 'B';
  assert(areEqual(a,b)==1);
  assert(areEqual(c,d)==0);
  assert(areEqual(a,c)==0);
  assert(areEqual(a,d)==0);
  assert(areEqual(a,e)==0);
}

void test_find_Index(){
  ArrayUtil a = create(4,6);
  int *address = a.base;
  for (int i = 0; i < a.length; i++) {
    *(address+i)=i+4;
  }
  int x = 2;
  void *y = &x;
  int result1 = findIndex(a,y);
  assert(result1 ==-1);
  x = 7;
  int result2 = findIndex(a,y);
  assert(result2 == 3);
}

void test_resize(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,3);
  ArrayUtil c = resize(a,12);
  assert(a.length==6);
  assert(b.length==3);
  assert(c.length==12);
  int *address = b.base;
  for (int i = 0; i < b.length; i++) {
    assert(*(address+i)==0);
  }
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
  int x = 3;
  void *x_address = &x;
  int y = 6;
  void *y_address = &y;
  int result1 = (match(x_address,y_address));
  assert(result1==1);
  x = 5;
  y = 7;
  result1 = (match(x_address,y_address));
  assert(result1==0);
  MatchFunc *func = isDivisible;
  x = 3;
  y = 6;
  int result2 = (func(x_address,y_address));
  assert(result2==1);
  x = 5;
  y = 6;
  result2 = (func(x_address,y_address));
  assert(result2==0);
}

void test_findFirst() {

  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int x = 7;
  void *x_address = &x;
  int result = *(int *)findFirst(a,match,x_address);
  assert(result==2);
  MatchFunc *func = isDivisible;
  x = 3;
  int result1 = *(int *)findFirst(a,func,x_address);
  printf("%d\n",result1 );
  assert(result1==6);
}

void test_findLast() {
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int x = 7;
  void *x_address = &x;
  int result = *(int *)findLast(a,match,x_address);
  assert(result==12);
  MatchFunc *func = isDivisible;
  x = 5;
  int result1 = *(int *)findLast(a,func,x_address);
  assert(result1==10);
}

void test_count(){
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  int x = 7;
  void *x_address = &x;
  int result = count(a,match,x_address);
  assert(result==6);
}

void test_filter(){
  ArrayUtil a = create(4,6);
  MatchFunc *match = isEven;
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = (i+1)*2;
  }
  void **dest = calloc(a.length,sizeof(int *));
  int x = 7;
  void *x_address = &x;
  int result = filter(a,match,x_address,dest,4);
  int y = 2;
  void *y_address = &y;
  assert(result==4);
  assert(*(int *)dest+0==2);
  assert(*(int *)dest+1==4);
  assert(*(int *)dest+2==6);
  assert(*(int *)dest+3==8);

}

// void test_convert(){
//   ConvertFunc *convert = multiply;
//   ArrayUtil source = create(4,6);
//   ArrayUtil destination = create(4,6);
//   int *a = (int *)source.base;
//   int *b = (int *)destination.base;
//   for (int i = 0; i < source.length; i++) {
//     a[i] = i;
//   }
//   assert(a[1]==1);
//   assert(b[1]==0);
//   convert(2,&a[1],&b[1]);
//   assert(a[1]==1);
//   assert(b[1]==2);
// }
//
// void test_map(){
//   ConvertFunc *convert = multiply;
//   ArrayUtil source = create(4,6);
//   ArrayUtil destination = create(4,6);
//   int *a = (int *)source.base;
//   int *b = (int *)destination.base;
//   for (int i = 0; i < source.length; i++) {
//     a[i] = i;
//   }
//   assert(b[0]==0);
//   assert(b[1]==0);
//   assert(b[2]==0);
//   assert(b[3]==0);
//
//   map(source,destination,convert,3);
//
//   assert(b[0]==0);
//   assert(b[1]==3);
//   assert(b[2]==6);
//   assert(b[4]==12);
//   assert(b[3]==9);
// }
//
// void test_OperationFunc(){
//   OperationFunc *operate = add;
//   ArrayUtil source = create(4,6);
//   int *a = (int *)source.base;
//   a[1] = 23;
//   assert(a[1]==23);
//   operate(2,&a[1]);
//   assert(a[1]==25);
// }
//
// void test_forEach(){
//   OperationFunc *operate = add;
//   ArrayUtil source = create(4,6);
//   int *a = (int *)source.base;
//   for (int i = 0; i < source.length; i++) {
//     a[i] = i;
//   }
//   assert(a[0]==0);
//   assert(a[1]==1);
//   assert(a[2]==2);
//   assert(a[3]==3);
//   forEach(source,operate,2);
//   assert(a[0]==2);
//   assert(a[1]==3);
//   assert(a[2]==4);
//   assert(a[3]==5);
// }
//
// void test_ReducerFunc(){
//   ReducerFunc *reducer = add_all;
//   int result = (int *)(reducer(3,5,6));
//   assert(result==14);
// }
//
// void test_reduce(){
//   ReducerFunc *reducer = add_all;
//   ArrayUtil source = create(4,3);
//   int *a = (int *)source.base;
//   for (int i = 0; i < source.length; i++) {
//     a[i] = 1;
//   }
//   int result = (int *)reduce(source,reducer,1,2);
//   assert(result == 8);
// }

int main(){
  test_create_array();
  test_areEqual();
  test_find_Index();
  test_resize();
  test_dispose();
  test_MatcFunc();
  test_findFirst();

  return 0;
}
