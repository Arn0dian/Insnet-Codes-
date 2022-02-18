/* C++ implementation to remove duplicates from a
sorted doubly linked list */

// Arn0dian - Optimised gfg code 

#include <bits/stdc++.h>

using namespace std;

/* a node of the doubly linked list */
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};


/* function to remove duplicates from a
sorted doubly linked list */
// re-written code
void removeDuplicates(struct Node* head)
{
	// we use map to check if it exists before 
    map<int , int> tmap;
    Node* checc = head; Node* pchecc = NULL;
    while (checc->next!=NULL)
    {
        if(tmap.find(checc->data) == tmap.end())
        {
            tmap[checc->data] = 1;
            pchecc = checc;
            checc = checc->next;
        }
        else
        {
            pchecc->next = checc->next;
            checc->next->prev = pchecc;
            checc->next = NULL;
            checc->prev = NULL;
            checc = pchecc->next;
        }
    }
    // condition for last element ( ERROR IN CODE , IT SHOULD RUN TILL LAST ELEMENT )
    if(tmap.find(checc->data) != tmap.end()) 
    {
        pchecc->next = NULL;
        checc->prev = NULL;
    }
}

/* Function to insert a node at the beginning
of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* since we are adding at the beginning,
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list */
void printList(struct Node* head)
{
	/* if list is empty */
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Create the doubly linked list:
	4<->4<->4<->4<->6<->8<->8<->10<->12<->12 */
  push(&head, 45);
	push(&head, 12);
	push(&head, 13);
	push(&head, 12);
	push(&head, 10);
	push(&head, 8);
	push(&head, 45);
	push(&head, 6);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);

	cout << "Original Doubly linked list:n";
	printList(head);

	/* remove duplicate nodes */
	removeDuplicates(head);

	cout << "\nDoubly linked list after"
			" removing duplicates: ";
	printList(head);

	return 0;
}
