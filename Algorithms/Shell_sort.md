#  希尔排序(Shell sort)
> If you want something you've never had, then you've got to do something you've never Done.
>  ~~说明~~
> ~~程序里面的增量序列为n/2即为一般增量序列~~

### 程序思路
- 确定递增数列
- 开始排序
## 1.  懵懂

####  图表演示

>对应的颜色进行(插入)排序

|   number[0]   |  number[1]    |  number[2]    |   number[3]   |  number[4]    |  number[5]    | Span |
|:---: | :----: | :----: | :----: | :----: | :----: | :----: |
| <font color=#FF3E96 size=4>2</font> | <font color=#436EEE size=4>1</font> | <font color=#9B30FF size=4>5</font> | <font color=#FF3E96 size=4>7</font>  | <font color=#436EEE size=4>0</font>  |    <font color=#9B30FF size=4>4</font>  | Span=3&sort |
|2|0|4|7|1|5|after_sort|
|<font color=#FFAE89 size=4>2</font>|<font color=#FFAE89 size=4>0</font>|<font color=#FFAE89 size=4>4</font>|<font color=#FFAE89 size=4>7</font>|<font color=#FFAE89 size=4>1</font>|<font color=#FFAE89 size=4>5</font>|span=1&sort|
|0|1|2|4|5|7|after_sort|

> > 可能上面不够清晰表达希尔排序的思想
> > show you the code

####  Code

**Code-1**

```c
for(int span=n/2; span>0; span/=2)
{
    for(int i=0; i<span; i++)
    {
        Insert_sort;
    }
}
```
##### **Meskill Detail code**

```c
for(int span=n/2; span>0; span/=2)
{
    int start = span,end = 2*span;
    while(start < span)
    {
        for(int i=start; i<n; i+=span)
        {
            int key=number[i],j=i-span;
            while(j>=0 && key < number[j])
            {
                number[j+span] = number[j];
                number[j] = key;
                j-=span
            }
        }
        start++;
    }
}
```
**Code-2**

> From  Data Structures and Algorithm Analysis in C

```c
void
shellsort（ElementType A[],int N）
{
    int i,j,Increment;
    ElementType Tmp;

    for(int Increment = N/2; Increment > 0; Increment /= 2)
        for(i = Increment; i<N; i++)
        {
            Tmp = A[i];
            for(j=i; j>= Increment; j-=Increment)
                if(Tmp < A[j-Increment])
                    A[j] = A[j-Increment];
                else
                    break;
            A[j] = Tmp;
        }
}
```
## 2. 焉知
#### **增量序列**


希尔排序的时间复杂度和它的增量序列有关，<font size=5>增量序列</font>为每次选择数字的<font size=5>间隔数</font>
希尔排序突破了时间复杂度为<a href="https://www.codecogs.com/eqnedit.php?latex=O\left&space;(&space;n^{2}&space;\right&space;)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O\left&space;(&space;n^{2}&space;\right&space;)" title="O\left ( n^{2} \right )" /></a>的限制，当然最坏的情况下时间复杂度依然为<a href="https://www.codecogs.com/eqnedit.php?latex=O\left&space;(&space;n^{2}&space;\right&space;)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?O\left&space;(&space;n^{2}&space;\right&space;)" title="O\left ( n^{2} \right )" /></a>





