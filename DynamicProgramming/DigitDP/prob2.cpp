#include<bits/stdc++.h>
using namespace std;
// Given N and SUM, find count of numbers from [0, N] whose digits sum upto SUM

long long dp[501][501][2];
long long helper(string & num, int n, long long sum, bool tight = true){
    if(sum < 0)
        return 0;
    if(n==1){
        if(tight && (sum >= 0 && sum <= num.back()-'0')){
            return 1;
        }
        else if(!tight && (sum >= 0 && sum <= 9)){
            return 1;
        }
        return 0;
    }
    if(dp[n][sum][tight] != -1)
        return dp[n][sum][tight];
    long long ans = 0;
    int upper_limit = tight?num[(int)num.size()-n]-'0':9;
    for(int dig = 0; dig <= upper_limit; dig++){
        ans += helper(num, n-1, sum-dig, tight&&(dig==upper_limit));
    }
    return dp[n][sum][tight] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    string n;
    long long sum;
    cin >> n >> sum;
    cout << helper(n, n.size(), sum) << '\n';
}
