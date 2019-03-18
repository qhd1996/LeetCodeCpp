//DP
class Solution {
public:
	int countSubstrings(string s) {
		int len = s.length();
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			palindromic(s, i, i, len, cnt); // judge odd length substring
			palindromic(s, i, i + 1, len, cnt);// judge even length substring
		}
		return cnt;
	}
private:
	void palindromic(string s, int left, int right, int len, int &cnt) { // judge if a substring is palindromic
		while (left >= 0 && right < len && s[left] == s[right]) {
			left--;
			right++;
			cnt++;
		}