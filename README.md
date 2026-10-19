# dsa-c

用 C 语言从零实现数据结构课程中的全部内容，包含原理讲解、复杂度分析与测试用例。

## 项目进度

| 模块 | 内容 | 状态 |
|---|---|---|
| 线性表 | 顺序表 / 单链表 / 双向链表 / 循环链表 | ⬜ |
| 栈与队列 | 顺序栈 ✅ / 链栈 / 循环队列 / 链队列 | 🚧 |
| 串 | 朴素匹配 / KMP | ⬜ |
| 树 | 二叉树 / BST / AVL / 堆 / 哈夫曼 / Trie | ⬜ |
| 图 | 邻接矩阵 / 邻接表 / BFS / DFS / 最短路 / 最小生成树 | ⬜ |
| 查找 | 顺序 / 折半 / BST / 哈希 | ⬜ |
| 排序 | 冒泡 / 插入 / 折半插入 / 希尔 / 选择 / 堆 / 归并 / 快速 / 基数 | ⬜ |
| LeetCode | 刷题记录 | ⬜ |

> ✅ 已完成　🚧 进行中　⬜ 未开始

## 目录结构

```
dsa-c/
├── 02-stack-queue/
│   └── seq-stack.c        # 顺序栈：初始化、判空、判满、入栈、出栈、取栈顶
├── .gitignore             # 忽略 build/、*.exe、*.o
└── README.md
```

## 如何编译运行

每个 `.c` 文件都可以独立编译运行（内含自测）。

```bash
# 1. 创建输出目录（只需一次）
mkdir -p build

# 2. 编译
gcc -Wall -Wextra 02-stack-queue/seq-stack.c -o build/seq-stack

# 3. 运行
./build/seq-stack
```

Windows PowerShell：

```powershell
mkdir build
gcc -Wall -Wextra 02-stack-queue/seq-stack.c -o build/seq-stack.exe
.\build\seq-stack.exe
```

## 文件约定

每个 `.c` 文件按统一结构编写：

1. **文件头注释**：原理、复杂度、易错点
2. **实现**：核心函数
3. **测试**：`test_xxx()` 函数
4. **`main`**：调用测试并输出结果

## 开发环境

- 语言：C99
- 编译器：gcc