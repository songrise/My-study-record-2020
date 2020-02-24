# <div align = middle> Formula Editing </div>
[来源](https://www.jianshu.com/p/25f0139637b7)

  行内公式是在公式代码块的基础上前面加上$ ，后面加上$ 组成的，而行间公式则是在公式代码块前后使用$$ 和$$ 。  
****

例如
```
    $ \Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,. $

    $$\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.$$
```
效果：  

$` \Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,. `$
$$\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.$$
***
## 希腊字母
$\sigma \pi$
(详见网站)
****
## 上下标
上标和下标分别使用^ 与_   
## $x_i^2$
默认情况下，上、下标符号仅仅对下一个组起作用。一个组即单个字符或者使用{..} 包裹起来的内容。
例如  
### $x^{10}$   $x^10$

****
# 求和与积分
  \sum 用来表示求和符号，其下标表示求和下限，上标表示上限。如: 
$$\sum_{r=1}^n$$
连乘：
$$\prod {a+b}$$
$$
\prod _{i=1}^k
$$
****
# 分式与根式
## 分式
第一种 $\frac a b$   
$\frac {ax+by}{dz}$  
连分数 
$$x=a_0 + \frac {1^2}{a_1 + \frac {2^2}{a_2 + \frac {3^2}{a_3 + \frac {4^2}{a_4 + ...}}}}$$

## 根式
$\sqrt[4]{\frac xy}$  
$\sqrt {a+b}$
****
# 多行表达式
 定义函数的时候经常需要分情况给出表达式，使用\begin{cases}…\end{cases} 。
其中：  

- 使用\\ 来分类，  
- 使用& 指示需要对齐的位置，   
- 使用\ +空格表示空格。
$$
f(n)
\begin{cases}
\cfrac n2, &if\ n\ is\ even\\
3n + 1, &if\  n\ is\ odd
\end{cases}
$$

$$
L(Y,f(X)) =
\begin{cases}
0, & \text{Y = f(X)}  \\
1, & \text{Y $\neq$ f(X)}
\end{cases}
$$

## 方程组
$$
\left \{ 
\begin{array}{c}
a_1x+b_1y+c_1z=d_1 \\ 
a_2x+b_2y+c_2z=d_2 \\ 
a_3x+b_3y+c_3z=d_3
\end{array}
\right.
$$
****
# 特殊函数与符号
见[来源](https://www.jianshu.com/p/25f0139637b7)
****
# 矩阵

使用\begin{matrix}…\end{matrix} 这样的形式来表示矩阵，在\begin 与\end 之间加入矩阵中的元素即可。矩阵的行之间使用\\ 分隔，列之间使用& 分隔，例如:
$$
\begin{matrix}
1 & x & x^2 \\
1 & y & y^2 \\
1 & z & z^2 \\
\end{matrix}
$$

如果要对矩阵加括号，可以像上文中提到的一样，使用\left 与\right 配合表示括号符号。也可以使用特殊的matrix 。即替换\begin{matrix}…\end{matrix} 中matrix 为pmatrix ，bmatrix ，Bmatrix ，vmatrix , Vmatrix 。

$\begin{pmatrix}1 & 2 \\ 3 & 4\\ \end{pmatrix}$、

$\begin{bmatrix}1 & 2 \\ 3 & 4\\ \end{bmatrix}$

$\begin{vmatrix}1 & 2 \\ 3 & 4\\ \end{vmatrix}$