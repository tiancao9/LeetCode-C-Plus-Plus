/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

*/

// reverse each group with k nodes, next_prev = prev->next, cur is k+1 nodes
// reverse_linkList(head, tail), tail is k+1 nodes
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* cur = prev->next;
        while(cur)
        {
            ListNode* next = prev->next;
            int count = 0;
            while(count < k && cur)
            {
                cur = cur->next;
                count++;
            }
            if(count == k){ 
                prev->next = reverse_linkList(prev->next, cur);
            }
            prev = next;
        }
        
        return dummy.next;
    }
    
private:
    ListNode* reverse_linkList(ListNode* head, ListNode* tail)
    {
        
        ListNode* prev = tail;
        ListNode* cur = head;
        while(cur != tail)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

};
