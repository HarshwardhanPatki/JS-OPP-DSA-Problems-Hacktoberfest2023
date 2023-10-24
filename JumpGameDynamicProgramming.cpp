//55. Jump Game - I

// Recursion + DP

Solution {
public:
    bool solve(int ind,vector<int>& nums,int n,vector<int> &dp)
    {
        if(ind == n-1) return true;
        if(nums[ind] == 0 ) return 0;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=nums[ind];i++)
        {
            if(i<n and solve(ind+i,nums,n,dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<int> dp(n,-1);
        return solve(0,nums,n,dp);
    }
};

45. Jump Game II
class Solution {
public:
    int solve(int ind,vector<int>& nums,int n,vector<int>& dp)
    {
        if(ind >= n-1) return 0;
        int ans = 1e8;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=1;i<=nums[ind];i++)
        {
            if(ind + i < n)
            {
                ans = min(ans , 1 + solve(ind+i,nums,n,dp));
            }
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,nums.size(),dp);
        
    }
};

1306. Jump Game III

class Solution {
    bool solve(int ind,vector<int>& arr,int n,vector<int>&vis)
    {
        vis[ind]=1;
        if(arr[ind] == 0) return true;

        bool back = false;
        if( (ind - arr[ind]) >=0 and !vis[ind-arr[ind]])
        {
            back = solve(ind-arr[ind],arr,n,vis);
        }

        bool front = false;
        if((ind + arr[ind]) <= n-1 and !vis[ind+arr[ind]])
        {
            front = solve(ind+arr[ind],arr,n,vis);
        }

        return back or front;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return solve(start,arr,n,vis);
    }
};
