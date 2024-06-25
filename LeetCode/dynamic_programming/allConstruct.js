// https://youtu.be/oBt53YbR9Kk?t=10282
// memoization not needed solution is o(n^m) so pointless in worstcase where all leaf node returns solution
const allConstruct = (target, wordBank, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === "") return [[]];
  let result = [];
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const suffixWays = allConstruct(suffix, wordBank, memo);
      const targetWays = suffixWays.map((x) => [word, ...x]);
      result.push(...targetWays);
    }
  }
  memo[target] = result;
  return result;
};
// just for fun hehe
// const allConstruct = (target, wordBank, memo = {}) => {
//   if (target in memo) return memo[target];
//   if (target === "") return [[]];
//   let result = [];
//   for (let word of wordBank) {
//     if (target.indexOf(word) === 0) {
//       const suffix = target.slice(word.length);

//       memo[suffix] = allConstruct(suffix, wordBank, memo);
//       const targetWays = memo[suffix].map((x) => [word, ...x]);
//       result.push(...targetWays);
//     }
//   }
//   memo[target] = result;
//   return result;
// };

//orginal solution
// const allConstruct = (target, wordBank) => {
//   if (target === "") return [[]];
//   let result = [];
//   for (let word of wordBank) {
//     if (target.indexOf(word) === 0) {
//       const suffix = target.slice(word.length);
//       const suffixWays = allConstruct(suffix, wordBank);
//       const targetWays = suffixWays.map((x) => [word, ...x]);
//       result.push(...targetWays);
//     }
//   }

//   return result;
// };

console.log(allConstruct("purple", ["purp", "p", "ur", "le", "purpl"])); //2
console.log(
  allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd", "ef", "c"])
); //4
console.log(
  allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])
); //0
console.log(
  allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])
); // 4
console.log(
  allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "eeeeee",
  ])
); // 0
