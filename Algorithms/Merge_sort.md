# 归并排序(Megre sort)

> You make the failure complete when you stop trying

#### 前言
Q:	 如何把两个已经排好的<font color='black' size=6>数组</font>合并成一个已经排好的<font color='black' size=6>大数组</font>呢？

> 其实只要从两个数组最小的开始相互比较把最小的放入大数组中（依序）当一个全放入的时候直接将剩余的用剩余的林另外一个数组全部填满就好了
> 终极目标实现Merge(int *number,int p,int q,int r)

**程序思路**

###### 前期准备

>当为三个数组的时候
1. 假设有两个排好序的数组A[n],B[m]，另外的新数组为C[m+n]
2. 开始比较  *(A+ia)  &  *(B+ib) //数组名就是首地址，直接用数组名就好了
3. 如果ia<n && ib <m 
1. 如果*(A+ia)  <=  *(B+ib)   ->   *(C+i++)  =   *(pA+ia++)
2. 如果*(A+ia)  <  *(B+ib)   - >  *(C+i++)  =  *(pB+ib++)   //直接用else就好
4. i < m+n ~~wsl~~
7. 结束操作

**Code-when arry == 3**

```c
int ia=0,ib=0,i=0;
while(ia < n && ib < m)
{
    if(*(A+ia) <= *(B+ib))
        *(C+i++) = *(A+ia++);
    else
        *(C+i++) = *(B+ib++);
}
while(i < m+n)
{
    if(ia < n)
        *(C+i++) = *(A+ia++);
    else   
        *(C+i++) = *(B+ib++);
}
```
**Code -plus**
​    
```c
void Merge(int *number,int p,int q,int r)
{
​    int n1=p-q+1,n2=r-q;
​    int *B = &number[q];
​    int ia=0,ib=0,i=0;
​    int *A=(int *)malloc(sizeof(int)*n1);
​    for(int j=0; j<n1; j++)
​        *(A+j)=number[j];
​    while(ia < n1 && ib < n2)
​    {
​        if(*(A+ia) <= *(B+ib))
​            *(number+i++) = *(A+ia++);
​        else
​            *(number+i++) = *(B+ib++);
​    }
​    int end = n1+n2;
​    while(i < end)
​    {
​        if(ia < n1)
​            *(number+i++) = *(A+ia++);
​        else
​            *(number+i++) = *(B+ib++);
​    }
​    return;
}
```

#### 归并排序
>Tips : 归并可以递归来写
>~~懒得介绍了直接放一张归并排序的图片吧~~


![Mirasire_github/pic01](https://raw.githubusercontent.com/Mirasire/study-notes/master/pic/Merge_sort.png)


> 图来自百度

#### 思路

**1. 主要思想**

- 分治（详见前一篇说明）
- 递归的使用~~PS:虽然递归我也不是很会用,但是细推还是能理解的~~

**2. 程序思路**
### Solution1-自顶向下
>  假设我们写的外部调用归并的函数名为Merge_sort(number,p,r) 
>  **number** 就是我们需要排序的那个数组
>  **p**是排序数组的起始下标
>  **r**是排序数组的终止下标

1. 令  q = (p+r)/2
2. 调用Merge_sort(number,p,q)
3. 调用Merge_sort(number,q,r)
4. 调用外部函数Merge(number,p,q,r)	//就是上面那个排序程序
   
```c
void Merge_sort(int number,int p,int r)
{
	if(p >= r)
		return;
	else
	{
        int q = (p+r)/2;
        Merge_sort(number,p,q);
        Merge_sort(number,q,r);
        Merge(number,p,q,r);
     }
    return;    
}
```

