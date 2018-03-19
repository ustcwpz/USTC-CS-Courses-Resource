# Introduction
This teamwork project is one of the [projects](https://github.com/ustc-compiler/2017fall-student-teamworks) for the class [USTC-Compilter-H](http://staff.ustc.edu.cn/~yuzhang/compiler/), which is focused on the mechanism of the Java Garbage Collection and researches on kinds of  GC algorithms.
# 项目介绍
本项目是中国科大[编译原理(h)](http://staff.ustc.edu.cn/~yuzhang/compiler/)课程中[团队项目](https://github.com/ustc-compiler/2017fall-student-teamworks)中的一个,针对的是“Java Garbage Collection 与各种GC算法”。
### 1. 成员信息
| job  | name | GitHub         |
| ---- | ---- | -------------- |
| 队长   | 齐炜祯  | qiweizhen      |
| 成员   | 黄一凡  | GhostScreaming |
| 成员   | 金泽文  | kingzevin  |
### 2. 项目简介
本组研究的课题为“Java Garbage Collection 与各种GC算法”。
WikiPedia 对 Garbage Collection 的定义如下:

>In computer science, garbage collection (GC) is a form of automatic memory management. The garbage collector, or just collector, attempts to reclaim garbage, or memory occupied by objects that are no longer in use by the program

几乎现代编程语言都使用了动态内存分配，在内存有限的环境下，回收运行过程中不再需要的对象，重新释放内存就显得尤为重要。通常有两种回收策略：显示内存释放和自动动态内存管理。显示内存释放由程序员负责回收使用的内存，但常出现过早回收（引发悬挂指针问题）和未释放内存（引发内存泄露问题）两大错误。此外，考虑内存分配也大大提高了编程方案的复杂性。实际中，我们常使用自动动态内存管理方案。GC 则是管理中实现回收的重要步骤。

实现GC有几种经典算法，如：**标记-清除算法**——对所有堆中活动对象进行标记，把剩余没有标记的对象进行清除；**引用计数法**——每个对象记录有多少个程序在引用自己，计数为0的对象被释放；**GC复制算法**——将某个内存分配完的空间里的活动对象整理后，复制到另一个未被分配的活动对象，释放原内存的所有对象；**GC标记-压缩算法**——结合了GC标记-清除算法和复制-压缩算法，和GC标记-清除算法一样，先进行标记，然后搜索数次堆进行压缩，重新装填活动对象（不用牺牲半个堆）。

具体实现GC时，为了提升回收效率，还有**分代垃圾回收算法**——给每个对象记录年龄，优先回收容易成为垃圾的对象；**增量式垃圾回收算法**——通过逐渐推进垃圾回收来控制mutator最大暂停时间。

本次项目，我们准备了解探究GC的经典算法，每个算法实现一些实例，最后调研java语言中GC的具体实现策略。
