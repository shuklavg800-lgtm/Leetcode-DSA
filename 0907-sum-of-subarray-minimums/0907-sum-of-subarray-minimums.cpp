class Solution {
    vector<int> nextSmallerIndex(vector<int>& arr){
        // monotonically increasing stack
        int n=arr.size();
        vector<int> ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerEqualtoIndex(vector<int>& arr){
        // monotonically increasing stack
        int n=arr.size();
        vector<int> ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> prevSmallerEqualto=prevSmallerEqualtoIndex(arr);
        vector<int> nextSmaller=nextSmallerIndex(arr);
        int sum=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            long long curr_sum=0;
            int left=i-prevSmallerEqualto[i];
            int right=nextSmaller[i]-i;
            curr_sum=left*right*1LL*arr[i];
            curr_sum=curr_sum%mod;
            sum+=curr_sum;
            sum=sum%mod;
        }
        return sum;
    }
};