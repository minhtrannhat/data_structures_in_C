#ifndef SRC_LINKED_LIST_LINKED_LIST_H_
#define SRC_LINKED_LIST_LINKED_LIST_H_

#include <stdlib.h>
#include <string.h>

/* A structure for linked list elements. */
typedef struct ListElmt_ {
  void             *data;
  struct ListElmt_ *next;
} ListElmt;

/* A structure for linked lists */
typedef struct List_ {
  int       size;

  /* A function to check */
  int       (*match)(const void *key1, const void *key2);

  /* A function to destroy
   * a certain element of the linked list */
  void      (*destroy)(void *data);

  ListElmt  *head;
  ListElmt  *tail;
} List;

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->tail)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

/* Public interface */
void list_init(List *list, void (*destroy)(void *data)) {
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;
}

int list_rem_next(List *list, ListElmt *element, void **data);

void list_destroy(List *list) {
  void *data;

  /* Remove each element. */
  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void**)&data) == 0 &&
        list->destroy != NULL) {

      /*******************************************************************
       * Call a user-defined function to free dynamically allocated data *
       * ****************************************************************/

      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(List));
}

int list_ins_next(List *list, ListElmt *element, const void *data) {
  ListElmt *new_element;

  /* Allocate storage for the element. */
  if ((new_element = (ListElmt *) malloc(sizeof(ListElmt))) == NULL)
    return -1;

  /* Insert element into the list. */
  new_element->data = (void*) data;

  if(element == NULL) {
    /* Insertion at the head of the list */
    if (list_size(list) == 0)
      list->tail = new_element;
    
    new_element->next = list->head;
    list->head = new_element;
  }
  
  /* Handle insertion at somewhere other than head. */
  else {
    if (element->next == NULL)
      list->tail = new_element;

    new_element->next = element->next;
    element->next = new_element;

  }

  list->size++;

  return 0;
}



#endif // SRC_LINKED_LIST_LINKED_LIST_H_
