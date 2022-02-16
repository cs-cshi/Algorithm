/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
*/

#include <unordered_map>
#include <iostream>

using std::cout;
using std::endl;
using std::unordered_map;

struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr){};
    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr){};
};

class LRUCache
{
private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head; // 双向链表头指针
    DLinkedNode *tail; // 双向链表尾指针
    int capacity;      // cache 容量
    int size;          // 双向链表的大小

public:
    LRUCache(int capacity) : capacity(capacity), size(0)
    {
        // 初始化的时候需要先创建头尾结点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key)) // 不存在
        {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            if (capacity == size)
            {
                DLinkedNode *node = removeTail();
                cache.erase(node->key);
                delete node;
            }
            addToHead(node);
        }
        else
        {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DLinkedNode *node)
    {
        // 当前节点脱链
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
        addToHead(node);
    }

    // 将尾结点从链表脱离，并返回尾结点
    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        size--;
        return node;
    }

    void addToHead(DLinkedNode *node)
    {
        // 将当前节点移至链表头
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
};

int main()
{
    LRUCache my_lru(2);
    my_lru.put(1, 1);
    my_lru.put(2, 2);
    my_lru.get(1);
    my_lru.put(3, 3);
    my_lru.get(2);
    my_lru.put(4, 4);
    my_lru.get(1);
    my_lru.get(3);
    my_lru.get(4);
}