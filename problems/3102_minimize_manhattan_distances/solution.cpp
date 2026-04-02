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
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        auto calc = [&](int skip) {
            int mxS=INT_MIN,mnS=INT_MAX,mxD=INT_MIN,mnD=INT_MAX;
            for (int i=0;i<n;i++) {
                if (i==skip) continue;
                int s=points[i][0]+points[i][1], d=points[i][0]-points[i][1];
                mxS=max(mxS,s); mnS=min(mnS,s);
                mxD=max(mxD,d); mnD=min(mnD,d);
            }
            return max(mxS-mnS, mxD-mnD);
        };
        int mxSi=0,mnSi=0,mxDi=0,mnDi=0;
        for (int i=0;i<n;i++) {
            int s=points[i][0]+points[i][1], d=points[i][0]-points[i][1];
            if (s>points[mxSi][0]+points[mxSi][1]) mxSi=i;
            if (s<points[mnSi][0]+points[mnSi][1]) mnSi=i;
            if (d>points[mxDi][0]-points[mxDi][1]) mxDi=i;
            if (d<points[mnDi][0]-points[mnDi][1]) mnDi=i;
        }
        set<int> cands={mxSi,mnSi,mxDi,mnDi};
        int res=INT_MAX;
        for (int c:cands) res=min(res,calc(c));
        return res;
    }
};
