#include "linked_list.h"
#include <stddef.h>
/*
 * Initialize a list
 * with a destroy function to destroy a member
 * and a matching function to search for a member
 */
void list_init(List *list, void (*destroy)(void *),
               int (*match)(const void *key1, const void *key2)) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->destroy = destroy;
  list->match = match;
}

int list_rem_next(List *list, ListElmt *element, void **data) {
  /*
   * No removal from empty list
   */
  if (list_size(list) == 0)
    return -1;

  /*
   * remove from head of the list
   */
  *data = list->head->data;
  ListElmt *old_element = list->head;
  list->head = list->head->next;

  if (list_size(list) == 1)
    list->tail = NULL;
}

void list_destroy(List *list) {
  void *data;

  /*
   * Remove each element
   */
  while (list_size(list) > 0) {
    if (list_rem_next(list, NULL, (void **)&data) == 0 &&
        list->destroy != NULL) {
      /*
       * Call a user-defined function to free dynamically allocated data.
       */
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(List));
}
