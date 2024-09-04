## $\lim\limits_{x \to 0}\frac{\cos x -e^{-\frac{x^2}{2}}}{x^4}$

$$
\begin{align*}
L' &= \lim\limits_{x \to 0}\frac{\cos x - e^{-\frac{x^2}{2}}}{x^4}\\
&= \lim\limits_{x \to 0}\frac{(-\sin x) - (-xe^{-\frac{x^2}{2}})}{4x^3}\\
&= \lim\limits_{x \to 0}\frac{\cos x - (-e^{-\frac{x^2}{2}}(1-x^2))}{12x^2}\\
&=\lim\limits_{x \to 0}\frac{e^{-\frac{x^2}{2}}(1-x^2) - \cos x}{12x^2}\\
&= \lim\limits_{x \to 0}\frac{-xe^{-\frac{x^2}{2}}(1-x^2) + e^{-\frac{x^2}{2}}(-2x) - \sin x}{24x}\\
&= \lim\limits_{x \to 0}\frac{-e^{-\frac{x^2}{2}}(2x^2-x^4) - \sin x}{24}\\
&= -\frac{1}{24}
\end{align*}
$$


$x^x=e^{x\ln x}$
## 指数的定义
对于任意正实数 $a$ 和实数 $x$，我们定义 $a^x = e^{x\ln a}$。

$x^x = e^{x\ln x}$

$e^{\ln x} = x$ 对任何正实数 $x$ 都成立。
$\ln(x^x) = x\ln x$ 是对数的一个性质。


## 验证
如果我们对 $e^{x\ln x}$ 取自然对数，我们得到：
$\ln(e^{x\ln x}) = x\ln x$
这与直接计算 $\ln(x^x)$ 的结果相同。

---  
$\arctan \frac{y}{x}=\ln \sqrt{x^2+y^2}$

$\lim\limits_{x \to 0}\frac{\tan \sin x -x \cos x}{e^x+\ln(1-x)-1}$

### 柯西不等式 (Cauchy Inequality)
对于任意的两个向量 $\mathbf{a} = (a_1, a_2, \dots, a_n)$ 和 $\mathbf{b} = (b_1, b_2, \dots, b_n)$，柯西不等式（或柯西-施瓦兹不等式）表示为：

$$
\left( \sum_{i=1}^n a_i b_i \right)^2 \leq \left( \sum_{i=1}^n a_i^2 \right) \left( \sum_{i=1}^n b_i^2 \right)
$$

当且仅当 $\mathbf{a}$ 和 $\mathbf{b}$ 共线时，等号成立。

---

### 常用定理和不等式

#### 1. **均值不等式 (AM-GM Inequality)**
对于非负数 $a_1, a_2, \dots, a_n$，均值不等式表示为：

$$
\frac{a_1 + a_2 + \dots + a_n}{n} \geq \sqrt[n]{a_1 \cdot a_2 \cdot \dots \cdot a_n}
$$

当且仅当 $a_1 = a_2 = \dots = a_n$ 时，等号成立。

#### 2. **拉格朗日中值定理 (Lagrange Mean Value Theorem)**
如果函数 $f(x)$ 在闭区间 \([a, b]\) 上连续，并且在开区间 \((a, b)\) 上可导，则存在 $c \in (a, b)$，使得：

$$
f'(c) = \frac{f(b) - f(a)}{b - a}
$$

#### 3. **罗尔定理 (Rolle's Theorem)**
如果函数 $f(x)$ 在闭区间 \([a, b]\) 上连续，在开区间 \((a, b)\) 上可导，并且 $f(a) = f(b)$，则存在 $c \in (a, b)$，使得：

$$
f'(c) = 0
$$

#### 4. **泰勒定理 (Taylor's Theorem)**
设函数 $f(x)$ 在 $x = a$ 处可导到 $n+1$ 阶，则在 $x$ 附近可以表示为：

$$
f(x) = f(a) + f'(a)(x-a) + \frac{f''(a)}{2!}(x-a)^2 + \dots + \frac{f^{(n)}(a)}{n!}(x-a)^n + R_n(x)
$$

其中，$R_n(x)$ 是剩余项。

#### 5. **极值定理 (Extreme Value Theorem)**
如果函数 $f(x)$ 在闭区间 \([a, b]\) 上连续，那么 $f(x)$ 在该区间上至少存在一个最大值和一个最小值。

#### 6. **积分中值定理 (Mean Value Theorem for Integrals)**
如果函数 $f(x)$ 在闭区间 \([a, b]\) 上连续，则存在 $c \in [a, b]$，使得：

$$
\int_a^b f(x) \, dx = f(c)(b - a)
$$

#### 7. **牛顿-莱布尼茨公式 (Newton-Leibniz Formula)**
如果函数 $F(x)$ 是 $f(x)$ 的一个原函数，即 $F'(x) = f(x)$，则有：

$$
\int_a^b f(x) \, dx = F(b) - F(a)
$$


$$
\int x \sin x dx
$$
