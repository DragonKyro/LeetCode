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
    int vowelStrings(vector<string>& words, int left, int right) {
        string v = "aeiou"; int cnt = 0;
        for (int i = left; i <= right; i++)
            if (v.find(words[i].front())!=string::npos && v.find(words[i].back())!=string::npos) cnt++;
        return cnt;
    }
};
