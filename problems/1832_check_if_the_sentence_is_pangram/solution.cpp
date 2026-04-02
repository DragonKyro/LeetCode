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
    bool checkIfPangram(string sentence) {
        unordered_set<char> s(sentence.begin(), sentence.end());
        return s.size() == 26;
    }
};
