# <div align=middle>**Assignment 1**<div>
# 概率函数的大P小p得区分一下（Q1，Q2）
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
## (1.c)要放回。下面全错（系数不变）。
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

## (1.d) 不相关不代表不独立
they are dependent.  
Especially, suppose we draw 10-dollar coin at first, then we will have $X=1$ and $Y=10$.  
$P(X=1)=\frac{\binom{2}{1}}{\binom{10}{1}}=\frac 1 5$  
$P(Y=10)=\frac{\binom{2}{1}}{\binom{10}{1}}+{\frac {\binom83 \binom 9 2}{\binom81\binom91}}=$  
$P(X=1\cap Y=10)=\frac{\binom{2}{1}}{\binom{10}{1}}=\frac 1 5$   
$P(X=1)\times P(Y=10)\ne P(X=1\cap Y=10)$  
So, they are dependent.
## (1.e)
(这里缺过程)
|  $Y$   |          10          |         11         |         12         |         13          |         14          |        15        |         16          |         17          |         18         |        19         |
| :----: | :------------------: | :----------------: | :----------------: | :-----------------: | :-----------------: | :--------------: | :-----------------: | :-----------------: | :----------------: | :---------------: |
| $P(Y)$ | $\frac{8889}{25600}$ | $\frac{623}{3200}$ | $\frac{767}{6400}$ | $\frac{911}{12800}$ | $\frac{211}{51200}$ | $\frac{53}{800}$ | $\frac{101}{16000}$ | $\frac{149}{32000}$ | $\frac{197}{6400}$ | $\frac{49}{2560}$ |


$$
E[Y]=\sum{Y·P(Y)}= 
$$

We have
| $Y^2$  |         100          |        121         |        144         |         169         |         196         |       225        |         256         |         289         |        324         |        361        |
| :----: | :------------------: | :----------------: | :----------------: | :-----------------: | :-----------------: | :--------------: | :-----------------: | :-----------------: | :----------------: | :---------------: |
| $P(Y)$ | $\frac{8889}{25600}$ | $\frac{623}{3200}$ | $\frac{767}{6400}$ | $\frac{911}{12800}$ | $\frac{211}{51200}$ | $\frac{53}{800}$ | $\frac{101}{16000}$ | $\frac{149}{32000}$ | $\frac{197}{6400}$ | $\frac{49}{2560}$ |

$$
\sigma(Y) = \sqrt{E[Y^2]-(E[Y])^2}=
$$

## (1.f)
X can be 1,2,3,4,5,6,7,8,9,10  
(计算过程)
|  $X$   |       1       |       2       |       3       |        4        |       5        |       6        |        7        |        8        |        9        |       10        |
| :----: | :-----------: | :-----------: | :-----------: | :-------------: | :------------: | :------------: | :-------------: | :-------------: | :-------------: | :-------------: |
| $P(X)$ | $\frac{1}{5}$ | $\frac{1}{4}$ | $\frac{1}{5}$ | $\frac{11}{80}$ | $\frac{7}{80}$ | $\frac{7}{64}$ | $\frac{1}{128}$ | $\frac{1}{256}$ | $\frac{1}{512}$ | $\frac{1}{512}$ |
$$
E[X]=\sum{X·P(X)}= 
$$

|  Y,X  |     1     |        2        |        3        |        4         |        5         |        6        |        7        |        8         |        9         |        10        |
| :---: | :-------: | :-------------: | :-------------: | :--------------: | :--------------: | :-------------: | :-------------: | :--------------: | :--------------: | :--------------: |
|  10   | $\frac15$ | $\frac{9}{100}$ |                 |                  |                  |                 |                 |                  |                  | $\frac{1}{1024}$ |
|  11   |           |  $\frac1{10}$   | $\frac{9}{100}$ |                  |                  |                 | $\frac{3}{640}$ |                  |                  |                  |
|  12   |           |                 |  $\frac1{20}$   | $\frac{27}{400}$ |                  |                 |                 | $\frac{3}{1280}$ |                  |                  |
|  13   |           |                 |                 |   $\frac1{40}$   | $\frac{27}{400}$ |                 |                 |                  | $\frac{3}{2560}$ |                  |  |
|  14   |           |                 |                 |                  |   $\frac1{80}$   | $\frac{9}{320}$ |                 |                  |                  | $\frac{3}{5120}$ |  |
|  15   |           | $\frac{3}{50}$  |                 |                  |                  | $\frac{1}{160}$ |                 |                  |                  |                  |  |
|  16   |           |                 | $\frac{3}{50}$  |                  |                  |                 | $\frac{1}{320}$ |                  |                  |                  |  |
|  17   |           |                 |                 | $\frac{9}{200}$  |                  |                 |                 | $\frac{1}{640}$  |                  |                  |  |
|  18   |           |                 |                 |                  | $\frac{3}{100}$  |                 |                 |                  | $\frac{1}{1280}$ |                  |  |
|  19   |           |                 |                 |                  |                  | $\frac{3}{160}$ |                 |                  |                  | $\frac{1}{2560}$ |  |

$$
E(X,Y)=\sum(XY)*P(XY)=\\Cov(X,Y)=E(X,Y)-E(X)E(Y)
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
Also note that for any $(i,j),1\le i, j \le n$, we have
$F_iF_j=\emptyset$,  
Then for any event E, $(E\cap F_i)(E\cap F_j)=\emptyset$ (i.e. they are disjoint)  
By the distributive law, $E\cap (\bigcup_{i=1}^n F_i)=\bigcup_{i=1}^n (F_i\cap E)$

$$
P(E)=P\bigg(\bigcup_i^n (E \cap F_i)\bigg)=\sum_{i}^n P(E \cap F_i)=\sum_{i}^n P(E | F_i) P(F_i).
$$

## (2.b)
Let $O$ denote the event that the sample student is outstanding, and $A, B, C, D$ denote that the student come from school A, B, C, D respectively.  
Then $S=A\cup B\cup C\cup D$, it can be easily derived that:   
$$
P(A)=\frac {3} {10},P(B)=\frac {1} {5},P(C)=\frac {1} {4},P(D)=\frac {1} {4}
$$
By the Law of total Probabiliy,
$$
\begin{aligned}
P(O)&=P(O\cap A)+P(O\cap B)+P(O\cap C)+P(O\cap D)
\\&=P(O|A)P(A)+ P(O|B)P(B)+P(O|C)P(C)+P(O|D)P(D)
\\&=\frac{187}{2000}   
\\&=0.0935
\end{aligned}

$$

## (2.c)
We already have $P(O)=\frac{187}{2000}$   
By the Baye's Theroem,  
$$
P(A|O)=\frac{P(O|A)P(A)}{P(O)} =\frac {30}{187}\approx 0.160

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
Using Chebyshev's Inequality, we can derive
$$
P(|X-65| \ge 10) \le \frac{\sigma ^2}{\epsilon ^2}=\frac14
$$
Since $\int_0^\infty  P(X) dX = 1$,  
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
\frac{\bar X - \mu_{\bar X}}{\frac{\sigma_{\bar X}}{n}} approximately\space follows N(0,1)
$$
If $P(60 \le \bar X \le 70)\ge 0.8$,
Then we have equation
$$
{\frac{70-\mu_{\bar X}}{\frac{\sigma_{\bar X}}{n}} \ge Y} \tag{1}
$$
Where $P(X\ge Y) =0.90$ for a standard normal distribution.  
It can be obtained by checking the table that $Y=1.28$,  
By $(1)$, we can get $N \ge 1.6384$.    

**Thus at least $2$ people whould have to be sampled to satisfy the requirement.**