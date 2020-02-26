# Quiz 1

let A be the event that a product has a certain defect,  then, $P(A) = \frac{1}{200}$.  

let $B$ be the event that a test is positive,   
then according to *the Law of Total Probability*, we have:
$$
\tag{1} P(B)=P(B\cap A)+P(B \cap A^c)
$$
The test can detect 90% real defective products, so $P(B|A) = \frac {9}{10}$   
It can also show positive for 5% non-defective. So, $P(B|A^c) =\frac 1 {20}$  
According to *Baye's formula*,
$$
P(A|B) = \frac {P(B|A)P(A)}{P(B)} \tag 2
$$
from (1),(2):
$$
\begin{aligned}
\\P(A|B)&=\frac {P(B|A)P(A)} {P(B|A)P(A)+P(B|A^c)P(A^c)}
\\&=\frac {P(B|A)P(A)} {P(B|A)P(A)+P(B|A^c)[1-P(A)]}
\\&= \frac {\frac 9{10}\times\frac 1{200}}{\frac{9}{10}\times \frac 1{200}+\frac 1 {20}\times \frac{199}{200}}
\\&=\frac {18} {217}
\\ &\approx 0.0829
\end{aligned}

$$