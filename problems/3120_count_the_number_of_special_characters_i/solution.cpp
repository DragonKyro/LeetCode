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
    int numberOfSpecialChars(string word) {
        set<char> s(word.begin(), word.end());
        int res = 0;
        for (char c = 'a'; c <= 'z'; c++)
            if (s.count(c) && s.count(c - 32)) res++;
        return res;
    }
};
