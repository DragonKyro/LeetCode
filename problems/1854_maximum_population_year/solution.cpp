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
    int maximumPopulation(vector<vector<int>>& logs) {
        int delta[101] = {};
        for (auto& l : logs) { delta[l[0] - 1950]++; delta[l[1] - 1950]--; }
        int maxPop = 0, maxYear = 1950, curr = 0;
        for (int i = 0; i < 101; i++) {
            curr += delta[i];
            if (curr > maxPop) { maxPop = curr; maxYear = 1950 + i; }
        }
        return maxYear;
    }
};
