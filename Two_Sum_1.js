
// brute force no memory but time complexity O(n^2)
var twoSum=function(nums,target){
    for(let i=0;i<nums.length;i++){
        for(let j=0;j<nums.length-1;j++){
            if(target==nums[i]+nums[j] && i!=j)
            return [i,j];
        }
    }
};

// scrapped easier to do mapping
// sort nlog(n)  time: o(nlogn) space:o(n) size of array
// var twoSum=function(nums,target){
//     let copy=[...nums];
//     copy.sort((a,b)=>a-b);//sort doesnt return value
//     for(let i=0;i<copy.length-1;i++){
//         for(let j=copy.length-1;j>i;j--){
//             if(target===copy[i]+copy[j]){
//                 index1=nums.indexOf(copy[i]);// starting value for searching
//                 //indexOf(searchValue,parameters)
//                 return [nums.indexOf(copy[i]),nums.indexOf(copy[j],index1+1)]
//             }
//         }
//     }
// };

