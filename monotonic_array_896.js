/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function(nums) {
    const length=nums.length-1;
    const same = nums[0]===nums[length];
    const decreases = nums[0]>nums[length];
    if(same){
        for(let i = 0;i<length;i++) if(nums[i]!==nums[i+1])return false;
    }
    else if(decreases){
        for(let i = 0;i<length;i++) if(nums[i]<nums[i+1])return false;
    }
    else{
        for(let i = 0;i<length;i++) if(nums[i]>nums[i+1])return false;
    }
    return true;
};