class Solution {
public:
    bool ingrid(vector<vector<char>>& board ,string& word , int index , int i  , int j ){
        if(index == word.size()) return true;
        int n = board[0].size();
        char temp = board[i][j];
        board[i][j] = '#';
        if(j != 0 && board[i][j - 1] == (word[index])){
            if (ingrid(board , word , index + 1 , i , j - 1)) return true;
        }
        if(i != 0 && (board[i - 1][j]) == (word[index])){
            if (ingrid(board , word , index + 1 , i - 1 , j)) return true;
        }
        if(j + 1 != n && (board[i][j + 1]) == (word[index])){
            if (ingrid(board , word , index + 1 , i , j + 1)) return true;
        }
        if(i + 1 != board.size() && (board[i + 1][j]) == (word[index])){
            if (ingrid(board , word , index + 1 , i + 1 , j)) return true;
        }
        board[i][j] = temp;
        return false;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int a = word.size();
        vector<int> boardF(128, 0);
        vector<int> wordF(128, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                boardF[board[i][j]]++;
            }
        }
        for(char c : word) {
            wordF[c]++;
        }
        for(int i = 0; i < 128; i++) {
            if(wordF[i] > boardF[i])
                return false;
        }
        if(boardF[word[0]] > boardF[word.back()]) {
            reverse(word.begin(), word.end());
        }
        if(n*m < a) return false;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(board[i][j] == word[0]){
                    if (ingrid(board , word , 1 , i , j)) return true;
                }
            }
        }
        return false;
    }
};