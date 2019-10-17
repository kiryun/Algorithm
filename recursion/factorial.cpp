#include <bits/stdc++.h>

using namespace std;

int func(int n){
    if( n == 1 ){
        return 1;
    }
    return n * func(n-1);
}

int main(){
    cout<<"5!: "<<func(5)<<endl;
}