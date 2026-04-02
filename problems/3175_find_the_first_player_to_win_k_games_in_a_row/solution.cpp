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
    int findWinningPlayer(vector<int>& skills, int k) {
        int curr = 0, wins = 0;
        for (int i = 1; i < skills.size(); i++) {
            if (skills[curr] > skills[i]) wins++;
            else { curr = i; wins = 1; }
            if (wins >= k) return curr;
        }
        return curr;
    }
};
