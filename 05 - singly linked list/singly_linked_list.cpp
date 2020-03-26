#include <iostream>
#include<stdlib.h>

struct tnode {
	int value;
	struct tnode* next;
};

struct tnode* create_node(int value){
	struct tnode* node = (struct tnode*)malloc(sizeof(struct tnode));
	node->next = NULL;
	node->value = value;
	
	return node;
}

void print_linked_list(struct tnode* head){
	struct tnode* temp = head;
	while(temp!=NULL){
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

struct tnode* insert_head(struct tnode* head, int value){
	struct tnode* new_node = create_node(value);
	new_node->next = head;
	head = new_node;
	return head;
}

struct tnode* insert_tail(struct tnode* head, int value){		
	struct tnode* new_node = create_node(value);
	struct tnode* temp = head;
	
	while(temp->next!=NULL){
		temp = temp->next;
	}		
	temp->next = new_node;		
	
	return head;	
}

struct tnode* insert_after(struct tnode* head, int value, int search){
	struct tnode* new_node = create_node(value);
	struct tnode* temp = head;
	
	while(temp->value!=search){
		temp = temp->next;
	}
			
	new_node->next = temp->next;
	temp->next = new_node;
	
	return head;
}

struct tnode* insert_before(struct tnode* head, int value, int search){
	struct tnode* temp = head;
	struct tnode* temp2 = head;	
	
	struct tnode* new_node = create_node(value);

	while(temp2->value!=search){				
		temp = temp2;
		temp2 = temp2->next;		
	}
			
	temp->next = new_node;
	new_node->next = temp2;
		
	return head;
}

struct tnode* delete_head(struct tnode* head){
	struct tnode* temp = head;
	head = head->next;
	free(temp);
	
	return head;
}
struct tnode* delete_tail(struct tnode* head){
	struct tnode* temp = head;
	struct tnode* temp2 = head;
	
	while(temp2->next!=NULL){
		temp = temp2;
		temp2 = temp2->next;
	}	
	temp->next = NULL;
	free(temp2);	
		
	return head;	
}
struct tnode* delete_mid(struct tnode* head, int search){	
	struct tnode* temp = head;
	struct tnode* temp2 = head;	
		
	while(temp2->value!=search){
		temp = temp2;
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	free(temp2);
	
	return head;
}

int main() {
	struct tnode* head = create_node(2);
		
	head = insert_head(head, 1);
	print_linked_list(head);
	printf("\n");
		
	head = insert_tail(head, 6);
	print_linked_list(head);
	printf("\n");
	
	head = insert_after(head, 3, 2);
	print_linked_list(head);
	printf("\n");
	
	head = insert_before(head, 5, 6);	
	print_linked_list(head);
	printf("\n");
	
	head = delete_head(head);
	print_linked_list(head);
	printf("\n");
	
	head = delete_tail(head);
	print_linked_list(head);
	printf("\n");
	
	head = delete_mid(head, 5);	
	print_linked_list(head);
	printf("\n");
	
	return 0;
}

