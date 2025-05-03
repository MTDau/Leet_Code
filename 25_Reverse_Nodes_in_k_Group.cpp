class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode *temp = new ListNode(0, head);
        ListNode *prev = temp;
        ListNode *curr = head;
        // Get the size of the list
        int count{};
        while (curr)
        {
            count++;
            curr = curr->next;
        }
        // Only reverse if k <= size of list
        while (count >= k)
        {
            curr = prev->next;
            ListNode *temp1 = curr->next;
            //Reverse k nodes
            //Keep switching the temp1 node to the head
            //For 3 node only need 2 switch
            for (int i{}; i < k - 1; i++){
                curr->next = temp1->next;
                temp1->next = prev->next;
                prev->next = temp1;
                temp1 = curr->next;
            }
            prev = curr;
            count -=k;
        }
        return temp->next;
    }
};
