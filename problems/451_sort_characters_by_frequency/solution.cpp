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
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        sort(s.begin(), s.end(), [&](char a, char b) {
            return count[a] == count[b] ? a < b : count[a] > count[b];
        });
        return s;
    }
};
