/*Cole Mark Olafson
 *September 11, 2020
 *Computer Science 346-02
 *Program 1: Merge Sort
 *This program was made by implementing the merge sort function in order to sort a list of nodes
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//the typedef is used so I didn't have to type struct node everytime I needed to use a node
typedef struct node node;
struct node
{
	int data;
	node * next;
};

//merge function takes in two perameters that point to a sorted list and returns a new head pointer that points to
//the merged list
node * merge(node* left, node * right)
{
	node* tracer = NULL;
	node* leftPoint = left;
	node* rightPoint = right;
	if(leftPoint && rightPoint)
	{
	 if(leftPoint->data < rightPoint->data)
    	{
		left = leftPoint;
		leftPoint = leftPoint->next;
	}
     	 else
     	 {
		 left = rightPoint;
	   	 rightPoint = rightPoint->next;
     	 }
     	 tracer = left;
      	}
      	while(leftPoint && rightPoint)
	{
		if(leftPoint->data < rightPoint->data)
		{
			tracer->next = leftPoint;
			leftPoint = leftPoint->next;
		}
	    	else
	    	{
		  	tracer->next = rightPoint;
		  	rightPoint = rightPoint->next;
	    	}
	    	tracer = tracer->next;
	}
	tracer->next = (leftPoint) ? leftPoint : rightPoint;
	return left;
}

//utilizes the merge function and recursion to sort the list
node * mergeSort(node * left , int len)
{
	if(len>1)
	{
	    	int it = (len-1)/2;
	    	int mid = len/2;
	    	node* temp = left;
	    	node* prev = temp;
	    	for(int i = 0; i < it; i++)
	    	{
		  	prev = prev -> next;
	    	}
	    	temp = prev->next;
	    	prev -> next = NULL;
	    	left = mergeSort(left, len - mid);
	    	temp = mergeSort(temp, mid);
	    	left = merge(left, temp);
      	}
      	return left;
}

//this function is to generate a new node
node * nodeGen(node* node1, int nodeData)
{
	node1 = malloc(sizeof(node));
	node1->data = nodeData;
	node1->next = NULL;
	return node1;
}

//this returns a true or false to check if the list is sorted or not
bool  checkIfSorted(node* head)
{
	node* temp = head->next;
	node* prev = head;
	while(temp)
	{
		if(prev->data > temp->data)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}

//add at head
node * addAtHead(node* head, int data)
{
	node* temp = NULL;
	temp = nodeGen(temp, data);
	temp->next = head;
	head = temp;
	temp = NULL;
	return head;
}

//check for missing nodes
bool checkListIntegrity(node* head, int length)
{
	node* temp = head;
	int counter = 0;
	while(temp)
	{
		temp = temp->next;
		counter++;
	}
	if(length == counter)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//prints list
void printList(node* head)
{
	node* temp = head;
	while(temp)
	{
		printf("%d, ", temp->data);
		temp = temp->next;	
	}
	printf("\n");
}

int main()
{
	node* head = NULL;
	head = addAtHead(head, 86);
	head = addAtHead(head, 42);
	head = addAtHead(head, 38);
	head = addAtHead(head, 12);
	head = addAtHead(head, 8);
	head = addAtHead(head, 69);
	head = addAtHead(head, 70);
	head = addAtHead(head, 21);
	head = addAtHead(head, 10);
	printf("Unsorted List\n");
	printList(head);
	head = mergeSort(head, 9);
	printf("Sorted List\n");
	printList(head);
	if(checkIfSorted(head))
	{
		printf("List is correctly sorted \n");
	}
	else
	{
		printf("List is incorrectly sorted \n");
	}
	if(checkListIntegrity(head, 9))
	{
		printf("List has no missing nodes\n");
	}
	else
	{
		printf("List has missing nodes\n");
	}
	return 0;
}
