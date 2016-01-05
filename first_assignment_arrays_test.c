#include <stdio.h>
#include <assert.h>
#include "first_assignment_arrays.h"

void test_create_array() {
  ArrayUtil a = create(4,5);
  assert(a.length==5);
  assert(a.typeSize==4);
  return;
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
  return;
}

void test_find_Index(){
  ArrayUtil a = create(4,6);
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i]=i+4;
  }
  void * element;
  int result1 = findIndex(a,element);
  assert(result1 ==-1);
  int element2 = 7;
  int result2 = findIndex(a,&element2);
  assert(result2 == 3);
}

void test_resize(){
  ArrayUtil a = create(4,6);
  ArrayUtil b = resize(a,3);
  assert(a.length==6);
  assert(b.length==3);
  int *a1 = (int *)a.base;
  int *b1 = (int *)b.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = i;
  }
  for (int i = 0; i < b.length; i++) {
    b1[i] = i;
  }
}

void test_dispose(){
  ArrayUtil a = create(4,6);
  int *a1 = (int *)a.base;
  for (int i = 0; i < a.length; i++) {
    a1[i] = i+2;
  }
  assert(a1[1] == 3);
  dispose(a);
  assert(a1[1] != 3);
}

int main(){
  test_create_array();
  test_areEqual();
  test_resize();
  test_find_Index();
  test_dispose();
  return 0;
}
