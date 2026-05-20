class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        int count=0;
        int n = nums.size();
        unordered_map<int, int> m;
        m[0]=1;

        for(int i = 0; i<n; i++) {
            presum+=nums[i];
            if(m.find(presum-k)!=m.end()) {
                count+=m[presum-k];
            }
            m[presum]++;
        }
        return count;
    }
};
