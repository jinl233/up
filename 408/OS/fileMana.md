## 文件和文件系统

### 数据项、记录和文件
   
   
  文件、记录和数据项之间的层次关系
  1、数据项
  (1) 基本数据项
  (2) 组合数据项
  2、记录：是一组相关数据项的集合，用于描述一个对象在某方面的属性
  包含哪些数据项，取决于需要描述对象的哪个方面
  3、文件：在文件系统中是一个最大的数据单位
   有结构文件：由若干个相关记录组成
   无结构文件：被看成一个字符流
   文件属性：
  （1）文件类型
  （2）文件长度
  文件的当前长度，长度的单位可以是字节、字或块，也可能是最大允许的长度
  （3）文件的物理位置
  指示文件所在的设备及所在设备中地址的指针
  （4）文件的建立时间
  最后一次的修改时间

### 文件名和类型
  1、文件名和扩展名
  (1) 文件名
  (2) 扩展名：后缀名，指示文件类型
  2、文件类型
  1) 按用途分类
   (1) 系统文件
   (2) 用户文件
   (3) 库文件
  2) 按文件中数据的形式分类
   (1) 源文件
   (2) 目标文件
   (3) 可执行文件
  3) 按存取控制属性分类
   (1) 只执行文件
   (2) 只读文件
   (3) 读写文件
  4) 按组织形式和处理方式分类
   (1) 普通文件
   (2) 目录文件
   (3) 特殊文件
   

### 文件系统的层次结构
三个层次：最底层：对象及其属性
  中间层：对对象进行操纵和管理的软件集合
  最高层：文件系统提供给用户的接口
  
   1、对象及其属性
  (1) 文件：管理的直接对象
  (2) 目录：方便用户对文件的存取和检索（目录项：文件名、文件属性、物理地址（或指针））
  (3) 磁盘(磁带)存储空间 ：提高外存利用率，提高对文件的存取速度 
   2、对对象操纵和管理的软件集合
  ① 对文件存储空间的管理
  ② 对文件目录的管理
  ③ 用于将文件的逻辑地址转换为物理地址的机制
  ④ 对文件读和写的管理
  ⑤ 对文件的共享与保护等功能
  与文件管理有关的软件的四个层次：
  1、I/O控制层次（设备驱动程序层）
  2、基本文件系统层：内存和磁盘之间的数据块的交换
  3、基本I/O管理程序：与磁盘I/O有关
  4、逻辑文件系统：文件相关
   3、文件系统的接口
  (1) 命令接口：用户与文件系统直接交互的接口（可通过键盘终端键入命令）
  (2) 程序接口：用户程序与文件系统的接口（通过系统调用）
  

### 文件操作
  1、最基本的文件操作
  (1) 创建文件：分配空间->建立目录项->记录信息
  (2) 删除文件：找到目录项->回收存储空间
  (3) 读文件：文件名->目录->位置->指针读
  (4) 写文件：文件名->目录->位置->指针写
  (5) 设置文件的读/写位置
  2、文件的“打开”和“关闭”操作
  打开：在用户和指定文件之间建立起一个连接
   系统将指名文件的属性->从外存拷贝到内存打开文件表的一个表目->编号返回给用户
  关闭：断开连接，从  打开文件表 删除
  3、其它文件操作
  1、对文件属性的操作
  2、有关目录的操作


## 文件的逻辑结构
  两种形式的文件结构
   1、文件的逻辑结构
   2、文件的物理结构


### 文件逻辑结构的类型
  基本要求：
   1、有助于提高对文件的检索速度
   2、方便对文件进行修改
   3、降低文件存放在外存上的存储费用
   1、按文件是否有结构分类
  1）、有结构文件（信息管理系统和数据库系统）
  (1) 定长记录：文件中所有记录长度都相同，文件的长度用记录数目表示
  (2) 变长记录
  2）、无结构文件（系统运行的源程序、可执行文件、库函数）流式文件
  长度以字节为
   2、按文件的组织结构分类




















