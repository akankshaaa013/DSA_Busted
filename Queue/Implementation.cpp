#include <bits/stdc++.h>
using namespace std;

//* Queue Implementation using array;
class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100001);
    }

//* Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        if (rear == arr.size())
            return;

        arr[rear] = e;
        rear++;
    }

//* Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }

        int x = arr[front];
        front++;
        return x;
    }
};


//* Queue Implementation using stack.
class MyQueue
{
public:
    stack<int> input, output;

    MyQueue()
    {
    }

    void push(int x)
    {

        input.push(x);
    }

    int pop()
    {

        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }

    int peek()
    {

        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        return x;
    }

    bool empty()
    {

        if (output.empty() && input.empty())
            return true;

        return false;
    }
};

//* Queue Implementation using Linked list

// Definition of linked list
class Node
{

public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Definition of Queue
struct Queue
{
    Node *front;
    Node *rear;
    void push(int);
    int pop();

    Queue()
    {
        front = rear = NULL;
    }
};

Node *front = NULL;
Node *rear = NULL;

void Queue::push(int x)
{

    Node *temp = new Node(x);

    if (temp == NULL)
        return;

    if (front == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    temp->next = NULL;
    rear = temp;
}

int Queue::pop()
{

    if (front == NULL)
    {
        return -1;
    }

    Node *i = front;
    front = front->next;

    int x = i->data;

    i->next = NULL;
    delete i;

    return x;
}

int main()
{
}