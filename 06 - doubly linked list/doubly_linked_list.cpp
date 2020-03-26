#include <iostream>
#include<stdlib.h>

struct tnode {
	int value;
	struct tnode* prev;
	struct tnode* next;
};
struct tnode* head = NULL;
struct tnode* tail = NULL;

struct tnode* create_node(int value){
	struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
	node->prev = NULL;
	node->next = NULL;
	node->value = value;
	
	return node;
}

void print_linked_list(){
	struct tnode* temp = head;
	while(temp!=NULL){
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

void insert_head(int value){
	struct tnode* new_node = create_node(value);
	
	new_node->next = head;
	head->prev = new_node;	
	
	head = new_node;
}

void insert_tail(int value){		
	struct tnode* new_node = create_node(value);
	
	new_node->prev = tail;	
	tail->next = new_node;
	
	tail = new_node;
}

void insert_after(int value, int search){	
	struct tnode* new_node = create_node(value);
	struct tnode* temp = head;
	
	while(temp->value!=search){
		temp = temp->next;
	}
					
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;
}

void insert_before(int value, int search){
	struct tnode* new_node = create_node(value);
	struct tnode* temp = head;
	
	while(temp->value!=search){
		temp = temp->next;
	}
			
	new_node->next = temp;
	new_node->prev = temp->prev;
	temp->prev->next = new_node;
	temp->prev = new_node;
}

void delete_head(){
	struct tnode* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}

void delete_tail(){
	struct tnode* temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
}

void delete_mid(int search){
	struct tnode* temp = head;
			
	while(temp->value!=search){		
		temp = temp->next;	
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
}

int main() {	
	head = create_node(2);
	tail = create_node(5);
	head->next = tail;
	tail->prev = head;
		
	insert_head(1);
	print_linked_list();
	printf("\n");
	
	insert_tail(6);
	print_linked_list();
	printf("\n");
	
	insert_after(3,2);
	print_linked_list();
	printf("\n");
	
	insert_before(4,5);	
	print_linked_list();
	printf("\n");
	
	delete_head();
	print_linked_list();
	printf("\n");
	
	delete_tail();
	print_linked_list();
	printf("\n");
	
	delete_mid(4);	
	print_linked_list();
	printf("\n");
	
	print_linked_list_backward();
	
	return 0;
}

