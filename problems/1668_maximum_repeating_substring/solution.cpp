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
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string repeated = word;
        while (sequence.find(repeated) != string::npos) {
            count++;
            repeated += word;
        }
        return count;
    }
};
