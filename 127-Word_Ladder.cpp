/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/


//BFS, queue<pair<string, int>>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> s;
        for(string word: wordList) s.insert(word);
        queue<pair<string,int>> q;
        if(!s.count(endWord)) return 0;
        q.push(make_pair(beginWord,1));
        return find_next(s, q, endWord);
        
    }
    
private:
    int find_next(set<string> &s,
                  queue<pair<string,int>>& q,
                  string endword)
    {
        
       
            string curword = q.front().first;
            int n = q.front().second;
            q.pop();
            for(int i = 0; i < curword.size(); i++)
                for(int j = 0; j < 25; j++)
                {
                    if(j + 'a' != curword[i])
                    {
                        string nextword = curword;
                        nextword[i] = j + 'a';
                        if(nextword == endword)
                            return n+1;
                        else if(s.count(nextword))
                        {
                            q.push(make_pair(nextword,n+1));
                            s.erase(nextword);
                        }
                    }
                }
        
        
        if(q.empty())
            return 0;
        return find_next(s, q, endword);
    }
};
