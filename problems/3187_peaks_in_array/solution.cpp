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
    vector<int> tree;
    int n;
    void upd(int i, int d) { for(i++;i<=n;i+=i&(-i)) tree[i]+=d; }
    int qry(int i) { int s=0; for(i++;i>0;i-=i&(-i)) s+=tree[i]; return s; }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size(); tree.assign(n+1,0);
        vector<bool> peaks(n,false);
        for(int i=1;i<n-1;i++) if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){peaks[i]=true;upd(i,1);}
        vector<int> res;
        for(auto& q:queries){
            if(q[0]==1){int l=q[1],r=q[2]; res.push_back(r-l<2?0:qry(r-1)-qry(l));}
            else{
                int idx=q[1]; nums[idx]=q[2];
                for(int i=max(1,idx-1);i<min(n-1,idx+2);i++){
                    bool now=nums[i]>nums[i-1]&&nums[i]>nums[i+1];
                    if(peaks[i]&&!now){upd(i,-1);peaks[i]=false;}
                    else if(!peaks[i]&&now){upd(i,1);peaks[i]=true;}
                }
            }
        }
        return res;
    }
};
