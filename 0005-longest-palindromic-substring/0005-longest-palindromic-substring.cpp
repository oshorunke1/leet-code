class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) {
            return s;
        }

        int start = 0, maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            expandAroundCenter(s, i, i, start, maxLength);

            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = left;
            }
            left--;
            right++;
        }
    }
};