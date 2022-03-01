#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/* Define members of a list node here */
struct ListNode{
	struct ListNode *prev;
	struct ListNode *next;
	int data; 
};

struct LinkedList{
	int length;
	struct ListNode *current;
	struct ListNode *first;
	struct ListNode *last;
};

/* Initialize an empty list */
void init_list(struct LinkedList *list);

/* Destroy the list. */
void destroy_list(struct LinkedList *list);

/* Print all elements in the list*/
void print_list(struct LinkedList *list);

/* Insert value at the index-th position */
void insert_node(struct LinkedList *list, int index, int value);

/* Remove the index-th element */
void remove_node(struct LinkedList *list, int index);

#endif
