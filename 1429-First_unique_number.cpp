You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]
Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
Example 2:

Input: 
["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
[[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
Output: 
[null,-1,null,null,null,null,null,17]
Explanation: 
FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
firstUnique.showFirstUnique(); // return -1
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
firstUnique.showFirstUnique(); // return 17
Example 3:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique"]
[[[809]],[],[809],[]]
Output: 
[null,809,null,-1]
Explanation: 
FirstUnique firstUnique = new FirstUnique([809]);
firstUnique.showFirstUnique(); // return 809
firstUnique.add(809);          // the queue is now [809,809]
firstUnique.showFirstUnique(); // return -1
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^8
1 <= value <= 10^8
At most 50000 calls will be made to showFirstUnique and add.

// Linklist + Hashmap<int, prev_node*>.
// When remove a node, needs to update its next's prev_node* in the map.
// When add a new node (all prev nodes have been removed), need to relink
// head_.next to cur.
class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            m_tmp_[num]++;
        }
        for (int num : nums) {
            if (m_tmp_[num] == 1) {
                cur_->next = new ListNode(num);
                m_[num] = cur_;
                cur_ = cur_->next;
                std::cout << cur_->val << std::endl;
            }
        }
    }
    
    int showFirstUnique() {
        if (head_.next == NULL) return -1;
        return head_.next->val;
    }
    
    void add(int value) {
      if (m_.count(value)) {
          std::cout << "remove " << value << std::endl;
          if (m_[value]->next->next) {
              m_[m_[value]->next->next->val] = m_[value];
          }
          m_[value]->next = m_[value]->next->next;
          m_.erase(value);
      } else if (!m_tmp_.count(value)) {
          m_tmp_[value]++;
          cur_->next = new ListNode(value);
          m_[value] = cur_;
          cur_ = cur_->next;
          if (head_.next == NULL) {
              m_[value] = &head_;
              head_.next = cur_;
          }
      }
    }
private:
    struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode head_ = ListNode(0);
    ListNode* cur_ = &head_;
    unordered_map<int, ListNode*> m_;
    unordered_map<int, int> m_tmp_;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
