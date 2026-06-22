class Solution {
public:
    void solvedNList(vector<int>& solvedSubList , int rowCount , vector<vector<int>>& spaceValidity , int n , int& count)
    // to get a list that holds all valid possibilities , with its index being the row and value the column...
    { 
        if(rowCount == n ){
            count++;

            return ;
        }
        for(int i = 0 ; i < n ; ++i){
            if(spaceValidity[rowCount][i] == 0){
                solvedSubList.push_back(i);
                updateValidity(spaceValidity , 1 , i , rowCount , n);
                solvedNList(solvedSubList , rowCount + 1 , spaceValidity , n , count);
                solvedSubList.pop_back();
                updateValidity(spaceValidity , -1 , i , rowCount , n);
            }
        }
    }
    void updateValidity(vector<vector<int>>& spaceValidity , int a , int colm , int row , int n)
    // to update the space validity matrix , by adding 1 or by reducing 1... 
    {
        int k = 0;
        for(int i = row ; i < n ; ++i) spaceValidity[i][colm] += a;
        for(int j = row + 1 ; j < n ; ++j){
            ++k;
            if(colm + k < n) spaceValidity[j][colm + k] += a;
            if(colm - k >= 0) spaceValidity[j][colm - k] += a;
        }
    }
    int totalNQueens(int n) {
        vector<int> solvedSubList;
        int count = 0;
        vector<vector<int>> spaceValidity(n , vector<int>(n , 0));
        solvedNList(solvedSubList , 0 , spaceValidity , n , count );
        return count;
    }
};