// #include <bits/stdc++.h>

// using namespace std;

// // @ 출발지, 목적지, 경유지, 원판의 갯수 (기둥 1, 2, 3)
// // 
// void hanoi(int src, int des, int by, int n){
//     if(n == 1){
//         cout<<src<<" "<<des<<endl;
//         return;
//     }else{
//         hanoi(src, by, des, n-1);
//         cout<<src<<" "<<des<<endl;
//         hanoi(by, des, src, n-1);
//     }
// }

// int main(){
//     int n = 0;

//     cin>>n;

//     cout<<(1<<n) - 1<<endl;
//     hanoi(1, 3, 2, n);
    
//     return 0;
// }

//정답 코드
#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){
    if(n==1){ // a에 있는 원판 1개를 b로 옮기기만 하면 됨
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6-a-b; // a, b가 아닌 나머지 기둥의 번호
    func(a,c,n-1); // a에 있던 1 to n-1번째 원판을 a에서 c로 이동
    cout << a << ' ' << b << '\n'; // a에 남아있던 n번째 원판을 b로 이동
    func(c,b,n-1); // c에 있던 1 to n-1번째 원판을 c에서 b로 이동
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n'; // 2의 n승 - 1
    func(1,3,n);
}