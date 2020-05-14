gambleNtimes <- function(n) {
    #Return the probabilty that not run out of money after n gamble
    win = 0.49 # prob. to win each gamble.
    fortune = 100
    #return prob. that fail 99 or less times after n times gamble
    return (pbinom(fortune-1, n, 0.51))
}

times = 100
for (i in c(1:4)) {
    prob = gambleNtimes(times)
    print(paste("Probability that not run out of monery after ",times," gamble is ", prob))
    times = times * 10
}