class Solution {
public:

int dp[21][21][2];
int solve(int i,int j,bool who,const vector<int> &nums)
{
    if(i>j) return 0;

    if(dp[i][j][who] != -1)   return dp[i][j][who];

    int p1 = 0;

    if(who){
        p1 = max(nums[i]+solve(i+1,j,false,nums),nums[j]+solve(i,j-1,false,nums));
    } 
    else{
        p1 += min(solve(i+1,j,true,nums),solve(i,j-1,true,nums));
    }

    return dp[i][j][who] = p1;
}
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int i = 0, j = nums.size()-1;
        int total = accumulate(nums.begin(),nums.end(),0);
        int sum1 = solve(i,j,true,nums);
        cout<<sum1;
        return sum1>=(total-sum1);
    }
};