#include <bits/stdc++.h>
using namespace std;

//* Stack implementation using array.
class Stack
{

public:
    int topIndex;
    int size;
    int *arr;

    Stack(int capacity)
    {
        size = capacity;
        topIndex = -1;
        arr = new int[size];
    }

    void push(int num)
    {
        if (topIndex != (size - 1))
        {
            topIndex++;
            arr[topIndex] = num;
        }
        else
        {
            return;
        }
    }

    int pop()
    {
        if (topIndex != -1)
        {
            return arr[topIndex--];
        }
        return -1;
    }

    int top()
    {
        if (topIndex != -1)
        {
            return arr[topIndex];
        }
        return -1;
    }

    int isEmpty()
    {
        if (topIndex == -1)
            return 1;
        return 0;
    }

    int isFull()
    {
        if (topIndex == (size - 1))
        {
            return 1;
        }
        return 0;
    }
};


//* Stack implementation using single queue.
class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {

        q.push(x);

        int s = q.size() - 1;

        while (s-- != 0)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {

        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {

        return q.front();
    }

    bool empty()
    {

        return q.size() == 0 ? true : false;
    }
};


//* Stack implementation using Linked List.
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack
{

public:
    int topNum;
    Node *head;

    Stack()
    {
        head = NULL;
        topNum = 0;
    }

    int getSize()
    {
        return topNum;
    }

    bool isEmpty()
    {
        if (topNum == 0)
            return true;
        return false;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        topNum++;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node *i = head;

        head = head->next;
        i->next = NULL;
        topNum--;
        delete i;
    }

    int getTop()
    {
        if (head == NULL)
            return -1;

        return head->data;
    }
};

int main()
{
}