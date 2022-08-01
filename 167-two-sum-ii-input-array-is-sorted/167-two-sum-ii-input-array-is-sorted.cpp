class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 1, r = numbers.size()-1;
		while (l <= r) {
			int m = l + ((r - l) >> 1);
			if (numbers[m] > target)
				r = m - 1;
			else
				l = m + 1;
		}
		r = min(l,(int)numbers.size()-1);
		l = 0;
		while (l < r) {
			int sum = numbers[l] + numbers[r];
			if (sum == target)
				return { l+1,r+1 };
			else if (sum < target) {
				l++;
			}
			else {
				r--;
			}
		}
		return { 0,0 };
    }
};