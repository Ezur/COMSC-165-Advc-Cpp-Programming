#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() : value(0), next(nullptr), prev(nullptr) {};

LinkedList::LinkedList(int value) : value(value), next(nullptr), prev(nullptr) {};

int LinkedList::get_length()
{
	if (!next) return 1;
	return 1 + next -> get_length();
}

void LinkedList::print_list(LinkedList *head)
{
	for (const LinkedList *nodePtr = head; nodePtr; nodePtr = nodePtr->next)
			cout << nodePtr->value << endl;

//	cout << value << " ";
//	if (next)
//		next -> print_list(head);
}

void LinkedList::print_list_backwards()
{
	cout << value << " ";
	if (prev)
		prev -> print_list_backwards();
}

void LinkedList::append_node(int number, LinkedList *&head, LinkedList *&tail)
{
	if (!next)
	{
		// we are at the last element of list
		LinkedList* newNode = new LinkedList;

		newNode->value = number;
		newNode->next = nullptr;

		next = newNode;

		newNode->prev = this;

		tail = newNode;
	}
	else
	{
		next->append_node(number, head, tail);
	}
}

LinkedList* LinkedList::insert_node(int index, int number, LinkedList*& tail) {
	if (index == 0) {
		// should insert before
		LinkedList* new_node = new LinkedList(number);
		if (prev) prev -> next = new_node;
		new_node -> prev = prev;
		new_node -> next = this;
		prev = new_node;
		return new_node;
	}
	if (!next) {
		// assert(index == 1); // we should put the next one at the end
		LinkedList* new_node = new LinkedList(number);
		next = new_node;
		new_node -> prev = this;
		tail = new_node;
		return this;
	}
	next = next -> insert_node(index - 1, number, tail);
	return this;
}

LinkedList* LinkedList::delete_node(int number, LinkedList *& tail) {
	if (number == value) {
		if (prev) prev -> next = next;
		if (next) next -> prev = prev;
		else tail = prev;
		return next;
	} else {
		if (next) next = next -> delete_node(number, tail);
		return this;
	}
}
