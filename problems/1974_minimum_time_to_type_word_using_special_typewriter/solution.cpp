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
    int minTimeToType(string word) {
        int time = 0, curr = 0;
        for (char c : word) {
            int target = c - 'a';
            int diff = abs(target - curr);
            time += min(diff, 26 - diff) + 1;
            curr = target;
        }
        return time;
    }
};
