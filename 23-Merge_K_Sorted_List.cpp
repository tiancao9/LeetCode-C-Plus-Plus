/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

// Time O(nklogk)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
  bool operator() (const ListNode*l1, const ListNode*l2)
  {
      return l1->val > l2->val;
  }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        //learn how to define operator 
        /*
        auto cmp = [](ListNode* p, ListNode* q)
        {
            return (p->val > q->val);
        };*/
        
        //priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); i++)
            if(lists[i])
                q.push(lists[i]);
        
        while(!q.empty())
        {
            ListNode* temp = q.top();
            q.pop();
            cur->next = temp;
            if(temp->next) q.push(temp->next);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};
