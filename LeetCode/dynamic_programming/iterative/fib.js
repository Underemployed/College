//https://youtu.be/oBt53YbR9Kk?t=11883
const fib = (n) => {
  const table = Array(n + 1).fill(0);
  table[1] = 1;

  for (let i = 1; i <= n; i++) {
    table[i + 1] += table[i];
    table[i + 2] += table[i];
  }
  return table[n - 1];
};

console.log(fib(4));
