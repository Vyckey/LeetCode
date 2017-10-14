/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
	ListNode* reverse(ListNode* list) {
		ListNode* pre = NULL;
		while (list) {
			ListNode* lnext = list->next;
			list->next = pre;
			pre = list;
			list = lnext;
		}
		return pre;
	}
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ln1 = l1, *ln2 = l2;
		ListNode* lsum = NULL;
		int c = 0;
		while (ln1 || ln2) {
			int x = 0, y = 0;
			if (ln1 != NULL) {
				x = ln1->val;
				ln1 = ln1->next;
			}
			if (ln2 != NULL) {
				y = ln2->val;
				ln2 = ln2->next;
			}
			ListNode* node = new ListNode((x + y + c) % 10);
			node->next = lsum;
			lsum = node;
			if ((x + y + c) >= 10) c = 1;
			else c = 0;
		}
		if (c == 1) {
			ListNode* node = new ListNode(1);
			node->next = lsum;
			lsum = node;
		}
		return reverse(lsum);
	}
	/*ListNode* generate(vector<int>& v) {
		ListNode* head = NULL;
		for (int i = v.size() - 1; i >= 0; --i) {
			ListNode* node = new ListNode(v[i]);
			node->next = head;
			head = node;
		}
		return head;
	}*/
};
