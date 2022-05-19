/**
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 * 实现 LRUCache 类：
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 * 链接：https://leetcode-cn.com/problems/lru-cache
 */

#include <deque>
#include <unordered_map>

using namespace std;

struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    //初始化 LRU 缓存
    LRUCache(int capacity)  
    {
        _size = 0;
        _capacity = capacity;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
    int get(int key)    
    {
        if (!map.count(key))    // 当前
            return -1;
        moveToHead(map[key]);
        return map[key]->value;
    }

    // 如果关键字 key 已经存在，更新其 value 值；如果不存在，则插入
    void put(int key, int value)
    {
        if (!map.count(key)) // 链表不存在
        {
            DLinkedNode *node = new DLinkedNode(key, value);
            map[key] = node;
            if (_size == _capacity) // 缓存满，需逐出最久未使用的关键字
            {
                DLinkedNode *tmp = removeTail();
                map.erase(tmp->key);
                delete tmp;
            }
            addToHead(node);
        }
        else
        { //链表中存在
            map[key]->value = value;
            moveToHead(map[key]);
        }
    }

    // 将 node 节点添加至表头
    void addToHead(DLinkedNode *node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        _size++;
    }

    // 将 node 节点移至表头
    void moveToHead(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        _size--;
        addToHead(node);
    }

    // 移除表尾元素
    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        _size--;
        return node;
    }

private:
    int _size;
    int _capacity;
    unordered_map<int, DLinkedNode *> map;
    DLinkedNode *head;
    DLinkedNode *tail;
};


Line 58: Char 21: runtime error: member access within null pointer of type 'DLinkedNode' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:63:21