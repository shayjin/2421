#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
int main(){    
        char *line = NULL;    
        size_t size;    
        int len;    
        struct LinkedList list;    
	int i; 
	char *token;   
	init_list(&list);    
	while(1){
		printf("Please enter your command (use help if you don't remember): ");
		len = getline(&line, &size, stdin);
		if(len <= 0) continue;
		/* Remove the last \n */
		line[len-1] = '\0';
		if(strcmp(line, "exit") == 0){    
			printf("Bye\n");    
			break;
		}
		else if(strcmp(line, "help") == 0){    
			printf("exit: quits this tool\n");    
			printf("help: print all commands\n");    
			printf("print: print all values in the linked list\n");    
			printf("add <i> <value>: add value as the ith element\n");    
			printf("delete <i>: delete the ith element\n"); 
		} 
		else if(strcmp(line, "print") == 0){
			print_list(&list);
		}   
		else{
			token = strtok(line, " ");
			if(strcmp(token, "add") == 0){
				int i, value;
				i = strtol(strtok(NULL, " "), NULL, 10);
				value = strtol(strtok(NULL, " "), NULL, 10);
				insert_node(&list, i, value);				
			}
			else if(strcmp(token, "delete") == 0){
				int i;
				i = strtol(strtok(NULL, " "), NULL, 10);
				remove_node(&list, i);
			}
			else{
				printf("Error\n");
				return 0;
			}	
		}
	}
 	destroy_list(&list);
	return 0;
}
