/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/
// user vector upper to record the upper index for each char
class Solution:
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        upper = {c: i for i, c in enumerate(S)}
        res = []
        left = 0;
        idx = 0;
        for i in range(0, len(S)):
            idx = max(idx, upper[S[i]])
            if idx == i:
                res.append(i-left+1)
                left=i+1
            i += 1
        return res
