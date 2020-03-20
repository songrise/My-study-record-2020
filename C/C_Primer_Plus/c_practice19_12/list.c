/* list. c -- 支持 链 表 操作 的 函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 局部 函数 原型 */
static void CopyToNode(Item item, Node *pnode);
//内部链接，仅限于本文件使用

/* 接口 函数 */
/* 把 链 表 设置 为 空 */
void InitializeList(List *plist)
{
    *plist = NULL;
}

/* 如果 链 表为 空， 返回 true */
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}
/* 如果 链 表 已满， 返回 true */

bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);

    return full;
}
/* 返回 节点 的 数量O（n） */
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = *plist;
    /* 设置 链 表 的 开始 */
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next; /* 设置 下一个 节点 */
    }

    return count;
}

/* 创建 储存 项 的 节点， 并将 其 添加 至 由 plist 指向 的 链 表 末尾（ 较慢 的 实现） */
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
        return false; /* 失败 时 退出 函数 */

    CopyToNode(item, pnew);
    pnew->next = NULL; //要add的这一项是最后一项，因此其next应该为空指针
    if (scan == NULL)  /* 空 链 表， 所以 把 */
        *plist = pnew; /* pnew 放在 链 表 的 开头 */
    else
    {
        while (scan->next != NULL)
            scan = scan->next; /* 找到 链 表 的 末尾 */
        scan->next = pnew;     /* 把 pnew 添 加到 链 表 的 末尾 */
    }
    return true;
}

/* 访问 每个 节点 并 执行 pfun 指向 的 函数 */
void Traverse(const List *plist, void (*pfun)(Item item))
{
    Node *pnode = *plist; /* 设置 链 表 的 开始 */
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* 把 函数 应用于 链 表 中的 项 */
        pnode = pnode->next;  /* 前进 到下 一项 */
    }
}
/* 释放 由 malloc() 分配 的 内存 */
/* 设置 链 表 指针 为 NULL */

void EmptyTheList(List *plist)
{
    Node *psave;
    while (*plist != NULL)
    {
        psave = (*plist)->next; /* 保存 下一个 节点 的 地址 　 */
        free(*plist);           /* 释放 当前 节点 */
        *plist = psave;         /* 前进 至 下一个 节点 */
    }
}
/* 局部 函数 定义 */
/* 把 一个 项 拷贝 到 节点 中 */
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item; /* 拷贝 结构 */
}
