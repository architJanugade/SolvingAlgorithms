#include<iostream>

struct node{
    node* next;
    int data;
    node(int _data)
    {
        data = _data;
        next = NULL;
    }
};

 node* reverseRecursive(node* head , node* next)
    {
        if (head == NULL || head->next == next)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        node* rest = reverseRecursive(head->next , next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = next;
 
        /* fix the head pointer */
        return rest;
    }

struct node* GetHead(struct node* prev , struct node* current , struct node* next, struct node* head , int k)
{
    node* temp = current;
    if(temp == NULL)
        return head;
    int count = 1;
    while(count < k && temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    next = temp->next;
    if(prev == NULL)
    {
        head = reverseRecursive(head , next);
        prev = current;
        current = next;
    }
    else
    {
        prev->next = reverseRecursive(prev->next , next);        
        prev = current;
        current = next;
    }
    head = GetHead(prev , current , next , head , k);
    return head;

}


struct node* reverse(struct node* head , int k)
{
    return GetHead(NULL ,head , NULL , head , k );
}


int main()
{
    node* temp = new node(1);
    temp->next = new node(2);
     temp->next->next = new node(3);
    temp->next->next->next = new node(4);
    temp->next->next->next->next = new node(5);
    temp->next->next->next->next->next = new node(6);
    temp->next->next->next->next->next->next = new node(7);
    temp->next->next->next->next->next->next->next = new node(8);
    temp->next->next->next->next->next->next->next->next = new node(9);
    

    node* head = reverse(temp , 4);

    while(head !=NULL){
        std::cout<<head->data<<" ";
        head = head->next;
    }
}

//1 2 3 4 5 6 7 8 9