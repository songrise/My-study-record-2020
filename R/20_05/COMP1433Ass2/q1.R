f1 <- function(x=1, n=3){
    # x is a real num and n is a positive int
    sum <- 0

    for (i in c(1:n)) {
        sum <- sum + i*x^i
    }
    return(sum)
}

f2 <- function(x){
    #x is a vector
    if (length(x) == 0) {
        #if x contains no element
        return(NA)
    }

    sum <- 0 #if no element divisible by 2 or 3, then return value is 0
    for (number in x) {
        if (number %% 2 == 0) { #divisible by 2
            sum <- sum + number
        }
        else if (number %% 3 == 0) {
            sum <- sum + number
        }

    }

    return(sum)
}

f3 <- function(x,n){
    #x is a vector of real num, and n is a positive int.
    len = length(x)
    if (n>len) {
        return(NA)
    }
    x <- sort(x)
    return(x[len-n+1]) # return the n-th largest number in x
}

f4 <- function(x){
    # x is a vector with m numbers, and n_k is at its k-th entry.
    len = length(x)
    all_student = sum(x)

    if (x[1] >= 0) { #inintialize all_possible_sol to be the combination of mPn_1
    all_possible_sol <- choose(all_student, x[1])
    }
    else {
       return (NA)
    }

    all_student <-all_student - x[1] # student remaining

    if (len == 1) {
        #avoid index error in coming for loop
        return(all_possible_sol) # same as return (1)
    }

    for (nk in x[2:len]) {
        if (nk < 0) {
            return (NA)
        }

        #applying mutiplication rule here.
        all_possible_sol <- all_possible_sol * choose(all_student, nk)
        all_student <-all_student - nk # student remaining.
    }

    return (all_possible_sol)
}
##########end of Question1##########