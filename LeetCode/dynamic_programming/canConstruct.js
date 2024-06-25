//https://youtu.be/oBt53YbR9Kk?t=8756 basically removing suffix if match
const canConstruct = (target, wordBank, memo = {}) => {
  if (target in memo) return memo[target];
  if (target === "") return true;

  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      suffix = target.slice(word.length);
      const res = canConstruct(suffix, wordBank, memo);
      if (res === true) {
        memo[target] = true;
        return true;
      }
    }
  }
  memo[target] = false;
  return false;
};
// const canConstruct = (target, wordBank) => {
//   if (target === "") return true;

//   for (let word of wordBank) {
//     if (target.indexOf(word) === 0) {
//       suffix = target.slice(word.length);
//       const res = canConstruct(suffix, wordBank);
//       if (res === true) {
//         return true;
//       }
//     }
//   }
//   return false;
// };

console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); //true
console.log(
  canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])
); // false
console.log(
  canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])
); //true
true;
console.log(
  canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    "e",
    "ee",
    "eee",
    "eeee",
    "eeeee",
    "eeeeee",
  ])
); // false
