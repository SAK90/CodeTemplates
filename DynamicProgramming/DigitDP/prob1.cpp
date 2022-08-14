#include<bits/stdc++.h>
using namespace std;

// Given N and SUM, find count of N digit numbers whose digits sum upto SUM
int helper(int n, int sum){
    if(sum < 0)
        return 0;
    if(n == 1){
        if(sum >= 0 && sum <= 9)
            return 1;
        return 0;
    }
    int ans = 0;
    for(int i=0; i<=9; i++){
        ans += helper(n-1, sum-i);
    }
    return ans;
}

int main(){
    int n, sum;
    cin >> n >> sum;
    int ans = 0;
    for(int i=1; i<=9; i++){
        ans += helper(n-1, sum-i);
    }
    cout << ans << '\n';
}
