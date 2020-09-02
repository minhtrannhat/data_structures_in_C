#include <stdlib.h>
#include <stdio.h>

#pragma once

/*
 * A node in a linked list 
 * has a "key" that represent the its data and 
 * a pointer to the next node
 */
typedef struct node
{
  int key;
  struct node *next;
}node;

/* 
 * A (dummy) node called 'z': 
 * that last node in the list will 
 * point to z and z will point to it self.
 * 
 * A node at the start of the list called 'head': 
 * point to the first node of the list.
 *
 * we will interact with node 't' in this program.
 */

node *t, *head, *z;

/* 
 * Initialize a list
 */
void listinitialize()
{
  /*
   * As of the point of initializing a list, 
   * head points to z and z points to itself.
   */
  head = (node*) malloc(sizeof(node));
  z = (node*) malloc(sizeof(node));
  head->next = z;
  z->next = z;
}

/*
 * This function delete the node proceeding it by
 * making the pointer points to 
 * the node after the node getting deleted
 */
void delete_next_node(node *t)
{
  t->next = t->next->next;
  free(t->next);
}

/* 
 * insert a node after a certain node in the list
 */
node *insert_after(int v, node *t)
{
  node *x = (node*) malloc(sizeof(node));
  x->key = v;
  x->next = t->next;
  t->next = x;
  return x;
}

/* prints out the linked list */
void print_linked_list_recursively(node* t)
{
  if (t == head) exit(0);
  if(t== z) exit(0);
  printf("%d ", t->key);
  printf("--> ");
  print_linked_list_recursively(t->next);
}
