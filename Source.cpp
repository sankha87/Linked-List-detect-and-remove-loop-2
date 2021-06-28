#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

Node* push(Node *head_ref, int new_data)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;
		new_node->next = head_ref;
		head_ref = new_node;
		return head_ref;
	}
}

Node* append(Node *head_ref, int new_data)
{
	struct Node *temp = head_ref;

	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
		printf("\nStack Overflow");
	else
	{
		new_node->data = new_data;

		if (temp != NULL)
		{
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
			new_node->next = NULL;
		}
		else
		{
			new_node->next = head_ref;
			head_ref = new_node;
		}
		return head_ref;
	}
}

void printList(Node* head)
{
	while (head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}

// Function to detect and remove loop in a linked list that may contain loop 
void detectAndRemoveLoop(Node* head)
{
	// If list is empty or has only one node without loop 
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	slow = slow->next;				// Move slow and fast 1 and 2 steps ahead respectively. 
	fast = fast->next->next;

	while (fast != NULL && fast->next != NULL)		// Search for loop using slow and fast pointers 
	{
		if (slow == fast)
		{
			printf("\nCycle detected");
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		printf("\nCycle not detected");

	if (slow == fast)			/* If loop exists */
	{
		slow = head;

		while (slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}

		/* since fast->next is the looping point */
		fast->next = NULL; /* remove loop */
	}
}

int main()				/* Driver program to test above function*/
{
	struct Node *head = NULL, *head2 = NULL;

	head = append(head, 15);
	head = append(head, 4);
	head = append(head, 10);
	head = append(head, 8);
	head = push(head, 20);
	head = push(head, 50);
	//		while (1)				//	- for checking Stack overflow condition
	//		head = append(head, 9);
	head->next->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);
	printf("\nLinked List after removing loop \n");
	printList(head);

	_getch();
}