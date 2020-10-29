#pragma once

#include <stdlib.h>

typedef struct DListElmt_ {
  void              *data;
  struct DListElmt_ *prev;
  struct DListElmt_ *next;
} DListElmt;

typedef struct DList_ {
  int       size;
  int       (*match)(const void *key1, const void *key2);
  void      (*destroy)(void *data);
  DListElmt *head;
  DListElmt *tail;
} Dlist;
