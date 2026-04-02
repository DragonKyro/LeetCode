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
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;
        candidates.insert((long long)pow(10, len - 1) - 1);
        candidates.insert((long long)pow(10, len) + 1);
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (long long p = prefix - 1; p <= prefix + 1; p++) {
            string s = to_string(p);
            string rev = s;
            reverse(rev.begin(), rev.end());
            string cand = s + rev.substr(len % 2);
            candidates.insert(stoll(cand));
        }
        candidates.erase(num);
        long long closest = -1;
        for (long long c : candidates) {
            if (closest == -1 || abs(c - num) < abs(closest - num) ||
                (abs(c - num) == abs(closest - num) && c < closest))
                closest = c;
        }
        return to_string(closest);
    }
};
