public int numSubarrayProductLessThanK(int[] nums, int k) {
        //假设枚举的right处乘积符合条件,那么(left,right)->(left+1,right)->....(right,right)
        int length = nums.length;
        int left=0;
        int right=0;
        int result = 1;
        int ans = 0;
        while(right<length){
            result*=nums[right];
            if(result<k){
                ans+=(right-left+1);
            }else{
                while(result>=k&&left<=right){
                    result/=nums[left];
                    left++;
                }
                ans+=(right-left+1);
            }
            right++;
        }
        return ans;
    }