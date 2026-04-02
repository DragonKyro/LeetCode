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
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {};
        for (char c : magazine) count[c - 'a']++;
        for (char c : ransomNote)
            if (--count[c - 'a'] < 0) return false;
        return true;
    }
};
