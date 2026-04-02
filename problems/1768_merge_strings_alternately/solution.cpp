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
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0;
        while (i < word1.size() || i < word2.size()) {
            if (i < word1.size()) result += word1[i];
            if (i < word2.size()) result += word2[i];
            i++;
        }
        return result;
    }
};
