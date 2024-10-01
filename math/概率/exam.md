# 第一章

#### 条件概率
$\quad \Large P(A+B|\overline{A})=\frac{P(A\cup B)\cap \overline{A}}{P(\overline{A})}$

#### 重要的题目1

> 设 $X,Y$ 为随机变量，且 $P\{X\geqslant 0\}=\frac{1}{2},P\{Y\geqslant 0\}=\frac{3}{5},P\{X\geqslant 0,Y\geqslant 0\}=\frac{1}{4}$ ，则   
> $\qquad (1)P\{\min(X,Y)<0\} =\underline{\qquad}$  
> $\qquad (2)P\{\max(X,Y)\geqslant 0\} =\underline{\qquad}$  

**解:**
1. 令 $C=\min \{X,Y\}<0$ , 则 $\overline{C}=\min \{X,Y\}\geqslant 0$  
   $P\{\min(X,Y)<0\}=P(C)=1-P(\overline{C})$  
   $=1-P\{\min(X,Y)\geqslant 0\}$  
   $=1-P\{X\geqslant 0\cap Y\geqslant 0\}$  
   $=1-P\{X\geqslant 0,Y\geqslant 0\}$   
   $\large=1-\frac{1}{4}=\frac{3}{4}$
2. 令 $D=\max \{X,Y\}\geqslant 0$  
   $P\{\max(X,y)\geqslant 0\}=P(D)=1-P(\overline{D})=1-P\{\max(X,Y)< 0\}$  
   $=1-P\{X<0,Y<0\}$    
   $=1-P(\overline{A}  \  \overline{B})=1-P\{\overline{A\cup B}\}=1-(1-P(A\cup B))$  
   $=P(A\cup B)=P(A)+P(B)-P(AB)$    
   $=P\{X\geqslant 0\}+P\{Y\geqslant 0\}-P\{X\geqslant 0,Y\geqslant 0\}$  
   $\large=\frac{1}{2}+\frac{3}{5}-\frac{1}{4}=\frac{17}{20}$



#### n次独立重复实验

[n次独立重复实验](a7.md#n次独立重复实验) 

