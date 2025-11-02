isprime = function(n) {
    if (n <= 1) {
        return(FALSE)
    }
    if (n == 2) {
        return(TRUE)
    }

    for (i in 2:(n - 1)) {
        if (n %% i == 0) {
            return(FALSE)
        }
    }
    return(TRUE);
}


generate_prime = function(n) {
    primes = c()
    num = 2
    while (length(primes) < n) {
        if (isprime(num)) {
            primes = c(num, primes)
        }
        num = num + 1
    }
    return(primes)
}

generate_prime(6)