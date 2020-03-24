roll2=function(bone=1:6) 
{
    dice = sample(bone, 2, replace = TRUE)
    sum(dice)
}