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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mins;
        for (auto& t : timePoints)
            mins.push_back(stoi(t.substr(0,2)) * 60 + stoi(t.substr(3)));
        sort(mins.begin(), mins.end());
        int minDiff = 1440 - mins.back() + mins[0];
        for (int i = 1; i < (int)mins.size(); i++)
            minDiff = min(minDiff, mins[i] - mins[i-1]);
        return minDiff;
    }
};
