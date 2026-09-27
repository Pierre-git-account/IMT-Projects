#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  return NULL;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  if(sprite==NULL){return list;}
  list_ptr new_node = malloc(sizeof(s_list_node_t));
  new_node->data = sprite;
  new_node->next = NULL;

  if(list==NULL){
    return new_node;
  }

  list_ptr cur = list;
  while(cur->next!=NULL){
    cur=cur->next;
  }
  cur->next = new_node;
  return list;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return l == NULL;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if((l==NULL)){return l;}
  l=l->next;
  return l;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  
  if(l == NULL){return NULL;}
  return l->data;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  if(*l == NULL){return NULL;}
  if((*l)->next == NULL){
    sprite_t s = (*l)->data;
    free((*l));
    //(*l) == NULL;
    return s;}

  /* Variable temporaire car contrairement 
  au autre fonction (list_ptr l), on nous 
  transmet la véritable variable, 
  il faut donc faire attention */ 
  list_ptr cur = *l;

  while(cur->next->next!=NULL){
    cur=cur->next;
  }
  sprite_t s = cur->next->data;
  free(cur->next);
  cur->next = NULL;
  return s;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  list_ptr cur = l; 
  while(cur != NULL){
    sprite_free(cur->data);
    cur = cur->next;
  }
  free(l);
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  return 0;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}
