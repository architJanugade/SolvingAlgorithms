#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};
// ListNode *partition(ListNode *head, int x)
// {
//     ListNode* current = head;
//     ListNode* next = head -> next;
//     ListNode* prev = head;
//     while(current)
//     {
//         if(current->val < x)
//         {
//             prev = current;
//             next = prev->next;
//             current = current->next;
//         }
//         if(current->val >= x)
//         {
//             current = current->next;
//         }

//     }

// }

ListNode *partition(ListNode *head, int x)
{
    ListNode *lowest = NULL;
    ListNode *highest = NULL;
    ListNode *highEnd = NULL;
    ListNode *lowEnd = NULL;
    ListNode *head2 = head;

    if (head == NULL || head->next == NULL)
        return head;

    while (head != NULL)
    {
        if (head->val < x)
        {
            if (lowest == NULL)
            {
                lowest = head;
                head2 = lowest;
                lowEnd = lowest;
                head = head->next;
                if (highEnd != NULL && highest != NULL)
                {
                    highEnd->next = lowEnd->next;
                    lowEnd->next = highest;
                }
            }
            else
            {
                lowEnd->next = head;
                head = head->next;
                lowEnd = lowEnd->next;
                if (highEnd != NULL && highest != NULL)
                {
                    highEnd->next = lowEnd->next;
                    lowEnd->next = highest;
                }
            }
        }
        else if (head->val >= x)
        {
            if (highest == NULL)
            {
                highest = head;
                highEnd = highest;
                head = head->next;
            }
            else
            {
                highEnd->next = head;
                head = head->next;
                highEnd = highEnd->next;
                if (lowEnd != NULL)
                    lowEnd->next = highest;
            }
        }
    }

    return head2;
}

int main()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(1);
    // list->next->next = new ListNode(3);
    // list->next->next->next = new ListNode(2);
    // list->next->next->next->next = new ListNode(5);
    // list->next->next->next->next->next = new ListNode(2);
    ListNode *parted = partition(list, 1);
    while (parted)
    {
        cout << parted->val;
        parted = parted->next;
    }
}