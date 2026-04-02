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
    string truncateSentence(string s, int k) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') count++;
            if (count == k) return s.substr(0, i);
        }
        return s;
    }
};
