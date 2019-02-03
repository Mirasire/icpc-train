# 快速幂

> 断幺九就完事了

通常我们计算一个数字的阶乘，假设为a^n^的时候。

我们最简单的想法是$out = \underbrace{a*a*a....*a*a}_{\text{n}}$  。

用语言来描述就是

```c
int pord(int a,int n)
{
    int out = a; 
    while(n--) out = (out*a) % M;
    return out;
}
```

上述程序花费的是$O(n)$的时间复杂度，假设指数过大的话，时间花费也会变大。

细细分析，pord函数主要的时间花费在乘法上。所以如果要降低时间复杂度，首要是降低乘法的次数。

> 在写上面的函数的时候曾经写错过一种函数

```c
//wrong version
int pord(int a, int n)
{
    while(--n) a = (a*a) % M;
    return a;
}
```

仔细分析上面的程序有一个错误，就是循环次数的问题。

错误原因在于否认 a 的时事变化性，将 a 代换成 out = a 了。

**但是**  分析 该写发  发现的确可以降低乘法的次数，下面进行数学分析。

假设由于写在循环函数体内的函数为 a*=a 所以相当于每次对a进行平方操作。

我们做一个假设，第n次循环后的a为原来的$a^{2^n}$

- 当 n = 1 时， $out = a^2$
- 假设当 n = k 时，$out = a^{2^k}$
- 当 n = k + 1 时，$out = (a^{2^k})^2 = a^{{2^k}*{2}} = a^{2^{k+1}}$

所以证明完毕，假设 n 刚好为 $2^k$ 那么乘法的操作只要 k 次就好了。

这样我们的 时间复杂度 就从原来的 $O(n)$ 变化到了 $O(log_{2}{n})$

**但是即便如此** 还是不能运用于所有的指数乘法中，这十分不足，当n不是2的指数倍时候就无法使用了

> 顺带说一句如果n为2的指数倍，那么由$log_{a}{b} = \frac{log_{n}{b}}{log_{n}{a}}$公式，可以简单由 ${2}^k = n$ 得 $k = log_{2}{n} = \frac {log_{10}{n}}{log_{10}{2}}$   

那么怎么样才能让这个排序能够通用呢？假设我们在指数不满足的时候强行来使用这个方法

- 假设我们要求的pord(3,12)
- ${3}^{12} $ 在函数分割下得到的值为 ${3}^{8}$ 相比较于,我们所要求的  ${3}^{12}$  我们在指数方向损失了$3^4$
- 观察上面我们可以发现 $3^{12} = 3^{8}*3^{4}$ ，12不是2的指数倍，但是8和4却是
- 

由此有了个想法，是不是**所有**的**n**都能拆解为 **2的指数倍数 相加**呢？当然结论是**肯定可以**，早在计算机诞生之初 我们就知晓了这个问题的答案， 这也是为什么二进制能表示出所有正整数的原因。

那么基本思路有了，就是将$a^n$拆解为$a^{2^{k1}}*a^{2^{k2}}*a^{2^{k3}}*...*a^{2^{kn}}$其中 ${2}^{k1} + {2}^{k2} + {2}^{k3} +...+{2}^{kn} = n$

问题又出现了，如何高效的实现这个想法呢？

我们可以假设要求$3^{17}$，那么工作就是分解指数，指数分解如下
> 指数分解版本

$$
15=14+1=2*7+1=2*6+2+1=2*2*3+2+1=2*2*2+2*2+2+1 = 2^3+2^2+2+1
$$

>实际操作版本

$$
2^{15}=2^{14}*2=2^{2*7}*2=2^{2*6}*2^{2}*2=2^{2^{2}*3}*2^{2}*2=2^{2^{2}*2}*2^{2^{2}}*2^{2}*2 = 2^{2^{3}}*2^{2^{2}}*2^{2}*2
$$
```c
/*first try*/
int pord(int a,int n)
{
    int out = 1;
    while(n > 0)
    {
        if(n%2)
        {
            out = (out * a) % M; /*这一步是实际模拟指数操作*/
            n -= 1;/*得出额外的结论，这一步一定 为 最后一步操作*/
        }
        else
        {  
            a = (a * a) % M; /*注解*/
     		n /= 2;
        } 
    }
    return out;
}
```
> 注解：这一步就是靠我们上面的证明来求$a^{{2}^{k}}$,我们的方法是从后向前
>

 但是这个程序有一个**致命**的问题，当权变大时候，权的平方可能会**爆整形**，那么方向有了，现在的问题就是，解决**爆整形**的问题。后来发现是因为数据类型没有设置好只要将所有的int更换为long long 就解决问题了。

接下来是测时环节，以下是我用来测试时间的代码。

> 已经更换为long long 了

```c
#include <stdio.h>
#include <time.h>

#define M 1000000

long long int pord(long long int a,long long int n);

int main()
{
    long long int a,n,out;
    clock_t st,ed;
    scanf("%lld%lld",&a,&n);
    //test time
    st = clock();
    out = pord(a,n);
    ed = clock();
    //end test
    printf("pow(%lld,%lld) = %lld\n",a,n,out);
    printf("time : %lf\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}

/*
/*normal*/
long long int pord(long long int a,long long int n)
{
    long long int out = 1; 
    while(n--) out = (out*a) % M;
    return out;
}
*/

/*
/*quick pord*/
long long int pord(long long int a,long long int n
{
    long long int out = 1;
    while(n)
    {
        if(n%2)
        {
            out = (out * a) % M;
            n -= 1;
        }
        else
        {
            a = (a * a) % M;
     		n /= 2;
        }
    }
    return out;
}
*/
```

![test time](https://raw.githubusercontent.com/Mirasire/study-notes/master/pic/Quickpord.png)
 - 上面一行的是用normal版本进行计算
 - 下面一行是用quick pord版本进行计算

可以看出差距还是很明显的，但是有没有办法再次对已经推导得出的函数进行update呢？

方法还是有的，在观察quick pord后发现quick pord还可以更加简便

```c
/*quick pord plus(相比quick plus 权多做了次乘法)*/
long long int pord(long long int a,long long int n)
{
	long long out = 1;
	while(n)
    {
    	if(n%2) out = (out*a) % M;
    	a = (a * a) % M;
    	n /= 2;
    }
    return out;
}
```

至于什么可以取消else由以下推倒

- 由于n为正奇数 n/2 = (n-1)/2
  - n为正奇数 (n-1) 为偶数 
  - (n-1)/2 = ((n-1)+1)/2 = (n-1)/2 + 1/2 = (n-1)/2 
  - 1/2 = 0 为整数相除特性
- 由于指数操作分离之后，肯定可以乘2，不分离时候也要乘2

在不引入**位云算**前，得到的快速幂。