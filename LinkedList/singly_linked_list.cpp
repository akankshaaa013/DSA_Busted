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

// To delete the element at the first position of the linked list.
void delStart(Node *&head)
{

    if (head == NULL)
    {
        cout << "Underflow !!!";
    }
    else
    {
        Node *i = head;

        head = head->next;
        delete (i);
    }
}

// To delete the element at the last position of the linked list.
void delEnd(Node *&head)
{

    if (head == NULL)
    {
        cout << "Underflow !!!";
    }
    else
    {
        Node *i = head;
        Node *j = NULL;

        while (i->next != NULL)
        {
            j = i;
            i = i->next;
        }
        j->next = NULL;
        delete (i);
    }
}

// To delete the element from the required position of the linked list.
void del_from_pos(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow !!!";
    }
    else
    {
        Node *i = head;
        Node *j = NULL;

        while (pos > 1)
        {
            j = i;
            i = i->next;
            pos--;
        }

        j->next = i->next;
        delete (i);
    }
}

int main()
{
    Node *node1 = new Node(30);
    Node *head = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 10);

    insertAtTail(head, 40);

    insertAtPos(head, 25, 2);

    print(head);

    del_from_pos(head, 3);
    print(head);
}