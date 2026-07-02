class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        table = [[0] * (m+1 )for i in range(n+1)]
        for i in range(m+1):
            table[0][i] = i 
        for i in range(n+1):
            table[i][0] = i
        for i in range(1 , n+1):
            for j in range(1 , m + 1):
                if(word1[i - 1] == word2[j - 1]):
                    table[i][j] = table[i-1][j-1]
                else:
                    table[i][j] = min(table[i - 1][j] , table[i - 1][ j - 1], table[i][j - 1]) + 1
        return table[n][m]
