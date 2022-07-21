//memoization
function fun(m,n, memo = {}) {
    let key = "m,n";
    if(key in memo) return memo[key];
    if(n==1 || m==1) return 1;
    memo[key] = fun(m-1, n, memo) + fun(m, n-1, memo);
    return memo[key];
} 

console.log(fun(3,3));
console.log(fun(2,1));
console.log(fun(1000,1000));
