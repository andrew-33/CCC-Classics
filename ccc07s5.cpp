#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using vi = vector<int>;
#define pb push_back

ll dp[507][30007];

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,k,w;
        scanf("%d%d%d",&n,&k,&w);
        vector<ll> inp(n);
        vector<ll> s(n);

        for (int i = 0; i < n; i++) {
            scanf("%lld",&inp[i]);
            }

        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            s[i] = 0;
            for (int j = 0; j < w; j++) {
                if (i+j < n)
                    s[i] += inp[i+j];
            }
        }
        
        /////////////
        for (int j = 1; j <= k; j++) {

            for (int i = n-1; i >= 0; i--) {

                if (i + w >= n) {
                    if (i != n) {
                        dp[j][i] = max(s[i],dp[j][i+1]);
                    } else {
                        dp[j][i] = s[i];
                    }
                    
                }
                else  {
                    dp[j][i] = max(s[i]+dp[j-1][i+w],dp[j][i+1]);
                }

            }
        }
        ///////////
        

        printf("%lld\n",dp[k][0]);
    }
}
