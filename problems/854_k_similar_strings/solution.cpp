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
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s1); visited.insert(s1);
        int swaps = 0;
        while (!q.empty()) {
            swaps++;
            int sz = q.size();
            while (sz--) {
                string curr = q.front(); q.pop();
                int i = 0;
                while (curr[i] == s2[i]) i++;
                for (int j = i + 1; j < curr.size(); j++) {
                    if (curr[j] == s2[i] && curr[j] != s2[j]) {
                        string nxt = curr;
                        swap(nxt[i], nxt[j]);
                        if (nxt == s2) return swaps;
                        if (!visited.count(nxt)) { visited.insert(nxt); q.push(nxt); }
                    }
                }
            }
        }
        return -1;
    }
};
