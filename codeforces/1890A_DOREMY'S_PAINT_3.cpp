#include<iostream>
#include<cmath>

using namespace std;

auto fastio = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n;
    cin >> n;
    int a;
    int b;
    int c;
    int ac = 0;
    int bc = 0;
    int flag = 1;
    while(n--){
        cin >> c;
        if(!ac) a = c;
        if(a == c) ++ac;
        else{
            if(!bc) b = c;
            if(b == c) ++bc;
            else if(flag){
                flag = 0;
            }
        }
    }
    if(((ac >= 2 && bc == 0) || abs(ac - bc) <= 1) && flag ) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t ;
    cin >> t;
    while(t--){
        solve();
    }
}