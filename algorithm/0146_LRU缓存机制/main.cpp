// date: 2020-04-28
// desc: 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
// 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。
// 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。


#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end())
            return -1;
        pair<int, int> temp = *map[key];
        cache.erase(map[key]);
        cache.push_front(temp);
        map[key] = cache.begin();

        return temp.second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end())
        {
            if (map.size() == cap)
            {
                map.erase(cache.back().first);
                cache.pop_back();
            }

            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
        else
        {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

    void printall()
    {
        for (auto num : cache)
            cout << "key = " << num.first << ", vaule = " << num.second << endl;
    }

private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int cap = 0;
};
        
int main(void)
{
    LRUCache lruc(3);

    int getresult = lruc.get(3);
    if (getresult == -1)
    {
        cout << "The vaule 3 is not in LRUC." << endl;
        cout << endl;
    }
    else
    {
        cout << "The vaule is " << getresult << endl;
        cout << endl;
    }

    lruc.put(1, 1);
    cout << "lruc.put(1, 1)" << endl;
    lruc.printall();
    cout << endl;
    lruc.put(2, 2);
    cout << "lruc.put(2, 2)" << endl;
    lruc.printall();
    cout << endl;
    lruc.put(3, 3);
    cout << "lruc.put(3, 3)" << endl;
    lruc.printall();
    cout << endl;
    lruc.put(2, 4);
    lruc.printall();
    cout << endl;

    getresult = lruc.get(1);
    if (getresult == -1)
    {
        cout << "The key 2 is not in LRUC." << endl;
        cout << endl;
    }
    else
    {
        cout << "key = 1, vaule = " << getresult << endl;
        cout << endl;
    }

    cout << endl;
    lruc.printall();

    return 0;
}
