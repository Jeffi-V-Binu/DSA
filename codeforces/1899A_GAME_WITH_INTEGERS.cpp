#include<iostream>

using namespace std;

auto fastio = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n;
    cin >> n;
    if(n % 3 == 0) cout << "Second\n";
    else cout << "First\n";
}

int main(){
    int t ;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}