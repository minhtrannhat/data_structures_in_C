#include "../src/linked_list_of_ints.h"

int main(void)
{
  /* Initialize a linkedlist of ints */
  listinitialize();
  
  /* Insert a node after a certain node */
  node *a = insert_after(5, head);        // after the first node called HEAD
  node *b = insert_after(11, a);          // after the second node

  /* Print out the linked list 
   * starting from a certain position
   * recursively */
  print_linked_list_recursively(head);

  return 0;
}
