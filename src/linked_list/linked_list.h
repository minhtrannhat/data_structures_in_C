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

void list_init(List *list, void (*destroy)(void *data), int (*match)(const void *key1, const void *key2));

#endif // HEADERS_LINKED_LIST_LINKED_LIST_H_
