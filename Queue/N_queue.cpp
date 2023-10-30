#include <bits/stdc++.h>
using namespace std;

class NQueue
{
public:
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freeSpot = 0;

    // Initialize your data structure.
    NQueue(int n, int s)
    {

        front = new int[n];
        rear = new int[n];
        next = new int[s];
        arr = new int[s];

        for (int i = 0; i < n; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
            next[s - 1] = -1;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {

        if (freeSpot == -1)
            return false;

        int idx = freeSpot;

        freeSpot = next[idx];

        if (front[m - 1] == -1)
        {
            front[m - 1] = idx;
        }
        else
        {
            next[rear[m - 1]] = idx;
        }

        next[idx] = -1;

        rear[m - 1] = idx;
        arr[idx] = x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m)
    {

        if (front[m - 1] == -1)
            return -1;

        int idx = front[m - 1];

        front[m - 1] = next[idx];

        next[idx] = freeSpot;

        freeSpot = idx;

        return arr[idx];
    }
};

int main()
{
    
}