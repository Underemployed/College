/**
 * @param {number[]} nums
 * @return {number[]}
 */

//linear time complexity of O(n) and space complexity O(n)
var sortedSquares = function(nums) {
    const result= new Array(nums.length).fill(0);
    let r =nums.length-1;
    let l=0;
    let resultIdx= r;
    while(l<=r){
        if(nums[l]**2>nums[r]**2){
            result[resultIdx--]=nums[l++]**2;
            
        }else{  
            result[resultIdx--]=nums[r--]**2;
        }
        

    }
    return result;
}











// squaring and then sorting array time complexity nlogn
var sortedSquares = function(nums) {
    for(let i=0;i<nums.length;i++){
        nums[i]=nums[i]*nums[i];

}
nums.sort((a,b)=>(a-b));
return nums;
}
