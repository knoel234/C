/********************************************************************

 The pqueue module implements a priority queue for the Huffman coding
 algorithm.  It is a very simple implementation of a priority queue.  In
 particular, it simply maintains an array of TreeNode objects that gets sorted
 each time a TreeNode is enqueued (not efficient, but does the job).

 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
#include "tree.h"

// The maximum size of the priority queue.  It should never exceed this size
// as it is the maximum number of characters.  In fact, we do not even need to
// have this many entries as we are only dealing with ASCII encoded
// characters (0 through 127).
#define MAXSIZE 256


/**
 * The PriorityQueue struct represents a priority queue.  It holds an array of
 * TreeNode's and an int indicating the number of currently used entries in
 * the array.
 */
struct PriorityQueue {
  TreeNode *queue[MAXSIZE];
  int       count;
};


/**
 * This function is used by the C library qsort routine.  It is similar to a
 * Comparator object in Java.  However, C uses a comparator function.  It
 * compares two TreeNode objects to determine when one is less than the other.
 * The Huffman coding algorithm requires characters to be sorted by their
 * frequencies in ascending order.
 */
static int comparator (const void *x, const void *y) {
  TreeNode* n1 = *(TreeNode**)x;
  TreeNode* n2 = *(TreeNode**)y;
  int a = n1->freq.v;
  int b = n2->freq.v;
  return a - b;
}


/**
 * A utility function to sort a PriorityQueue.
 */
static void sort (PriorityQueue *pq) {
  qsort(pq->queue, pq->count, sizeof(TreeNode *), comparator);
}


/**
 * Creates a new PriorityQueue object.
 */
PriorityQueue *pqueue_new () {
  PriorityQueue *pq = (PriorityQueue *)(malloc(sizeof(PriorityQueue)));
  for (int i = 0; i < MAXSIZE; i++) {
    pq->queue[i] = NULL;
  }
  pq->count = 0;
  return pq;
}


/**
 * Returns 1 if the priority queue is empty; 0 otherwise.
 */
static int is_empty (PriorityQueue *pq) {
  return pq->count == 0;
}


/**
 * Deallocates a priority queue.
 */
void pqueue_free (PriorityQueue *pq) {
  for (int i = 0; i < MAXSIZE; i++) {
    if (pq->queue[i] != NULL)
      free(pq->queue[i]);
  }
  free(pq);
}


/**
 * Enqueues the given TreeNode object `n` in the
 * PriorityQueue `pq`.
 */
void pqueue_enqueue (PriorityQueue *pq, TreeNode *n) {
  // TODO:

  // First, check whether there is still room in the PriorityQueue (comparing
  // count against MAXSIZE).  Then, if there is room, store the tree node in
  // the array slot indicated by count, and increment count.  Finally, call
  // sort (to keep the queue properly sorted).

  if(pq->count <= MAXSIZE)
  {
    pq->queue[pq->count] = n;
    pq->count += 1;
    sort(pq);
  }
  
  return;
}


/**
 * Dequeues a TreeNode object frm the PriorityQueue.  Returns NULL if the
 * PriorityQueue is empty.
 */
TreeNode *pqueue_dequeue (PriorityQueue *pq) {
  
  // TODO:

  // First, check to see if the priority queue is empty.  If it is, return
  // NULL.  Next, assign the tree node at the front of the queue to a
  // temporary variable T and move each of the subsequent elements in the
  // queue (1 through count-1) over by one slot to the left.  You need to do
  // this to fill in the hole left by the tree node we just dequeued.  Next,
  // decrement count and make the last entry (the one now referred to by
  // count) NULL.  Finally, return the tree node you assigned to the temporary
  // T.
  
  if(pq->count == 0)
  {
    return NULL;
  }
  else
  {
    TreeNode *T = pq->queue[0];
    for(int i = 0; i < (pq->count); i++)
    {
      pq->queue[i] = pq->queue[i+1];
    }
    pq->queue[pq->count] = NULL;
    pq->count -= 1;
    return T;
  }

  
}


/**
 * Prints the priority queue.
 */
void pqueue_print (PriorityQueue *pq) {
  for (int i = 0; i < pq->count; i++) {
    printf("%c", pq->queue[i]->freq.c);
    if (i+1 < pq->count) {
      printf(", ");
    } else {
      printf("\n");
    }
  }
}


/**
 * Returns the size of the priority queue.
 */
int pqueue_size (PriorityQueue *pq) {
  return pq->count;
}
