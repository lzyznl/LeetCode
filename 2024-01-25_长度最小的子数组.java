public int minSubArrayLen(int target, int[] nums) {
        int length = nums.length;
        int sum = 0;
        int ans = length+1;
        int left=0,right=0;
        while(right<length){
            sum+=nums[right];
            if(sum>=target){
                while(sum>=target){
                    ans=Math.min(ans,right-left+1);
                    sum-=nums[left];
                    left++;
                }
            }
            right++;
        }
        return ans<=length?ans:0;
    }