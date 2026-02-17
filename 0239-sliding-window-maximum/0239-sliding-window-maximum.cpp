class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n=nums.size();
        // the first k elements or the first window 
        // tc O(k)
        for(int i=0;i<k;i++){
            while(dq.size()!=0 && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        // the consecutive windows 
        // tc O(n-k)
        for(int i=k;i<n;i++){
            ans.push_back(nums[dq.front()]);

            // check for the valid window
            if(dq.front()<= i-k){
                dq.pop_front();
            }
            while(dq.size()!=0 && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};