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
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int deletions = 0;
        unordered_set<int> used;
        for (int f : freq) {
            if (f == 0) continue;
            while (f > 0 && used.count(f)) f--;
            deletions += freq[&f - &freq[0]] - f;
            if (f > 0) used.insert(f);
        }
        return deletions;
    }
};
