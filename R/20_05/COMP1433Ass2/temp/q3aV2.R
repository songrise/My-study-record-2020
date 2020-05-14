
#!##################BUGGY ALGORITHM##################
gambleNtimes <- function(n) {
    #Return the probabilty that not run out of money after n gamble
    win = 0.49 # prob. to win each gamble.
    fortune = 100
    #negative binomial
    bankrupt_at_last_gamble = ((1-win) ^ fortune) * (win ^ (n - fortune)) * choose(n-1, fortune-1)
    #Event that "not yet run out of money after n gambles" is the
    #inverse event of "just run out of money at n-th gamble".
    print(bankrupt_at_last_gamble)
    return (1 - bankrupt_at_last_gamble)
}

times = 100
for (i in c(1:4)) {
    prob = gambleNtimes(times)
    print(paste("Probability that not run out of monery after ",times," gamble is ", prob))
    times = times * 10
}