Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

 

Example 1:

Input: A = ["tars","rats","arts","star"]
Output: 2
 

Constraints:

1 <= A.length <= 2000
1 <= A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.

// Sol1: BFS.
// Add item to visited before the analysis. To save time when multiple same items in the array.
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int res = 0;
        unordered_set<string> visited;
        queue<int> q;
        for (int i = 0; i < A.size(); i++) {
            if (visited.count(A[i])) continue;
            res++;
            q.push(i);
            visited.insert(A[i]);
            while(!q.empty()) {
                int cur_index = q.front(); q.pop();
                for (int j = 0; j < A.size(); j++) {
                    if (visited.count(A[j])) continue;
                    int diff = 0;
                    for (int k = 0; k < A[j].size(); k++) {
                        if (A[cur_index][k] != A[j][k]) {
                            diff++;
                            if (diff > 2) break;
                        }
                    }
                    if (diff == 2) {   
                        q.push(j);
                        visited.insert(A[j]);
                    }
                }
            }           
        }
        return res;
    }
};
