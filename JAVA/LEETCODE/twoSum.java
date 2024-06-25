package JAVA.LEETCODE;

import java.util.HashMap;



class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i =0;i<nums.length;i++){
            map.put(nums[i],i);

        }
        for(int i =0;i<nums.length;i++){
            int answer = target- nums[i];
            if(map.containsKey(answer)){
                if( map.get(answer) != i){
                    return new int [] { i,map.get(answer)};
                }
            }
        }
        return new int []{};
        
    }
}