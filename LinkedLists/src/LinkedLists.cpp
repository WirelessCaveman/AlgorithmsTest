/*
 ============================================================================
 Name        : LinkLists.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node *next;
	struct Node *prev;
};

void PrintLinkedList(struct Node* head)
{
	while (head != NULL)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

struct Node* MergeLinkedLists(struct Node *l1, struct Node *l2)
{
	struct Node temp;
	struct Node *curr = &temp;

	while ((l1) && (l2))
	{
		if ((l1->value < l2->value))
		{
			curr->next = l1;
			l1 = l1->next;
		}
		else
		{
			curr->next = l2;
			l2 = l2->next;
		}
		curr = curr->next;
	}

	if (l1)
	{
		curr->next = l1;
	}
	else
	{
		curr->next = l2;
	}

	return temp.next;
}

void LinkedListReverse(Node **head)
{
	Node *curr = *head;
	Node *prev = NULL;

	while (curr != NULL)
	{
		Node *tmp  = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	*head = prev;
}

Node* RecursiveCallLinkedListReverse(Node **head, Node *curr)
{
	if (curr->next != NULL)
	{
		Node *prev = RecursiveCallLinkedListReverse(head, curr->next);
		prev->next = curr;
	}
	else
	{
		*head = curr;
	}
	return curr;
}

void LinkedListReverseRecursive(Node **head)
{
	if ((*head != NULL) && ((*head)->next != NULL))
	{
		Node *last = RecursiveCallLinkedListReverse(head, *head);
		last->next = NULL;
	}
}

void ReverseDoubleLinkedList(Node **head)
{
	Node *prev = NULL;
	Node *curr = *head;

	while (curr != NULL)
	{
		Node *tmp = curr->next;
		curr->next = prev;
		curr->prev = tmp;
		prev = curr;
		curr = tmp;
	}
	*head = prev;
}

Node* ReturnNthNodeFromEnd(Node *head, int n)
{
	int count = 0;
	Node *beforeN = head;
	while ((count < n) &&  (head != NULL))
	{
		head = head->next;
		++count;
	}
	if (head == NULL) return NULL;
	while (head->next != NULL)
	{
		head = head->next;
		beforeN = beforeN->next;
	}
	return beforeN;
}

//http://www.careercup.com/question?id=5838726617890816
Node* ReverseKAlternateNodes(Node *head, int k)
{
	Node *curr = head;
	Node *prev = NULL;
	Node *prevStop = NULL;
	Node *lastStop = NULL;
	Node *tmp = NULL;

	while (true)
	{
		for (int i = 0; (i < k-1) && (curr->next != NULL); ++i)
		{
			curr = curr->next;
		}
		if (curr->next == NULL) break;
		prevStop = curr;
		prev = curr;
		curr = curr->next;
		lastStop = curr;

		for (int i = 0; (i < k-1) && (curr->next != NULL); ++i)
		{
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		prevStop->next = curr;
		tmp = curr->next;
		curr->next = prev;
		curr = tmp;
		lastStop->next = curr;
		if (curr == NULL) break;
	}
	return head;
}

//Split the nodes of the given list into front and back halves,
//and return the two lists using the reference parameters.
//If the length is odd, the extra node should go in the front list.
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef)
{
	if (source == NULL) {*frontRef = NULL; *backRef = NULL; return;}

	struct Node* slow = source;
	struct Node* fast = source;
	while ((fast->next != NULL) && (fast->next->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	*backRef = slow->next;
	slow->next = NULL;
	*frontRef = source;
}

int main(void)
{
	struct Node* node7 = (Node *)malloc(sizeof(struct Node));
	node7->value = 15;
	node7->next = NULL;
	struct Node* node6 = (Node *)malloc(sizeof(struct Node));
	node7->prev = node6;
	node6->value = 13;
	node6->next = node7;
	struct Node* node5 = (Node *)malloc(sizeof(struct Node));
	node6->prev = node5;
	node5->value = 12;
	node5->next = node6;
	struct Node* node4 = (Node *)malloc(sizeof(struct Node));
	node5->prev = node4;
	node4->value = 8;
	node4->next = node5;
	struct Node* node3 = (Node *)malloc(sizeof(struct Node));
	node4->prev = node3;
	node3->value = 4;
	node3->next = node4;
	struct Node* node2 = (Node *)malloc(sizeof(struct Node));
	node3->prev = node2;
	node2->value = 3;
	node2->next = node3;
	struct Node* node1 = (Node *)malloc(sizeof(struct Node));
	node2->prev = node1;
	node1->value = 3;
	node1->next = node2;
	node1->prev = NULL;

	struct Node* node05 = (Node *)malloc(sizeof(struct Node));
	node05->value = 7;
	node05->next = NULL;
	struct Node* node04 = (Node *)malloc(sizeof(struct Node));
	node04->value = 3;
	node04->next = node05;
	struct Node* node03 = (Node *)malloc(sizeof(struct Node));
	node03->value = 3;
	node03->next = node04;
	struct Node* node02 = (Node *)malloc(sizeof(struct Node));
	node02->value = 2;
	node02->next = node03;
	struct Node* node01 = (Node *)malloc(sizeof(struct Node));
	node01->value = 0;
	node01->next = node02;

	struct Node* head1 = node1;
	struct Node* tail1 = node7;
	struct Node* head01 = node01;

	PrintLinkedList(head1);

//	printf("\nReturn Nth node from End: ");
//	printf("%d\n\n", (ReturnNthNodeFromEnd(node1, 3))->value);

//	printf("Reverse Single Linked List: ");
//	LinkedListReverse(&head1);
//	PrintLinkedList(head1);
//	printf("\n");
//	LinkedListReverse(&head1);
//	PrintLinkedList(head1);

	printf ("ReverseDoubleLinkedList\n");
	ReverseDoubleLinkedList(&head1);
	PrintLinkedList(head1);

//	printf("Merge Linked Lists\n");
//	PrintLinkedList(head01);
//	struct Node* mergedHead = MergeLinkedLists(head1, head01);
//	PrintLinkedList(mergedHead);
//
//	printf ("ReverseKAlternateNodes\n");
//	PrintLinkedList(ReverseKAlternateNodes(head1, 2));

//	printf ("FrontBackSplit\n");
//	struct Node *front;
//	struct Node *back;
//	FrontBackSplit(head1, &front, &back);
//	PrintLinkedList(front);
//	PrintLinkedList(back);

//	printf("Linked Lists Reverse Recursive\n");
//	PrintLinkedList(head01);
//	LinkedListReverseRecursive(&head01);
//	PrintLinkedList(head01);

	puts("!!!Linked Lists!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

