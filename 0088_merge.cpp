class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        if(m == 0)
        {
            nums1 = nums2;
            return;
        }
        int len = m + n - 1;
        m--;
        n--;
        while(m >= 0 && n >= 0)
        {
            if(nums1[m] >= nums2[n])
                nums1[len--] = nums1[m--]; 
            else
                nums1[len--] = nums2[n--];
                
        }
        if(n >= 0)
            for(int i = n; i >= 0; --i)
                nums1[i] = nums2[i];
    }
};