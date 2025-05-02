/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = new ListNode(0); 
        ListNode *temp = result;
        ListNode *first = list1;
        ListNode *second = list2;
        while (first != nullptr && second != nullptr)
        {
            if (first->val < second->val)
            {
                result->next = first;
                result = result->next;
                first = first->next;
            }
            else
            {
                result->next = second;
                result = result->next;
                second = second->next;
            }
        }
        while (first != nullptr)
        {
            result->next = first;
            result = result->next;
            first = first->next;
        }
        while (second != nullptr)
        {
            result->next = second;
            result = result->next;
            second = second->next;
        }
        return temp->next;
    }
};
