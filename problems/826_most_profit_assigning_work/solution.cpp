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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {difficulty[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int result = 0, best = 0, j = 0;
        for (int w : worker) {
            while (j < n && jobs[j].first <= w) best = max(best, jobs[j++].second);
            result += best;
        }
        return result;
    }
};
