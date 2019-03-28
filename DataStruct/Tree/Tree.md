# Tree

## BinarySearch

## introduction

## Define 

> 来自 MOOC 浙江大学《数据结构》

1. 有一个称为 **根(root)** 的特殊结点。一般用**r**来表示
2. 其余结点可分为m（m > 0）个互不相交的有限集 T1, T2, T3, ... ,Tm, 构成，其中每个集合本身就是一颗树

> N个结点 有 N-1条边

关于树的一些**术语**

![Tree01](https://raw.githubusercontent.com/Mirasire/study-notes/master/pic/Tree1.png)

1. 结点的度(Degree) : 结点的子树的个数
2. 树的度：树的所有结点中最大的度数
3. 叶节点：度(Degree)为 0 的节点
4. 父结点(Parent)：有子树的结点，是其子树的根结点的父结点
5. 子结点(Child)：若 A结点 是 B结点 的 (Parent)父结点，则称 B结点 是 A结点子结点；子结点 也称 孩子结点
6. 兄弟结点(Sibling)：具有同一 父结点(Parent) 的个个结点彼此是兄弟节点
7. 路径和路径长度：从结点 n1到nk 的路径为一个结点序列（n1,n2,n3,....,nk），其中ni 是 n(i+1) 的 父结点(Parent)。路径所包含边的个数为路径的长度。
8. 祖先结点(Ancestor)：父亲结点(Parent)&&父亲节点的父亲节点 &&.....&&root
9. 子孙结点(Descendant):某一结点的  子树中的所有结点 是 这个结点的子孙。 
10. 结点的层次(Level)：规定根结点 在1层，其它任一结点的层数是其父节点(Parent)的层数加1。
11. 树的深度(Depth)：树中所有的结点中的最大层次(Level)是这棵树的深度。

##### Child-Sibling 表示法

将 Child-Sibling 表示法 旋转 45度 就可以得到 二叉树