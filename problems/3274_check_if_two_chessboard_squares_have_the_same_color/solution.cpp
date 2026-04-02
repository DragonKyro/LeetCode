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
    bool checkTwoChessboards(string c1, string c2) {
        return (c1[0]+c1[1]) % 2 == (c2[0]+c2[1]) % 2;
    }
};
