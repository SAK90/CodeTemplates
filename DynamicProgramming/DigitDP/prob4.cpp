#include<bits/stdc++.h>
using namespace std;
// SPOJ: Digit sum
// https://www.spoj.com/problems/PR003004/

long long dp[20][2];
long long cnt(string & num, int n, bool tight){
    if(tight == 0){
        return pow(10, n) + 0.1;
    }
    if(n == 0)
        return 1;
    long long ans = 0;
    int upper_limit = num[(int)num.size()-n]-'0';
    for(int dig = 0; dig <= upper_limit; dig++){
        ans += cnt(num, n-1, (tight&&(dig == upper_limit)));
    }
    return ans;
}
long long helper(string & num, int n, bool tight){
    if(n == 0)
        return 0;
    if(dp[n][tight] != -1){
        return dp[n][tight];
    }
    int upper_limit = tight?num[(int)num.size()-n]-'0':9;
    long long ans = 0;
    for(int dig = 0; dig <= upper_limit; dig++){
        ans += cnt(num, n-1, tight&&(dig==upper_limit))*dig;
        ans += helper(num, n-1, (tight&&(dig==upper_limit)));
    }
    return dp[n][tight] = ans;
}

void solve(){
    int L, R;
    cin >> L >> R;
    L--;
    string r = to_string(R);
    string l = to_string(L);
    memset(dp, -1, sizeof(dp));
    long long big = helper(r, r.size(), 1);
    memset(dp, -1, sizeof(dp));
    long long small = L>=0?helper(l, l.size(), 1):0;
    cout << big - small << '\n';
}
int main(){
    int tests;
    cin >> tests;
    while(tests--){
        solve();
    }
}


