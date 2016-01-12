typedef struct{
	void *value;
	void *nextValue;
	void *prevValue;
}ele;

typedef struct LinkedList{
	ele *first;
	ele *last;
	int length;
}LinkedList;



LinkedList create(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
typedef void* ElementProcessor(void *ele);
void forEach(LinkedList, ElementProcessor e);
void *increment(void *ele);
