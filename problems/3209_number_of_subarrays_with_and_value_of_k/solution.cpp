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
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int,long long> curr;
        for (int x : nums) {
            unordered_map<int,long long> nxt;
            for (auto& [v,c] : curr) nxt[v&x] += c;
            nxt[x]++;
            if (nxt.count(k)) res += nxt[k];
            curr = nxt;
        }
        return res;
    }
};
