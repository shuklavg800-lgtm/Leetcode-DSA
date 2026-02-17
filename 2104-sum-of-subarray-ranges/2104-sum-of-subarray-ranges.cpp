class Solution {
    vector<int> nextSmallerIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevSmaller = prevSmallerIndex(arr);
        vector<int> nextSmaller = nextSmallerIndex(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;
            sum += left * right * 1LL * arr[i];
        }

        return sum;
    }

    vector<int> nextGreaterIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterIndex(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevGreater = prevGreaterIndex(arr);
        vector<int> nextGreater = nextGreaterIndex(arr);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            sum += left * right * 1LL * arr[i];
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};
