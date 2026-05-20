class Solution {
public:
    bool helper(vector<int>& arr, int mid,int days) {
        int daycount=1;
        int cap=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]<=mid-cap) cap+=arr[i];
            else {
                daycount++;
                cap=0;
                cap+=arr[i];
            }
        }
        return daycount<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=0;
        for(int i=0; i<weights.size(); i++) {
            high+=weights[i];
        }
        int ans;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(helper(weights, mid, days)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
