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
    bool validUtf8(vector<int>& data) {
        int remaining = 0;
        for (int b : data) {
            if (remaining > 0) {
                if ((b >> 6) != 0b10) return false;
                remaining--;
            } else if ((b >> 7) == 0) remaining = 0;
            else if ((b >> 5) == 0b110) remaining = 1;
            else if ((b >> 4) == 0b1110) remaining = 2;
            else if ((b >> 3) == 0b11110) remaining = 3;
            else return false;
        }
        return remaining == 0;
    }
};
