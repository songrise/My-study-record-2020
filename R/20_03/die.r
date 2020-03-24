roll<-function() 
  {
    die<-1:6
    dice<-sample(die,2,replace = TRUE)
    sum(dice)
  }
