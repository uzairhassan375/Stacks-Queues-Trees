#include<iostream>
#include<iostream>
using namespace std;
class Node
{
public:
    int value;
    Node* next;
    Node(int v)
    {
        value = v;
        next = NULL;
    }
};
class stackwithArray
{
    char* A;
    int top;
    int capacity;
    
public:
    stackwithArray(int size)
    {
        A = new char[size];
        top = -1;
        capacity = size;
    }

    ~stackwithArray()
    {
        delete[] A;
    }

    void push(char x)
    {
        if (isFull())
        {
            return;
        }
        top++;
        A[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        char x = A[top];
        top--;
        return x;
    }

    bool isFull()
    {
        if (top == capacity - 1)
        {
            cout << "Stack is full";
        }
        else
            cout << "not full";
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
            cout << "not empty";
        return top == -1;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty\n";
            return '\0';
        }
        return A[top];
    }
    bool isBalanced(char* exp)
    {
        stackwithArray s(strlen(exp));
        int i = 0;
        while (exp[i] != '\0')
        {
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            {
                s.push(exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
            {
                if (s.isEmpty())
                {
                    return false;
                }
                char temp = s.pop();
                if ((exp[i] == ')' && temp != '(') || (exp[i] == ']' && temp != '[') ||
                    (exp[i] == '}' && temp != '{'))
                {
                    return false;
                }
            }
            i++;
        }
        return s.isEmpty();
    }
    int pre(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
    }
    bool isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return false;
        else
            return true;
    }
    char* InToPost(char* infix) {
        stackwithArray myStack(strlen(infix));
        int i = 0, j = 0;
        int len = strlen(infix);
        char* postfix = new char[len + 1];

        while (infix[i] != '\0') {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];
            else {
                if (pre(infix[i]) > pre(myStack.peek()))
                    myStack.push(infix[i++]);
                else
                    postfix[j++] = myStack.pop();
            }
        }

        while (!myStack.isEmpty())
            postfix[j++] = myStack.pop();

        postfix[j] = '\0';
        return postfix;
    }

    int size()
    {
        return top + 1;
    }

};
class stackWithLinkedList {
public:
    Node* top;
    int size;

    stackWithLinkedList() : top(nullptr), size(0) {}

    void push(int x) {
        Node* newnode = new Node(x);
        newnode->next = top;
        top = newnode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return 0;
        }
        Node* temp = top;
        top = top->next;
        int key = temp->value;
        delete temp;
        size--;
        return key;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return 0;
        }
        return top->value;
    }
    bool isBalanced(char* exp) {
        stackWithLinkedList s;
        int i = 0;
        while (exp[i] != '\0') {
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
                s.push(exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
                if (s.isEmpty()) {
                    return false;
                }
                char temp = s.pop();
                if ((exp[i] == ')' && temp != '(') || (exp[i] == ']' && temp != '[') || (exp[i] == '}' && temp != '{')) {
                    return false;
                }
            }
            i++;
        }
        return s.isEmpty();
    }

    int pre(char x) {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        return 0; // Add this line to handle other cases
    }

    bool isOperand(char x) {
        return !(x == '+' || x == '-' || x == '*' || x == '/');
    }

    char* InToPost(char* infix) {
        stackWithLinkedList myStack;
        int i = 0, j = 0;
        int len = strlen(infix);
        char* postfix = new char[len + 1];

        while (infix[i] != '\0') {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];
            else {
                if (pre(infix[i]) > pre(myStack.peek()))
                    myStack.push(infix[i++]);
                else
                    postfix[j++] = myStack.pop();
            }
        }

        while (!myStack.isEmpty())
            postfix[j++] = myStack.pop();

        postfix[j] = '\0';
        return postfix;
    }

    void display() {
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
};
class queueWithArray {
private:
    int front;
    int rear;
    static const int Size = 10;
    int Arr[Size];
    int count; 

public:
    queueWithArray() {
        front = -1;
        rear = -1;
        count = 0;
    } 

    void Enqueue(int x) {
        if (IsFull()) {
            cout << "Queue is full." << endl;
        }
        else {
            rear = rear + 1;
            Arr[rear] = x;
            count++;  // Increment count when enqueuing an element
            cout << "Enqueued: " << x << endl;
        }
    }

    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            int dequeuedElement = Arr[front];
            front = front + 1;
            count--;  // Decrement count when dequeuing an element
            cout << "Dequeued: " << dequeuedElement << endl;
        }
    }

    int getFront() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else {
            return Arr[front];
        }
    }

    int getRear() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else {
            return Arr[rear];
        }
    }

    bool IsFull() {
        return rear == Size - 1;
    }

    int size() {
        return count;
    }

    bool IsEmpty() {
        return rear == -1 && front == -1;
    }
};
class queueWithLinkedList
{
private:
    Node* front;
    Node* rear;

public:
    queueWithLinkedList()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int v)
    {
        Node* newNode = new Node(v);
        if (rear == NULL)
        {
            rear = front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue already empty" << endl;
            return;
        }
        Node* t = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete t;
    }
    void getFront()
    {
        if (front == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Front is: " << front->value << endl;
        }
    }
    void getRear()
    {
        if (rear == NULL)
        {
            cout << "Queue empty";
            return;
        }
        else
        {
            cout << "Rear is: " << rear->value << endl;
        }
    }
    bool isEmpty()
    {
        return (front == NULL);
    }
    /* void reverseQueue() {
         if (front ==NULL)
        {
             cout << "Queue is empty";
             return;
         }
         //stack<Node*> stack;
         Node* t = front;
         while (t != NULL)
        {
             s1.push(t->value);
             t = t->next;
         }
         while (!s1.isEmpty())
        {
             //Node* node = s1.peek();
           s1.pop();
             enqueue(t->value);
         }
         int size = s1.size();
         for (int i = 0; i < size; ++i)
        {
             dequeue();
         }
         display();
        }*/
    void display()
    {
        Node* t = front;
        if (t == NULL)
        {
            cout << "Nothing in the queue" << endl;
        }
        else
        {
            while (t != NULL)
            {
                cout << t->value << " ";
                t = t->next;
            }
            cout << endl;
        }
    }

};

int main() {
    int choice;
    int value;
    int ch;
    char n;
    int x;
    char infix[] = "a+b*c-d/e";
    char exp1[] = "(a+b)*(c-d)()()";


    stackWithLinkedList sll;
    queueWithArray obj;
    queueWithLinkedList LQ1;

    while (true) {
        system("CLS");
        cout.clear();
    menu:
        cout << "-----------------------------------------------Stacks and Queues-------------------------------------------------------\n\n";
        cout << "1 to Choose Stack with Array:" << endl;
        cout << "2 to Choose Stack with Linked List" << endl;
        cout << "3 to Choose Queue with Array" << endl;
        cout << "4 to Choose Queue with Linked List" << endl;
        cout << "5 to exit" << endl;
        cin >> ch;
        system("CLS");

        switch (ch) {
        case 1: {
            cout << "Stack With Array\n";
            cout << "Enter size of the Stack: ";
            cin >> n;
            system("CLS");
            stackwithArray s(n);
            int op;

            while (true) {
                cout << "1 to Push a Value" << endl;
                cout << "2 to pop a Value" << endl;
                cout << "3 to peek a Value" << endl;
                cout << "4 to check if empty" << endl;
                cout << "5 to check if full" << endl;
                cout << "6 to get the size" << endl;
                cout << "7 to Check if Balanced" << endl;
                cout << "8 to Check infix to postfix" << endl;
                cout << "9 to Go back to menu" << endl;
                cout << "10 to Exit" << endl;
                cin >> op;

                switch (op) {
                case 1:
                    cout << "Enter a value to push: ";
                    cin >> x;
                    s.push(x);
                    break;
                case 2:
                    cout << s.pop() << "\n";
                    break;
                case 3:
                    cout << "Top element of the stack: " << s.peek() << "\n";
                    break;
                case 4:
                    if (s.isEmpty()) {
                        cout << "Stack is empty\n";
                    }
                    else {
                        cout << "Stack is not empty\n";
                    }
                    break;
                case 5:
                    if (s.isFull()) {
                        cout << "Stack is full\n";
                    }
                    else {
                        cout << "Stack is not full\n";
                    }
                    break;
                case 6:
                    cout << "Size of the stack: " << s.size() << "\n";
                    break;
                case 7:
                    cout << "Expression:(a+b)*(c-d)()()";
                    cout << "Is " << exp1 << " balanced? "
                        << (s.isBalanced(exp1) ? "Yes \n" : "No \n");
                    
                    break;
                case 8:
                    cout << "Expresion is a+b*c-d/e";
                    cout << "Infix: " << infix << endl;
                    cout << "Postfix: " << s.InToPost(infix) << endl;
                    break;
                case 9:
                    system("CLS");
                    goto menu;
                    break;
                case 10:
                    return 0;
                    break;
                default:
                    cout << "Enter a valid number\n";
                    break;
                }

                system("Pause>0");
                system("CLS");
            }
            break;
        }
        case 2: {
            cout << "Stack With Linked List\n";
            int op;

            while (true) {
                cout << "1 to Push a Value" << endl;
                cout << "2 to pop a Value" << endl;
                cout << "3 to peek a Value" << endl;
                cout << "4 to check if empty" << endl;
                cout << "5 to get the size" << endl;
                cout << "6 to display stack" << endl;
                cout << "7 to Check if balanced" << endl;
                cout << "8 to Check infix to postfix" << endl;
                cout << "9 to Go back to menu" << endl;
                cout << "10 to Exit" << endl;
                cin >> op;

                switch (op) {
                case 1:
                    cout << "Enter a value to push: ";
                    cin >> x;
                    sll.push(x);
                    break;
                case 2:
                    cout << sll.pop() << "\n";
                    break;
                case 3:
                    cout << "Top element of the stack: " << sll.peek() << "\n";
                    break;
                case 4:
                    if (sll.isEmpty()) {
                        cout << "Stack is empty\n";
                    }
                    else {
                        cout << "Stack is not empty\n";
                    }
                    break;
                case 5:
                    cout << "Size of the stack: " << sll.size << "\n";
                    break;
                case 6:
                    cout << "Stack elements: ";
                    sll.display();
                    cout << "\n";
                    break;
                case 7:
                    cout << "Expression:(a+b)*(c-d)()()";
                    cout << "Is " << exp1 << " balanced? "<< sll.isBalanced(exp1) ? "Yes \n" : "No \n";
                    break;
                case 8:
                    cout << "Expresion is a+b*c-d/e";
                    cout << "Infix: " << infix << endl;
                    cout << "Postfix: " << sll.InToPost(infix) << endl;
                    break;
                case 9:
                    system("CLS");
                    goto menu;
                    break;
                case 10:
                    return 0;
                default:
                    cout << "Enter a valid number\n";
                }

                if (op == 7) {
                    break;
                }
                system("Pause>0");
                system("CLS");
            }
            break;
        }

        case 3: {
            cout << "Queue With Array\n";


            while (true) {
                cout << "\n1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Get Front\n";
                cout << "4. Get Rear\n";
                cout << "5. Check if Full\n";
                cout << "6. Check if Empty\n";
                cout << "7. Get Size\n";
                cout << "8. Go Back To Menu";
                cout << "9. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "Enter a value to enqueue: ";
                    cin >> value;
                    obj.Enqueue(value);
                    break;

                case 2:
                    obj.Dequeue();
                    break;

                case 3:
                    cout << "Front value: " << obj.getFront() << endl;
                    break;

                case 4:
                    cout << "Rear value: " << obj.getRear() << endl;
                    break;

                case 5:
                    cout << (obj.IsFull() ? "Queue is full." : "Queue is not full.") << endl;
                    break;

                case 6:
                    cout << (obj.IsEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                    break;

                case 7:
                    cout << "Queue size: " << obj.size() << endl;
                    break;

                case 8:
                    system("CLS");
                    goto menu;
                    break;

                case 9:
                    cout << "Exiting program.\n";
                    return 0;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
                if (choice == 8) {
                    break;
                }
                system("Pause>0");
                system("CLS");
            }

            break;
        }




        case 4:{
            cout << "Queue With Linked List\n";

            while (true) {
                cout << "\n1. Enqueue\n";
                cout << "2. Dequeue\n";
                cout << "3. Get Front\n";
                cout << "4. Get Rear\n";
                cout << "5. Check if Full\n";
                cout << "6. Check if Empty\n";
                cout << "7. Get Size\n";
                cout << "8. Go Back To Menu\n";
                cout << "9. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << endl << "Enter the value you want to add  : ";
                    cin >> value;
                    LQ1.enqueue(value);
                    system("pause");
                    cout << endl;
                    break;
                case 2:
                    LQ1.dequeue();
                    system("pause");
                    cout << endl;
                    break;
                case 3:
                    LQ1.getFront();
                    system("pause");
                    cout << endl;
                    break;
                case 4:
                    LQ1.getRear();
                    system("pause");
                    cout << endl;
                    break;
                case 5:
                    //LQ1.reverseQueue();
                    system("pause");
                    break;
                case 6:
                    LQ1.isEmpty();
                    system("pause");
                    break;
                case 7:
                    LQ1.display();
                    system("pause");
                    break;
                case 8:
                    system("CLS");
                    goto menu;
                    break;
                case 9:
                    cout << "Exiting program.\n";
                    return 0;
                    break;
                }

                break;
            }
            break;
        case 5:
            return 0;
        default:
            cout << "Enter a valid option\n";
            }
        }



        return 0;
    }

}