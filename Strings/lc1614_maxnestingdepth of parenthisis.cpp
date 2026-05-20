class Solution {
public:
    int maxDepth(string s) {
        int globalmax=0;
        int open=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                open++;
                globalmax=max(globalmax, open);
            }
            else if(s[i]==')') open--;
        }
        return globalmax;
    }
};
