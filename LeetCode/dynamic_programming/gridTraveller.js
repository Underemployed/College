const grid = (x, y, memo = {}) => {
  let key = `${x},${y}`;

  if (x < y) key = `${y},${x}`;

  if (key in memo) return memo[key];
  if (x === 1 && y === 1) return 1;
  if (x === 0 || y === 0) return 0;

  memo[key] = grid(x - 1, y, memo) + grid(x, y - 1, memo);

  return memo[key];
};
//examples
let memo = {};
console.log(grid(1, 1)); //1
console.log(grid(2, 3)); //6435
console.log(grid(3, 2)); //6435
console.log(grid(18, 18, memo)); //2333606220
console.log(Object.keys(memo).length);

/* Make it work*/
// visualize problem as tree
// implement tree into recursion
// leaves of tree as base case
// test it

/* Make it efficient*/
// add memo
// add condition to store and return memo values
