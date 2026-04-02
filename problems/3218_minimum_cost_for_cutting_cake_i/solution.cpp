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
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        int h=0,v=0,hp=1,vp=1,res=0;
        while (h<(int)horizontalCut.size()&&v<(int)verticalCut.size()) {
            if (horizontalCut[h]>=verticalCut[v]) { res+=horizontalCut[h++]*vp; hp++; }
            else { res+=verticalCut[v++]*hp; vp++; }
        }
        while (h<(int)horizontalCut.size()) res+=horizontalCut[h++]*vp;
        while (v<(int)verticalCut.size()) res+=verticalCut[v++]*hp;
        return res;
    }
};
