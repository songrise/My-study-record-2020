#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;
typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef Node *List;

/* 函数 原型 */
/* 操作： 　 初始化 一个 链 表 */
/* 前提 条件： plist 指向 一个 链 表 */
/* 后置 条件： 链 表 初始化 为 空 */
void InitializeList(List *plist);

/* 操作： 　 确定 链 表 是否 为 空 定义， plist 指向 一个 已 初始化 的 链 表 */
/* 后置 条件： 如果 链 表为 空， 该 函数 返回 true； 否则 返回 false */
bool ListIsEmpty(const List *plist);

/* 操作： 　 确定 链 表 是否 已满， plist 指向 一个 已 初始化 的 链 表 */
/* 后置 条件： 如果 链 表 已满， 该 函数 返回 真； 否则 返回 假 */
bool ListIsFull(const List *plist);

/* 操作： 　 确定 链 表中 的 项数, plist 指向 一个 已 初始化 的 链 表 */
/* 后置 条件： 该 函数 返回 链 表中 的 项数 　 */
unsigned int ListItemCount(const List *plist);

/* 操作： 在 链 表 的 末尾 添加 项 */
/* 前提 条件： item 是 一个 待 添加 至 链 表 的 项, plist 指向 一个 已 初始化 的 链 表 */ /* 后置 条件： 如果 可以， 该 函数 在 链 表 末尾 添加 一个 项， 且 返回 true； 否则 返回 false */
bool AddItem(Item item, List *plist);

/* 操作： 把 函数 作用于 链 表中 的 每 一项 　 */
/* plist 指向 一个 已 初始化 的 链 表 　 */
/* pfun 指向 一个 函数， 该 函数 接受 一个 Item 类型 的 参数， 且 无 返回 值 　 */
/* 后置 条件： pfun 指向 的 函数 作用于 链 表中 的 每一 项 一次 　 */
void Traverse(const List *plist, void (*pfun)(Item item));

/* 操作： 释放 已 分配 的 内存（ 如果 有的 话） */
/* plist 指向 一个 已 初始化 的 链 表 　 */
/* 后置 条件： 释 放了 为 链 表 分配 的 所有 内存， 链 表 设置 为 空 　 */
void EmptyTheList(List *plist);

#endif
