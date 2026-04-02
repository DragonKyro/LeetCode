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
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return tasks[a][0] < tasks[b][0]; });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> result;
        long long time = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty() && i < n && tasks[idx[i]][0] > time) time = tasks[idx[i]][0];
            while (i < n && tasks[idx[i]][0] <= time) { pq.push({tasks[idx[i]][1], idx[i]}); i++; }
            auto [pt, id] = pq.top(); pq.pop();
            time += pt;
            result.push_back(id);
        }
        return result;
    }
};
