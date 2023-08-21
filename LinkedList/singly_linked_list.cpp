#include <bits/stdc++.h>
using namespace std;

// Creating the structure of the linked list.
class Node
{
public:
    int data;

    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

// To insert the element at the 1st position of the linked list.
void insertAtHead(Node *&head, int data)
{

    Node *temp = new Node(data);

    if (temp == NULL)
    {
        cout << "Overflow";
        return;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

// To insert the element at the last position of the linked list.
void insertAtTail(Node *&head, int data)
{

    Node *temp = new Node(data);

    if (temp == NULL)
    {
        cout << "Overflow";
        return;
    }
    else
    {
        Node *q = head;
        while (q->next != NULL)
        {
            q = q->next;
        }

        temp->data = data;
        temp->next = NULL;
        q->next = temp;
    }
}

// To insert the element at the required position in the linked list.
void insertAtPos(Node *&head, int key, int pos)
{

    Node *temp = new Node(key);

    if (temp == NULL)
    {
        cout << "Overflow";
        return;
    }
    else
    {
        Node *j = head;

        int i = 0;
        while (i != (pos - 1))
        {
            j = j->next;
            i++;
        }

        temp->next = j->next;
        j->next = temp;
    }
}

// Function to print the linked list.
void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;

    insertAtHead(head,20);
    insertAtHead(head,10);

    insertAtTail(head,40);
    insertAtTail(head,50);

    insertAtPos(head,25,2);

    insertAtPos(head,45,5);
    
    print(head);
    
}