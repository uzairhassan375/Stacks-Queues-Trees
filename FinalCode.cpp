#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* previous;

	Node(int value)
	{
		data = value;
		next = NULL;
		previous = NULL;
	}
};

class linkedlist
{
public:
	Node* head;
	linkedlist()
	{
		head = NULL;
	}



	void display()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* current = head;
			while (current != NULL)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}

	}

	void addFirst(int v)
	{
		Node* newNode = new Node(v);
		newNode->next = head;
		head = newNode;
	}

	void addLast(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void deleteFirst()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void deleteLast()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* current = head;
			Node* previous = NULL;
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			previous->next = NULL;
			delete current;
		}
	}

	void countNodes()
	{
		int count = 0;
		Node* current = head;
		while (current != NULL)
		{
			count++;
			current = current->next;

		}
		cout << "count: " << count << endl;
	}

	void  max()
	{
		if (head == NULL) {
			cout << "List is empty." << endl;
		}
		Node* current = head;
		int max = current->data;

		while (current != NULL)
		{
			if (current->data > max)
			{
				max = current->data;
			}
			current = current->next;
		}
		cout << "Maximum number is : " << max << endl;
	}

	void average()
	{
		int count = 0;
		double sum = 0;
		double average = 0;
		Node* current = head;
		if (head == NULL)
		{
			cout << "List is empty ";
		}
		else
		{
			while (current != NULL)
			{
				sum = sum + current->data;
				count++;
				current = current->next;
			}
		}
		average = sum / count;
		cout << "Average : " << average << endl;
	}

	int search(int key)
	{
		Node* current = head;
		while (current != NULL)
		{
			if (current->data == key)
			{
				cout << "Element Found" << endl;
			}
			current = current->next;
		}
		return 0;
	}

	void insertAt(int value, int pos)
	{
		Node* current = head;
		Node* newNode = new Node(value);
		if (pos < 1)
		{
			cout << "Invalid position" << endl;
			return;
		}
		else
		{

			for (int i = 1; i < pos - 1; i++)
			{
				current = current->next;
			}
			if (current == NULL)
			{
				cout << "Position out of bounds" << endl;
				delete newNode;
				return;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
	}

	void reverse()
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* current = head;
			Node* next;
			Node* previous = NULL;
			while (current != NULL)
			{
				next = current->next;
				current->next = previous;
				previous = current;
				current = next;
			}
			head = previous;
			Node* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;

		}

	}

	void isPalindrome() {
		if (head == NULL || head->next == NULL) {
			cout << "The linked list is a palindrome." << endl;
			return;
		}

		// Find the middle of the linked list
		Node* slow = head;
		Node* fast = head;

		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// Reverse the second half of the linked list
		Node* previous = NULL;
		Node* current = slow;
		Node* nextNode;

		while (current != NULL) {
			nextNode = current->next;
			current->next = previous;
			previous = current;
			current = nextNode;
		}

		// Compare the first half with the reversed second half
		while (previous != NULL) {
			if (head->data != previous->data) {
				cout << "The linked list is not a palindrome." << endl;
				return;
			}
			head = head->next;
			previous = previous->next;
		}

		cout << "The linked list is a palindrome." << endl;
	}


	void detectLoop() {
		if (!head) {
			cout << "No Loop";
		}

		Node* slow = head;
		Node* fast = head->next;
		while (fast && fast->next) {
			if (slow == fast)
			{
				cout << "Loop detected";
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		cout << "No Loop";
	}

};

class doublyLinkedlist
{
public:
	Node* head;
	doublyLinkedlist()
	{
		head = NULL;
	}
	void addFirst(int value)
	{
		Node* newnode = new Node(value);
		newnode->next = NULL;
		newnode->previous = NULL;
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head->previous = newnode;
			head = newnode;
		}
	}
	void addLast(int value)
	{
		Node* newnode = new Node(value);
		newnode->next = NULL;
		newnode->previous = NULL;
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node* current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = newnode;
			newnode->previous = current;
		}
	}
	void deleteFirst()
	{
		if (head == NULL)
		{
			return;
		}
		Node* current = head;
		head = head->next;
		if (head != NULL)
		{
			head->previous = NULL;
		}
		delete current;
	}
	void deleteLast()
	{
		Node* current = head;
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		delete current->next;
		current->next = NULL;
	}
	void insertatanyIndex(int pos, int value) {
		Node* current = head;
		Node* newNode = new Node(value);
		newNode->data = value;
		newNode->next = NULL;
		newNode->previous = NULL;

		if (head == NULL || pos == 0) {
			newNode->next = head;
			if (head != NULL) {
				head->previous = newNode;
			}
			head = newNode;
			return;
		}

		for (int i = 0; i < pos - 1 && current != NULL; i++) {
			current = current->next;
		}


		if (current == NULL) {
			cout << "Invalid position to insert\n";
			delete newNode;
			return;
		}

		newNode->next = current->next;
		newNode->previous = current;
		if (current->next != NULL) {
			current->next->previous = newNode;
		}
		current->next = newNode;
	}

	int Search(int key)
	{
		Node* current = head;
		int pos = 0;
		while (current != NULL)
		{
			if (current->data == key)
			{
				cout << "Search value is : " << pos << endl;
			}
			current = current->next;
			pos++;
		}
		return -1;
	}
	void countNode()
	{
		int count = 0;
		Node* current = head;
		while (current != NULL)
		{
			count++;
			current = current->next;

		}
		cout << "Nodes : " << count << endl;
	}
	int Max()
	{
		if (head == NULL)
		{
			cout << "List is Empty : " << endl;
		}
		else
		{
			Node* current = head;
			int max = current->data;

			while (current != NULL)
			{
				if (current->data > max)
				{
					max = current->data;
				}
				else
				{
					current = current->next;
				}
			}
			return max;
		}
	}
	void Average()
	{
		int count = 0;
		int sum = 0;
		int average = 0;
		Node* current = head;
		if (head == NULL)
		{
			cout << "List is empty ";
		}
		else
		{
			while (current != NULL)
			{
				sum = sum + current->data;
				count++;
				current = current->next;
			}
		}
		average = sum / count;
		cout << "Average : " << average << endl;

	}
	void reverseList() {
		Node* current = head;
		Node* temp = NULL;

		while (current != NULL) {

			temp = current->previous;
			current->previous = current->next;
			current->next = temp;

			current = current->previous;
		}
		if (temp != NULL) {
			head = temp->previous;
		}
	}
	void detectLoop() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node* slow = head;
		Node* fast = head->next;

		while (fast && fast->next)
		{
			if (slow == fast)
			{
				cout << "Loop detected" << endl;
				return;
			}
			slow = slow->next;
			fast = fast->next->next;
		}

		cout << "No loop detected" << endl;
	}
	void displayList() {
		Node* curr = head;

		if (curr == NULL) {
			cout << "Doubly Linked List is empty.";
			return;
		}

		cout << "Doubly Linked List: ";
		while (curr != NULL) {
			cout << curr->data << "  ";
			curr = curr->next;
		}
	}
};

class circularLinkedlist {
private:
	Node* head;
public:
	circularLinkedlist() :head(NULL) {}

	void addfirst(int value) {
		Node* newNode = new Node(value);
		if (head == NULL) {
			newNode->next = newNode;
		}
		else
		{
			Node* endingNode = head;
			while (endingNode->next != head) {
				endingNode = endingNode->next;
			}
			endingNode->next = newNode;
			newNode->next = head;

		}
		head = newNode;
	}
	void addLast(int value) {
		Node* newNode = new Node(value);

		if (head == NULL) {
			head = newNode;
			newNode->next = newNode;
		}
		else {
			Node* endingNode = head;
			while (endingNode->next != head) {
				endingNode = endingNode->next;
			}

			endingNode->next = newNode;
			newNode->next = head;
		}
	}
	void display() {
		if (head == NULL) {
			cout << "Empty\n";
			return;
		}
		Node* curr = head;
		do {
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head);
		cout << endl;
	}
	void insertAtPosition(int value, int pos) {
		Node* newNode = new Node(value);

		if (pos < 1) {
			cout << "Invalid position \n";
			return;
		}

		// If the list is empty or position is 1
		if (head == NULL || pos == 1) {
			newNode->next = head;
			head = newNode;

			if (head->next == NULL) {
				head->next = head;
			}
			return;
		}

		// Traverse to the desired position
		Node* curr = head;
		for (int i = 1; i < pos - 1 && curr->next != head; ++i) {
			curr = curr->next;
		}

		// Check if the position is valid
		if (curr == NULL || curr->next == head) {
			cout << "Invalid position \n";
			return;
		}

		// Update pointers to insert the new node 
		newNode->next = curr->next;
		curr->next = newNode;
	}
	void deleteFirst() {
		if (head == NULL) {
			cout << "List is empty\n";
			return;
		}

		Node* temp = head;
		// If there is only one node in the list
		if (head->next == head) {
			head = NULL;
			cout << "Element deleted successfully\n";
		}
		else {
			// If there is more than one node in the list
			Node* curr = head;
			while (curr->next != head) {
				curr = curr->next;
			}

			head = head->next;
			curr->next = head;
			cout << "Element deleted successfully\n";
		}

		delete temp;
	}
	int search(int value)
	{
		Node* current = head;
		while (current != NULL)
		{
			if (current->data == value)
			{
				cout << "\nElement found\n";
				return value;
			}
			current = current->next;
			if (current == head)
			{
				cout << "\nElement not found\n";
				return -1;
			}
		}
		cout << "\nElement not found\n";
		return -1;

	}
	int countNodes() {
		int count = 0;
		Node* current = head;

		// Check if the list is empty
		if (head == NULL) {
			return count;
		}

		while (current != NULL) {
			count++;
			current = current->next;

			if (current == head) {
				break;
			}
		}

		return count;
	}
	int max() {
		int max = 0;
		Node* current = head;
		while (current != NULL)
		{
			if (current->data > max)
			{
				max = current->data;
			}
			current = current->next;
			if (current == head)
			{
				break;
			}
		}
		return max;
	}
	double average()
	{
		int count = 0;
		double sum = 0;

		Node* current = head;

		while (current != NULL) {
			count++;
			current = current->next;
			sum = sum + current->data;


			if (current == head) {
				break;
			}
		}
		double average = sum / count;
		return average;
	}
	void reverse() {
		if (!head) {
			cout << "List is empty, Nothing to reverse\n";
			return;
		}

		Node* curr = head;
		Node* temp = NULL;
		Node* previous = NULL;

		// Traverse the list and reverse the direction of pointers
		do {
			temp = curr->next;
			curr->next = previous;
			previous = curr;
			curr = temp;
		} while (curr != head);

		// Update the head pointer to the new first node
		head->next = previous;
		head = previous;

		cout << "Reversed Circular Linked List : ";
		display();
	}
	void detectLoop() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node* slow = head;
		Node* fast = head->next;

		while (fast && fast->next)
		{
			if (slow == fast)
			{
				cout << "Loop detected" << endl;
				return;
			}
			slow = slow->next;
			fast = fast->next->next;
		}

		cout << "No loop detected" << endl;
	}
	void deleteLast() {
		if (!head) {
			cout << "List is empty, nothing to delete." << endl;
			return;
		}
		Node* curr = head;
		Node* previous = NULL;
		do {
			previous = curr;
			curr = curr->next;
		} while (curr != NULL && curr->next != head);

		if (curr == head) {
			delete curr;
			head = NULL;
			cout << "\nElement deleted successfully";
		}
		else if (curr != NULL) {
			previous->next = head;
			delete curr;
			cout << "\nElement deleted successfully";
		}
	}

};

class doubleCircularLinkedList {
private:
	Node* head;

public:
	doubleCircularLinkedList()
	{
		head = NULL;
	}

	//Insertion

	// Insert at the beginning
	void addFirst(int value)
	{
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			head->next = head;
			head->previous = head;
		}
		else {
			newNode->next = head;
			newNode->previous = head->previous;
			head->previous->next = newNode;
			head->previous = newNode;
			head = newNode;
		}
	}

	// Insert at the end
	void addLast(int value)
	{
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			head->next = head;
			head->previous = head;
		}
		else {
			newNode->previous = head->previous;
			newNode->next = head;
			head->previous->next = newNode;
			head->previous = newNode;
		}

	}

	// Insert at a specific position
	void insertAt(int value, int index)
	{
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			head->next = head;
			head->previous = head;
		}
		else
		{
			Node* current = head;
			for (int i = 1; i < index && current->next != head; i++)
			{
				current = current->next;
			}
			newNode->previous = current;
			newNode->next = current->next;
			current->next->previous = newNode;
			current->next = newNode;
		}
	}


	// Deletion
	// Delete from the beginning
	void deleteFirst()
	{
		if (!head) {
			cout << "list is empty";
		}
		if (head->next == head)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* temp = head;
			head->previous->next = head->next;
			head->next->previous = head->previous;
			head = head->next;
			delete temp;
		}
	}


	// Delete from the end
	void deleteLast()
	{
		if (!head) {
			cout << "list is empty";
		}
		if (head->next == head)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* temp = head->previous;
			temp->previous->next = head;
			head->previous = temp->previous;
			delete temp;

		}
	}


	// Search
	int search(int value)
	{
		Node* current = head;
		while (current != NULL)
		{
			if (current->data == value)
			{
				cout << "\nElement found\n";
				return value;
			}
			current = current->next;
			if (current == head)
			{
				cout << "\nElement not found\n";
				return -1;
			}
		}
		cout << "\nElement not found\n";
		return -1;

	}


	// Count Nodes
	int countNodes() {
		int count = 0;
		Node* current = head;

		// Check if the list is empty
		if (head == NULL) {
			return count;
		}

		while (current != NULL) {
			count++;
			current = current->next;

			if (current == head) {
				break;
			}
		}

		return count;
	}


	// Max
	int max() {
		int max = 0;
		Node* current = head;
		while (current != NULL)
		{
			if (current->data > max)
			{
				max = current->data;
			}
			current = current->next;
			if (current == head)
			{
				break;
			}
		}
		return max;
	}


	// Average
	double average()
	{
		int count = 0;
		double sum = 0;

		Node* current = head;

		while (current != NULL) {
			count++;
			current = current->next;
			sum = sum + current->data;


			if (current == head) {
				break;
			}
		}
		double average = sum / count;
		return average;
	}


	// Reverse
	void reverse() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}

		Node* current = head;
		Node* temp = NULL;

		do {
			temp = current->next;
			current->next = current->previous;
			current->previous = temp;
			current = temp; // Move to the next node correctly
		} while (current != head);

		head = head->next;
		cout << "\nThe list is reversed\n";
	}

	// Detect loop
	void detectLoop() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node* slow = head;
		Node* fast = head->next;

		while (fast && fast->next)
		{
			if (slow == fast)
			{
				cout << "Loop detected" << endl;
				return;
			}
			slow = slow->next;
			fast = fast->next->next;
		}

		cout << "No loop detected" << endl;
	}


	// Display
	void display() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}

		Node* current = head;
		do {
			cout << current->data << " ";
			current = current->next;
		} while (current != head);
		cout << endl;
	}




};

int main()
{
	linkedlist list;
	doublyLinkedlist d1;
	circularLinkedlist c1;
	doubleCircularLinkedList dlist;
	int ch = 0;
	int n = 0;
	int op = 0;
	int x = 0;
	int i = 0;
	int wh = 0;


menu:

	cout << "\t\t\t\t\t\t\tConsole App:\n\n";

	cout << "Enter 1 for Singly Linked List\n";
	cout << "Enter 2 for Doubly Linked List\n";
	cout << "Enter 3 for Singly Circular Linked List\n";
	cout << "Enter 4 for Doubly Circular Linked List\n";
	cout << "Enter 5 to Exit the Program\n";
	cin >> x;
	if (x < 5)
		system("CLS");

	switch (x)
	{
	case(1):
		// Singly Linked List:
		system("CLS");
	loop:
		cout << "\t\t\t\t\t\t SINGLY LINKED LIST \n";
		cout << "Enter 1 To Add element at first" << endl;
		cout << "Enter 2 To Add element at end" << endl;
		cout << "Enter 3 To Add element at a specific index" << endl;
		cout << "Enter 4 To Delete the first element" << endl;
		cout << "Enter 5 To Delete element at last" << endl;
		cout << "Enter 6 To Search an element" << endl;
		cout << "Enter 7 To Check if the list is Palindrome" << endl;
		cout << "Enter 8 To Find the Number of Nodes" << endl;
		cout << "Enter 9 To Find the Maximum Number of from List" << endl;
		cout << "Enter 10 To Find the Average from the lsit" << endl;
		cout << "Enter 11 To Check if there is a loop in the list" << endl;
		cout << "Enter 12 To Reverse the list" << endl;
		cout << "Enter 13 To Display the list" << endl;
		cout << "Enter 14 To Go back to Menu" << endl;
		cin >> op;



		/////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (op)
		{
		case(1):
			// Inserting elements at first:
			cout << "Enter a Number to add: ";
			cin >> x;
			list.addFirst(x);
			cout << "\nTime Complexity:O(1)\n";
			break;

		case(2):
			// Inserting elements at last:
			cout << "Enter a Number to add: ";
			cin >> x;
			list.addLast(x);
			cout << "\nTime Complexity:O(n)\n";
			break;


		case(3):
			// Inserting elements at index:
			cout << "Enter a Number to add: ";
			cin >> x;
			cout << "Enter where to add it: ";
			cin >> i;
			list.insertAt(x, i);
			cout << "\nTime Complexity:O(n)\n";
			break;


		case(4):
			// Deleting elements from first:
			list.deleteFirst();
			cout << "\nTime Complexity:O(1)\n";
			break;

		case(5):
			// Deleting elements from last
			list.deleteLast();
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(6):
			// Search an element from the list:
			cout << "Enter a Number to search: ";
			cin >> x;
			list.search(x);
			cout << "\nTime Complexity:O(n) \n";
			break;

		case(7):
			// Count number of elements/Nodes:
			list.isPalindrome();
			cout << "\nTime Complexity:O(n) \n";
			break;


		case(8):
			// Count number of elements/Nodes:
			list.countNodes();
			cout << "\nTime Complexity:O(n) \n";
			break;


		case(9):
			// Finding the maximum element from list:
			list.max();
			cout << "\nTime Complexity:O(n) \n";
			break;

		case(10):
			// Finding average of the list:
			list.average();
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(11):

			// Detect if there is a loop in the list:
			list.detectLoop();
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(12):
			// Reversing the list:
			list.reverse();
			cout << "\nTime Complexity: O(n)\n";
			break;

		case(13):
			// Displaying elements:
			list.display();
			cout << "\nTime Complexity: O(n)\n";
			break;

		case(14):
			// Go to menu:
			system("CLS");
			goto menu;
			break;


		default:
			cout << "Enter a valid number";
		}

		cout << "\nPress enter to move on to next operation" << endl;
		system("pause>0");
		system("CLS");
		goto loop;
		break;


	case(2):
		// Double Linked List:
		system("CLS");
	loop1:
		cout << "\t\t\t\t\t\t DOUBLY LINKED LIST \n";
		cout << "Enter 01 to Add element at first \n";
		cout << "Enter 02 to Add elemnts at last \n";
		cout << "Enter 03 to Display elements\n";
		cout << "Enter 04 to Insert a node at specific position\n";
		cout << "Enter 05 to Delete the first Node\n";
		cout << "Enter 06 to Search element \n";
		cout << "Enter 07 to Count Nodes \n";
		cout << "Enter 08 to Find the max element\n";
		cout << "Enter 09 to Find the average of nodes\n";
		cout << "Enter 10 to Reverse the Linked List\n";
		cout << "Enter 11 to Detect a loop in Linked List\n";
		cout << "Enter 12 to Delete last element\n";
		cout << "Enter 13 To Go Back To the Menu\n";
		cin >> ch;
		switch (ch) {
		case (1):
			cout << "\nEnter a number to add at first : ";
			cin >> x;
			d1.addFirst(x);
			cout << "Time complexity to add at first is O(1)\n";
			break;
		case(2):
			cout << "\nEnter a number to Add at last : ";
			cin >> x;
			d1.addLast(x);
			cout << "Time complexity for adding element at last is O(1)\n";
			break;
		case(3):
			d1.displayList();
			break;
		case(4):
			cout << "Enter the element you want to add : ";
			cin >> x;
			cout << "Enter the position on which you want to add the element : ";
			cin >> wh;
			d1.insertatanyIndex(x, wh);
			cout << "Time complexity for adding an elemnt at specific position is O(n)\n";
			break;
		case(5):
			d1.deleteFirst();
			cout << "Time complexity for deleting first element is O(1)\n";
			break;
		case(6):
			cout << "Enter the element to Search : ";
			cin >> x;
			d1.Search(x);
			cout << "Time complexity for Searching an elemnt is O(n)\n";
			break;
		case(7):
			d1.countNode();
			cout << "\nTime complexity for counting Nodes in is O(n)\n";
			break;
		case(8):
			cout << "Maximum : " << d1.Max();
			cout << "\nTime complexity to find Maximum is O(n)";
			break;
		case(9):
			d1.Average();
			cout << "\nTime complexity for finding average is O(n)\n";
			break;
		case(10):
			d1.reverseList();
			cout << "Time complexity to reverse is O(n)\n";
			break;
		case(11):
			d1.detectLoop();
			cout << "Time complexity for detecting loop is O(n)\n";
			break;
		case(12):
			d1.deleteLast();
			cout << "\nTime complexity for deleting last element is O(n)\n";
			break;
		case(13):
			// Go to menu:
			system("CLS");
			goto menu;
			break;
		default:
			cout << "Enter a valid number ";
		}
		cout << "\nPress Enter to move to the next operation ";
		system("pause>0");
		system("CLS");
		goto loop1;

		break;


	case(3):
		//Singly Circular Linked List
		system("CLS");
	loop2:
		cout << "\t\t\t\t\t\t SINGLY CIRCULAR LINKED LIST \n";
		cout << "Enter 01 to Add element at first \n";
		cout << "Enter 02 to Add elemnts at last \n";
		cout << "Enter 03 to Display elements\n";
		cout << "Enter 04 to Insert a node at specific position\n";
		cout << "Enter 05 to Delete the first Node\n";
		cout << "Enter 06 to Search element \n";
		cout << "Enter 07 to Count Nodes \n";
		cout << "Enter 08 to Find the max element\n";
		cout << "Enter 09 to Find the average of nodes\n";
		cout << "Enter 10 to Reverse the Circular Linked List\n";
		cout << "Enter 11 to Detect a loop in Circular Linked List\n";
		cout << "Enter 12 to Delete last element\n";
		cout << "Enter 13 To Go Back To Menu\n";
		cin >> ch;
		switch (ch) {
		case (1):
			cout << "\nEnter a number to add at first : ";
			cin >> x;
			c1.addfirst(x);
			cout << "Time complexity to add at first is O(1)\n";
			break;
		case(2):
			cout << "\nEnter a number to Add at last : ";
			cin >> x;
			c1.addLast(x);
			cout << "Time complexity for adding element at last is O(1)\n";
			break;
		case(3):
			cout << "\nList of elements is : ";
			c1.display();
			break;
		case(4):
			cout << "Enter the element you want to add : ";
			cin >> x;
			cout << "Enter the position on which you want to add the element : ";
			cin >> wh;
			c1.insertAtPosition(x, wh);
			cout << "Time complexity for adding an elemnt at specific position is O(n)\n";
			break;
		case(5):
			c1.deleteFirst();
			cout << "Time complexity for deleting first element is O(1)\n";
			break;
		case(6):
			cout << "Enter the element to Search : ";
			cin >> x;
			c1.search(x);
			cout << "Time complexity for Searching an elemnt in Circular Linked list is O(n)\n";
			break;
		case(7):
			cout << "Number of Nodes : " << c1.countNodes();
			cout << "\nTime complexity for counting Nodes in Circular linked list is O(n)\n";
			break;
		case(8):
			cout << "Maximum : " << c1.max();
			cout << "\nTime complexity to find Maximum is O(n)";
			break;
		case(9):
			cout << "Average of Nodes is : " << c1.average();
			cout << "\nTime complexity for finding average in circular linked list is O(n)\n";
			break;
		case(10):
			c1.reverse();
			cout << "Time complexity to reverse circular linked list is O(n)\n";
			break;
		case(11):
			c1.detectLoop();
			cout << "Time complexity for detecting loop in Circular linked list is O(n)\n";
			break;
		case(12):
			c1.deleteLast();
			cout << "\nTime complexity for deleting last element in circular linked list is O(n)\n";
			break;
		case(13):
			// Go to menu:
			system("CLS");
			goto menu;
			break;

		default:
			cout << "Enter a valid number ";
		}
		cout << "\nPress Enter to move to the next operation ";
		system("pause>0");
		system("CLS");
		goto loop2;

		break;


	case(4):
		//Doubly Circular Linked List
		system("CLS");

	loop3:
		cout << "\t\t\t\t\t\t DOUBLY CIRCULAR LINKED LIST \n";
		cout << "Enter 1 To Add element at first" << endl;
		cout << "Enter 2 To Add element at end" << endl;
		cout << "Enter 3 To Add element at a specific index" << endl;
		cout << "Enter 4 To Delete the first element" << endl;
		cout << "Enter 5 To Delete element at last" << endl;
		cout << "Enter 6 To Search an element" << endl;
		cout << "Enter 7 To Find the Number of Nodes" << endl;
		cout << "Enter 8 To Find the Maximum Number of from List" << endl;
		cout << "Enter 9 To Find the Average from the lsit" << endl;
		cout << "Enter 10 To Check if there is a loop in the list" << endl;
		cout << "Enter 11 To Reverse the list" << endl;
		cout << "Enter 12 To Display the list" << endl;
		cout << "Enter 13 To Go Back to Menu" << endl;
		cin >> op;



		/////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (op)
		{
		case(1):
			// Inserting elements at first:
			cout << "Enter a Number to add: ";
			cin >> x;
			dlist.addFirst(x);
			cout << "\nTime Complexity:O(1)\n";
			break;

		case(2):
			// Inserting elements at last:
			cout << "Enter a Number to add: ";
			cin >> x;
			dlist.addLast(x);
			cout << "\nTime Complexity:O(n)\n";
			break;


		case(3):
			// Inserting elements at index:
			cout << "Enter a Number to add: ";
			cin >> x;
			cout << "Enter where to add it: ";
			cin >> i;
			dlist.insertAt(x, i);
			cout << "\nTime Complexity:O(n)\n";
			break;


		case(4):
			// Deleting elements from first:
			dlist.deleteFirst();
			cout << "\nTime Complexity:O(1)\n";
			break;

		case(5):
			// Deleting elements from last
			dlist.deleteLast();
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(6):
			// Search an element from the list:
			cout << "Enter a Number to search: ";
			cin >> x;
			dlist.search(x);
			cout << "\nTime Complexity:O(n) \n";
			break;

		case(7):
			// Count number of elements/nodes:
			cout << "Number of nodes: " << dlist.countNodes() << endl;
			cout << "\nTime Complexity:O(n) \n";
			break;


		case(8):
			// Finding the maximum element from list:
			cout << "Maximum: " << dlist.max() << endl;
			cout << "\nTime Complexity:O(n) \n";
			break;

		case(9):
			// Finding average of the list:
			cout << "Average: " << dlist.average() << endl;
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(10):

			// Detect if there is a loop in the list:
			dlist.detectLoop();
			cout << "\nTime Complexity:O(n)\n";
			break;

		case(11):
			// Reversing the list:
			dlist.reverse();
			cout << "\nTime Complexity: O(n)\n";
			break;

		case(12):
			// Displaying elements:
			dlist.display();
			cout << "\nTime Complexity: O(n)\n";
			break;

		case(13):
			// Go to menu:
			system("CLS");
			goto menu;
			break;

		default:
			cout << "Enter a valid number";
		}

		cout << "\nPress enter to move on to next operation" << endl;
		system("pause>0");
		system("CLS");
		goto loop3;


		break;

	case(5):
		return 0;
		break;

	default:
		cout << "Enter a Valid Option";
	}
	system("pause>0");
	system("CLS");
	goto menu;

	return 0;
}