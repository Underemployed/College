/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let left =1;
    let right=1;
    const result=new Array(nums.length).fill(1);

    for(let i=0;i<nums.length;i++){
        // console.log(i,')left=',left,',right=',right)
        // console.log('result=',result)

        result[i]*=left;
        result[nums.length-i-1]*=right;
        left*=nums[i];
        right*= nums[nums.length-i-1];
    }
    return result;
};

console.log(productExceptSelf([1,2,3,4]));    
