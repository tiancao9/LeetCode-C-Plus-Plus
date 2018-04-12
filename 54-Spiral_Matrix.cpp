/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

// matrix manipulation 
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        i = 0
        res = []
        if len(matrix) == 0: return res;
      
        while len(matrix) > 0:
            #right
            for r in matrix[0]:
                res.append(r)
            matrix = matrix[1:]
            #down
            if matrix and matrix[0]:
                for row in matrix:
                    res.append(row.pop())
            #left
            if matrix and matrix[0]:
                res += matrix.pop()[::-1]
            #up
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    res.append(row.pop(0))
        return res
                
