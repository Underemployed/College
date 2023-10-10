/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    for(let i=0;i<nums.length-1;i++){
        let minIdx=i;
        for(let j=i+1;j<nums.length;j++){
            if(nums[minIdx]>nums[j]) minIdx=j;
        }
        [nums[i],nums[minIdx]]=[nums[minIdx],nums[i]];
    }
    return nums;
};
