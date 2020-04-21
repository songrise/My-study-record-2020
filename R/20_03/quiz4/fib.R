
fib <- rep(0,100)
fib[1] <- 0
fib[2] <- 1
for (i in 3:100){
  fib[i] <- fib[i-1]+fib[i-2]
}

write.table(fib,"user/R/output/Fibonacci_100.txt",sep="\n",row.names = FALSE,col.names = FALSE)


