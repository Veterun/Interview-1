// merge the elements from back to front
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
 {
  int i = m - 1, j = n - 1;
  int k = m + n -1;
  while (j >= 0) //only need to consider J we overwrite in the vector nums1.
  {
    nums1[k--] = i >= 0 && nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
  }
 }
