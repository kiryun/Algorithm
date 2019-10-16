#include <bits/stdc++.h>

using namespace std;

int n, m = 0;
int* arr;
bool* visit;
vector<int> v;

void Print(){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void nm(int cnt){
    if(cnt == m){
        Print();
        return;
    }
    for(int i = 0; i<n; i++){
        if(visit[i]){
            continue;
        }
        visit[i] = true;
        v.push_back(arr[i]);
        nm(cnt+1);
        visit[i] = false;
        v.pop_back();
    }
}

int main(){
    cin>>n>>m;

    arr = new int[n];
    visit = new bool[n];
    int a = 0;
    for(int i = 0; i<n; i++){
        cin>>a;
        arr[i] = a;
    }
    sort(arr, arr+n);

    nm(0);

    return 0;
}