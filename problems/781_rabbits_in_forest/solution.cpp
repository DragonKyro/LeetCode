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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int a : answers) count[a]++;
        int result = 0;
        for (auto& [k, v] : count)
            result += (v + k) / (k + 1) * (k + 1);
        return result;
    }
};
