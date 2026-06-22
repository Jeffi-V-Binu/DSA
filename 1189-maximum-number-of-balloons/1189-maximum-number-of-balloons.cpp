class Solution {
public:
    int maxNumberOfBalloons(string text) {
        short a1 = 0;
        short a2 = 0;
        short a3 = 0;
        short a4 = 0;
        short a5 = 0;
        for(const char& a: text){
            if(a == 'b') ++a1;
            else if(a == 'a') ++a2;
            else if(a == 'l') ++a3;
            else if(a == 'o') ++a4;
            else if(a == 'n') ++a5;
        }
        a3 /= 2;
        a4 /= 2;
        return min({a1 , a2 , a3 , a4 , a5});
    }
};