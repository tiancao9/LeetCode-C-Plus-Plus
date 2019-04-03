You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

// two stack
// and num from 2 stack and create res list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1 || l2) {
            if (l1) {
                s1.push(l1->val);
                l1 = l1->next;
            }
            if (l2) {
                s2.push(l2->val);
                l2 = l2->next;
            }
        }
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top(); 
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode* new_node = new ListNode(sum % 10);
            new_node->next = dummy->next;
            dummy->next = new_node;
        }
        if (carry) {
            ListNode* new_node = new ListNode(1);
            new_node->next = dummy->next;
            dummy->next = new_node;
        }
        return dummy->next;
    }
};
