// C++ program to find a pair with given sum x in given DLL
// Arn0dian

#include<bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
	int data;
	struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x in sorted LL
void pairSuminSorted(struct Node *head, int x)
{
	Node* first = head;
    Node* second = head;

    while (second->next!=NULL)
    {
        second = second->next;
    }
    
    bool found = false;

    while (first!=second && first!=second->next)
    {
        // if the pair is found 
        if (first->data+second->data==x)
        {
            cout<<"Pair is : "<<first->data<<" "<<second->data<<endl;
            found = true;
            first = first->next;
            second = second->prev;
        }
        // if don't find the pair
        else if (first->data+second->data<x)
        {
            first = first->next;
        }
        else 
        {
            second = second->prev;
        }
    }
    if (found == false)
    {
        cout<<"No such pairs found";
    }    
}

// Function to find pair whose sum equal to given value x in a unsorted LL
void pairSuminUnSorted(struct Node *head, int x)
{
	// we use hashtable to store and checc the preexisting pair , as done in array
    map<int , int> tmap;
    Node* check = head;
    bool found = false;
    while (check!=NULL)
    {
        if (tmap.find(check->data)!=tmap.end())
        {
            cout<<"Pair is : "<<tmap[check->data]<<" "<<x-tmap[check->data]<<endl;
            found = true;
        }
        else 
        {
            tmap[x-check->data]=check->data;
        }
        check = check->next;
    }
    if(!found)
    cout<<"No such pairs exist";
}


// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program
int main()
{
	struct Node *head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 7;

	pairSuminUnSorted(head, x);

	return 0;
}
