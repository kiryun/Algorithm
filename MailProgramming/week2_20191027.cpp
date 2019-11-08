#include <bits/stdc++.h>

using namespace std;

// 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 피보나치 수의 합이 된다. 정수 N이 주어지면, N보다 작은 모든 짝수 피보나치 수의 합을 구하여라.



// Fibonacci sequence starts with 0 and 1 where each fibonacci number is a sum of two previous fibonacci numbers. Given an integer N, find the sum of all even fibonacci numbers.



// 예제)

// Input: N = 12

// Output: 10 // 0, 1, 2, 3, 5, 8 중 짝수인 2 + 8 = 10.

int solution(int N)
{
    int* dp = NULL;
    dp = new int[N];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    int i = 3;

    int result = 2;

    while(true){
        dp[i] = dp[i-1] + dp[i-2];
        // cout<<"dp: "<<dp[i]<<endl;

        if(dp[i] < N ){
            if(dp[i] % 2 == 0){
                result += dp[i];
                // cout<<result<<endl;
            }
        }else{
            return result;
        }
        i++;
    }


}

int main()
{
    int N = 0;

    cin>>N;

    switch(N){
        case 0:
        cout<<0<<"\n";
        break;
        case 1:
        cout<<0<<"\n";
        break;
        case 2:
        cout<<2<<"\n";
        default:
        cout<<solution(N)<<"\n";
        break;
    }

        
    return 0;
}