#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modular(ll a, ll b, ll m){
    ll val = 1;
    while(b--){
        val = val * a;
    }

    return val%m;
}

int main(){
    cout<<modular(6, 12, 5)<<endl;

    return 0;
}