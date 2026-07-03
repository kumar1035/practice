// class Solution {
// public:
// int n ;
// int solve(int idx, vector<int>&nums,bool flag){
//     //base conmdition 
//     if (idx >= n){
//         return 0;
//     }
//     int skip = solve(idx+1,nums,flag);
//     int val = nums[idx];
//     if (flag == false){ 
//          // false = 0 -- means odd index so need to subtract 
//         val = -val;
// }
//     int take = solve(idx+1,nums,!flag)+ val  ; //if flag = true then change the sign( alternate) 
//     return max(take , skip);

// }
//     long long maxAlternatingSum(vector<int>& nums) {
//          n = nums.size();
//          return solve(0,nums,true) ; //0 = even idx ,true = 1

        
//     }
// };

// now move to the memoization method 

class Solution {
public:
typedef long long ll;
ll n ;
ll t[100001][2] ;  // 2 is for true or false means two things are changing 
ll solve(int idx, vector<int>&nums,bool flag){
    //base conmdition 
    if (idx >= n){
        return 0;
    }
    if (t[idx][flag] !=-1){
        return t[idx][flag];
    }
    ll skip = solve(idx+1,nums,flag);
    ll val = nums[idx];
    if (flag == false){ 
         // false = 0 -- means odd index so need to subtract 
        val = -val;
}
    ll take = solve(idx+1,nums,!flag)+ val  ; //if flag = true then change the sign( alternate) 
    return t[idx][flag] =max(take , skip);

}
    long long maxAlternatingSum(vector<int>& nums) {
         n = nums.size();
         memset(t,-1,sizeof(t));
         return solve(0,nums,true) ; //0 = even idx ,true = 1

        
    }
};

