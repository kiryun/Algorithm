#include <bits/stdc++.h>

using namespace std;

int n,m = 0;
int* arr = NULL;
vector<int> v;

void Print(){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

//c: 현재 어디까지 했는지
void nm(int c){
    if(c == m){
        Print();
        return;
    }
    for(int i = 0; i<n; i++){
        v.push_back(arr[i]);
        nm(c+1);
        v.pop_back();
    }
}

int main(){
    cin>>n>>m;
    arr = new int[n];
    for(int i = 0; i<n; i++){
        arr[i] = i+1;
    }
    nm(0);

    return 0;
}