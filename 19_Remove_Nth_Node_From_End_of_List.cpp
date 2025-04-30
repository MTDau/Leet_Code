
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* temp = new ListNode(0,head);
			ListNode* first = temp;
			ListNode* second = temp;

			for (int i{}; i <= n; i++){
				first = first->next;
			}
			while (first != nullptr){
				first = first->next;
				second = second->next;
			}
			ListNode* remove = second->next;
			second ->next = second->next->next;
			delete remove;
			remove = nullptr;
			return temp ->next;
		}
	};
