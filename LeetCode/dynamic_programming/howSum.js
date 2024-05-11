// time: O(n*m2)
// space: O(m2)
function howSum(target, numbers, memo = {}) {
  if (target in memo) return memo[target];
  if (target === 0) return [];
  if (target < 0) return null;
  for (let num of numbers) {
    const remainder = target - num;
    const res = howSum(remainder, numbers, memo);
    if (res !== null) {
      memo[target] = [...res, num];
      return memo[target];
    }
  }
  memo[target] = null;
  return null;
}

// function howSum(target, numbers) {
//   if (target === 0) return [];
//   if (target < 0) return null;
//   for (let num of numbers) {
//     const remainder = target - num;
//     const res = howSum(remainder, numbers);
//     if (res !== null) {
//       return [...res, num];
//     }
//   }
//   return null;
// }
// // time : O(n^m*m)
// //space : O(m)

// Test cases
console.log(howSum(7, [2, 3])); // [3, 2, 2]
console.log(howSum(7, [5, 3, 4, 7])); // [4, 3]
console.log(howSum(7, [2, 4])); // null
console.log(howSum(8, [2, 3, 5])); // [2, 2, 2, 2]
console.log(howSum(300, [7, 14])); // null
