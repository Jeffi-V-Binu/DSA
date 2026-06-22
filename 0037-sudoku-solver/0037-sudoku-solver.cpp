class Solution {
public:
    unsigned short row[9] , col[9] , box[9];
    bool solveSudoku(vector<vector<char>>& board , int a = 0) {
        if(a == 0){
            for(int i = 0 ; i < 9 ;  ++i){
                row[i] = 0 ; 
                col[i] = 0 ;
                box[i] = 0 ;
            }
            for(int r = 0 ; r < 9 ; ++r){
                for(int c = 0 ; c < 9 ; ++c){
                    if(board[r][c] != '.'){
                        unsigned short bit = 1 << (board[r][c] - '1') ;
                        row[r] |= bit;
                        col[c] |= bit;
                        box[((r/3)*3)+(c/3)] |= bit;
                    }
                }
            }
        }
        if(a == 81) return true;
        while(a < 81 && board[a / 9][a % 9] != '.' ) ++a;
        int i = a / 9;
        int j = a % 9;
        if(a == 81) return true;
        int valid = 0x1FF & ~(row[i] | col[j] | box[((i / 3) * 3) + (j /3)] ) ;
        while(valid){
            int bits = valid & -valid;
            valid &= valid - 1;
            int z = __builtin_ctz(bits);
            char k = '1' + z;
            board[i][j] = k;
            row[i] |= bits;
            col[j] |= bits;
            box[((i/3)*3)+(j/3)] |= bits;
            if(solveSudoku(board , a + 1)) return true;
            row[i] ^= bits;
            col[j] ^= bits;
            box[((i/3)*3)+(j/3)] ^= bits;
        }
        board[i][j] = '.';
        return false;
    }
};