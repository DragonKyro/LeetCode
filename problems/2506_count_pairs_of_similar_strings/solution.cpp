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
    int similarPairs(vector<string>& words) {
        int count = 0;
        auto mask = [](string& s) { int m = 0; for (char c : s) m |= 1 << (c - 'a'); return m; };
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (mask(words[i]) == mask(words[j])) count++;
        return count;
    }
};
