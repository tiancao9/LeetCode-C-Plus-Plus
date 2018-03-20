/*
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//sol1, use stack, 1st put all all NestedInteger into stack
//get s.top(), if it is Integer, return true, other wise, pop and push unlisted ones
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size()-1; i >= 0; i--)
            s.push(nestedList[i]);
    }

    int next() {
        NestedInteger cur = s.top();
        s.pop();
        return cur.getInteger();
    }

    bool hasNext() {
        while(!s.empty())
        {
            NestedInteger cur = s.top();
            if(cur.isInteger())
                return true;
            else
            {
                s.pop();
                for(int i = cur.getList().size()-1; i >= 0; i--)
                    s.push(cur.getList()[i]);
            }
        }
        return false;
    }
private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

//Sol2, check each element NestedInteger in the vector, if it is integer, return true, otherwise unlisted it unil nestedList1[i] is integer
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        nestedList1 = nestedList;
    }

    int next() {
        NestedInteger t = nestedList1[i];
        i++;
        return t.getInteger();
    }

    bool hasNext() {
        
        if(i < nestedList1.size() && nestedList1[i].isInteger())
            return true;
        else if (i < nestedList1.size())
        {
            
            while(i < nestedList1.size() && !nestedList1[i].isInteger())
            {
                vector<NestedInteger> cur = nestedList1[i].getList();
                nestedList1.erase(nestedList1.begin() + i);
                if(!cur.empty() && cur.size() > 0)
                    nestedList1.insert(nestedList1.begin() + i, cur.begin(), cur.end());
            }
            if(i < nestedList1.size())
               return true;
            else
                return false;
        }
        else
            return false;
    }
private:
    int i = 0;
    vector<NestedInteger> nestedList1;
};
