#include <iostream>
#include <vector>

using namespace std;

int n, m = 0;
vector<int> v;
bool* visit;
int* arr;

void Print()
{
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

void dfs(int c)
{
    if(c == m){
        Print();
        return;
    }
    for(int i = 0; i<n; i++){
        if(visit[i]){
            continue;
        }
        v.push_back(arr[i]);
        visit[i] = true;
        dfs(c+1);
        visit[i] = false;
        v.pop_back();
    }
    
}

int main()
{
    cin>>n>>m;

    arr = new int[n];
    visit = new bool[n];
    for(int i = 0; i<n; i++){
        arr[i] = i+1;
    }

    dfs(0);

    return 0;
}