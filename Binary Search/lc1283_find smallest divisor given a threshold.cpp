class Solution {
public:
    bool helper(vector<int>& arr, int mid, int threshold) {
        int sum=0;
        for(int i=0; i<arr.size(); i++) {
            sum += (arr[i] + mid - 1) / mid;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int ans;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(helper(nums, mid, threshold)) {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};
