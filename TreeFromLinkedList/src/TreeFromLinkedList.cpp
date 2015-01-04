//============================================================================
// Name        : TreeFromLinkedList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Create tree from Linked list
//1. TreeFromLinkedList: This creates a tree using recursive method. The third method is better and does the same thing
//2. TreeFromLinkedList_ArrCount: This also uses recursion, but first loads the LL to an Array, so no repeated curr->next to get to mid node
//3. RecursiveTreeFromLLWrapper: This method uses the standard recursive method to convert LL to tree and best in this file.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct TNode
{
	int Value;
	struct TNode* Left;
	struct TNode* Right;
	TNode(int val, TNode* l, TNode* r) : Value(val), Left(l), Right(r) {}
};

void PrintLinkedList(struct TNode* head)
{
	while (head != NULL)
	{
		printf("%d ", head->Value);
		head = head->Right;
	}
	printf("\n");
}

class NodeQue
{
	public:
		NodeQue(void) : NodeQueHead(0), NodeQueTail(0), NodeQueCount(0) {}
		void QuePush(TNode *nodePtr)
		{
			assert(NodeQueCount < MAX_NODES);
			if (NodeQueHead >= MAX_NODES) {NodeQueHead = 0;}
			NodeQueArr[NodeQueHead++] = nodePtr;
			++NodeQueCount;
		}

		TNode* QuePull(void)
		{
			if (NodeQueCount <= 0) return NULL;
			--NodeQueCount;
			if (NodeQueTail >= MAX_NODES) {NodeQueTail = 0;}
			return NodeQueArr[NodeQueTail++];
		}
	private:
		static const int MAX_NODES = 50;
		TNode* NodeQueArr[MAX_NODES];
		int NodeQueHead;
		int NodeQueTail;
		int NodeQueCount;
};

void TopToBottom(TNode *head)
{
	NodeQue saveQue;

	if (head == NULL) return;

	TNode *currentNode = head;

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

TNode * RecursiveCreateTree(TNode *midNode, TNode *head, int count)
{
	if (count == 0)
	{
		return NULL;
	}
	else if (count == 1)
	{
		head->Left = NULL;
		head->Right = NULL;
		return head;
	}

	int midCount = (count)/2;
	TNode *curr = head;
	for (int i = 0; i < (midCount/2); ++i)
	{
		curr = curr->Right;
	}
	midNode->Left = RecursiveCreateTree(curr, head, midCount);

	curr = midNode->Right;
	if (curr == NULL) return NULL;
	for (int i = 0; i < ((count - midCount - 1)/2); ++i)
	{
		curr = curr->Right;
	}
	midNode->Right = RecursiveCreateTree(curr, midNode->Right, count - midCount - 1);

	return midNode;
}

TNode * TreeFromLinkedList(TNode *head)
{
	int count = 0;
	TNode *curr = head;
	TNode *midNode = head;
	TNode *mid = curr;
	while (curr)
	{
		++count;
		curr = curr->Right;
		if (!(count & 0x1))
		{
			++mid;
			midNode = midNode->Right;
		}
	}
	printf("count: %d\n", count);
	RecursiveCreateTree(midNode, head, count);
	return midNode;
}

TNode * RecursiveTreeFromLL(TNode *head, int size)
{
	if(size == 0) return NULL;
	if (size == 1) {head->Right = NULL; head->Left = NULL; return head;}

	TNode *midNode = head;
	for (int i = 0; i < size/2; ++i)
	{
		midNode = midNode->Right;
	}
	midNode->Left = RecursiveTreeFromLL(head, size/2);
	midNode->Right = RecursiveTreeFromLL(midNode->Right, size - size/2 - 1);
	return midNode;
}

TNode * RecursiveTreeFromLLWrapper(TNode *head)
{
	if ((head == NULL) || (head->Right == NULL)) return head;
	TNode *curr = head;
	int size = 0;
	while(curr)
	{
		++size;
		curr = curr->Right;
	}
	return RecursiveTreeFromLL(head, size);
}

TNode * RecursiveCreateTree_ArrCount(TNode *ptrArr[], int count)
{
	assert(count >= 0);
	if (count == 0) return NULL;
	if (count == 1)
	{
		ptrArr[0]->Left = NULL;
		ptrArr[0]->Right = NULL;
		return ptrArr[0];
	}

	TNode *mid = ptrArr[(count/2) /*no +1*/];
	mid->Left = RecursiveCreateTree_ArrCount(ptrArr, count/2);
	if ((count - (count/2) - 1) >= 0)
	{
		mid->Right = RecursiveCreateTree_ArrCount(&(ptrArr[(count/2) + 1]), count - (count/2) - 1);
	}
	return mid;
}

TNode * TreeFromLinkedList_ArrCount(TNode *head)
{
	int count = 0;
	TNode* ptrArr[1000];
	while (head != NULL)
	{
		ptrArr[count++] = head;
		head = head->Right;
	}

	return (RecursiveCreateTree_ArrCount(ptrArr, count));
}


int main()
{
	struct TNode* node9 = (struct TNode *)malloc(sizeof(struct TNode));
	node9->Value = 15;
	node9->Right = NULL;
	struct TNode* node8 = (struct TNode *)malloc(sizeof(struct TNode));
	node8->Value = 14;
	node8->Right = node9;
	struct TNode* node7 = (struct TNode *)malloc(sizeof(struct TNode));
	node7->Value = 12;
	node7->Right = node8;
	struct TNode* node6 = (struct TNode *)malloc(sizeof(struct TNode));
	node6->Value = 11;
	node6->Right = node7;
	struct TNode* node5 = (struct TNode *)malloc(sizeof(struct TNode));
	node5->Value = 10;
	node5->Right = node6;
	struct TNode* node4 = (struct TNode *)malloc(sizeof(struct TNode));
	node4->Value = 8;
	node4->Right = node5;
	struct TNode* node3 = (struct TNode *)malloc(sizeof(struct TNode));
	node3->Value = 4;
	node3->Right = node4;
	struct TNode* node2 = (struct TNode *)malloc(sizeof(struct TNode));
	node2->Value = 3;
	node2->Right = node3;
	struct TNode* node1 = (struct TNode *)malloc(sizeof(struct TNode));
	node1->Value = 2;
	node1->Right = node2;

	PrintLinkedList(node1);

//	TopToBottom(TreeFromLinkedList(node1));
//	TopToBottom(TreeFromLinkedList_ArrCount(node1));
	TopToBottom(RecursiveTreeFromLLWrapper(node1));

	return 0;
}

