#include <bits/stdc++.h>

using namespace std;

int N, r, c = 0;
int cnt=0;

void Z(int size, int y, int x){
    if(size == 2){
        //현재좌표(x, y)가 (c,r)와 같은지
        //2*2에서 0번째
        if(y == r && x == c){
            cout<<cnt<<endl;
            return;
        }
        cnt++;

        //현재좌표(x+1, y)가 (c,r)와 같은지
        //2*2에서 1번째
        if(y == r && x+1 ==c){
            cout<<cnt<<endl;
            return;
        }
        cnt++;
        //현재좌표(x, y+1)가 (c,r)와 같은지
        //2*2에서 1번째
        if(y+1 == r && x ==c){
            cout<<cnt<<endl;
            return;
        }
        cnt++;
        //현재좌표(x+1, y+1)가 (c,r)와 같은지
        //2*2에서 1번째
        if(y+1 == r && x+1 ==c){
            cout<<cnt<<endl;
            return;
        }
        cnt++;
        return; // 2*2에서 r,c가 없을 경우
    }
    //1 사분면
    Z(size/2, y, x);
    //2 사분면
    Z(size/2, y, x + size/2);
    //3 사분면
    Z(size/2, y + size/2, x);
    //4 사분면
    Z(size/2, y + size/2, x + size/2);
}

int main(){
    cin>>N>>r>>c;
    
    //0,0부터 시작, 1<<N * 1<<N 크기
    Z(1<<N, 0, 0);


    return 0;
}