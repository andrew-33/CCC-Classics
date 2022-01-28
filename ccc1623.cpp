#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define pb push_back

set<int> pho;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);

    vector<set<int>> graph (n);
    vi visited (n);
    
    int what;
    for (int i = 0; i < m;i++) {
        int inp;
        scanf("%d",&inp);
        pho.insert(inp);
    }
    what = *pho.begin();
   
    for (int i = 0; i < n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);

        graph[a].insert(b);
        graph[b].insert(a);
    }

    // part 1

    deque<int> q;

    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1 && (pho.find(i) == pho.end())) {
            q.pb(i);
        }
    }

    int n2= n;
    while (q.size() > 0) {

        int node;
        node = q.back();

        q.pop_back();

        visited[node] = 1;

        int next = *graph[node].begin();

        graph[next].erase(node);
        graph[node].erase(next);

        n2--;
        if (graph[next].size() == 1 && (pho.find(next) == pho.end()) && !visited[next]) {
            q.pb(next);

        }

        

    }

    // part 2: diameter

    vi visited2 (n);

    int node;
    queue<pii> q2;
    q2.push(pii (what,0));
    visited2[what] = 1;
    int diameter = 0;
    int n1;

    while (q2.size() > 0) {
        int node;
        node = q2.front().first;
        int distance = q2.front().second;

        q2.pop();
        
        if (distance > diameter) {

            diameter = distance;
            n1 = node;
        }

        visited2[node] = 1;

        for (int a : graph[node]) {
            if (visited2[a] ==0) { 
                q2.push(pii (a,distance+1));
            }
        }

    }


    q2.push(pii (n1,0));
    vi visited3 (n);
    visited3[node] = 1;
    diameter = 0;

    while (q2.size() > 0) {
        node = q2.front().first;
        int distance = q2.front().second;

        q2.pop();

        diameter = max(diameter, distance);

        visited3[node] = 1;

        for (int a : graph[node]) {
            if (visited3[a]==0) { 
                q2.push(pii (a,distance+1));
            }
        }

    }
    printf("%d\n",(2*(n2-1) - diameter));
}
