#include <bits/stdc++.h>

#define MAX 5

using namespace std;

int arr[MAX];
bool select[MAX];
vector<int> v;

void Print(){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
}

void dfs(int cnt){
    if(cnt == 3){
        Print();
        return;
    }
    for(int i = 0; i<MAX; i++){
        if(select[i]){
            continue;
        }
        select[i] = true;
        v.push_back(arr[i]);
        dfs(cnt+1);
        v.pop_back();
        select[i] = false;
        
    }
}

int main(){
    for(int i = 0; i<MAX; i++){
        arr[i] = i+1;
    }
    dfs(0);
    return 0;
}