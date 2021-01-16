#include <bits/stdc++.h>
#define INPUT_LEN 3

using namespace std;


char board[5][5] = {
    {'u', 'r', 'l', 'p', 'm'},
    {'x', 'p', 'r', 'e', 't'},
    {'g', 'i', 'a', 'e', 't'},
    {'x', 't', 'n', 'z', 'y'},
    {'x', 'o', 'q', 'r', 's'}
};

string input[INPUT_LEN] = {
    "pretty",
    "girl",
    "repeat"
};

 // 상, 하, 좌, 우, 대각선
int dir_x[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dir_y[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool result = false;

void hasWords(int y, int x, list<char> words)
{
    // cout<<"hasWords"<<x<<y<<endl;
    // cout<<words.size()<<endl;

    // words의 사이즈가 0이면 return
    if(words.size() == 0){
        result = true;
        return;
    }

    // if(y == 4 && x == 4){
    //     return false;
    // }

    //8방향 검사
    for(int j = 0; j<8; j++){
        int tempX = x + dir_x[j];
        int tempY = y + dir_y[j];
        // cout<<tempX<<", "<<tempY<<endl;

        //범위를 넘어가는지
        if(tempX < 0 ||
        tempX > 4 ||
        tempY < 0 ||
        tempY > 4){
            // cout<<"out of range"<<endl;
            continue;
        }
        // cout<<board[tempX][tempY]<<", "<<words.front()<<endl;
        
        if(board[tempX][tempY] == words.front()){
            char tempC = words.front();
            words.pop_front();
            hasWords(tempY, tempX, words);
            words.push_front(tempC);
        }
    }

}

int main()
{
    list<char> q[INPUT_LEN];

    for(int i= 0; i<INPUT_LEN; i++){
        for(int j = 0; j<input[i].length(); j++){
            // cout<<input[i][j];
            q[i].push_back(input[i][j]);
        }
        // cout<<"\n";
    }

    // for(int i = 0; i<5; i++){
    //     for(int j = 0; j<5; j++){
    //         cout<<board[i][j];
    //     }
    //     cout<<"\n";
    // }
    
    // list<char>::iterator it;
    // for(int i = 0; i<INPUT_LEN; i++){
    //     for(it = q[i].begin();it != q[i].end();it++){ 
    //         //it이 li.begin()을 가리킴, it이 li.end()를 가리키지 않을때까지 반복, it가 다음것을 가리킴
    //         printf("%c ",*it); //원소 접근은 *it을 이용
    //     }
    //     cout<<"\n";
    // }

    for(int i = 0; i<INPUT_LEN; i++){
        result = false;
        for(int j = 0; j<5; j++){
            for(int k = 0; k<5; k++){

                hasWords(j,k,q[i]);
            }
        }

        if(result){
            cout<<"Exist\n";
        }else{
            cout<<"Not Found\n";
        }
        // cout<<hasWords(0, 0, q[i])<<"\n";
        
    }


    return 0;
}