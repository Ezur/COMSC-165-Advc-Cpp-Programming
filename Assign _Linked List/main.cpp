//============================================================================
// Name        : PA 12 Linked List
// Author      : Elise Zur
//============================================================================

#include <iostream>
using namespace std;

struct LinkedList
{
	int value;
	LinkedList* next;
};

void print_list(LinkedList *);
void append_node(int, LinkedList *&);
void insert_node(int, int, LinkedList *&);
void delete_node(int, LinkedList *&);
int search_node(int, LinkedList *);
void destroy_list(LinkedList *&);

int main()
{
	int num_of_nodes = 0;
	int number = 0, index = 0;

	LinkedList *head = nullptr;

	do
	{
		cout << "Enter the number of initial nodes"
				" (must be at least 1): ";
		cin >> num_of_nodes;
	}
	while(num_of_nodes < 1);


	cout << endl;

	for(int i = 0; i < num_of_nodes; i++)
	{
		cout << "Enter a number: ";
		cin >> number;

		append_node(number, head);
	}

	cout << endl << "Here is the initial linked list:" << endl;
	print_list(head);

	// APPEND NODE
	cout << "\nEnter a number to ADD to the list: ";
	cin >> number;

	append_node(number, head);

	cout << "Here is the updated linked list: " << endl;
	print_list(head);


	// INSERT NEW NODE AT X LOCATION
	cout << "\nHint: Enter 1 to insert as the first number in the list, " << num_of_nodes + 2
		 << " to insert as the last number in the list." << endl << endl;

	cout << "Enter a location between 1- " << num_of_nodes + 2 << ": ";

	cin >> index;

	cout << "\nEnter a number to INSERT to the list at location " << index << ": ";
	cin >> number;

	insert_node(index, number, head); 	// index @ where to add node, value of node, head ptr
	cout << "Here is the updated linked list: " << endl;
	print_list(head);


	// DELETE NODE
	cout << "Enter the number of the node that you want to delete from the linked list: ";
	cin >> number;

	delete_node(number, head);

	cout << "Here is the updated linked list: " << endl;
	print_list(head);


	// SEARCH FOR NODE
	int found = 0;

	cout << "Enter the number that you want to search for in the list: ";
	cin >> number;

	found = search_node(number, head);

	if (found == -1)
		cout << endl << "Number was not found in linked list.";
	else
		cout << "Number found at index " << found+1 << " in the linked list";


	// DESTROY LIST
	destroy_list(head);

	return 0;
}

// COMMENT ONE
// print_list function executes many times in this program.
// at the beginning of the function, it will execute to display the
// initial linked list and from that point on, it will execute
// after a desired action is finished to show the user the
// current state of the list.
void print_list(LinkedList *head)
{
	// COMMENT TWO
	// the for loop is using nodePtr as a pointer at our struct
	// LinkedList. the for loop executes until nodePtr has the
	// value of nullptr. the loop will continue to go through the
	// values using nodePtr->next.
	for (const LinkedList *nodePtr = head; nodePtr; nodePtr = nodePtr->next)
		cout << nodePtr->value << endl;
}

// COMMENT THREE
// append_node function will take a number that the user was
// asked to input, and add that number to the end of the
// linked list. this requires us to use a newNode pointer
// and use the reference of pointer head.
void append_node(int number, LinkedList *&head)
{
	LinkedList *newNode = new LinkedList;
	newNode->value = number;
	newNode->next = nullptr;

	// COMMENT FOUR
	// this if statement checks the condition, if head == nullptr,
	// then set head to the newNode. this is really saying, if the list
	// is empty, then set the head to the value of the newNode.
	if(!head)
		head = newNode; 	// head is pointing to the new memory
	else
	{
		// COMMENT FIVE
		// the else statement runs when the list is populated with numbers.
		// first, we need to create the pointer named nodePtr and loop
		// through the list to check the values. the for loop will loop
		// through to the end of the list, the condition is checking to see
		// when nodePtr-> next. when this value is met, it will insert
		// newNode as the last node of the list.

		LinkedList *nodePtr;

		for (nodePtr = head; nodePtr->next; nodePtr = nodePtr->next);

		nodePtr->next = newNode;
	}
}

// COMMENT SIX
// insert_node function will take a number that was chosen by the user
// and place a new node within the function. the location will be
// specified by the user, and will take the variable, index.
void insert_node(int index, int number, LinkedList *&head)
{
	int loop_index = 0;
	LinkedList *newNode;
	LinkedList *nodePtr = head;	// to traverse the list
	LinkedList *previousNode = nullptr;

	newNode = new LinkedList;
	newNode->value = number;

//	nodePtr = head;
//	previousNode = nullptr;

	// COMMENT SEVEN
	// the if statement will check the condition- if the index's value
	// - 1, for the offset, is equal to zero, the newNode will be
	// assigned to head. before we can do that, we must
	// reconnect the linked list together, but using newNode->next
	if (index-1 == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		// for practice, does the same thing as the while loop

//		for(nodePtr = head, previousNode = nullptr, loop_index = 0;
//		   (nodePtr && loop_index < index-1);
//		   previousNode = nodePtr, nodePtr = nodePtr->next, loop_index++);

		while((nodePtr != nullptr) && (loop_index++ < index-1))
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}
}

// COMMENT EIGHT
// delete_node function will take a number that was specified by the
// user and place a new node within the function. the user could
// choose an index to place the new number at the front of the list,
// in the middle, or at the very end of the list. depending on
// where that user-specified index is, the function
// will execute the if or else statement.
void delete_node(int number, LinkedList *&head)
{
	LinkedList *nodePtr;
	LinkedList *previousNode;

	if (head->value == number)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		// COMMMENT NINE
		// this while loop will skill all the nodes whose value
		// is not equal to the number the user entered in main.
		// this can change throughout the function. outside the while
		// loop, there is an if statement that will check
		// if nodePtr is not at the end of the list,
		// then link the previous node to the node after nodePtr,
		// then delete nodePtr.
		while (nodePtr != nullptr && nodePtr->value != number)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

// COMMENT TEN
// search_node function will search through the linked list to find
// a number that will be user-specified in main. the number
// is stored in the variable search_value. inside the function,
// the while loop will execute while temp has a value.
// if the function finds the value in the list,
// it will return that index to main. if it does not find the
// value, then it will return a -1 to main.
int search_node(int search_value, LinkedList *head)
{
	int index = 0;
	const LinkedList *temp = head;

	while(temp != nullptr)
	{
		if ((temp->value) == search_value)
		{
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

// COMMENT ELEVEN
// destroy_list function will make sure that a memory
// leak or dangling pointer is not going to happen
// by deleting the pointer and the linked list at
// the end of the program.
void destroy_list(LinkedList *&head)
{
	LinkedList *nodePtr;
	LinkedList *nextNode;

	nodePtr = head;

	while(nodePtr != nullptr)
	{
		// save a pointer to the next node
		nextNode = nodePtr->next;

		// delete current node
		delete nodePtr;

		// position nodePtr at the next node
		nodePtr = nextNode;
	}
}
