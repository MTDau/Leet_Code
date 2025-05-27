

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0 || head->next == nullptr)
        {
            return head;
        }
        ListNode *temp = head;
        int mem{};
        while (temp != nullptr)
        {
            mem++;
            temp = temp->next;
        }
        k = mem - k % mem; // get the idx of the new head.
        if (k == mem)
            return head;
        ListNode *new_head = head;
        temp = new ListNode(0, head);
        ListNode *junk = temp;
        for (int i{}; i < k; i++)
        {
            temp = temp->next;
            new_head = temp->next;
        }
        temp->next = nullptr;
        temp = new_head;
        while (temp->next != nullptr) // traverse to the last element;
            temp = temp->next;
        temp->next = head;
        delete junk;
        return new_head;
    }
};
