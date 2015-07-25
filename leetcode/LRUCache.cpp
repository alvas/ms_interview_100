#include <iostream>
#include <map>

using namespace std;

class LRUCache{
public:
    class CacheNode
    {
    public:
        CacheNode(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
        int key;
        int value;
        CacheNode *prev, *next;
    };

    LRUCache(int capacity) {
        m_capacity = capacity;
        m_head = NULL;
        m_tail = NULL;
    }

    int get(int key) {
        map<int, CacheNode *>::iterator itr = m.find(key);

        // Query also update the last update element.
        if (itr != m.end())
        {
            CacheNode *node = itr->second;

            if (node != m_head)
            {
                CacheNode *prev = node->prev;
                CacheNode *next = node->next;
                node->prev = NULL;

                prev->next = next;

                if (next != NULL)
                {
                    next->prev = prev;
                }
                else
                {
                    m_tail = prev;
                }

                node->next = m_head;
                m_head->prev = node;
                m_head =  node;
            }

            return node->value;
        }
        else
        {
            return -1;
        }
    }

    void set(int key, int value) {
        map<int, CacheNode *>::iterator itr = m.find(key);

        if (itr != m.end())
        {
            CacheNode *node = itr->second;
            node->value = value;

            if (node != m_head)
            {
                CacheNode *prev = node->prev;
                CacheNode *next = node->next;
                node->prev = NULL;

                prev->next = next;

                if (next != NULL)
                {
                    next->prev = prev;
                }
                else
                {
                    m_tail = prev;
                }

                node->next = m_head;
                m_head->prev = node;
                m_head =  node;
            }
        }
        else
        {
            int sz = m.size();
            CacheNode *node = new CacheNode(key, value);

            if (sz >= m_capacity)
            {
                if (m_tail != NULL)
                {
                    CacheNode *tmp = m_tail;
                    m.erase(tmp->key);

                    // Be careful about the condition there is only one element, capability is 1.
                    if (m_tail != m_head)
                    {
                        m_tail = m_tail->prev;
                        
                        // Be very careful  when removing the last element. Do clean up the next pointer. Otherwise, it would point to invalid element.
                        m_tail->next = NULL;
                    }
                    else
                    {
                        m_tail = NULL;
                        m_head = NULL;
                    }

                    delete tmp;
                }
            }

            m.insert(make_pair(key, node));
            node->next = m_head;

            if (m_head == NULL)
            {
                m_head = node;
                m_tail = node;
            }
            else
            {
                m_head->prev = node;
                m_head = node;
            }
        }
    }

    CacheNode *m_head, *m_tail;
    map<int, CacheNode *> m;
    int m_capacity;
};

int main()
{
    //LRUCache cache(5);
    //cache.set(1, 9);
    //cache.set(2, 8);
    //cache.set(3, 7);
    //cache.set(1, 6);
    //cache.set(4, 0);
    //cache.set(5, 6);

    //for_each(cache.l.begin(), cache.l.end(), [](LRUCache::CacheNode *e){cout << "key: " << e->key << ", value: " << e->value << endl;});

    LRUCache cache(2);
    cache.set(2, 1);
    cache.set(1, 1);
    cout << cache.get(2) << endl;
    cache.set(4, 1);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;

    //LRUCache::CacheNode *p = cache.m_head;

    //while (p != NULL)
    //{
        //cout << "key: " << p->key << ", value: " << p->value << endl;
        //p = p->next;
    //}


    //cache.set(6, 16);

    //p = cache.m_head;

    //while (p != NULL)
    //{
        //cout << "key: " << p->key << ", value: " << p->value << endl;
        //p = p->next;
    //}

    //cout << cache.get(2) << endl;
    //cout << cache.get(1) << endl;
    //cout << cache.get(6) << endl;
    return 0;
}
