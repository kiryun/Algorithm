#include <bits/stdc++.h>

using namespace std;

int n = 0;
int m = 0;
bool* visit; //방문 체크 변수
int* arr; //
vector<int> v;

void Print(){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

//c: 현재 몇개까지 뽑았는지
void nm(int c){
    //현재 m개만큼 뽑았으면 출력하고 return 
    if(c==m){
        Print();
        return;
    }
    for(int i = 0; i<n; i++){
        //만약 방문했던 곳이면 넘어간다.
        if(visit[i]){
            continue;
        }
        //방문 표시
        visit[i] = true;
        v.push_back(arr[i]);
        //재귀로 들어간 다음 
        nm(c+1);
        //다시 방문해제 해준다.
        visit[i] = false;
        v.pop_back();
        
    }
}


int main(){
    cin>>n>>m;

    visit = new bool[n];
    arr = new int[n];
    for(int i = 0; i<n; i++){
        visit[i] = false;
        arr[i] = i+1;
    }

    nm(0);

    return 0;
}