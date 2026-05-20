class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string ans;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            int j = i;
            while (j < n && s[j] != ' ') j++;

            string word = s.substr(i, j - i);
            if (ans.empty()) ans = word;
            else ans = word + " " + ans;
            i = j;
        }
        return ans;
    }
};
