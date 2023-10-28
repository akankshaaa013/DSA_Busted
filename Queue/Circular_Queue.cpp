#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    int front = -1;
    int count = 0;
    int rear = -1;
    int *q;
    int size;

    MyCircularQueue(int k)
    {

        size = k;

        q = new int[k];
    }

    bool enQueue(int value)
    {

        if (count == size)
            return false;

        count++;

        rear = (rear + 1) % size;

        q[rear] = value;

        if (front == -1)
            front = 0;

        return true;
    }

    bool deQueue()
    {

        if (count == 0 || front == -1)
            return false;

        count--;

        front = (front + 1) % size;

        return true;
    }

    int Front()
    {

        return count == 0 ? -1 : q[front];
    }

    int Rear()
    {

        return count == 0 ? -1 : q[rear];
    }

    bool isEmpty()
    {

        return (front == -1 || count == 0) ? true : false;
    }

    bool isFull()
    {

        return (count == size) ? true : false;
    }
};

int main()
{ 

    MyCircularQueue* obj = new MyCircularQueue(4);
    bool param_1 = obj->enQueue(10);
    bool param_1 = obj->enQueue(20);
    bool param_1 = obj->enQueue(30);
    bool param_1 = obj->enQueue(40);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();

}