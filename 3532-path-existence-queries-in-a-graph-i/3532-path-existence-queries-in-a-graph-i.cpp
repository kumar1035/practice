class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>component(n,-1);
        int cmpid = 0;
        component[0]= cmpid;
        for(int i = 1 ;i <n;i++){
            if (nums[i]- nums[i-1]>maxDiff){
                cmpid++;
            }
            component[i] = cmpid;
        }
        vector<bool>result;
        for(auto &query :queries){
            int u = query[0];
            int v = query[1];
            result.push_back(component[u] == component[v]);
        }
        return result;
        
    }
};