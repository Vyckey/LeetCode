class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int i, j, ileft, iright;
		unsigned int half_len;
		vector<int>& A = (nums1.size() > nums2.size() ? nums2 : nums1),
			B = (nums1.size() > nums2.size() ? nums1 : nums2);
		half_len = (A.size() + B.size() + 1) >> 1;
		ileft = 0; iright = A.size();
		while (ileft <= iright) {
			i = (ileft + iright) >> 1;
			j = half_len - i;
			if (i > 0 && A[i - 1] > B[j])
				iright = i - 1;
			else if (i < A.size() && B[j - 1] > A[i])
				ileft = i + 1;
			else {
				int max_left, min_right;
				if (i == 0) max_left = B[j - 1];
				else if (j == 0) max_left = A[i - 1];
				else max_left = max(A[i - 1], B[j - 1]);
				if (((A.size() + B.size()) & 0x1) == 0x1)
					return max_left;
				if (i == A.size()) min_right = B[j];
				else if (j == B.size())	min_right = A[i];
				else min_right = min(A[i], B[j]);
				return (max_left + min_right) / 2.0;
			}
		}
	}
};
