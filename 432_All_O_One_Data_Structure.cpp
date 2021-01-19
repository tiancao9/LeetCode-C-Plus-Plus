Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.

// Sol, list<ValKeys>(bi-directional).
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (key_pos.count(key) == 0) {
            key_pos[key] = l.insert(l.begin(), {0, {key}});
        } 
        auto next = key_pos[key];
        auto cur = next++;
        if (next == l.end() || next->val > cur->val + 1) {
            next = l.insert(next, {cur->val + 1, {}});
        }        
        next->keys.insert(key);
        key_pos[key] = next;
        
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            l.erase(cur);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (key_pos.count(key) == 0) return;
        auto prev = key_pos[key];
        auto cur = prev--;
        key_pos.erase(key);
        if (cur->val > 1) {
            if (cur == l.begin() || prev->val < cur->val - 1) {
                prev = l.insert(cur, {cur->val - 1, {}});
            }            
            prev->keys.insert(key);
            key_pos[key] = prev;
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            l.erase(cur);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (l.empty()) return "";
        return *(l.back().keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (l.empty()) return "";
        return *(l.begin()->keys.begin());
    }
private:
    struct ValKeys {
        int val;
        unordered_set<string> keys;
    };
    list<ValKeys> l;
    unordered_map<string, list<ValKeys>::iterator> key_pos;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
