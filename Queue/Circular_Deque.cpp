#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:
    int *q;
    int front = -1;
    int rear = -1;

    int size;

    MyCircularDeque(int k)
    {

        size = k;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {

        if (isFull())
            return false;

        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
            front = (front - 1 + size) % size;

        q[front] = value;

        return true;
    }

    bool insertLast(int value)
    {

        if (isFull())
            return false;

        if (front == -1 && rear == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        q[rear] = value;

        return true;
    }

    bool deleteFront()
    {

        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = rear = -1;
            return true;
        }

        front = (front + 1) % size;

        return true;
    }

    bool deleteLast()
    {

        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = rear = -1;
            return true;
        }

        rear = (rear - 1 + size) % size;

        return true;
    }

    int getFront()
    {

        return isEmpty() ? -1 : q[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : q[rear];
    }

    bool isEmpty()
    {

        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {

        if ((rear + 1) % size == front)
            return true;
        return false;
    }
};

int main()
{
    MyCircularDeque* obj = new MyCircularDeque(5);
    cout << obj->insertFront(10) << "   ";
    cout <<  obj->insertLast(30)<< "   ";
    cout <<  obj->deleteFront()<< "   ";
    cout <<  obj->deleteLast()<< "   ";
    cout << obj->getFront()<< "   ";
    cout << obj->getRear()<< "   ";
    cout <<  obj->isEmpty()<< "   ";
    cout <<  obj->isFull()<< "   ";

}
