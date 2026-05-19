class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> list;
        for(int i=0; i<intervals.size(); i++) {
            list.push_back({intervals[i][1], intervals[i][0]});
        }
        int count=0;
        sort(list.begin(), list.end());
        int end=list[0].first;
        for(int i=1; i<list.size(); i++) {
            if(list[i].second<end) {
                count++;
            }
            else {
                end=list[i].first;
            }
        }
        return count;
    }
};
