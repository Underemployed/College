/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(nums) {
    nums.sort((a,b)=>a[0]-b[0]);
    const result=[nums[0]];
    for(let i=1;i<nums.length;i++){
        let e1=result[result.length-1][1];
        let e2=nums[i][1];
        let s1=nums[i][0];
        if(e1>= s1){;
            //we need to merge
            result[result.length-1][1]=Math.max(e1,e2);
        }else{
            result.push(nums[i]);
        }
    }
    return result;
};