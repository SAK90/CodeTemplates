#include<bits/stdc++.h>
using namespace std;
// Google Kickstart 2020 R:H Boring numbers
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b0c6

long long dp[25][2][2][2];
long long helper(string& num, int n, bool even, bool leading_zero, bool tight){
    if(n == 0){
        return 1;
    }
    if(dp[n][even][leading_zero][tight] != -1){
        return dp[n][even][leading_zero][tight];
    }
    if(even){
        int upper_limit = tight?num[(int)num.size()-n]-'0':9;
        long long ans = 0;
        for(int dig = 0; dig <= upper_limit; dig += 2){
            ans += helper(num, n-1, 0, 0, (tight && (dig==upper_limit)));
        }
        return dp[n][even][leading_zero][tight] = ans;
    }
    else{
        long long ans = 0;
        if(leading_zero){
            ans += helper(num, n-1, 0, 1, 0);
        }
        int upper_limit = tight?num[(int)num.size()-n]-'0':9;
        for(int dig = 1; dig <= upper_limit; dig += 2){
            ans += helper(num, n-1, 1, 0, (tight && (dig==upper_limit)));
        }
        return dp[n][even][leading_zero][tight] = ans;
    }
}
long long solve(){
    long long L, R;
    cin >> L >> R;
    --L;
    string l = to_string(L), r = to_string(R);
    memset(dp, -1, sizeof(dp));
    long long big = helper(r, r.size(), 0, 1, 1);
    memset(dp, -1, sizeof(dp));
    long long small = helper(l, l.size(), 0, 1, 1);
    return (big-small);

}

int main(){
    int tests, curr = 1;
    cin >> tests;
    while(tests--){
        cout << "Case #" << curr << ": " << solve() << '\n';
        ++curr;
    }
}


