# Notes for [Java Garbage Collection][1]

## 1.初步认识 JVM

### 1.1 分代GC
    eden space(伊甸园空间)
    Survivor Space(幸存空间) S0和S1
    Old Generation(年老代)
    (SE 8中移除了"永久代")

### 1.2 四种引用
    Strong Reference    --不释放
    Soft Reference      --可以释放,但是尽可能作为最后一个释放选项
    Weak Reference      --即将释放
    Phantom Reference   --即将释放

### 1.3 四种GC
    Serial GC
        单线程GC,工作时暂停所有应用的线程,STW(stop the world)
    Parallel GC
        多个并行的GC线程.默认GC.工作时也会暂停所有应用的线程,STW
    CMS GC
        Concurrent Mark Sweep
        并发标记-清除GC.
        使用更多CPU来保证应用的性能.
        如果cpu资源充足,CMS是首选.
        压缩时STW.
    G1 GC
        针对较大的堆内存空间
        将堆分成多个区域,并行管理,随时在释放之后压缩空闲堆空间

### 1.4 GC监控与分析

    为了便于直观地监控Java应用中的堆的情况,cpu占用情况,以及GC中的分代情况等,Oracle提供了多种工具,比如Java VisualVM.

## 2.阅读 HotSpot JVM 源码!

### 2.1 概览
    获取源码之后得到如下图所示目录结构的jdk9的HotSpot源码:
![01_概览][2]

    HotSpot项目主体主要是用C++实现的,并伴有少量的C代码和汇编代码(平台相关).(当然也有java的部分,负责调试的SA(Serviceability Agent)部分由Agent目录里的java实现.)
    share目录里面是平台无关的共享代码,我们关注的gc以及memory模块,就在里面.

### 2.2 HotSpot内核架构


​    


















​    
### **杂记-魔法**:
    宏-##:
        #define DEF_OOP(type)                   \
            class type##OopDesc;                \
                class type##Oop : public oop {  \
                public:                         \
                    type##Oop() : oop() {}      \
                    operator type##OopDesc* () const { return (type##OopDesc*)obj(); }  \
            };
    宏-循环:
        #define ALL_JAVA_THREADS(x) for (JavaThread* x=_thread_list; x; x = x->next();
        ALL_JAVA_THREADS(p){tc->do_thread(p);}

### **杂记-心得**:
    1.阅读源码:
        阅读源码,是为了理解源码的工作原理,了解各个组件如何协作发挥作用.而源码的"数据结构"最能直接反映组件的本质,反映依赖关系,反映状态条件.

### links:

1   [Java垃圾回收的介绍](https://javapapers.com/java/java-garbage-collection-introduction/)
2   [Java垃圾回收的工作机制](https://javapapers.com/java/how-java-garbage-collection-works/)
3   [Java垃圾回收的类型](https://javapapers.com/java/types-of-java-garbage-collectors/)
4   [Java垃圾回收的监测与分析](https://javapapers.com/java/java-garbage-collection-monitoring-and-analysis/)
5   [Visualvm-可视化VM](https://docs.oracle.com/javase/8/docs/technotes/guides/visualvm/)

[1]: https://javapapers.com/java/how-java-garbage-collection-works/
[2]: http://home.ustc.edu.cn/~jzw0222/01_%E6%A6%82%E8%A7%88.png