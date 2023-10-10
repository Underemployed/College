/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    for(let i=1;i<nums.length;i++){
        let j=i;
        while(j>0 && nums[j-1]>nums[j]){
            [nums[j-1],nums[j]]=[nums[j],nums[j-1]];
            j--;
        }
    }
    return nums;
};
