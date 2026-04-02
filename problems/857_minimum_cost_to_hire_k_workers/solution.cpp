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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers(n);
        for (int i = 0; i < n; i++) workers[i] = {(double)wage[i] / quality[i], quality[i]};
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double result = DBL_MAX;
        int totalQuality = 0;
        for (auto& [ratio, q] : workers) {
            pq.push(q);
            totalQuality += q;
            if ((int)pq.size() > k) { totalQuality -= pq.top(); pq.pop(); }
            if ((int)pq.size() == k) result = min(result, totalQuality * ratio);
        }
        return result;
    }
};
