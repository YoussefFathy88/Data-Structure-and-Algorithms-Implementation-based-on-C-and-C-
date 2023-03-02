#include <iostream>
#include <stdio.h>
#include<stdlib.h>

using namespace std;
struct Node *head = NULL; // Pointer of the first node

struct Node {
	int data;
	struct Node * next = nullptr;
}*first = nullptr; // Node is nothing but self refernical structure
//Define initial global variable


/*
 * Convert Array To linked list
 */

void create(int A[], int n){
	//Draw it for imagine
	int i;
	struct Node *t,*last;
	first = (struct Node *) malloc(sizeof(struct Node));
	first->data = A[0];
	// first->next = nullptr; each time or in the struct one time NULL for C
	last = first;

	for(i = 1; i<n;i++){

		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		//t->next = NULL;
		last->next = t;
		last = t;


	}

}


void DisplayLinkedList(struct Node * head) {
	printf("[");
	struct Node * node = head;
	while(node){ // equvilant to node != nullptr = node != 0
		printf("%d",node->data);

		if((node->next)){//node->next (last node == null)
			printf(",");
		}
		node = node->next;
	}
	printf("]");
	printf("\n");
}


int count_nodes(struct Node * head){
	struct Node* temp = head;
	int count = 0;
	while(temp){
		count++;
		temp =temp->next;
	}
	return count;
}

int sum_nodes(struct Node * head){
	struct Node* temp = head;
	int sum = 0;
	while(temp){
		sum += temp->data;
		temp =temp->next;
	}
	return sum;
}

int max_element(struct Node * head){
	struct Node* temp = head;
	int max = temp->data;
	while(temp){
		if(max < temp->data){
			max = temp->data;
		}
		temp =temp->next;
	}
	return max;
}

void delete_element(int i){
	/*
	 * VIP (head shall be global variable because I cannot make pointer = pointer but what i can make the value inside
	 * this pointer = another value :)
	 */
	struct Node * prev = head;
	struct Node * curr = prev->next;

	if(i == 0){

		head = head->next;
		free(prev);
 	}
	else{


	int catch_element = 1;
	while(curr != NULL){

		if(catch_element == i){
			prev->next = curr->next;
			free(curr);
		}
		catch_element++;
		prev = prev->next;
		curr = prev->next;

	}

 	}
}

int main() {

	int A[] = {1,2,3,4,5,6,7,8,9};
	create(A, sizeof(A)/sizeof(A[0]));
	printf("Display The linked list using Create function \n");
	DisplayLinkedList(first);

	struct Node * Node1 = new struct Node; // Is it same as new Struct Node? Yes

	struct Node * Node2 = new  Node; // Is it same as new Struct Node?

	struct Node * Node3 = new  Node; // Is it same as new Struct Node?

	head = Node1;

    Node1->data = 10;
    Node1->next = Node2;

    Node2->data = 5;
    Node2->next = Node3;

    Node3->data = 11;
    Node3->next = nullptr;

	printf("Display The linked list using custom data \n");
    DisplayLinkedList(head);
    printf("the number of nodes is: %d \n",count_nodes(head));
    printf("the sum of nodes is: %d \n",sum_nodes(head));
    printf("the max of nodes is: %d \n",max_element(head));


    delete_element(head,0);

    DisplayLinkedList(head);


    return 0;
}


