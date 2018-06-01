# 3.2 标准记号与常用函数

## 单调性

**单调性**
 若m<=n蕴涵f(m)<=f(n)，则函数f(n)是**单调递增**的。类似地，若m<=n蕴涵f(m)>=f(n)，则函数f(n)是**单调递减**的。若m<n蕴涵f(m)<f(n)，则函数f(n)是**严格递增**的。若m<n蕴涵f(m)>f(n)，则函数f(n)是**严格递减**的。
 **向下取整与向上取整**
 对任意实数x，我们用

![img](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/取下界.png)

 表示小于或等于x的最大整数（读作“x的向下取整”），并用

![img](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上取整.png)

表示大于或等于x的最小整数（读作“x的向上取整”）。对所有实数x，

![向上向下取整性质](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上向下取整性质.png)

对任意整数n，

![img](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上向下取整相加.png)

对任意实数x>=0和整数a,b>0，

![向上取整性质](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上取整性质.png)

![向下取整性质](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向下取整性质.png) 

![向上取整性质1](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上取整性质1.png)

![向下取整性质1](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向下取整性质1.png)



向下取整函数f(x)=![取下界](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/取下界.png)是单调递增的，向上取整函数f(x)=![向上取整](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/向上取整.png)也是单调递增的。



模运算

 对任意整数a和任意正整数n，a mod n的值就是商a/n的**余数**：

![取整模运算](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/取整模运算.png)



结果有
 0<=a mod n<n    
 给定一个整数除以另一个整数的余数的良定义后，可以方便地引入表示余数相等的特殊记号。若(a mod n)=(b mod n)，则记a≡b(mod n)，并称模n时a**等价于**b。换句话说，若a与b除以n时具有相同的余数，则a≡b(mod n)。等价地，a≡b(mod n)当且仅当n是b-a的一个因子。若模n时a不等价于b，则记a!≡b(mod n)。 

 

多项式

 给定一个非负整数d，**n的d次多项式**为具有以下形式的一个函数p(n)：



$$ p(n) = \sum_{i = 0}^d a_in^i $$



 

其中常量a0, a1, ... , ad是多项式的**系数**且ad!=0。一个多项式为渐近正的当且仅当ad>0。对于一个d次渐近正的多项式p(n)，有p(n)=Θ(nd)。对任意实常量a>=0，函数na单调递增，对任意实常量a<=0，函数na单调递减。若对某个常量k，有f(n)=O(nk)，则称函数f(n)是**多项式有界(polynomially bounded)**的。
 **指数**
 对所有实数a>0、m和n，我们有以下恒等式：

$ a^0 = 1$

$ a^1= a $

$ a^{-1} = \frac 1 a$

$ (a^m)^n = a^{mn} $

$ ( a^m )^n = a^{mn} $

$ a^m a^n = a^ {m + n} $





 对所有n和a>=1，函数an关于n单调递增。方便时，我们假定00=1。 可以通过以下事实使多项式与指数的增长率互相关联。对所有使得a>1的实常量a和b，有

$$ \lim _{n \to \infty} = 0$$



 据此可得 $ n^b = o(a^n )$  因此，任意底大于1的指数函数比任意多项式函数增长得快。 使用e来表示自然对数函数的底2.718 28...，对所有实数x，我们有

$$ e^x  = 1 + x + \frac {x^2} {2!} + \frac {x^3} {3!} + ... = \sum _{i=0} ^\infty \frac {x^i} {i!}$$

其中“！”表示本节后面定义的阶乘函数。对所有实数x，我们有不等式
 $$ e^x >= 1+ x$$ 
 其中只有当x=0时等号才成立。当|x|<=1时，我们有近似估计

$$ 1 + x <= e^x <= 1 + x + x^2$$



 当x→0时，用1+x作为e^x的近似是相当好的：
 $$ e^x = 1 + x  + \Theta(x)$$

 （在这个等式中，渐近记号用来描述当x→0而不是x→∞时的极限行为）。对所有x，我们有：

$$ \lim _{n \to \infty} (1 + \frac x n)^n = e^x$$



 **对数** 

我们将使用下面的记号

$$ lg n = log_2 n$$ (binary logarithm)

$$ ln n = log_e n$$ (natural logarithm)

$$ lg^k n = (lg n)^k$$  (exponentiation)

$$ lg lg n = lg (lg n)$$ (composition)

分别为：以2为底的对数，自然对数，取幂，复合） 我们将采用的一个重要记号约定是*对数函数只适用于公式中的下一项*，所有lgn+k意指(lgn)+k而不是lg(n+k)。如果常量b>1，那么对n>0，函数logbn是严格递增的。 对所有实数a>0, b>0, c>0和n，有

$$ a = b ^{log_b a}$$

$$ log_c(ab) = log_c a + log_c b$$

$$ log_b {a^n} = n log_b a$$

$$ log_b a = \frac {log_c a} {log_c b}$$

 $$ log_b (\frac 1 a) = - log _b a$$

$$ log_b a =  \frac 1 {log_a b}$$

$$ a^ {log_b c} = c^{log_b a}$$

其中，在上面的每个等式中，对数的底不为1。
 根据等式(3.15)，对数的底从一个常量到另一个常量的更换仅使对数的值改变一个常量因子，所以当我们不关心这些常量因子时，例如在O记号中，我们经常使用记号“lgn”。计算机科学家发现2是对数的最自然的底，因为非常多的算法和数据结构涉及把一个问题分解成两个部分。
 当|x|<1时，ln(1+x)存在一种简单的级数展开：

$$ ln(1 + x) = x - \frac {x^2} 2 + \frac {x^3} 3 - \frac {x^4} 4 + \frac {x^5} 5 - ...$$

对x>-1，还有下面的不等式

$$ \frac x {1 + x} <= ln(1 + x) <= x$$

 其中仅对x=0等号成立。 若对某个常量k，f(n)=O(lg^k n)，则称函数f(n)是**多对数有界**的。在等式(3.10)中，通过用lgn代替n并用2^n代替a，可以使多项式与多对数的增长互相关联：

$$ \lim _ {n \to \infty} \frac {lg^b n} {(2^a)^{lgb} } = \lim_{n \to \infty} \frac {lg^b n} {n^a} $$

 根据这个极限，我们可以得到：对任意常量a>0， lg^b n=o(n^a) 因此，任意正的多项式函数都比任意多对数函数增长得快。 **阶乘** 记号n!（读作“n的阶乘”）定义为对整数n>=0，有

$$ n ! = 1, if n = 0 ; n*(n - 1), if n > 0$$ 

$$ n! =  n , 若 i = 0; f(f^{(i - 1)}(n))$$

因此，n!= 1×2×3...n。 阶乘函数的一个弱上界是n!<=n^n，因为在阶乘中，n项的每项最多为n。**斯特林(Stirling)近似公式**

$$ n! = \sqrt{2\pi n}(\frac n e) ^n (1 + \Theta(\frac 1 n))$$

给出了一个更紧确的上界和下界，其中e是自然对数的底。正如练习3.2-3要求证明

$$ n! = o(n^n)$$

$$ n! = w(2 ^ n)$$

$$ lg(n!) = \Theta(nlgn)$$

其中斯特林近似公式有助于证明等式(3.19)。对s所有n>=1，下面的等式也成立：

$$ n! = \sqrt{2\pi n}(\frac n e) ^n (e^{a_n })$$

其中

$$ \frac 1{12n + 1} < a_n < \frac 1 {12n}$$

 

 

 

 

 

 

 

 