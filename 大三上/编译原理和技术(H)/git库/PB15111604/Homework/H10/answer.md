### **环境**

​	GCC:  (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609

#### 题目2 

**知识点**：局部数据存储顺序

​	test1.c代码如下。

```c
//test1.c
#include <stdio.h>
int main(){
    long a[1][1];
    int i;
    long b[1][1];
    printf("a:0x%08lx\n", a);
    printf("i:0x%08lx\n", &i);
    printf("b:0x%08lx\n", b);
    printf("b-a:0x%x\n", (unsigned long)b-(unsigned long)a);
    return 0;
}

```

​	编译选项：

```bash
gcc test1.c -o t -w -O1
```

​	得到运行结果：

```
a:0x7fffe19528f0
i:0x7fffe19528ec
b:0x7fffe1952900
b-a:0x10
```

问题1：请分析i的地址小于a、b的原因，并判断将a数组的声明改为

```c
	long a[1][2];
```

​	后的运行结果（假设关闭了地址随机化）。

回答1：分配局部数据时，先分配小的，再分配大的，大小相等的，按照先后顺序分配。改变后的运行结果：

```
a:0x7fffe1952800
i:0x7fffe19528ec
b:0x7fffe19529f0
b-a:0x10
```

#### 题目2

**知识点**：数组对齐

​	代码同上，

问题2：请分析b-a结果为0x10，而不是4 (sizeof(int)=4) 的原因，并判断将数组a数组的声明改为

```c
	long a[1][2];
```

​	后b-a的大小。

回答2：由于数组对齐，（64位系统中）按照8字节对齐，所以尽管a只有一个int类型元素，占据4字节，但是由于对齐，分配8字节空间。修改之后，a占据的还是8个字节，但由于a的顺序会在b后面，所以b-a的输出结果将是0xfffffff0(-1)。

目录结构：
	/H10	
	├── answer.md
	└── test
		├── Makefile
		├── t
		└── test1.c

