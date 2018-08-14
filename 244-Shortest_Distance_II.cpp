/*
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
*/

// Can not use unordered_map<pair<>, int>, need to define the hash key function for pair<>
// use hash map to record word and index list
// per each word pair, iterate the index list and find the min dis O(n)
// if list1[i] - list2[j] < 0, i++, else, j++

class WordDistance {
public:
    WordDistance(vector<string> words) {
      for(int i = 0; i < words.size(); i++)
          if(m.count(words[i]))
              m[words[i]].push_back(i);
          else
              m[words[i]] = {i};
    }
    
    int shortest(string word1, string word2) {
      
        int dis = INT_MAX;
        vector<int> &l1 = m[word1];
        vector<int> &l2 = m[word2];
        for(int i = 0, j = 0; i < l1.size() && j < l2.size();)
        {
            int d = l1[i] - l2[j];
            if(abs(d) < dis)
                dis = abs(d);
            if(d < 0)
                i++;
            else
                j++;
        }
        return dis;
    }
private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
