class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
  
        int start = 0, end = nums.size() - 1;
        while(start < end)
        {
            while(nums[start] != val && start < end)
                ++start;
            while(nums[end] == val && end > start)
                --end;
            
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;   
        }
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != val)
            {
                count++;
            }
            else
                break;
        }
        return count;
        
    }
};