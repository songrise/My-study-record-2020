# <div align=middle>**Assignment 1**<div>

# Question 1
## (1.a)
Two coins taken out can be : 2 one-dollar, 2 five-dollar, 2 ten-dollar,1 one-dollar and 1 five-dollar,1 five-dollar and 1 ten-dollar, 1 one-dollar and 1 ten dollar.  
So we can get Sample space $S$:

$$
S=\{2,6,11,10,15,20\}
$$
## (1.b)
Let vector $(c_1,c_2)$ denotes the outcome of one expriment, then it is a discrete random variable.  
for example $(1,5)$ stands for $c_1$ is one-dollar and $c_2$ is five-dollar.  
Then there will be $\binom{10}2\times 2!$ possible expriments if sequence is considered.  
if $c_2 > c_1$, then there are three possible outcomes $(5,1),(10,1),(10,5)$ .  
- for (5,1), there are $\binom3 1\times \binom 5 1$ expriments.
- for (10,1), there are $\binom2 1\times \binom 5 1$ expriments.
- for (10,5), there are $\binom2 1\times \binom 3 1$ expriments.

Let $A$ be the event that the value of $c_1$ is larger than $c_2$, then
$P(A)=\frac{\binom3 1\times \binom 5 1+\binom2 1\times \binom 5 1+\binom2 1\times \binom 3 1}{\binom{10}2\times 2!}=\frac{31}{90}\approx 0.344$
## (1.c)
$P(X\le3)=P(X=1)+P(X=2)+P(X=3)$  
1. for $P(X=1)$, only if the coin we draw is ten-dollar can we satisfy the requirement.  
We can easily get $P(X=1)=\frac{\binom{2}{1}}{\binom{10}{1}}=\frac 1 5$.
2. for $P(X=2)$, it implies that first draw is not ten-dollar.  
The requirement can be met if our outcome is (1,10) or (5,5) or (5,10)  
then, $P(X=2)=(\frac{3}{10})^2+\frac{1}{5}*\frac{3}{10}*+\frac{1}{5}*\frac{1}{2}=\frac{1}{4}$

1. for $P(X=3)$, it excludes $X=1 orX=2$, so first draw cannot be (10), and the second draw cannot be (1,10) (5,5) (5,10).  
    The outcome should be $S=\{(1,1,10),(1,5,5),(1,5,10),(5,1,5),(5,1,10)\}$  
   then, $P(X=3)=(\frac{3}{10})^2*(\frac{1}{2})*2+\frac{1}{5}*\frac{3}{10}*(\frac{1}{2})*2+\frac{1}{5}*(\frac{1}{2})^2=\frac{1}{5}$

So, we have $P(X\le 3)=\frac15+\frac{1}{4}+\frac{1}{5}=\frac{13}{20}=0.65$

## (1.d) 
They are **not** independent.  
Especially, suppose we draw 10-dollar coin at first, then we will have $X=1$ and $Y=10$.  
$p(X=1)=\frac 1 5$  
$p(X=1\cap Y=10)= \frac 1 5$   
$p(Y=10)= \frac1 5 + (\frac3{10})^2 + 5 \times ({\frac{1}{2}}^5\times{\frac{3}{10}}) + (\frac12)^{10}= \frac{8889}{25600}$  

$p(X=1)\times p(Y=10)\ne p(X=1\cap Y=10)$  

$(x_i,y_j),p(X=x_i)p(Y=y_j)\ne p(X=x_i, Y=y_j)$  

**So, X and Y are not independent**.
## (1.e)

1. $P(Y=10)=\frac{1}{5}+(\frac{3}{10})^2+(\frac{1}{2})^5\times(\frac{3}{10})\times6+(\frac{1}{2})^{10}$  

2. for $11\le Y\le14$,  
   $P(Y=10+i)=(\frac{1}{2})^i*\frac{1}{5}+\frac{3}{10}*(\frac{1}{2})^{i+5}*(6+i)+{\frac{3}{10}}^2*(\frac{1}{2})^i,(1\le i\le 4)$ 

3. for $15\le Y\le19$,  
   $P(Y=14+i)=\frac{1}{5}*\frac3{10}*(\frac{1}{2})^i*i+\frac{1}{5}(\frac{1}{2})^{5+i},(1\le i \le 4)$


|  $Y$   |          10          |         11         |         12         |          13          |         14         |        15        |         16         |         17         |         18         |        19         |
| :----: | :------------------: | :----------------: | :----------------: | :------------------: | :----------------: | :--------------: | :----------------: | :----------------: | :----------------: | :---------------: |
| $p(Y)$ | $\frac{8889}{25600}$ | $\frac{623}{3200}$ | $\frac{767}{6400}$ | $\frac {911}{12800}$ | $\frac{211}{5120}$ | $\frac{53}{800}$ | $\frac{101}{1600}$ | $\frac{149}{3200}$ | $\frac{197}{6400}$ | $\frac{49}{2560}$ |


$$
E[Y]=\sum{Y·P(Y)}= \frac{7851}{640}
$$


|  $Y^2$   |         100          |        121         |        144         |         169         |        196         |       225        |        256         |        289         |        324         |        361        |
| :------: | :------------------: | :----------------: | :----------------: | :-----------------: | :----------------: | :--------------: | :----------------: | :----------------: | :----------------: | :---------------: |
| $p(Y^2)$ | $\frac{8889}{25600}$ | $\frac{623}{3200}$ | $\frac{767}{6400}$ | $\frac{911}{12800}$ | $\frac{211}{5120}$ | $\frac{53}{800}$ | $\frac{101}{1600}$ | $\frac{149}{3200}$ | $\frac{197}{6400}$ | $\frac{49}{2560}$ |
$$E[Y^2]= \frac{100511}{640}$$
$$
\sigma(Y) = \sqrt{E[Y^2]-(E[Y])^2}=\frac{\sqrt{2688839}}{640}\approx2.562
$$

## (1.f)
$X$ can be 1,2,3,4,5,6,7,8,9,10    
1. $P(X=1)=\frac{1}{10}$  

2. for $2\le X \le5$,  
    $P(X=2+i)=(\frac{3}{10})^2*(\frac{1}{2})^i*(i+1)+\frac{1}{5}*\frac{3}{10}*(\frac{1}{2})^i*(i+1)+\frac{1}{5}*(\frac{1}{2})^i,(0\le i\le3)$  

3. $(P=6)=(\frac{3}{10})^2*(\frac{1}{2})^4*5+\frac{1}{5}*\frac{3}{10}*(\frac{1}{2})^4*5+\frac{1}{5}*(\frac{1}{2})^5+6*\frac{3}{10}*(\frac{1}{2})^5$

4. for $7\le X\le 10$  
    $P(X=7+i)=\frac{1}{5}*(\frac{1}{2})^{6+i}+\frac{3}{10}(\frac{1}{2})^{6+i},(0\le i\le3)$


|  $X$   |       1       |       2       |       3       |        4        |       5        |       6        |        7        |        8        |        9        |       10        |
| :----: | :-----------: | :-----------: | :-----------: | :-------------: | :------------: | :------------: | :-------------: | :-------------: | :-------------: | :-------------: |
| $P(X)$ | $\frac{1}{5}$ | $\frac{1}{4}$ | $\frac{1}{5}$ | $\frac{11}{80}$ | $\frac{7}{80}$ | $\frac{7}{64}$ | $\frac{1}{128}$ | $\frac{1}{256}$ | $\frac{1}{512}$ | $\frac{1}{512}$ |
$$
E[X]=\sum{X·P(X)}=\frac{7851}{2560}
$$

|   Y,X    |       1       |        2        |        3        |        4         |        5        |        6        |        7        |        8         |        9         |        10        |       $p(Y=i)$       |
| :------: | :-----------: | :-------------: | :-------------: | :--------------: | :-------------: | :-------------: | :-------------: | :--------------: | :--------------: | :--------------: | :------------------: |
|    10    |   $\frac15$   | $\frac{9}{100}$ |                 |                  |                 | $\frac{9}{160}$ |                 |                  |                  | $\frac{1}{1024}$ | $\frac{8889}{25600}$ |
|    11    |               |  $\frac1{10}$   | $\frac{9}{100}$ |                  |                 |                 | $\frac{3}{640}$ |                  |                  |                  |  $\frac{623}{3200}$  |
|    12    |               |                 |  $\frac1{20}$   | $\frac{27}{400}$ |                 |                 |                 | $\frac{3}{1280}$ |                  |                  |  $\frac{767}{6400}$  |  |
|    13    |               |                 |                 |   $\frac1{40}$   | $\frac{9}{200}$ |                 |                 |                  | $\frac{3}{2560}$ |                  | $\frac{911}{12800}$  |
|    14    |               |                 |                 |                  |  $\frac1{80}$   | $\frac{9}{320}$ |                 |                  |                  | $\frac{3}{5120}$ |  $\frac{211}{5120}$  |
|    15    |               | $\frac{3}{50}$  |                 |                  |                 | $\frac{1}{160}$ |                 |                  |                  |                  |   $\frac{53}{800}$   |
|    16    |               |                 | $\frac{3}{50}$  |                  |                 |                 | $\frac{1}{320}$ |                  |                  |                  |  $\frac{101}{1600}$  |
|    17    |               |                 |                 | $\frac{9}{200}$  |                 |                 |                 | $\frac{1}{640}$  |                  |                  |  $\frac{149}{3200}$  |
|    18    |               |                 |                 |                  | $\frac{3}{100}$ |                 |                 |                  | $\frac{1}{1280}$ |                  |  $\frac{197}{6400}$  |
|    19    |               |                 |                 |                  |                 | $\frac{3}{160}$ |                 |                  |                  | $\frac{1}{2560}$ |  $\frac{49}{2560}$   |
| $p(X=i)$ | $\frac{1}{5}$ |  $\frac{1}{4}$  |  $\frac{1}{5}$  | $\frac{11}{80}$  | $\frac{7}{80}$  | $\frac{7}{64}$  | $\frac{1}{128}$ | $\frac{1}{256}$  | $\frac{1}{512}$  | $\frac{1}{512}$  |
$$
E(X,Y)=\sum(XY)*P(XY)=\frac{100973}{2560}
$$
$$
Cov(X,Y)=E(X,Y)-E(X)E(Y)=\frac{100973}{2560}-\frac{61638201}{1638400}=\frac{2984519}{1638400}\approx1.8216
$$

# Question2
## (2.a)
Proof:

Note that $S=\bigcup_{i=1}^n F_i$, then for any event $E$,
$$
\begin{aligned}
E&=E\cap S
\\&=E\cap (\bigcup_{i=1}^n F_i)
\end{aligned}
$$
Also note that for any $(i,j)that\le i, j \le n$, we have
$F_iF_j=\emptyset$,  
Then for any event E, $(E\cap F_i)(E\cap F_j)=\emptyset$ (i.e. they are disjoint)  
By the distributive law, $E\cap (\bigcup_{i=1}^n F_i)=\bigcup_{i=1}^n (F_i\cap E)$

$$
P(E)=P\bigg(\bigcup_{i=1}^n (E \cap F_i)\bigg)=\sum_{i=1}^n P(E \cap F_i)=\sum_{i=1}^n P(E | F_i) P(F_i).
$$

## (2.b)
Let $O$ denote the event that the sample student is outstanding, and $A, B, C, D$ denote that the student come from school A, B, C, D respectively.  
Then $S=A\cup B\cup C\cup D$, it can be easily derived that:   
$$
P(A)=\frac {3} {10},P(B)=\frac {1} {5},P(C)=\frac {1} {4},P(D)=\frac {1} {4}
$$
By the Law of total Probabiliy,
$$
P(O)=P(O\cap A)+P(O\cap B)+P(O\cap C)+P(O\cap D)
=P(O|A)P(A)+ P(O|B)P(B)+P(O|C)P(C)+P(O|D)P(D)
=\frac{187}{2000}   
=0.0935
$$

## (2.c)
We already have $P(O)=\frac{187}{2000}$   
By the Baye's Theroem,  
$$
P(A|O)=\frac{P(O|A)P(A)}{P(O)}=\frac{30}{187}\approx 0.160
$$

# Question 3
## (3.a)
Proof Markov Inequality for continuous random variable:  
for any $X\ge 0, \epsilon \gt 0,$
$$
   E(X)={\int ^\infty_0 Xp(X) dX} \ge {\int ^\infty_\epsilon Xp(X) dX} \ge {\epsilon\int ^\infty_\epsilon p(X) dX} \ge \epsilon P(X \ge \epsilon)
$$
So we have $P(X \ge \epsilon) \le \frac{E(X)}{\epsilon}$

## (3.b) 
Using Chebyshev's Inequality, it can be derived that:
$$
P(|X-65| \ge 10) \le \frac{\sigma ^2}{\epsilon ^2}=\frac14
$$
Since $\int_{-\infty}^\infty  p(X) dX = 1$,  
$$
P(55\le X\le 75) = 1-P(|X-65| \ge 10)\ge \frac34
$$
## (3.c)
Let $\bar X$ denotes the expectation of our sample, then we have
$$
\mu_{\bar X} = \mu = 65,\sigma^2_{\bar X} =\frac{\sigma^2}{n}
$$ 
Then,
$$
(\frac{\bar X - \mu_{\bar X}}{\frac{\sigma_{\bar X}}{\sqrt{n}}})N(0,1)
$$
If $P(60 \le \bar X \le 70)\ge 0.8$,
Then we have equation (by the symmetric property of normal distribution)
$$
({\frac{70-\mu_{\bar X}} {\frac{\sigma_{\bar X}}{\sqrt{n}}}) \ge Y}
$$
Where $P(X\ge Y) =0.90$ for a standard normal distribution.  
It can be obtained by checking the table that $Y=1.28$,  
By equation $(1)$, we can get $n \ge 1.6384$, where $n$ shoulud be an integer.    

**Thus, at least $2$ people whould have to be sampled to satisfy the requirement.**
## (3.d)
By the Law of Large Number and Central Limit Theorem,  
$\frac{\bar X-\mu}{\frac{\sigma}{\sqrt{n}}}$approximately follows $N(0,1)$ 

Then
$$
P\left(|\frac{\bar X-\mu}{\frac{\sigma}{\sqrt{n}}}|\le z\right)\cong1-2 \Phi(-z)
$$
To get a 95% confidence interval, $\Phi(-z)=0.025$  
By checking the standard Normal distribution table, we have $z=1.96$  
So, the 95% confidence interval of $\mu$:
$$ 
[\bar X-\frac{\sigma z}{\sqrt{n}},\bar X+\frac{\sigma z}{\sqrt{n}}] = [64.73,71.27]
$$

## (3.e)

We have $\bar{X}=68,\sigma=5$  
Null hypothesis $H_0:\mu \lt 65$  
Then p-value:
$P(\bar{X}\ge68)=P(\frac{\bar{X}-\mu}{\frac{\sigma}{\sqrt{n}}}\ge1.8)=\Phi(-1.8)=0.03593\lt0.05$  
So we will reject $H_0$ at level of significance $0.1$  
we will also reject $H_0$ at level of significance $0.05$