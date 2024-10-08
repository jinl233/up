## I/O系统的功能、模型和接口
### I/O系统的基本功能
##### 隐藏物理设备的细节
I/O设备在（接收和产生数据的速度，传输方向、粒度、数据的表示形式及可靠性）方面都有差异，所以需要隐藏物理设备现实细节，只提供少量的读/写命令。
##### 与设备的无关性
1）用户可以使用抽象的I/O命令，抽象的逻辑设备名
2）不需要重新编译整个操作系统 就增添新的设备驱动程序
##### 提高处理器和I/O设备的利用率
让处理机和I/O设备并行操作，提高利用率
---处理机能快速响应用户的I/O请求
---减少在每个I/O设备运行时处理机的干预时间
##### 对I/O设备进行控制
① 采用轮询的可编程I/O方式
 ② 采用中断的可编程I/O方式
③ 直接存储器访问方式
④ I/O通道方式
（根据不同设备的不同传输数据方式选择不同控制方式）
I/O软件应该屏蔽  I/O操作的组织和数据的传输  的差异，向高层软件提供统一的操作系统
##### 确保对设备的正确共享
(1) 独占设备：进程应互斥地访问这类设备，分配进程后独占直至用完释放。如：打印机、磁带机
(2) 共享设备：一段时间内允许多个进程同时访问的设备。如：磁盘，当有多个进程需对磁盘执行读、写操作时，可以交叉进行，不会影响到读、写的正确性
##### 错误处理
机械和电气部分，运行时容易出现错误和故障
临时性错误：通过重试操作来纠正
持久性错误：向上层报告
（重传多次仍有错，则磁盘故障）

### I/O系统的层次结构和模型

##### I/O软件的层次结构
（1）用户层 I/O软件（实现与用户交互的接口）：
直接调用该层所提供的、与I/O 操作有关的库函数对设备进行操作  分装指令，库函数
（2）设备独立性软件：
实现用户程序与设备驱动器的统一接口、设备命名、设备的保护以及设备的分配与释放等。并且为设备管理和数据传送提供必要的存储空间。 替CPU管理硬件
（3）设备驱动程序：
 具体实现系统对设备发出的指令，驱动I/O设备工作的驱动程序。告知操作系统如何使用硬件  说明书
（4）中断处理程序：
 保存被中断进程的 CPU环境，处理中断处理程序，处理完恢复现场，返回到被中断的进程  是基础，告知CPU成功与否、硬件变化 CPU立即响应
##### I/O系统中各个模块之间的层次视图
 1) I/O系统的上、下接口
 (1) I/O系统接口
 为文件系统、虚拟存储器系统以及用户进程提供对设备进行操作的抽象 I/O命令（相关库函数），方便使用
 (2) 软件/硬件(RW/HW)接口
 上面是中断处理程序和用于不同设备的设备驱动程序，下面是各种设备的控制器上、下两个接口之间是I/O系统
   
2) I/O系统的分层
 (1) 中断处理程序
 I/O系统的底层，直接与硬件进行交互
 保存环境->处理中断程序->恢复CPU环境->返回断点继续运行
 (2) 设备驱动程序
 进程和设备控制器之间的通信程序
 上层发来的抽象 I/O 请求转换为对 I/O 设备的具体命令和参数，并把它装入到设备控制器中的命令和参数寄存器中，或者相反
 (3) 设备独立性软件
 I/O 软件独立于具体使用的物理设备
 提高了I/O 系统的可适应性和可扩展性
 备独立性软件的内容包括设备命名、设备分配、数据缓冲和数据高速缓冲一类软件等

### I/O系统接口
##### 块设备接口
(1) 块设备：
指数据的存取和传输都是以数据块为单位的设备。 如磁盘：磁盘设备的 I/O常采用DMA方式
(2) 隐藏了磁盘的二维结构
   
扇区从0到n-1依次编号，n 是磁盘中的扇区总数。把磁盘的二维结构改变为一种线性序列。
(3) 将抽象命令映射为低层操作
块设备接口支持上层发来的对文件或设备的打开、读、写和关闭等抽象命令。  命令映射为设备能识别的较低层具体操作
##### 流设备接口
(1) 字符设备
以字符为单位存取和传输数据的设备。采用中断驱动方式
(2) get和put操作
为字符设备建立一个字符缓冲区（队列）
get 操作用于从字符缓冲区取得一个字符（到内存）
 put 操作则用于把一个新字符（从内存）输出到字符缓冲区中
 (3) in-control指令
该指令中包含了许多参数，每个参数表示一个与具体设备相关的特定功能。
##### 网络通信接口
同时操作系统提供相应的网络软件和网络通信接口，使计算机能通过网络与网络上的其它计算机进行通信或上网浏览。 


## I/O设备和设备控制器
I/O设备=执行I/O操作的机械部分+执行控制I/O的电子部件
执行控制I/O的电子部件则称为设备控制器或适配器(adapter)
控制卡、接口卡或网卡，还配置了I/O通道或I/O处理机

### I/O设备
##### I/O设备的类型
 1) 按使用特性分类
  ①存储设备：该类设备存取速度较内存慢，容量大，价格便宜。
 ②I/O 设备：它又可分为输入设备、输出设备和交互式设备。
2) 按传输速率分类
 ①低速设备：每秒钟几个字节至数百个字节。键盘、鼠标
 ②中速设备：每秒钟数千个字节至数十万个字节。打印机
 ③高速设备：数十万字节至千兆字节。磁盘、光盘
##### 设备与控制器之间的接口：I/O设备中含有与设备控制器间的接口，在该接口中有三种类型的信号，各对应一条信号线
(1) 数据信号线：
 设备和设备控制器之间传送数据信号
(2) 控制信号线：
 作为由设备控制器向 I/O 设备发送控制信号时的通路，规定了设备将要执行的操作，如读操作（设备向控制器传送数据）或写操作（从控制器接收数据），或执行磁头移动等操作。
发要求，命令，有什么命令
  (3) 状态信号线：
  用于传送指示设备当前状态的信号。
   

### 设备控制器
控制一个或多个 I/O 设备，以实现 I/O 设备和计算机之间的数据交换。是 CPU与I/O设备之间的接口，接收从CPU发来的命令，去控制I/O设备工作，使处理机能够从繁杂的设备控制事务中解脱出来。
##### 设备控制器的基本功能：
(1) 接收和识别命令：
 设备控制器能接收并识别处理机发来的多种命令。在控制器中具有相应的控制寄存器，用来存放接收的命令和参数，并对所接收的命令进行译码
  存在多个寄存器和命令译码器
(2) 数据交换
 设备控制器可实现 CPU与控制器之间、控制器与设备之间的数据交换
 故在控制器中设置数据寄存器
 (3) 标识和报告设备的状态
 控制器应记下设备的状态供 CPU 了解
 故在控制器中设置状态寄存器
(4) 地址识别
 就像内存中的每一个单元都有一个地址一样，系统中的每一个设备也都有一个地址。设备控制器必须能够识别其所控制的每个设备的地址
 故在控制器中设置地址译码器
(5) 数据缓冲区
 由于I/O 设备的速率较低，而 CPU 和内存的速率却很高，故在控制器中必须设置一缓冲区。
 输入输出时使数据传输速度与相应设备匹配
(6) 差错控制 
 将差错检测码置位，报告CPU，本次数据作废并重新传送数据
##### 设备控制器的组成
  (1) 设备控制器与处理机的接口
  三类信号线∶数据线、地址线和控制线
 数据线与两类寄存器相连接：
 ①数据寄存器
 ②控制/状态寄存器
  (2) 设备控制器与设备的接口
  (3) I/O逻辑
   用于实现对设备的控制
  CPU要启动一个设备时：
 1、启动命令发送给控制器
 2、通过地址线把地址发送给控制器
   由控制器的 I/O 逻辑对收到的地址进行译码，再根据所译出的命令对所选设备进行控制。
  

### I/O通道
##### I/O通道设备的引入
  CPU向通道发送I/O指令->取出要执行的通道程序->执行->完成规定的I/O任务->向CPU发中断信号
  I/O通道是一种特殊的处理机
  与一般的处理机不同：
  指令类型单一：通道硬件简单，命令只与I/O操作有关
  没有自己的内存：与CPU共享内存
##### 通道类型
  1) 字节多路通道 -低速设备/流设备
  
  含有许多非分配型子通道
  每个子通道连接一台I/O设备，并控制该设备的I/O操作。这些子通道按时间片轮转方式共享主通道
  控制器A传送A1A2A3…
  控制器B传送B1B2B3…
  主通道送往主机：A1B1A2B2A3B3…
  
  2) 数组选择通道 -高速设备/块设备
  以块为单位成批传送数据
  只含有一个分配型子通道，在一段时间内只能执行一道通道程序
  设备占用通道后一直独占，无数据传送时不允许其它设备使用
  3) 数组多路通道 -分时/块设备
  多个非分配型子通道
##### 瓶颈问题
  
  一个设备链接多个控制器，一个控制器链接多个通道
  解决瓶颈问题且增加可靠性

## 中断机构和中断处理程序：中断处理程序是整个I/O系统的基础
### 中断简介
##### 中断和陷入主要区别是信号的来源
  1) 中断
  外部设备引起的中断，称外中断
  2) 陷入
  由 CPU 内部事件所引起的中断
##### 中断向量表和中断优先级
  1) 中断向量表
  中断请求->根据中断号查找中断向量表->获得入口地址->转入中断处理程序执行
  2) 中断优先级
  规定不同的优先级处理
##### 对中断源的处理方式
  
  1) 屏蔽(禁止)中断
  正在处理一个中断时屏蔽新的中断请求，直至处理完毕
  2) 嵌套中断
  1->在有不同优先级时按照优先级处理
  2->高优先级的中断请求可抢占处理机

### 中断处理程序
 
 （1）测定是否有未响应的中断信号
   设备完成字符（字/数据块）的输入（输出）->向处理器发送中断请求信号->程序完成当前指令->测试是否有未响应的中断信号->执行或停止
 （2）保护被中断进程的CPU环境
  
 （3）转入相应的设备处理程序
  测试中断源->确定I/O设备->设备取消中断请求信号->将相应的设备中断处理程序入口地址装入程序计数器
 处理机运行时自动转向中断处理程序
 （4）中断处理
  正常完成中断
 根据不同程序不同设备作出不同修改、放入、指向
  异常结束中断
 根据异常原因做相应处理
 （5）恢复 CPU的现场并退出中断
 
## 设备驱动程序
：I/O系统的高层与设备控制器之间的通信程序
 接收上层软件的抽象I/O要求（read/write）->转换为具体要求->发送给设备控制器->启动设备执行
### 设备驱动程序概述
##### 设备驱动程序的功能
  (1) 接收由与设备无关的软件发来的命令和参数
 将命令中的抽象要求转换为与设备相关的低层操作序列
  (2) 检查用户I/O请求的合法性
 了解I/O设备的工作状态
 传递与I/O设备操作有关的参数
 设置设备的工作方式
  (3) 发出I/O命令
 如果设备空闲，便立即启动I/O设备，完成指定的I/O操作
 如果设备忙碌，则将请求者的请求块挂在设备队列上等待
  (4) 及时响应由设备控制器发来的中断请求
 根据中断类型调用相应的中断处理程序进行处理
##### 设备驱动程序的特点
  (1) 实现与设备无关的软件和设备控制器之间通信和转换的程序
  (2) 驱动程序与设备控制器以及I/O设备的硬件特性紧密相关
 不同类型的设备配置不同驱动程序
 相同的多个终端设置一个终端驱动程序
  (3) 驱动程序与I/O设备所采用的I/O控制方式紧密相关
 常用的I/O控制方式是中断驱动和DMA方式。
  (4) 驱动程序与硬件紧密相关，一部分用汇编语言书写
 目前有很多驱动程序的基本部分已经固化在ROM中
  (5) 驱动程序应允许可重入
 一个正在运行的驱动程序常会在一次调用完成前被再次调用
##### 设备处理方式

### 对I/O设备的控制方式
  
##### 使用轮询的可编程I/O方式
  处理机向控制器发出I/O指令->启动输入设备输入数据->状态寄存器中的忙/闲标志busy置为1->不断地循环测试busy(称为轮询)
  
   busy=1，表示输入机尚未输完一个字(符),继续轮询
   busy=0，表明输入机已将输入数据送入控制器的数据寄存器中->处理机将数据寄存器中的数据取出->送入内存指定单元
  结束后启动读取下一个数据，busy=1
##### 使用中断的可编程I/O方式
  在I/O设备输入每个数据时，CPU和I/O设备并行工作
  在输入完一个数据时，CPU花费极短的时间做中断处理
  提高了资源利用率和吞吐量
##### 直接存储器访问方式
  1) 接存储器访问方式的引入
   
   特点：
 (1) 数据传输的基本单位是数据块
 即：在CPU与I/O设备之间，每次传送至少一个数据块
 (2) 所传送的数据是从设备直接送入（出）内存的
 (3) 仅在传送一个或多个数据块的开始和结束时，需要CPU干预
   进一步提高了CPU与I/O设备的并行操作程度
  2) DMA控制器的组成：
 主机与DMA控制器的接口
 DMA控制器与块设备的接口
 I/O控制逻辑
   
 
 1·命令/状态寄存器CR
 2·内存地址寄存器MAR
 3·数据寄存器DR
 4·数据计数器DC4
  3) DMA工作过程
  
   
##### I/O通道控制方式（没有内存的处理器（CPU））
  1) I/O通道控制方式的引入
  减少CPU的干涉：
 对一个数据块的干预减少为一组数据看块的干涉
 实现CPU、通道、I/O设备的并行
  2) 通道程序
  通道指令:
 （1）操作码: 规定指令所执行的操作，如读、写、控制
 （2）内存地址：
 标明字符送入内存（读操作）和从内存取出（写操作）时的内存首址。
 （3）计数：本条指令所要读（或写）数据的字节数
 （4）通道程序结束位P：
 用于表示通道程序是否结束。
 P=1表示本条指令是通道程序的最后一条指令
 （5）记录结束标志R：
 R=0：本指令与下一条指令处理的数据属于一个记录
 R=1 ：处理某记录的最后一条指令
 
  
   将内存中不同地址的数据写成多个记录：
   1->2->3->将813~892单元的80个字符
   1034~1173单元的140个字符
   5830~5889单元的60个字符写成一个记录
   4->单独写一个有300个字符的记录
   5->6->共写300字符的记录

## 与设备无关的I/O软件
 应用程序中所用的设备，不局限于使用某个具体的物理设备

### 与设备无关软件的基本概念
 1、以物理设备名使用设备：系统只能根据设备的物理名来分配，无法将另外相同的设备（但具有不同的物理设备名）分配给需要的进程
 2、引入了逻辑设备名：系统在程序需求进行设备分配时，查找相同逻辑设备名的设备，只要系统中有一台该类设备未被分配，进程就不会被阻塞。应用进程不会由于指定设备退役而无法在本系统上运行
 3、逻辑设备名称到物理设备名称的转换：在系统中，必须具有将逻辑设备名称转换为某物理设备名称的功能，配置逻辑设备表

### 与设备无关的软件
 1、设备驱动程序的统一接口
  每个设备驱动程序与OS之间都有相同（相近）的接口
  将抽象的设备名映射到适当的驱动程序上（转换为具体的物理设备名）
   方便添加新的设备驱动程序
   进行设备保护
 2、缓冲管理：现代OS中为字符设备和块设备配置了相应的缓冲区，平衡与CPU的速度差来提高CPU的利用率。如单缓冲区、双缓冲区、循环缓冲区、公用缓冲池
 3、差错控制
  (1) 暂时性错误：可通过重试操作纠正
  (2) 持久性错误：容易发现，要查清错误原因进行相应处理
 4、对独立设备的分配与回收
  独占设备：为避免诸进程对独占设备的争夺由系统来统一分配
 5、独立于设备的逻辑数据块
  与设备无关软件的功能层次
  

## 用户层的I/O软件
### 系统调用与库函数
 1、系统调用
 应用程序通过系统调用间接调用OS中的I/O过程，对I/O设备进行操作
 CPU的状态转换-->用户态和内核态
 
 
   系统调用的执行过程
 2、库函数
  内核提供了OS的基本功能，库函数扩展了OS内核

### 假脱机技术：在联机情况下实现同时外围操作的技术
多个用户共享一台物理 I/O 设备
##### 假脱机技术
  系统利用多道程序中的一道程序模拟脱机输入时的外围控制机功能。
##### SPOOLing的组成
   
  
  (1) 输入井和输出井
  (2) 输入缓冲区和输出缓冲区
  (3) 输入进程和输出进程
  (4) 井管理程序
##### SPOOLing系统的特点
  (1) 提高了I/O的速度
  (2) 将独占设备改造为共享设备
  (3) 实现了虚拟设备功能
##### 假脱机打印机系统
  (1) 磁盘缓冲区
  (2) 打印缓冲区
  (3) 假脱机管理进程和假脱机打印进程
##### 守护进程

## 缓冲区管理
 I/O设备在与处理机交换数据时使用缓冲区（因为两个设备速度不同）

### 缓冲的引入
 (1) 缓和CPU与I/O设备间速度不匹配的矛盾
 (2) 减少对CPU的中断频率，放宽对CPU中断响应时间的限制
   
 (3) 解决数据粒度（数据单元大小）不匹配的问题
 (4) 提高CPU和I/O设备之间的并行性
### 单缓冲区和双缓冲区
 1、单缓冲区
  
 2、双缓冲区
 

为了实现双向数据传输，必须在两台机器中都设置两个缓冲区，一个用作发送缓冲区，另一个用作接收缓冲区


### 环形缓冲区
##### 环形缓冲区的组成
  装输入数据的空缓冲区R
  已装满数据的缓冲区G
  计算进程正在使用的现行工作缓冲区C
  
  指示计算进程下一个可用缓冲区G的指针 Nextg
  指示输入进程下次可用的空缓冲区R的指针 Nexti
  指示计算进程正在使用的缓冲区 C 的指针 Current
  
  （1）多个缓冲区
  （2）多个指针

##### 环形缓冲区的使用
  (1) Getbuf过程：计算进程要使用缓冲区的数据时
  (2) Releasebuf过程：计算进程把缓冲区C的数据提取完毕时

##### 进程之间的同步问题
  (1) Nexti指针追赶上Nextg指针：输入进程的输入数据速度大于计算进程处理数据的速度，可用的空缓冲区已经全部装满，输入进程应该阻塞。
  称为系统受计算限制
  (2) Nextg指针追赶上Nexti指针：输入数据的速度低于计算进程处理数据的速度，缓冲区已全部抽空，计算进程阻塞
  称为系统受I/O限制



### 缓冲池：
缓冲池包含了一个管理的数据结构及一组操作函数的管理机制，用于管理多个缓冲区

##### 缓冲区的组成
 缓冲首部一般包括缓冲区号、设备号、设备上的数据块号、同步信号量以及队列链接指针等
  相同类型的缓冲区链接成队列：
  (1) 空白缓冲队列emq
  (2) 输入队列inq
  (3) 输出队列outq

##### Getbuf过程和Putbuf过程
  Addbuf(type，number)：由参数number所指示的缓冲区B挂在type队列上
  Takebuf(type)：从type所指示的队列的队首摘下一个缓冲区

##### 缓冲区的工作方式
  


## 磁盘存储器的性能和调度

### 磁盘性能简述

##### 数据的组织和格式
  
  
  
  每条磁道可存储相同数目的二进制位
  
  一个10GB的磁盘，有8个双面可存储片，每面16383个磁道（柱面），63个扇面
  600（）  512数据

##### 磁盘的类型
  (1) 固定头磁盘：每条磁道上都有一读/写磁头
  (2) 移动头磁盘：一个盘面一个磁头，可移动访问不同磁道

##### 磁盘访问时间
  寻找时间：找到指定的柱面（磁道）
  延迟时间：找到指定扇区
  传送时间：信息传送时间
  

### 早期的磁盘调度算法
 1、先来先服务FCFS
 
 2、最短寻道时间优先SSTF
 要求访问的磁道与当前磁头所在的磁道距离最近
 总共移动距离：236
 
 
### 基于扫描的磁盘调度算法
 1、单向扫描调度算法：从0号柱面开始向里扫描，到达最后一个柱面时快速返回0号柱面
 382
  
 2、双向扫描调度算法
 321
   
 3、电梯调度算法：
 优先考虑的是磁头当前的移动方向
 沿着移动臂的移动方向选择距离当前移动臂最近的那个访问者进行调度
 208
   
 
 
 



