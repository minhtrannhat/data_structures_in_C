#ifndef HEADERS_LINKED_LIST_LINKED_LIST_H_
#define HEADERS_LINKED_LIST_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A structure for linked list elements. */
typedef struct ListElmt_ {
  void *data;
  struct ListElmt_ *next;
} ListElmt;

/* A structure for linked lists */
typedef struct List_ {
  int size;

  /* A function to be used by datatypes
   * that will derived later from linked_list
   */
  int (*match)(const void *key1, const void *key2);

  /* A function to destroy
   * a certain element of the linked list */
  void (*destroy)(void *data);

  ListElmt *head;
  ListElmt *tail;
} List;

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

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

/* Removes the element just after *element* from the linked list *list*.
 * If *element* is NULL, the element at the head of the list is removed.
 * *data* points to the data stored in the element that was
 * removed.
 * Return 0 if succeeded and -1 if not.*/
int list_rem_next(List *list, ListElmt *element, void **data) {
  ListElmt *old_element;

  /* Removal from an empty list is not allowed */
  if (list_size(list) == 0)
    return -1;

  /* Removes the element at head of list */
  if (element == NULL) {
    *data = list->head->data;
    old_element = list->head;
    list->head = list->head->next;

    if (list_size(list) == 1)
      list->tail = NULL;
  } else {
    /* Removal at somewhere other than right after head */
    if (element->next == NULL)
      return -1;

    *data = element->next->data;
    old_element = element->next;
    element->next = element->next->next;

    if (element->next == NULL)
      list->tail = element;
  }

  free(old_element);
  list->size--;
  return 0;
}

/* Destroy the linked list specified by list.
 * No other operations are allowed after calling list_destroy unless list_init
 * is called again. */
void list_destroy(List *list) {
  void *data;

  /* Remove each element. */
  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void **)&data) == 0 &&
        list->destroy != NULL) {

      /*******************************************************************
       * Call a user-defined function to free dynamically allocated data *
       * ****************************************************************/

      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(List));
}

/* Insert a list element after *element*
 * Pass NULL as second argument to insert at head*/
int list_ins_next(List *list, ListElmt *element, const void *data) {
  ListElmt *new_element;

  /* Allocate storage for the element.
   * Check if there is enough space for the element.
   * If not, return error code -1 */
  if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    return -1;

  /* Insert element into the list. */
  new_element->data = (void *)data;

  if (element == NULL) {
    /* Insertion at the head of the list */
    if (list_size(list) == 0)
      list->tail = new_element;

    new_element->next = list->head;
    list->head = new_element;
  } else {
    /* Handle insertion at somewhere other than head. */
    if (element->next == NULL)
      list->tail = new_element;

    new_element->next = element->next;
    element->next = new_element;
  }

  list->size++;

  return 0;
}

#endif // HEADERS_LINKED_LIST_LINKED_LIST_H_
