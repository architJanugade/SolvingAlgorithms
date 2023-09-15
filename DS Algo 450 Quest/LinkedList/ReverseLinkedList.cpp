#include <iostream>

using namespace std;

//LinkedList Node
struct Node
{
    struct Node* next;
    int value;
    Node(int _val)
    {
        this->value = _val;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;
    
    LinkedList() {head = NULL;}

    //Iterative Approach
    void ReverseIter()
    {
        Node* next = NULL;
        Node* prev = NULL;
        Node* current;
        current = head;
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 1->2->3->4->5
    //Recursive approach
    Node* reverseRecursive(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverseRecursive(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }


    void print()
    {
        Node* printVal = head;
        while(printVal != NULL)
        {
            cout<<printVal->value;
            printVal = printVal->next;

        }

    }

    void push(int val)
    {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    int pull()
    {
        if(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }       
    }

};

int main()
{

}


