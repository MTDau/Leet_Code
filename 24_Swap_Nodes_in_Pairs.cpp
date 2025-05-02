class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head  || !head->next) //empty or 1 node list
            return head;
            ListNode* temp = new ListNode(0);
            temp->next = head;
            ListNode* ptr1 = temp;

            while(ptr1->next && ptr1->next->next){
                ListNode* first = ptr1->next;
                ListNode* second = first->next;

                first ->next = second->next;
                second->next = first;
                ptr1->next = second;
                ptr1 = first;
            }
            return temp->next;
    }
};

//Took too much time don't work, over complicated.
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ptr1 = head;
        ListNode *result = new ListNode(0);
        result->next = ptr1;
        if (ptr1 == nullptr)
        { // Empty list
            return result;
        }
        ListNode *ptr2 = ptr1->next;
        if (ptr2 == nullptr)
        { // List contain 1 node
            return result;
        }
        ListNode *ptr3 = ptr2->next;
        if (ptr3 == nullptr)
        {
            ptr2->next = ptr1;
            ptr1->next = ptr3;
        }
        ListNode *temp = new ListNode(0);

        while (ptr3 != nullptr)
        {
            temp->next = ptr3;
            ptr2->next = ptr1;
            ptr1->next = temp->next;
            ptr3 = ptr3->next;
            ptr2 = ptr3;
            ptr1 = ptr1->next;
        }
        delete temp;
        temp = nullptr;
        return result->next;
    }
};
