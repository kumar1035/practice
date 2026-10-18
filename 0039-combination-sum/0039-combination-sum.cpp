class Solution {
    private:
    void solve(vector<int>ip , vector<int> op , int target , vector<vector<int>>&res){

        //edge cases
        if (target==0){
            res.push_back(op);
            return ;
        }
        if (target < 0 || ip.empty()){
            return ;
        }

        // for not taking/picking  the element 
        vector<int>ip1=ip;
        ip1.erase(ip1.begin());
        solve(ip1,op, target , res);

        // for taking the element 
        vector<int> op2=op;
        op2.push_back(ip[0]);
        solve(ip,op2,target-ip[0],res);


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>op;
        solve(candidates,op,target,res);
        return res;

        
    }
};