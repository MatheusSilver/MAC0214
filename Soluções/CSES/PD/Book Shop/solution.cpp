#include <bits/stdc++.h>
 
using namespace std;
 
/* Esse é praticamente o mesmo problema das moedas (só que com limitação de usar uma vez cada moeda) */
/* Ou talvez um knapsack para os íntimos gulosos. */
int main(){
    int dp[100005],h[100005],s[100005];
    int n, x;
    memset(dp, 0, sizeof(dp));
 
    cin >> n >> x;
 
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
 
    for (int j = 0; j < n; j++){
        cin >> s[j];
    }
 
    for (int i=0; i < n; i++){
        for (int j = x; j >= h[i]; j--){
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
 
    cout << dp[x] << endl;
}