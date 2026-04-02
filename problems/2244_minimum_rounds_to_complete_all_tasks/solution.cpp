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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        for (int t : tasks) count[t]++;
        int rounds = 0;
        for (auto& [k, v] : count) {
            if (v == 1) return -1;
            rounds += (v + 2) / 3;
        }
        return rounds;
    }
};
