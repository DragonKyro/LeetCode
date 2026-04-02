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
    int numTilePossibilities(string tiles) {
        int count[26] = {};
        for (char c : tiles) count[c - 'A']++;
        return backtrack(count);
    }
    int backtrack(int count[]) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                count[i]--;
                total += 1 + backtrack(count);
                count[i]++;
            }
        }
        return total;
    }
};
