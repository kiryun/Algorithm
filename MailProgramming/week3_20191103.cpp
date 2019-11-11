#include <bits/stdc++.h>

using namespace std;

// 정수 n이 주어지면, n개의 여는 괄호 "("와 n개의 닫는 괄호 ")"로 만들 수 있는 괄호 조합을 모두 구하시오. (시간 복잡도 제한 없습니다).
// Given an integer N, find the number of possible balanced parentheses with N opening and closing brackets.

// 예제)
// Input: 1
// Output: ["()"]

// Input: 2
// Output: ["(())", "()()"]

// Input: 3
// Output: ["((()))", "(()())", "()(())", "(())()", "()()()"]

int N = 0;
char* arr = NULL;
bool* visit = NULL;
vector<char> v;
// vector<vector<char>> result;
int stk = 0;

void Print()
{
    cout<<"\"";
    for(int i = 0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<"\",";
}

void solution(int cnt)
{
    if(stk == 0 && cnt == N*2){
        Print();
        return;
    }

    for(int i = 1; i<N*2; i++){
        // cout<<i;
        int temp = stk;
        int a = 0;
        if(arr[i] == '('){
            temp +=1;
            a = -1;
        }else{
            temp -=1;
            a = 1;
        }
        
        if(temp < 0 || visit[i]){
            continue;
        }

        stk = temp;
        v.push_back(arr[i]);
        visit[i] = true;
        solution(cnt+1);
        stk += a;
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    cin>>N;

    arr = new char[N*2];
    visit = new bool[N*2];

    for(int i = 0; i<N; i++){
        arr[i] = '(';
        visit[i] = false;
    }
    for(int i = N; i<N*2; i++){
        arr[i] = ')';
        visit[i] = false;
    }

    cout<<"[";
    v.push_back(arr[0]);
    stk += 1;
    solution(1);
    cout<<"]"<<"\n";

    return 0;
}