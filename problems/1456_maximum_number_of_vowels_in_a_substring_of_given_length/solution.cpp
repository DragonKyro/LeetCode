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
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) { return string("aeiou").find(c) != string::npos; };
        int count = 0;
        for (int i = 0; i < k; i++) count += isVowel(s[i]);
        int res = count;
        for (int i = k; i < (int)s.size(); i++) {
            count += isVowel(s[i]) - isVowel(s[i - k]);
            res = max(res, count);
        }
        return res;
    }
};
