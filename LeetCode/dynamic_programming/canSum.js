//https://youtu.be/oBt53YbR9Kk?t=4603

const canSum = (targetSum, numbers, memo = {}) => {
  if (targetSum in memo) return memo[targetSum];
  if (targetSum === 0) return true;
  if (targetSum < 0) return false;
  for (let num of numbers) {
    let remainder = targetSum - num;
    if (canSum(remainder, numbers, memo) === true) {
      memo[targetSum] = true;
      return true;
    }
  }
  memo[targetSum] = false;
  return false;
};

console.log(canSum(7, [2, 3])); // Output: true
console.log(canSum(7, [5, 3, 4, 7])); // Output: true
console.log(canSum(7, [2, 4])); // Output: false
console.log(canSum(8, [2, 3, 5])); // Output: true
console.log(canSum(300, [7, 14])); // Output: false
