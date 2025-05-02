#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        // Get all the value from all the list to a vector
        std::vector<int> temp;
        for (auto node : lists)
        {
            while (node != nullptr)
            {
                temp.push_back(node->val);
                node = node->next;
            }
        }
        // Sort all the value
        std::sort(temp.begin(), temp.end());

        // Create a new list and pass all value in.

        ListNode *result = new ListNode(0);
        ListNode *dummy = result;

        for (int val : temp){
            dummy->next = new ListNode(val);
            dummy = dummy->next;
        }
        return result->next;
    }
};
