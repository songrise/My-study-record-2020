# <div align=middle>**Assignment 1**<div>
# Question 1
## (1.a)
$$
S=\{2,6,11,10,15,20\}
$$
## (1.b)
let $(c1,c2)$ denotes the outcome of one expriment, then it is a discrete random variable.  
for example $(1,5)$ stands for $c_1$ is one-dollar and $c_2$ is five-dollar.  
then there will be $\binom{10}2\times 2!$ possible expriments when sequence is considered.  
if $c_2 > c_1$, then there are three possible outcome $(5,1),(10,1),(10,5)$ .  
- for (5,1), there are $\binom3 1\times \binom 5 1$ expriments
- for (10,1), there are $\binom2 1\times \binom 5 1$ expriments
- for (10,5), there are $\binom2 1\times \binom 3 1$ expriments

Let $A$ be the event that value of $c_1$ is larger than $c_2$,then
$P(A)=\frac{\binom3 1\times \binom 5 1+\binom2 1\times \binom 5 1+\binom2 1\times \binom 3 1}{\binom{10}2\times 2!}=\frac{31}{90}\approx 0.344$
## (1.c)
$P(X\le3)=P(X=1)+P(X=2)+P(X=3)$  
1. for $P(X=1)$, only if the coin we draw is ten-dollar can we satisfy the requirement.  
We can easily get $P(X=1)=\frac{\binom{2}{1}}{\binom{10}{1}}=\frac 1 5$.
2. for $P(X=2)$, it implies that first draw is not ten-dollar.  
The requirement can be met if our outcome is (1,10) or (5,5) or (5,10)  
then, $P(X=2)=\frac {\binom{8}{5} \binom 9 2+\binom83 \binom 9 2+\binom82 \binom 9 1}{\binom81\binom91}=$

3. for $P(X=3)$, it excludes $X=1 orX=2$, so first draw cannot be (10), and the second draw cannot be (1,10) (5,5) (5,10).  
    The outcome should be S={(1,1,10),(1,5,5),(1,5,10),(5,1,5),(5,1,10)}  
then,$P(X=3)=\frac{\binom{5}{1}\binom{4}{1}\binom{2}{1}+\binom{5}{1}\binom{3}{1}\binom{2}{1}+\binom{5}{1}\binom{3}{1}\binom{2}{1}+\binom{3}{1}\binom{5}{1}\binom{2}{1}+\binom{3}{1}\binom{5}{1}\binom{2}{1}} {\binom{5}{1}\binom{7}{1}\binom{8}{1}+\binom{3}{1}\binom{5}{1}\binom{8}{1}}=$
   
So,we have $P(x\le 3)=++=\approx$

## (d)
$\Sigma\Epsilon\Pi$