/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */
var rotateString = function(s = "abcde", goal = "cdeab") {
    if (s.length !== goal.length) return false;
    const doubledS = 2 * s;
    return doubledS.includes(goal);
};

console.log(rotateString()); // Should print true
