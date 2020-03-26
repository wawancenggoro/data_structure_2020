#include <iostream>
#include <stdlib.h>
#include <string.h>

struct tnode {
	int priority;
	char name[100];
	struct tnode* next;
};

struct tnode* create_node(int priority, char* name){
	struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
	node->next = NULL;
	node->priority = priority;
	strcpy(node->name, name);
	
	return node;
}

void print_queue(struct tnode* head){
	struct tnode* temp = head;
	while(temp!=NULL){
		printf("%d: %s -> ", temp->priority, temp->name);
		temp = temp->next;
	}
}

struct tnode* push(struct tnode* head, int priority, char* name){
	struct tnode* new_node = create_node(priority, name);
	struct tnode* temp = head;
	
	while(temp->next->priority<=priority){
		temp = temp->next;
		if(temp->next==NULL){
			break;
		}
	}
			
	new_node->next = temp->next;
	temp->next = new_node;
	
	return head;
}

struct tnode* pop(struct tnode* head){
	struct tnode* temp = head;
	head = head->next;
	free(temp);
	
	return head;
}

int main() {
	struct tnode* head = create_node(1,"alpha");
	
	struct tnode* new_node = create_node(2,"beta");
	head->next = new_node;
	
	struct tnode* new_node2 = create_node(3,"omega");
	new_node->next = new_node2;
	print_queue(head);
	printf("\n");
		
	head = push(head, 2, "delta");
	print_queue(head);
	printf("\n");
	
	head = pop(head);
	print_queue(head);
	printf("\n");
	
	return 0;
}

