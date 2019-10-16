#include <bits/stdc++.h>

using namespace std;

int n = 0;
int m = 0;
bool* visit; //방문 체크 변수
int* arr; //

void Print(){
    for(int i = 0; i<n; i++){
        if(visit[i]){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

//idx: 현재 보고있는 부분, c: 현재 몇개까지 뽑았는지
void nm(int idx, int c){
    //현재 m개만큼 뽑았으면 출력하고 return 
    if(c==m){
        Print();
        return;
    }
    for(int i = idx; i<n; i++){
        //만약 방문했던 곳이면 넘어간다.
        if(visit[i]){
            continue;
        }else{
            //방문 표시
            visit[i] = true;
            //재귀로 들어간 다음 
            nm(i, c+1);
            //다시 방문해제 해준다.
            visit[i] = false;
        }
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

    nm(0,0);

    return 0;
}