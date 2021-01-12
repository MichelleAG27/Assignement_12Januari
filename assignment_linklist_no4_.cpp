#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	int angka;
	struct Node* next;
};

void removeDuplicates(struct Node* head)
{
	struct Node* curr = head;
	struct Node* next2; 

	if (curr == NULL){
	  return; 
    }
	while (curr->next != NULL) {
	if (curr->angka == curr->next->angka) {	
        next2 = curr->next->next;
		free(curr->next);
		curr->next = next2; 
	}
	else{
		curr = curr->next; 
	}
	}
}

void push(struct Node** head2, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
			
	new_node->angka = new_data;
	new_node->next = (*head2);	 
	(*head2) = new_node;
}

void printList(struct Node *node)
{
	while (node!=NULL)
	{
	printf("%d ->", node->angka);
	node = node->next;
	}
    puts("NULL");
} 

int main()
{
	struct Node* head = NULL;
	push(&head, 132);
	push(&head, 90); 
	push(&head, 95);
	push(&head, 95);
	push(&head, 95);
    push(&head, 88);
    push(&head, 82);
    push(&head, 80);								 

	printf("\n Before Remove : ");
	printList(head);
	removeDuplicates(head); 
	printf("\n After Remove :  ");		 
	printList(head);		 

	return 0;
}