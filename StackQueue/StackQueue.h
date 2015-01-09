/*
 * StackQueue.h
 *
 *  Created on: Jan 8, 2015
 *      Author: Wireless Caveman
 */

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
		void StackPush(Node *nodePtr);
		Node* StackPop(void);
	private:
		static const int MAX_NODES = 50;
		Node* NodeStackArr[MAX_NODES];
		int NodeStackIndex;
};

class NodeQue
{
	public:
		NodeQue(void) : NodeQueHead(0), NodeQueTail(0), NodeQueCount(0) {}
		void QuePush(Node *nodePtr);
		Node* QuePull(void);
	private:
		static const int MAX_NODES = 50;
		Node* NodeQueArr[MAX_NODES];
		int NodeQueHead;
		int NodeQueTail;
		int NodeQueCount;
};
