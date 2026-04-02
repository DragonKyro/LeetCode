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
    bool detectCapitalUse(string word) {
        int caps = count_if(word.begin(), word.end(), ::isupper);
        return caps == (int)word.size() || caps == 0 || (caps == 1 && isupper(word[0]));
    }
};
