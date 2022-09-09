class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),i=0,j=1;
        
        while(j<n)
        {
            if(nums[i]!=nums[j])
            {
                j++;
            }
            else
            {
                int temp;
                i++;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
//return nums;
        
    }
};
