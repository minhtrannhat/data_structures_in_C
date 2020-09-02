#include "../src/linked_list_of_ints.h"

int main(void)
{
  /* Initialize a linkedlist of ints */
  listinitialize();
  
  /* Insert a node after the node 'head' */
  insert_after(5, head);
  insert_after(10, head->next);
  /* Print out the linked list */
  print_linked_list_recursively(head->next);

  return 0;
}
