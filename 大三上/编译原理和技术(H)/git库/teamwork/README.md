# Introduction

This teamwork project is one of the [projects](https://github.com/ustc-compiler/2017fall-student-teamworks) for the class [USTC-Compilter-H](http://staff.ustc.edu.cn/~yuzhang/compiler/), which is focused on the mechanism of the Java Garbage Collection and researches on kinds of  GC algorithms.

# 项目介绍

本项目是中国科大[编译原理(h)](http://staff.ustc.edu.cn/~yuzhang/compiler/)课程中[团队项目](https://github.com/ustc-compiler/2017fall-student-teamworks)中的一个,针对的是“Java Garbage Collection 与各种GC算法”。

### 1. 项目链接
#### [项目主页](https://github.com/USTC-Compiler-H-Team-10/teamwork.git)
#### ssh key 
git@github.com:USTC-Compiler-H-Team-10/teamwork.git

### 2. 成员信息
| job  | name | GitHub                                   |
| ---- | ---- | ---------------------------------------- |
| 队长   | 齐炜祯  | [ qiweizhen](https://github.com/qiweizhen) |
| 成员   | 黄一凡  | [GhostScreaming](https://github.com/GhostScreaming) |
| 成员   | 金泽文  | [kingzevin](https://github.com/kingzevin)    |

### 3. 项目简介
本组研究的课题为“Java Garbage Collection 与各种GC算法”。
WikiPedia 对 Garbage Collection 的定义如下:

>In computer science, garbage collection (GC) is a form of automatic memory management. The garbage collector, or just collector, attempts to reclaim garbage, or memory occupied by objects that are no longer in use by the program

几乎现代编程语言都使用了动态内存分配，在内存有限的环境下，回收运行过程中不再需要的对象，重新释放内存就显得尤为重要。通常有两种回收策略：显示内存释放和自动动态内存管理。显示内存释放由程序员负责回收使用的内存，但常出现过早回收（引发悬挂指针问题）和未释放内存（引发内存泄露问题）两大错误。此外，考虑内存分配也大大提高了编程方案的复杂性。实际中，我们常使用自动动态内存管理方案。GC 则是管理中实现回收的重要步骤。

实现GC有几种经典算法，如：**标记-清除算法**——对所有堆中活动对象进行标记，把剩余没有标记的对象进行清除；**引用计数法**——每个对象记录有多少个程序在引用自己，计数为0的对象被释放；**GC复制算法**——将某个内存分配完的空间里的活动对象整理后，复制到另一个未被分配的活动对象，释放原内存的所有对象；**GC标记-压缩算法**——结合了GC标记-清除算法和复制-压缩算法，和GC标记-清除算法一样，先进行标记，然后搜索数次堆进行压缩，重新装填活动对象（不用牺牲半个堆）。

具体实现GC时，为了提升回收效率，还有**分代垃圾回收算法**——给每个对象记录年龄，优先回收容易成为垃圾的对象；**增量式垃圾回收算法**——通过逐渐推进垃圾回收来控制mutator最大暂停时间。

本次项目，我们准备了解探究GC的经典算法，每个算法实现一些实例，最后调研java语言中GC的具体实现策略。

### 4. 12月23日提交
**任务和分工**  

已经完成了之前制定的任务计划：调研若干个经典算法，以及JAVA中GC的算法使用情况。具体完成效果如下：  
齐炜祯：[调研GC复制算法、标记压缩法、增量式垃圾回收算法](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/Algotirhms.md)  
黄一凡：[调研GC标记-清除算法、引用计数法、分代垃圾回收](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/Algorithm%20by%20Fan.md)  
金泽文：[调研JVM中GC算法的使用](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/notes_for_JVM.md)

**讨论记录**  
#### 12.23
QQ群: 30分钟 + 图书馆四楼讨论区: 40分钟  
第一阶段的任务已经完成；  
分享各自学习心得；  
讨论制定接下来的目标和计划
#### 12.14
QQ群: 40分钟  
交流了各自找到的资料；具体分配任务。
#### 12.13
QQ群: 40分钟  
确定课题，开始准备。  

**进展记录及问题**

第一阶段就完成了项目简介中计划的内容；调研成果在任务分工中已经给出了链接。因此商讨下一步的研究方向。现在遇到的问题是后面的工作需要重新指定，现在确定了若干个有可能进行的希望，但是暂时不能完全确定。

**下一步的计划**  

因为前面指定的计划（探索经典GC算法）已经被完成掉了，因此商讨出下面探索的方向，并会在进一步探索后具体确定。  
探索方向：  
1. 尝试探索JVM源码，分配任务阅读JVM的GC源码；
2. 如果有可能，在探索JVM后，确定造JVM的小轮子或者改写or实现JVM中GC部分的难度和可行性。
3. 探索现在最前沿的GC算法，阅读新发表的论文。
4. 对C语言的malloc函数进行封装，并实现GC函数，为C语言提供垃圾回收机制。  
  **后面的任务将会探索以上四个方向，并选择最合适的方向进行。**


### 5. 1月3日提交
**任务和分工**  

完成了对上一阶段计划的探索调研，并确定方向开始了相关工作：尝试阅读JVM的GC源码；调研实现JVM中GC轮子的难度和可行性；调研业界最前沿的GC算法，调研近些年的论文；通过封装C语言的malloc等函数，实现GC算法，为C语言提供垃圾回收机制。具体调研及完成效果如下：  
齐炜祯：[调研论文-Android O的GC实现](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/GC-state-of-the-art.md)  、 [调研C语言垃圾回收的开源项目](https://github.com/USTC-Compiler-H-Team-10/teamwork/tree/master/gcForC) 
黄一凡：[调研JVM中不同种类的垃圾收集器](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/Java%20Garbage%20Collector.md)  
金泽文：[进一步调研JVM中GC机制的细节](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/notes_for_JVM.md)

**讨论记录**  
#### 1.3
QQ群: 30分钟 + 图书馆四楼讨论区: 45分钟  
第二阶段的调研任务基本完成；
分享各自调研情况；  
讨论并确定、分配了最后阶段的工作任务以及方向。
#### 1.2
QQ群: 30分钟  
交流了各自的进展。

**进展记录及问题**

第二阶段的调研任务基本完成，四个方向都进行了基本的了解，并商讨了最后阶段的深入研究方向。：
JVM的GC源码深入调研可行，决定进一步阅读，并深入理解；
实现JVM的小轮子难度较大，放弃；
调研业界最前沿的GC算法，调研近些年的相关论文，探索了近几年有关GC的论文，突破极小。基本上都是在特定的场合下优化改进传统GC算法的一些细节，调研了Android O的最新GC框架；
调研发现对C语言的垃圾回收实现可行，决定通过开源项目进一步自行实现。

之前遇到的问题基本通过本次调研得到的解决。接下来根据确定的方向进一步深入。

**下一步的计划**  

结合上面的进展记录部分的结果，商讨出下面探索的方向。 探索方向：
1. 进一步阅读JVM的GC源码，并深入理解。目标：分析到源码各个函数；  
2. 通过进一步调研C语言垃圾回收的开源项目，对C语言独立实现垃圾回收机制。目标：实现C语言的简单garbage collector。


### 6. 1月13日提交

**任务和分工**  

详细分析C语言开源项目，尝试用C语言实现简单的garbage collector。阅读完JVM的shared和Serial GC模块。根据组间交流，完善了之前工作的不足，调研了Java9 GC的新特性。

齐炜祯：[C语言Garbage Collector的源代码分析](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/gcForC.md)  、[尝试用C语言实现GC复制算法](https://github.com/USTC-Compiler-H-Team-10/teamwork/tree/master/gcForC/copying)、[尝试用C语言实现GC标记-清除算法](https://github.com/USTC-Compiler-H-Team-10/teamwork/tree/master/gcForC/markAndSweep)，写好自己之前工作的PPT

黄一凡：[Java9 GC机制的新特性](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/Java%20Garbage%20Collector.md)，完善之前工作的不足，汇总PPT

金泽文：[HotSpot-jdk9的GC源码分析](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/notes_for_JVM.md)，写好自己之前工作的PPT

**讨论记录**

**1.12**

组间交流：30分钟（QQ群）

QQ群：30分钟

两个组交流了各自工作进展，提出了对彼此工作的建议（记录在issue中）。组内交流了各自的进展，根据组间交流内容，完善了先前工作的不足

**1.13**

组间交流：60分钟（QQ群）+图书馆四楼讨论区：30分钟

汇报了每个人工作的成果，讨论了presentation的汇报内容。



**进展记录及问题**

第三阶段的调研任务基本完成。详细分析开源C语言GC项目，尝试用C语言实现Garbage Collector（GC复制算法和标记-清除算法），基本阅读完了HotSpot-jdk9的GC部分，将理解记录在笔记里。通过组织间交流，完善了之前工作的一些不足，加深了对我们工作的理解。调研了java9 GC的新特性，为什么用G1替代CMS。

在用C语言实现Garbage Collector时遇到了一些问题，记录在[文档](https://github.com/USTC-Compiler-H-Team-10/teamwork/blob/master/gcForC.md)中。

之前的遇到的问题基本解决，并且完成了之前的计划。



**文献及引用和参考链接**  

[《垃圾回收的算法与实现》 【日】 中村成洋 相川光](https://www.amazon.cn/dp/B01JZS0AO8 )  

[JVM的GC相关内容](https://javapapers.com/java/how-java-garbage-collection-works)

[Mark and Sweep Garbage Collector in C - GitHub开源项目](https://github.com/briancain/garbage-collector)

[Performance and Memory Improvements in Android Run Time (ART) (Google I/O '17) - youtube](https://www.youtube.com/watch?v=iFE2Utbv1Oo)

[深入理解 Java G1 垃圾收集器](http://blog.jobbole.com/109170/)

[Garbage-First Garbage Collection](https://dl.acm.org/citation.cfm?id=1029879)

[深入理解JVM(3)——7种垃圾收集器](https://crowhawk.github.io/2017/08/15/jvm_3/)

[What’s the difference between concurrency and parallelism](http://joearms.github.io/2013/04/05/concurrent-and-parallel-programming.html)

[Getting Started with the G1 Garbage Collector](http://www.oracle.com/webfolder/technetwork/tutorials/obe/java/G1GettingStarted/index.html)，[翻译文章](http://blog.csdn.net/renfufei/article/details/41897113)

[Java垃圾回收的介绍](https://javapapers.com/java/java-garbage-collection-introduction/)    

[Java垃圾回收的工作机制](https://javapapers.com/java/how-java-garbage-collection-works/)

[Java垃圾回收的类型](https://javapapers.com/java/types-of-java-garbage-collectors/)  

[Java垃圾回收的监测与分析](https://javapapers.com/java/java-garbage-collection-monitoring-and-analysis/)  

[Visualvm-可视化VM](https://docs.oracle.com/javase/8/docs/technotes/guides/visualvm/)  

[HotSpot实战](https://book.douban.com/subject/25847620/)  

[Java堆的创建](http://www.importnew.com/17068.html)   

[从持久代到metaspace](https://juejin.im/post/59e969ca51882561a05a3340)  

[metaspace in java8](http://java-latte.blogspot.sg/2014/03/metaspace-in-java-8.html)  


