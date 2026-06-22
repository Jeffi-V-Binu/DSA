#include<iostream>
#include<vector>
using namespace std;

auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void solve(){
    int n , k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
    }
    bool is_sorted = true;
    if(k > 1 || n == 1) cout << "YES" << endl;
    else{
        for(int i = 0 ; i < n - 1 ;++i){
            if(a[i] > a[i + 1]){
                is_sorted = false;
                break;
            }
        }
        if(!is_sorted) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}