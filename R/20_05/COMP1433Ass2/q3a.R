gambleNtimes <- function(n) {
    #n is the gamble time, return probability that do not run out of money after n gamble.
    SimulationTimes = 100000
    winTimes = 0 # if he do not run out of money at last, we call it win.

    for (i in c(1:SimulationTimes)) {
        fortune = 100
        sim = runif(n)

        for (i in c(1:n)) {

            if (sim[i] <= 0.49) {# win a gamble
                fortune = fortune + 1
            }
            else {
                fortune = fortune - 1
            }

            if (fortune < 0) {
                break
            }
        }

        if (fortune > 0)
        {
            winTimes = winTimes + 1
        }
    }

    return (winTimes / SimulationTimes)
}

times = 100
for (i in c(1:4)) {
    prob = gambleNtimes(times)
    print(paste("Probability that not run out of monery after ",times," gamble is ", prob))
    times = times * 10
}