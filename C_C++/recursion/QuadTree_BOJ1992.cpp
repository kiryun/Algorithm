#include <bits/stdc++.h>

using namespace std;

string* arr;

bool check_zero_one(int size, int x, int y){
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(arr[y][x] != arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

//
void quad(int size, int x, int y){

    if(size == 1){
        cout<<arr[x][y];

        // cout<<")";
        return;
    }
    if(check_zero_one(size, x, y)){
        cout<<arr[y][x];
    }else{

        cout<<"("; 
        //left top
        //0 ~ size/2 - 1
        //0 ~ size/2 - 1
        quad(size/2, x, y);

        //right top
        //0 ~ size/2 - 1
        //size/2 ~ size
        quad(size/2, x+size/2, y);

        //left bottom
        //size/2 ~ size
        //0 ~ size/2 - 1
        quad(size/2, x, y+size/2);

        //right bottom
        //size/2 ~ size
        //size/2 ~ size
        quad(size/2, x+size/2, y+size/2);

        cout<<")";
    }
    
}

int main(){
    int N;
    string l;

    cin>>N;
    arr = new string[N];

    for(int i = 0; i<N; i++){
        cin>>l;
        arr[i] = l;
    }
    quad(N, 0, 0);
    cout<<endl;
    // cout<<endl;
    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<N; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;
    // }
    return 0;
}