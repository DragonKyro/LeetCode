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
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> c1, c2;
        for (auto& w : words1) c1[w]++;
        for (auto& w : words2) c2[w]++;
        int count = 0;
        for (auto& [w, cnt] : c1) {
            if (cnt == 1 && c2[w] == 1) count++;
        }
        return count;
    }
};
