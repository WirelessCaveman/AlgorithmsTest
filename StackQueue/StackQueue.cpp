/*
 * StackQueue.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: Wireless Caveman
 */


#include <assert.h>

#include "StackQueue.h"

void NodeStack::StackPush(Node *nodePtr)
{
	if (NodeStackIndex < MAX_NODES) NodeStackArr[NodeStackIndex++] = nodePtr;
}

Node* NodeStack::StackPop(void)
{
	if (NodeStackIndex > 0) return NodeStackArr[--NodeStackIndex];
	else return NULL;
}

void NodeQue::QuePush(Node *nodePtr)
{
	assert(NodeQueCount < MAX_NODES);
	if (NodeQueHead >= MAX_NODES) {NodeQueHead = 0;}
	NodeQueArr[NodeQueHead++] = nodePtr;
	++NodeQueCount;
}

Node* NodeQue::QuePull(void)
{
	if (NodeQueCount <= 0) return NULL;
	--NodeQueCount;
	if (NodeQueTail >= MAX_NODES) {NodeQueTail = 0;}
	return NodeQueArr[NodeQueTail++];
}




