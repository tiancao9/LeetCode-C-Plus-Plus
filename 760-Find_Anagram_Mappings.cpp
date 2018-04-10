/*
Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].
*/

// use a map to record pos of B[i], dict_B{B[i]: [i, j...]}
// iterate A, find A[i] in dict_B and append dict[A[i][0]] into res
class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        dict_B = {}
        res = []
        for i in range(len(B)):
            if B[i] in dict_B:
                dict_B[B[i]].append(i)
            else:
                dict_B[B[i]] = [i]
        for i in range(len(A)):
            if A[i] in dict_B:
                res.append(dict_B[A[i]][0])
                dict_B[A[i]] = dict_B[A[i]][1:]
        return res

