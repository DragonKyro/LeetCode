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
    bool checkDistances(string s, vector<int>& distance) {
        int first[26];
        memset(first, -1, sizeof(first));
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] >= 0) {
                if (i - first[c] - 1 != distance[c]) return false;
            } else first[c] = i;
        }
        return true;
    }
};
