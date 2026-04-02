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
    bool isValidSerialization(string preorder) {
        int slots = 1;
        stringstream ss(preorder);
        string node;
        while (getline(ss, node, ',')) {
            slots--;
            if (slots < 0) return false;
            if (node != "#") slots += 2;
        }
        return slots == 0;
    }
};
