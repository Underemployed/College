/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    if(nums.length===1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[nums.length-1]>nums[nums.length-2]) return nums.length-1;
    for(let i=0;i<nums.length-2;i++){
        const left=nums[i];
        const mid=nums[i+1];
        const right=nums[i+2];
        if(mid>left && mid>right) return i+1;
    }
};

//binary search
/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    let l=0;
    let r=nums.length-1
    while(l<r){
        mid=Math.floor((l+r)/2);
        if(nums[mid]>nums[mid+1]){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;

};