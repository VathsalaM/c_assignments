#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linkedList.h"

LinkedList create(){
  LinkedList new_list;
  new_list.first = NULL;
  new_list.last = NULL;
  new_list.length = 0;
  return new_list;
}

int add_to_list(LinkedList *list,void *element){
  list->length = list->length+1;
  ele *e = (ele *)calloc(1,sizeof(ele));
  e->value = element;

  ele *prevEle = list->last;
  if(prevEle!=NULL)
    prevEle->nextValue = e;
  list->last = e;
  if(list->first == NULL){
    list->first = e;
    e->nextValue = NULL;
  }
  return 0;
}

void *get_first_element(LinkedList list){
  return list.first;
}

void *get_last_element(LinkedList list){
  return list.last;
}

void *increment(void *element){
  ele *e = (ele *)element;
  *(int *)e->value = *(int *)e->value+1;
  return e;
}

void forEach(LinkedList list, ElementProcessor e){
  ele *e1 = list.first;
  for (int i = 0; i < list.length; i++) {
      *e1 = *(ele *)e(e1);
      e1 = e1->nextValue;
  }
}
