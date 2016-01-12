#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linkedList.h"

void test_create(void){
  LinkedList a = create();
  assert(a.first == NULL);
  assert(a.last == NULL);
  assert(a.length == 0);
}

void test_add_to_list(){
  LinkedList a = create();
  assert(a.first == NULL);
  assert(a.last == NULL);
  assert(a.length == 0);
  int x = 23;
  void *x_address = &x;
  int result = add_to_list(&a,x_address);
  assert(*(int *)a.first->value == 23);
  assert(*(int *)a.last->value == 23);
  assert(a.length == 1);
  int y = 24;
  void *y_address = &y;
  result = add_to_list(&a,y_address);
  assert(*(int *)a.first->value == 23);
  assert(*(int *)a.last->value == 24);
  assert(a.length == 2);
  int z = 25;
  void *z_address = &z;
  result = add_to_list(&a,z_address);
  assert(*(int *)a.first->value == 23);
  assert(*(int *)a.last->value == 25);
  assert(a.length == 3);

}

void test_get_first_element(){
  LinkedList a = create();
  int x = 23;
  void *x_address = &x;
  int result = add_to_list(&a,x_address);
  int y = 24;
  void *y_address = &y;
  result = add_to_list(&a,y_address);
  int z = 25;
  void *z_address = &z;
  result = add_to_list(&a,z_address);
  ele *e = (ele *)get_first_element(a);
  assert(*(int *)e->value == 23);

}

void test_get_last_element(){
  LinkedList a = create();
  int x = 23;
  void *x_address = &x;
  int result = add_to_list(&a,x_address);
  int y = 24;
  void *y_address = &y;
  result = add_to_list(&a,y_address);
  int z = 25;
  void *z_address = &z;
  result = add_to_list(&a,z_address);

  ele *e = (ele *)get_last_element(a);
  assert(*(int *)e->value == 25);

}

void test_element_processor(){
  LinkedList a = create();
  int x = 23;
  void *x_address = &x;
  int result = add_to_list(&a,x_address);
  int y = 24;
  void *y_address = &y;
  result = add_to_list(&a,y_address);
  int z = 25;
  void *z_address = &z;
  result = add_to_list(&a,z_address);
  ElementProcessor *elePro = increment;
  assert(*(int *)a.first->value == 23);
  ele *e = (ele *)elePro(a.first);
  assert(*(int *)e->value == 24);
}

void test_forEach(){
  LinkedList a = create();
  int x = 23;
  void *x_address = &x;
  int result = add_to_list(&a,x_address);
  int y = 24;
  void *y_address = &y;
  result = add_to_list(&a,y_address);
  int z = 25;
  void *z_address = &z;
  result = add_to_list(&a,z_address);
  ElementProcessor *elePro = increment;
  forEach(a,elePro);
  ele *e1 = a.first;
  int value = 23;
  for (int i = 0; i < a.length; i++) {
    assert(*(int *)e1->value==(value +=1));
    e1 = e1->nextValue;
  }
}
