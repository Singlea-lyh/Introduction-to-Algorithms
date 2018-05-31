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
 0<=a mod n<n     ---------(3.9)
 给定一个整数除以另一个整数的余数的良定义后，可以方便地引入表示余数相等的特殊记号。若(a mod n)=(b mod n)，则记a≡b(mod n)，并称模n时a**等价于**b。换句话说，若a与b除以n时具有相同的余数，则a≡b(mod n)。等价地，a≡b(mod n)当且仅当n是b-a的一个因子。若模n时a不等价于b，则记a!≡b(mod n)。 

 

多项式

 给定一个非负整数d，**n的d次多项式**为具有以下形式的一个函数p(n)：

![多项式](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/多项式.png)

 

其中常量a0, a1, ... , ad是多项式的**系数**且ad!=0。一个多项式为渐近正的当且仅当ad>0。对于一个d次渐近正的多项式p(n)，有p(n)=Θ(nd)。对任意实常量a>=0，函数na单调递增，对任意实常量a<=0，函数na单调递减。若对某个常量k，有f(n)=O(nk)，则称函数f(n)是**多项式有界(polynomially bounded)**的。
 **指数**
 对所有实数a>0、m和n，我们有以下恒等式：

![指数运算](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/指数运算.png)

 对所有n和a>=1，函数an关于n单调递增。方便时，我们假定00=1。 可以通过以下事实使多项式与指数的增长率互相关联。对所有使得a>1的实常量a和b，有

![指数极限运算](/home/singlea_lyh/GitHub/Introduction-to-Algorithms/Chapter-3/Chapter3-2/Picture/指数极限运算.png)

 据此可得 nb=o(an) 因此，任意底大于1的指数函数比任意多项式函数增长得快。 使用e来表示自然对数函数的底2.718 28...，对所有实数x，我们有

