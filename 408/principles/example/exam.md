# 第一章 计算机系统概述 
### 指令地址
![alt text](../../../images/408-pr-exam-image.png)
### 存储体容量
![alt text](../../../images/408-pr-exam-image-1.png)
### CPU执行时间
![alt text](../../../images/408-pr-exam-image-2.png)
![alt text](../../../images/408-pr-exam-image-3.png)
### MIPS计算
![alt text](../../../images/408-pr-exam-image-4.png)
### 程序运行速度计算1
![alt text](../../../images/408-pr-exam-image-5.png)

### 程序运行速度计算2
![alt text](../../../images/408-pr-exam-image-6.png)
### 程序运行速度计算3
![alt text](../../../images/408-pr-exam-image-7.png)

--- 
# 第二章 数据的表示和运算

### 进制转换
![alt text](../../../images/408-pr-exam-image-8.png)
![picture 5](../../../images/83ec6d0fac9415351bbb53700e5a38d86b43964a722eeff41faf2d26ce6fa4b2.png)  

### 运算结果溢出
![picture 4](../../../images/eab15c9be9dfc2435c22ae1b9f7926292d50564a235ffdbad6e1502441b59698.png)  
### 最小补码
![图 6](../../../images/6ef8edb970c0ed740369b2e78de262720ba26465d0b3f2d7ad0414f998619863.png)  

### 最大值
![图 7](../../../images/7f3b56967d274abf7bf4f82d54289b80c29d55f554c08108428d6e88c6df84a1.png)  

<!-- ### 浮点数表示范围
![图 8](../../../images/a92d3d7536862e286b1ec99fea277deb9b96cfc6f0074f7bf07a96ae5e0682e5.png)   -->

### 浮点数规格化
![图 9](../../../images/ed3a36707849e242447638b8e51ea58fad7459e1c65875d3e8739a87affa8ee4.png)  
![图 10](../../../images/299b301e149ee5abd320536ab710a68a5907dab1a2e69a155aae78582382bea0.png)  
![图 11](../../../images/718db4abc18e65ec809329900730e5aece43786cd509bc69e6ec3168e0ca86c1.png)  

### IEEE754单精度32位浮点数与真值转换
![图 12](../../../images/a2ccc605c4d51580532e29e3ce44f7420b440e1e7dfbd1718079e37b5d64c025.png)  
![图 13](../../../images/61965aa26f474c9b1f6f4838dde90523fcac2cc9e53e9a5ca2350bdec944f28f.png)  
![图 14](../../../images/859b7ad49ae8fe9259de953305b54c9cd81f4b6b083cde015e0b9accd44c9662.png)  



--- 
# 第三章 存储器层次结构
### 逻辑位移的应用
![图 15](../../../images/d92d0069c92eca7203d6eb25561b43a32902f8dcce283348d5bfc6ff2a4ac110.png)  
![图 16](../../../images/f4a5cdcf09c6595f59e5723cabdcfb4cb6eab7141657526648e7ee476ab56b91.png)  
![图 17](../../../images/032d48ce16fe1380554369f17055e3b1df8ee4c1d92c31ef8308023cf1c771da.png)  

![图 18](../../../images/edd71507752d84a8cd4d303592a3bcb52e98adab186abad549abc6989b725bf6.png)  

### 逻辑位移的应用2
![图 19](../../../images/c3bc30c0c40a0785e9a3eb8ec2018d89d651289a6125f084fd559abbed3ce3a5.png)  

```c
/*定义相关位的为掩码*/
#define b0_mask (1<<0)
#define b2_mask (1<<2)
#define b3_mask (1<<3)
#define b5_mask (1<<5)
/*将b0和b5的内容清0而不影响其他各位*/
regData &=~(b0_mask | b5_mask);
/*将b2和b3的内容置1而不影响其他各位*/
regData |= (b2_mask | b3_mask);
```
### 负数算术位移
![图 20](../../../images/da36ae3f34612a624963bf12182a09c694e82087097687268e63d5e5073b38ae.png)  


### 补码加减法运算

![图 13](../../../images/73da391e7d3127ddc196a4949e0231ae568dc37404617f7f739e620f133cc314.png) 
![图 14](../../../images/e8ea67aceed85fccb22d91ee0b190110bf49b7853fabdc3949fa84a4424a41b5.png)  
![图 15](../../../images/340173496637cf363d3f2b01d75800baba6a0aab6d36ba65de00ae6e2d38e8ad.png)  

### 综合题
![图 22](../../../images/fd5da75f024deb7918283a9ddde152d8df2a11bc6451073d247df1edf1e6b0d4.png)  

### 大题
![图 23](../../../images/070ee721c497b24f866ea1ccbfcfce45c9693771af156dfa9c43ea90e13722ad.png)  
![图 24](../../../images/cb2a70eab250c5d37ba6df2d0cf3f861b3dd2efca3dd6f85766895724410554d.png)  
![图 25](../../../images/31925c25ef255e1cb249c6ccfb2a01d0ddea76fa6b0f796d7fc3f6ae126bcfae.png)  
![图 26](../../../images/de66584c3de5fa4fb0b9c097b81c084775f2500309e6b383f18aa1d7e998f294.png)  

### 补码表示范围
![图 27](../../../images/500675c1a79ddbb08a77af1a893bf88ffcf334e7212eefa9565c1dec5b578842.png)  
![图 28](../../../images/5ab2bd2e713158a71fa6f7980d994d76a5b125d6e9ef6304e7b746fa854cea55.png)  
> [! danger] 8位补码所表示的真值x的范围：-128≤x≤127 </p>  16位补码所表示的真值x的范围：-32768≤x≤32767

<!-- ### 原码除法运算（不恢复余数法） -->



--- 
# 第四章 指令系统
### 主存中数据的存放
![图 29](../../../images/d06a0f708c6ca5c741cecf077873c99a6c61bf6e7d5c3e85a1cca4b8f673840d.png)  
![图 30](../../../images/69c9b5908aa1574ca7af2da7dfb77251464d4c13743b3d78b41e8cfb322e885f.png)  

### DRAM芯片引脚
![图 31](../../../images/f6ff2b2154cfbce15b4dee65c5dd2abd9c06a4d1c3f28d4475a6052a5256526f.png)  


--- 
# 第五章 中央处理器


--- 
# 第六章 总线



--- 
# 第七章 输入\输出系统





--- 