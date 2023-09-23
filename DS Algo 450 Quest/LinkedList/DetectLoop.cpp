#include<iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};


bool DetectTheLoop(Node* head , Node* next)
{
    if(head == next)
        return true;
    if(next == NULL)
        return false;
    if(next->next == NULL)
        return false;
    if(next->next->next == NULL)
        return false;
    head = head->next;
    if(head == next)
    {
        return true;
    }
    
    next = next->next->next;
     

     bool isLoop = DetectTheLoop(head , next);
     return isLoop;
}
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return false;
        if(head->next->next == NULL)
           return false;
      return DetectTheLoop(head , head->next->next); 
}

int main()
{
    Node* temp = new Node(1);
    temp->next = new Node(2);
     temp->next->next = new Node(3);
    temp->next->next->next = new Node(4);
    //temp->next->next->next->next = temp->next;
    std::cout<<detectLoop(temp);
}