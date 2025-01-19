#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{

	private:
		int value;
		LinkedList *next;
		LinkedList *prev;
	public:
		LinkedList();
		LinkedList(int);
		int get_length();
		void print_list(LinkedList *);
		void print_list_backwards();
		void append_node(int, LinkedList *&, LinkedList *&);
		LinkedList* insert_node(int, int, LinkedList *&);
		//LinkedList* reverse_list();
		LinkedList* delete_node(int, LinkedList *&);
		/*int search_list_from_end(int);
		void destroy_list();*/
};

#endif
