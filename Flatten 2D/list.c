#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* taken from stackoverflow*/
static int cmpfunc(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

static void insert(SLnodePtr prev, int data) {
  SLnodePtr after = prev->next, SLnew = malloc(sizeof(struct SLnode));
  prev->next = SLnew;
  SLnew->key = data;
  SLnew->next = after;
}

static void posfinder(SLnodePtr following, int data) {
  while (1) {
    if (following->next == NULL || ((following->next)->key > data)) {
      insert(following, data);
      break;
    }
    following = following->next;
  }
}

HBnodePtr createHBlist(int n, int m) {
  srand(time(0));
  int length = (n + 1) * m; /* max number of lists is (n+1)*m*/
  if (m == 0)
    length = n;
  int *sorted = malloc(sizeof(int) * length), count = 0, i, j;
  HBnodePtr first = NULL, prev = NULL, new = NULL;
  SLnodePtr initial = NULL, temp = NULL, tail = NULL;
  for (i = 0; i < length; i++)
    *(sorted + i) = (int)rand() % 400;
  qsort(sorted, length, sizeof(int), cmpfunc);
  for (i = 0; i < n; i++) {
    switch (i) {
    case (0):
      prev = malloc(sizeof(struct HBnode));
      first = prev;
      prev->key = sorted[count++];
      prev->next = NULL;
      break;
    default:
      new = malloc(sizeof(struct HBnode));
      prev->next = new;
      new->key = sorted[count++];
      new->next = NULL;
      prev = new;
    }
    initial = NULL;
    for (j = 0; j < (rand() % (m + 1)); j++) {
      switch (j) {
      case (0):
        temp = malloc(sizeof(struct SLnode));
        initial = temp;
        temp->key = sorted[count++];
        temp->next = NULL;
        break;
      default:
        tail = malloc(sizeof(struct SLnode));
        temp->next = tail;
        tail->key = sorted[count++];
        tail->next = NULL;
        temp = tail;
      }
    }
    prev->bottom = initial;
  }
  free(sorted);
  return first;
}

SLnodePtr flattenList(const HBnodePtr L) {
  if (L == NULL)
    return NULL;
  SLnodePtr flat, following = malloc(sizeof(struct SLnode)), below;
  HBnodePtr curr = L;
  following->key = curr->key;
  following->next = NULL;
  flat = following;
  below = curr->bottom;
  while (below) {
    posfinder(following, below->key);
    below = below->next;
  }
  curr = L->next;
  while (curr) {
    below = curr->bottom;
    while (below) {
      following = flat;
      posfinder(following, below->key);
      below = below->next;
    }
    following = flat;
    posfinder(following, curr->key);
    curr = curr->next;
  }
  return flat;
}

void freeSLlist(SLnodePtr L) {
  if (L != NULL) {
    SLnodePtr next = L->next;
    free(L);
    freeSLlist(next);
  }
}

void freeHBlist(HBnodePtr L) {
  if (L != NULL) {
    HBnodePtr next = L->next;
    freeSLlist(L->bottom);
    free(L);
    freeHBlist(next);
  }
}

void printHBlist(const HBnodePtr L) {
  if (L != NULL) {
    printf("%d-> ", L->key);
    printSLlist(L->bottom);
    printf("\n");
    printHBlist(L->next);
  }
}

void printSLlist(const SLnodePtr L) {
  if (L != NULL) {
    printf("%d ", L->key);
    printSLlist(L->next);
  }
}
