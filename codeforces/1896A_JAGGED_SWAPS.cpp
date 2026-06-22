#include<iostream>
#include<vector>

using namespace std;

auto fastio = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n ;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i ){
        cin >> a[i];
    }
    if(a[0] == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}