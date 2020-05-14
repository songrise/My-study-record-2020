# Report for Q3 and Q4

## Q3

### Q3(1)

The probability that he do not run ot of money after 100,1,000,10,000 , and 100,000 times are 1, 6.52956269890831e-170, 0, 0 respectively.  
(Some number are too small to  be stored as floating number, so some results are rounded to 1 or 0)

### Q3(2)

![YB5dqU.png](https://s1.ax1x.com/2020/05/14/YB5dqU.png)
**My observation**: The more he gamble, the less money he will have on average.(i.e. the money he have is a decreasing liner function to the gamble times $T$ until he run out of money)


## Q4

### Q4(1)

x denotes age, y denotes height.  
$\bar{x} = \frac{\sum^N_{i=1} x_i}{N} = 4.923572$  
$\bar{y} = \frac{\sum^N_{i=1} y_i}{N} = 1.064686$

$\hat{\beta_1}=\frac{s_{xy}}{s_{xx}}=\frac{\sum^N_{i=1}(x_i-\bar{x})(y_i-\bar{y})}{\sum^N_{i=1}(x_i-\bar{x})^2}=\frac{0.1906353}{2.984218}=0.06388116$  
$\hat{\beta_0}=\bar{y}-\hat{\beta_1}\bar{x}=1.064686-4.923572*0.06388116=0.7501625$

So, applying the least square algorithm, the regression line is  $y =0.06388116x + 0.7501625$

### Q4(2)

![YB5FVe.png](https://s1.ax1x.com/2020/05/14/YB5FVe.png)

### Q4(3)

the model we get in Q4(2) is $y = 0.75016 + 0.06388x$.  
So, for a 3.5-yr-old boy, his expected height is $0.75016 + 0.06388*3.5=0.97374$ meters  
and for an 8-yr-old boy, it's $0.75016 + 0.06388*8=1.2612$ meters