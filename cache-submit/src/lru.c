#include <stdlib.h>
#include <stdio.h>
#include "cache.h"
#include "lru.h"

void lru_init_queue (Set *set) {
  LRUNode *s = NULL;
  LRUNode **pp = &s;  // place to chain in the next node
  for (int i = 0; i < set->line_count; i++) {
    Line *line = &set->lines[i];
    LRUNode *node = (LRUNode *)(malloc(sizeof(LRUNode)));
    node->line = line;
    node->next = NULL;
    (*pp) = node;
    pp = &((*pp)->next);
  }
  set->lru_queue = s;
}

void lru_init (Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    lru_init_queue(&sets[i]);
  }
}

void lru_destroy (Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    LRUNode *p = sets[i].lru_queue;
    LRUNode *n = p;
    while (p != NULL ) {
      p = p->next;
      free(n);
      n = p;
    }
    sets[i].lru_queue = NULL;
  }
}

void lru_fetch(Set *set, address_type tag, LRUResult *result) {
  /* TODO:
     Implement the LRU algorithm to determine which line in
     the cache should be accessed.
   */

    for (LRUNode **prevp = &(set->lru_queue); (*prevp) != NULL; 
      prevp = &((*prevp)->next)) 
    {
      LRUNode *current = *prevp;
      Line *line = current->line;

      if(line->valid == 1 && line->tag == tag)
      {
        result->access = HIT;
      }

      else if(line->valid == 0)
      {
        line->valid = 1;
        line->tag = tag;
        result->access = COLD_MISS;
      }

      else if(current->next == NULL)
      {
        line->tag = tag;
        result->access = CONFLICT_MISS;
      }
      else
      {
        continue;
      }

      *prevp = (*prevp)->next;
      current->next = set->lru_queue;
      set->lru_queue = current;
      result->line =line;
      return;

    }


}
