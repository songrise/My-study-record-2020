# Report for Q3 and Q4

## Q3

### Q3(1)

The probability that he do not run ot of money after 100,1,000,10,000 , and 100,000 times are 1, 6.52956269890831e-170, 0, 0 respectively.  
(Some number are too small to  be stored as floating number, so some results are rounded to 1 or 0)

### Q3(2)


**My observation**: The more he gamble, the less money he will have on average.(i.e. the money he have is a decreasing liner function to the gamble times $T$ until he run out of money)


## Q4

### Q4(1)

Our sample looks like this, 

to find the linear regression line is to find a line which makes the sum of errors is minimal.

for each pint, error $d_i = y_i-(\hat{\beta_1}x_i+\hat{\beta_0})$.

Sum of error square $D =(y_i-(\hat{\beta_1}x_i+\hat{\beta_0}))^2$

To minimize D, we shall use calculus.  
Find the partial derivate of $\hat{\beta_0}$ and $\hat{\beta_1}$

$\frac{\partial D}{\partial \hat{\beta_0}} = \sum^n_{i=1}-2(y_i-\hat{\beta_0}-\hat{\beta_1}x_i)$

$\frac{\partial D}{\partial \hat{\beta_1}}=-2(\sum^n_{i=1}x_iy_i-\hat{\beta_0}\sum^n_{i=1}x_i - \hat{\beta_1}x_i^2)$

let $\frac{\partial D}{\partial \hat{\beta_0}}$ and $\frac{\partial D}{\partial \hat{\beta_1}}$ be 0, $n\bar x = \sum^n_{i=1}x_i$ and $n\bar y = \sum^n_{i=1}y_i$.
(I think unbiased estimation is also ok here (as slides shows), anyway it do not affect the result)

We have: $\sum^n_{i=1}x_iy_i-\bar y\sum^n_{i=1}x_i+\hat{\beta_1}\bar x\sum^n_{i=1}x_i - \hat{\beta_1}\sum^n_{i=1}x_i^2=0$

and $\hat{\beta_0}=\bar y - \hat{\beta_1}\bar x$

Finally, we can get 
$\hat{\beta_0}=\bar y - \hat{\beta_1}\bar x$

and 
$\hat{\beta_1} = \frac{\sum^n_i=1(x_i-\bar x)(y_i-\bar y)}{\sum^n_i=1(x_1-\bar x)^2}$

### Q4(2)

![YB5FVe.png](https://s1.ax1x.com/2020/05/14/YB5FVe.png)

### Q4(3)

the model we get in Q4(2) is $y = 0.75016 + 0.06388x$.  
So, for a 3.5-yr-old boy, his expected height is $0.75016 + 0.06388*3.5=0.97374$ meters  
and for an 8-yr-old boy, it's $0.75016 + 0.06388*8=1.2612$ meters
