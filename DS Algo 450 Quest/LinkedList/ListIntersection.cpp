#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode* head)
{
    int len = 0;
    while(head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}


ListNode *FindIntersection(ListNode *list1, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;
    int length1 = length(list1);
    int length2 = length(list2);
    
    if(length1 > length2)
    {
        while(length1 > length2)
        {
            head1 = head1->next;
            length1--;
        }
    }
    else if(length1 < length2)
    {
        while(length1 < length2)
        {
            head2 = head2->next;
            length2--;
        }
    }


    while(head1 && head2)
    {
        if(head1 == head2)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
    
}

int main()
{
    ListNode *mainNode = new ListNode(4);
    mainNode->next = new ListNode(1);
    mainNode->next->next = new ListNode(8);
    mainNode->next->next->next = new ListNode(4);
    mainNode->next->next->next->next = new ListNode(5);
    ListNode *secondNode = new ListNode(5);
    secondNode->next = new ListNode(6);
    secondNode->next->next = new ListNode(1);
    secondNode->next->next->next = mainNode->next->next;
    cout << FindIntersection(mainNode, secondNode)->val;
}
