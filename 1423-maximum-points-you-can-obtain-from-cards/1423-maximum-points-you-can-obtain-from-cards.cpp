// here we calculate the left sum upto k-1 then  for right sum we remove the element from the left sum and add  from the right side one by one 


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int rightsum = 0;
        int maxsum = 0;
        int n =  cardPoints.size();
        for(int i = 0; i<k;i++){
            leftsum += cardPoints[i];
        }
        maxsum = leftsum;
        int rindex = n -1;
        for(int i = k-1;i>=0;i--){
            leftsum = leftsum - cardPoints[i];
            rightsum = rightsum + cardPoints[rindex];
            rindex--;
            maxsum = max(maxsum , leftsum + rightsum);
        }
        
        return maxsum;
        
    }
};