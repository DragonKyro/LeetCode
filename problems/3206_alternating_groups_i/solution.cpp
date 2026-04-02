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
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size(), res = 0;
        for (int i = 0; i < n; i++)
            if (colors[i] != colors[(i-1+n)%n] && colors[i] != colors[(i+1)%n]) res++;
        return res;
    }
};
