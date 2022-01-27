#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main() {
    int g; int p;
    scanf("%d%d",&g,&p);

    set<int> s;
    int ans = 0;

    for (int i = 0; i < g; i++) {
        s.insert(i+1);
    }

    for (int i = 0; i < p; i++) {
        int node;
        scanf("%d",&node);
        auto u = s.upper_bound(node);
        
        if (u == s.begin()) {
            for (int j = i+1; j < p; j++) {
                int f; scanf("%d",&f);
            }
            break;
        }
        s.erase(--u);
        ans++;
    }
    printf("%d",ans);



