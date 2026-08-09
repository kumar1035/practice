class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int , int>> maxh;
        for(auto it : mp){
            maxh.push({it.second,it.first});

        }
        vector<int> ans;
        while( k-- && !maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};