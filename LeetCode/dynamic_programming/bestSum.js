//https://youtu.be/oBt53YbR9Kk?t=7394
const bestSum = (targetSum, numbers, memo = {}) => {
  if (targetSum in memo) return memo[targetSum];
  if (targetSum === 0) return [];
  if (targetSum < 0) return null;
  let shortest = null;
  for (let num of numbers) {
    const remainder = targetSum - num;
    const res = bestSum(remainder, numbers, memo);
    if (res !== null) {
      let combination = [...res, num];
      if (shortest === null || combination.length < shortest.length)
        shortest = combination;
    }
  }
  memo[targetSum] = shortest;
  return shortest;
};

// const bestSum = (targetSum, numbers) => {
//   if (targetSum === 0) return [];
//   if (targetSum < 0) return null;
//   let shortest = null;
//   for (let num of numbers) {
//     const remainder = targetSum - num;
//     const res = bestSum(remainder, numbers);
//     if (res !== null) {
//       let combination = [...res, num];
//       if (shortest === null || combination.length < shortest.length)
//         shortest = combination;
//     }
//   }
//   return shortest;
// };

console.log(bestSum(7, [2, 3])); // [3, 2, 2]
console.log(bestSum(7, [5, 3, 4, 7])); // [4, 3]
console.log(bestSum(7, [2, 4])); // null
console.log(bestSum(8, [2, 3, 5])); // [2, 2, 2, 2]
console.log(bestSum(300, [7, 14])); // null
