#ifndef SRC_LINKED_LIST_LINKED_LIST_OF_FRAMES_H_
#define SRC_LINKED_LIST_LINKED_LIST_OF_FRAMES_H_

/***********************************************************
 * Linked List Example: Frame Management:
 *
 * Linked list is used for frame management because frame
 * allocation involves frequent insertions and deletions,
 * and these operations are performed at the head of
 * the list.
 *
 * Virtual memory is a mapping of address space that allows
 * a process to execute without being completely in physical
 * memory.
 *
 * A process running in virtual memory deals with virtual
 * adresses. These are addreses that seem like physical
 * adresses to the process, but that the system must
 * translate before using.
 *
 * Address translation has its own page table that maps
 * pages of its virtual address space to frames in physical
 * memory. When a process reference a particular virtual
 * address, the appropriate entry in its page table is
 * inspected to determine which physical frame the page
 * resides.
 **********************************************************/

#include "./linked_list.h"

int alloc_frame(List *frames) {
  int frame_number, *data;

  if (list_size(frames) == 0) {
    return -1; /* No frames available. */
  } else {
    if (list_rem_next(frames, NULL, (void **)&data) != 0)
      return -1; /* A frame could not be retrived */

    else {
      /* Store the number of the available frame */
      frame_number = *data;
      free(data);
    }
  }

  return frame_number;
}

int free_frame(List *frames, int frame_number) {
  int *data;

  /* Allocate storage for the frame number. */
  if ((data = (int*)malloc(sizeof(int))) == NULL)
    return -1;

  /* Put the frame back in the list of available frames. */
  *data = frame_number;

  if(list_ins_next(frames, NULL, data) != 0)
    return -1;

  return 0;
}

#endif // SRC_LINKED_LIST_LINKED_LIST_OF_FRAMES_H_
