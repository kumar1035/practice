class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int x =pq.top();
        pq.pop();
        return (x-1)*(pq.top()-1);
    }
};