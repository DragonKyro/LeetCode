#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        vector<bool> vis(n, false); int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> nodes; queue<int> q; q.push(i); vis[i]=true;
                while (!q.empty()) { int u=q.front();q.pop();nodes.push_back(u); for(int v:adj[u])if(!vis[v]){vis[v]=true;q.push(v);} }
                int k=nodes.size(), ec=0;
                for (int u:nodes) ec+=adj[u].size();
                if (ec/2==k*(k-1)/2) ans++;
            }
        }
        return ans;
    }
};
