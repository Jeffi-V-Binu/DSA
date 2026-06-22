#include<iostream>
#include<vector>
#include<string>

using namespace std;

auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n ;
    cin >> n;
    string a ;
    cin >> a;
    int dot_count = 0;
    int dot_substring = 0;
    int max_dot_substring = 0;
    for(char& b: a){
        if(b == '#'){
            dot_substring = 0;
        }
        else{
            ++dot_count;
            ++dot_substring;
        }
        max_dot_substring = max(max_dot_substring , dot_substring);
    }
    if(max_dot_substring >= 3) cout << 2 << "\n";
    else cout << dot_count << "\n";
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}