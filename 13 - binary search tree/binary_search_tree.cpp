#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node {
	int key;
	struct node *left;
	struct node *right;
} *root;

void search(struct node* curr, int find) {
	while (curr != NULL && curr->key != find) {
		if (find < curr->key) {
			curr = curr->left;
		}
		else if (find > curr->key) {
			curr = curr->right;
		}
	}
	if (curr == NULL) {
		printf("not found\n");
	}
	else if (curr->key == find) {
		printf("%d is found\n", curr->key);
	}
}

void searchRecursive(struct node* curr, int find) {
	if (curr == NULL) {
		printf("not found\n");
	}
	else if (curr->key == find) {
		printf("%d is found\n", curr->key);
	}
	else if (find < curr->key) {
		searchRecursive(curr->left, find);
	}
	else if (find > curr->key) {
		searchRecursive(curr->right, find);
	}
}

void insert(struct node* curr, int val) {
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->key = val;
	new_node->left = NULL;
	new_node->right = NULL;

	if (root == NULL) {
		root = new_node;
	}
	else if (val != curr->key) {
		if (val < curr->key && curr->left == NULL) {
			curr->left = new_node;
		}
		else if (val > curr->key && curr->right == NULL) {
			curr->right = new_node;
		}
		else if (val < curr->key && curr->left != NULL) {
			insert(curr->left, val);
		}
		else if (val > curr->key && curr->right != NULL) {
			insert(curr->right, val);
		}
	}
}
void inorder_traversal(struct node* curr) {
	if (curr == NULL) return;
	inorder_traversal(curr->left);
	printf("%d ", curr->key);
	inorder_traversal(curr->right);
}

void preorder_traversal(struct node* curr) {
	if (curr == NULL) return;
	printf("%d ", curr->key);
	preorder_traversal(curr->left);
	preorder_traversal(curr->right);
}

void postorder_traversal(struct node* curr) {
	if (curr == NULL) return;
	postorder_traversal(curr->left);
	postorder_traversal(curr->right);
	printf("%d ", curr->key);
}

void executeDeleteNode(struct node* parent, struct node* curr) {
	if (curr->left == NULL && curr->right == NULL) {
		if (curr == parent->left) {
			parent->left = NULL;
			free(curr);
		}
		else if (curr == parent->right) {
			parent->right = NULL;
			free(curr);
		}
	}
	else if (curr->left != NULL && curr->right == NULL) {
		if (curr == parent->left) {
			parent->left = curr->left;
			free(curr);
		}
		else if (curr == parent->right) {
			parent->right = curr->left;
			free(curr);
		}
	}
	else if (curr->left == NULL && curr->right != NULL) {
		if (curr == parent->left) {
			parent->left = curr->right;
			free(curr);
		}
		else if (curr == parent->right) {
			parent->right = curr->right;
			free(curr);
		}
	}
	else if (curr->left != NULL && curr->right != NULL) {
		struct node* p = NULL;
		struct node* pp = NULL;

		pp = curr;
		p = curr->left;

		while (p->right != NULL) {
			pp = p;
			p = p->right;
		}

		curr->key = p->key;
		executeDeleteNode(pp, p);
	}
}

void deleteNode(struct node* curr, int find) {
	struct node *parent;
	parent = curr;
	while (curr != NULL && curr->key != find) {
		if (find < curr->key) {
			parent = curr;
			curr = curr->left;
		}
		else if (find > curr->key) {
			parent = curr;
			curr = curr->right;
		}
	}
	if (curr == NULL) {
		printf("not found");
	}
	else if (curr->key == find) {
		executeDeleteNode(parent, curr);
	}
}

int main() {
	root = NULL;
	insert(root, 8);
	insert(root, 4);
	insert(root, 12);
	insert(root, 2);
	insert(root, 6);
	insert(root, 10);
	insert(root, 14);
	insert(root, 1);
	insert(root, 3);
	insert(root, 5);
	insert(root, 7);
	insert(root, 9);
	insert(root, 11);
	insert(root, 13);
	insert(root, 15);

	deleteNode(root, 2);
	deleteNode(root, 1);
	deleteNode(root, 15);

	inorder_traversal(root);
	printf("\n");
	preorder_traversal(root);
	printf("\n");
	postorder_traversal(root);
	printf("\n");
	
	search(root, 14);
	searchRecursive(root, 14);

	_getch();
	return 0;
}
