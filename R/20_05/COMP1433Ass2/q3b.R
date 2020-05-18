library("ggplot2")
moneyAtT <- function(T) {
    #return expected fortune after T times gamble.
    #fail event F ~ B(T, 0.51), E(F) =T * 0.51
    return(100-T*0.51 +T*0.49)#expected money
}
ExpectVal = rep(0,10000)
for (i in c(1:10000)) {
    if (moneyAtT(i)<=0) {
      #assume that he cannot owe
       break
    }
    ExpectVal[i] = moneyAtT(i)
}
q3data = data.frame(c(1:10000),ExpectVal)
ggplot(q3data,aes(x=c.1.10000.,y=ExpectVal)) + geom_line() + xlab("T") + ylab("fortune ($N)")
