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
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), target = skill[0] + skill[n-1];
        long long chemistry = 0;
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n-1-i] != target) return -1;
            chemistry += (long long)skill[i] * skill[n-1-i];
        }
        return chemistry;
    }
};
