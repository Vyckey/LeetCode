class Solution {
public:
	vector<int> twoSum_n2(vector<int>& nums, int target) { // O(n^2)
		int result[2];
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					result[0] = i;
					result[1] = j;
					return vector<int>(result, result + 2);
				}
			}
		}
		return vector<int>();
	}
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hmap;
		for (int i = 0; i < nums.size(); ++i) {
			int second = target - nums[i];
			if (hmap.find(second) == hmap.end()) {
				hmap.insert(make_pair(nums[i], i));
			}
			else {
				int result[2] = { hmap[second],i };
				return vector<int>(result, result + 2);
			}
		}
		return vector<int>();
	}
};
