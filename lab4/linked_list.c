#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init_list(struct LinkedList *list){
	list->current = NULL;
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

void destroy_list(struct LinkedList *list){
	int i;
	struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	list->current = list->first;	
	while(list->current != NULL){
		temp = list->current;
		list->current = NULL;
		list->current = temp->next;
	}
}

void print_list(struct LinkedList *list){
	list->current = list->first;
	while(list->current != NULL){
		printf("%d", list->current->data);
		list->current = list->current->next;
		if(list->current != NULL){
			printf("->");
		}
	}
	printf("\n");
}

void insert_node(struct LinkedList *list, int index, int value){
	if(index >= 0 && index == list->length){
		struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
		new_node->data = value;
		if(list->length == 0){
			list->first = new_node;
			list->last = new_node;
				
		} else{
			list->last->next = new_node;
			list->last->next->prev = list->last;
			list->last = new_node;	
		}
		list->length++;
	}			
}

void remove_node(struct LinkedList *list, int index){
	int i;
	struct ListNode* removing_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (index >= 0){
		list->current = list->first;
		for (i = 0; i < index; i++){
			list->current = list->current->next;
		}
		removing_node = list->current;
		if (list->first == removing_node)
			list->first = removing_node->next;
		if (removing_node->next != NULL)
			removing_node->next->prev = removing_node->prev;
		if (removing_node->prev != NULL)
			removing_node->prev->next = removing_node->next;				
	}
}
