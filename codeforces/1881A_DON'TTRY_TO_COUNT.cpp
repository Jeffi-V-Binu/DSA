#include<iostream>
#include<string>

using namespace std;

bool fastio = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int a ,b;
    string s, x;
    cin >> a >> b;
    int count = 0;
    cin >> x >> s;
    if(x.find(s) != string::npos){
        cout << 0 << "\n";
        return;
    }
    while(a < b ){
        a *= 2;
        x = x +  x;
        ++count;
    }
    if(x.find(s) != string::npos){
        cout << count << "\n";
    }
    else{
        ++count;
        x = x + x;
        if(x.find(s) != string::npos) cout << count << "\n" ;
        else cout << -1 << "\n" ;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}