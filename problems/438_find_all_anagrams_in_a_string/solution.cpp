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
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        vector<int> pCount(26, 0), sCount(26, 0);
        for (char c : p) pCount[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            sCount[s[i] - 'a']++;
            if (i >= (int)p.size()) sCount[s[i - p.size()] - 'a']--;
            if (sCount == pCount) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
