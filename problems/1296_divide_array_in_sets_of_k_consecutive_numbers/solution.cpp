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
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        while (!cnt.empty()) {
            int first = cnt.begin()->first;
            for (int i = first; i < first + k; i++) {
                if (cnt.find(i) == cnt.end()) return false;
                if (--cnt[i] == 0) cnt.erase(i);
            }
        }
        return true;
    }
};
