#ifndef SRC_LINKED_LIST_H_
#define SRC_LINKED_LIST_H_

#include <stdlib.h>

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

/* public interface */
void list_init(List *list, void (*destroy)(void *data));

void list_destroy(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->tail)

#define list_tail(list) ((list)->tail)

#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

#endif // SRC_LINKED_LIST_H_
