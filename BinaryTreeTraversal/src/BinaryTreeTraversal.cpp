//============================================================================
// Name        : BinaryTreeTraversal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include "../../StackQueue/StackQueue.h"
// for linbrary, inclue ../../StackQueue/${ConfigName}/libStackQueue.a

using namespace std;

class Node
{
public:
	int Value;
	struct Node* Left;
	struct Node* Right;
	Node(int val, Node* l, Node* r) : Value(val), Left(l), Right(r) {}
};

class NodeStack
{
	public:
		NodeStack(void) : NodeStackIndex(0) {}
		void StackPush(Node *nodePtr)
		{
			if (NodeStackIndex < MAX_NODES) NodeStackArr[NodeStackIndex++] = nodePtr;
		}

		Node* StackPop(void)
		{
			if (NodeStackIndex > 0) return NodeStackArr[--NodeStackIndex];
			else return NULL;
		}
	private:
		static const int MAX_NODES = 50;
		Node* NodeStackArr[MAX_NODES];
		int NodeStackIndex;
};

class NodeQue
{
	public:
		NodeQue(void) : NodeQueHead(0), NodeQueTail(0), NodeQueCount(0) {}
		void QuePush(Node *nodePtr)
		{
			assert(NodeQueCount < MAX_NODES);
			if (NodeQueHead >= MAX_NODES) {NodeQueHead = 0;}
			NodeQueArr[NodeQueHead++] = nodePtr;
			++NodeQueCount;
		}

		Node* QuePull(void)
		{
			if (NodeQueCount <= 0) return NULL;
			--NodeQueCount;
			if (NodeQueTail >= MAX_NODES) {NodeQueTail = 0;}
			return NodeQueArr[NodeQueTail++];
		}
	private:
		static const int MAX_NODES = 50;
		Node* NodeQueArr[MAX_NODES];
		int NodeQueHead;
		int NodeQueTail;
		int NodeQueCount;
};


void DepthFirst(Node *head)
{
	NodeStack stack;
	while (head)
	{
		printf("%d ", head->Value);
		if (head->Right != NULL) stack.StackPush(head->Right);
		head = head->Left;
		if (!head) head = stack.StackPop();
	}
}

void DepthFirstRecursive(Node *head)
{
	if (head)
	{
		printf("%d ", head->Value);
		DepthFirstRecursive(head->Left);
		DepthFirstRecursive(head->Right);
	}
}

void TopToBottom(Node *head)
{
	NodeQue saveQue;

	if (head == NULL) return;

	Node *currentNode = head;

	while(currentNode)
	{
		printf("%d ", currentNode->Value);
		if (currentNode->Left)
		{
			saveQue.QuePush(currentNode->Left);
		}
		if (currentNode->Right)
		{
			saveQue.QuePush(currentNode->Right);
		}
		currentNode = saveQue.QuePull();
	}
}

void BottomToTop(Node *head)
{
	NodeStack stack;
	NodeQue que;

	while (head)
	{
		stack.StackPush(head);
		if (head->Right)
		{
			que.QuePush(head->Right);
		}
		if (head->Left)
		{
			que.QuePush(head->Left);
		}
		head = que.QuePull();
	}

	while (head = stack.StackPop())
	{
		printf("%d ", head->Value);
	}
}

void BinaryTreeMirrorNoRecursion(Node *head)
{
	NodeStack memStack;

	Node *currentNode = head;
	while (currentNode)
	{
		Node *tempNode = currentNode->Right;
		currentNode->Right = currentNode->Left;
		currentNode->Left = tempNode;
		if (NULL != currentNode->Right)
		{
			memStack.StackPush(currentNode->Right);
		}
		if (NULL != currentNode->Left)
		{
			currentNode = currentNode->Left;
		}
		else
		{
			currentNode = memStack.StackPop();
		}
	}

	TopToBottom(head);
}

void BinaryTreeMirrorRecursion(Node *head)
{
	if (head != NULL)
	{
		Node *tmp = head->Left;
		head->Left = head->Right;
		head->Right = tmp;
		BinaryTreeMirrorRecursion(head->Left);
		BinaryTreeMirrorRecursion(head->Right);
	}
}


/********************************************************
									8
				4										17
		3				7					10						25
				      6								12
				   5     6

*********************************************************/

int main()
{
	Node *node5 = new struct Node(5, NULL, NULL);
	Node *node6s = new struct Node(6, NULL, NULL);
	Node *node6 = new struct Node(6, node5, node6s);
	Node *node7 = new struct Node(7, node6, NULL);
	Node *node3 = new struct Node(3, NULL, NULL);
	Node *node4 = new struct Node(4, node3, node7);
	Node *node12= new struct Node(12, NULL, NULL);
	Node *node10= new struct Node(10, NULL, node12);
	Node *node25= new struct Node(25, NULL, NULL);
	Node *node17= new struct Node(17, node10, node25);
	Node *node8 = new struct Node(8, node4, node17);

	printf("DepthFirst\n");
	DepthFirst(node8);

	printf("\n\n");
	printf("DepthFirstRecursive\n");
	DepthFirstRecursive(node8);

	printf("\n\n");
	printf("TopToBottom\n");
	TopToBottom(node8);

	printf("\n\n");
	printf("BottomToTop\n");
	BottomToTop(node8);

	printf("\n\n");
	printf("BinaryTreeMirrorNoRecursion\n");
	BinaryTreeMirrorNoRecursion(node8);
	printf("\n");
	BinaryTreeMirrorNoRecursion(node8);

	printf("\n\n");
	printf("BinaryTreeMirrorRecursion\n");
	BinaryTreeMirrorRecursion(node8);
	TopToBottom(node8);
	printf("\n");
	BinaryTreeMirrorRecursion(node8);
	TopToBottom(node8);

//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
