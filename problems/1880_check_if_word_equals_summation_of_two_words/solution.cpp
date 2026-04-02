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
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto val = [](string& w) {
            int v = 0;
            for (char c : w) v = v * 10 + (c - 'a');
            return v;
        };
        return val(firstWord) + val(secondWord) == val(targetWord);
    }
};
