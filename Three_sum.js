/**
 * @param {number[]} nums
 * @return {number[][]}
 */

const twoSum = (left, right, target, nums) => {
    const result = [];
    
    while (left < right) {
        const leftVal = nums[left];
        const rightVal = nums[right];
        const sum = leftVal + rightVal;
        
        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        } else {
            result.push([-target, leftVal, rightVal]);
            while (left < right && nums[left] === leftVal) left++;
            while (left < right && nums[right] === rightVal) right--;
        }
    }
    
    return result;
}

var threeSum = function(nums) {
    const result = [];
    nums.sort((a, b) => a - b);
    
    for (let i = 0; i < nums.length - 2; i++) {
        if (i === 0 || (i > 0 && nums[i] !== nums[i - 1])) {
            const target = -nums[i];
            const subResult = twoSum(i + 1, nums.length - 1, target, nums);
            result.push(...subResult);
        }
    }
    
    return result;
};
