#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll POW(ll a, ll n, ll m){
    if(n == 0){
        return 1;
    }

    ll val = POW(a, n/2, m);
    val = val*val%m;

    if(n%2 == 0){
        return val;
    }
    return val*a%m;
}

int main(){
    ll a, n, m;
    cin>>a>>n>>m;

    cout<<POW(a, n, m)<<endl;
    
    return 0;
}