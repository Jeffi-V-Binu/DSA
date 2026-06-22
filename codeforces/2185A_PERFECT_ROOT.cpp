#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; ++i){
        int n;
        cin >> n;
        for(int k = 1 ; k <= n ; ++k) cout << k << " ";
        cout << endl;
    }
}
