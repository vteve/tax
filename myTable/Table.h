//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_TABLE_H
#define OOOP3_TABLE_H

#include <iostream>

template<typename K, typename V>
struct Node {
    bool isElement = false; // exist or not
    K key;
    V *value = nullptr;
    int contractNumber = 0;
};

template<typename K, typename V>
class Table {
private:
    static const int maxSize = 10000;
    Node<K, V> *table;
    int curSize;

//    int countRelease(const K &key);

//    void decreaseRelease(const K &key, int release);

public:

    static const int getMaxSize() {
        return maxSize;
    }

    Table() {
        table = new Node<K, V>[maxSize];
//        for (int i = 0; i < maxSize; ++i) {
//            table[i].key = 123;
//        }
        curSize = 0;
    }

    ~Table() {
        delete[] table;
    }

    class Iterator {
    private:
        Node<K, V> *node;
        Node<K, V> *table;
        int index;
        int size;
    public:

        Iterator(Node<K, V> *table, int size) : size(size), table(table), index(0) {
            while (index < size && !table[index].isElement) {
                ++index;
            }
            if (index < size) {
                node = &table[index];
            }
        }

        Node<K, V> &operator*() {
            return *node;
        }

        Iterator &operator++() {
            index++;
            node = &table[index];
            return *this;
        }

        Iterator operator++(int) {
            Iterator newIter = *this;
            ++(*this);
            return newIter;
        }

        Iterator &operator--() {
            index--;
            node = &table[index];
            return *this;
        }

        Iterator operator--(int) {
            Iterator newIter = *this;
            --(*this);
            return newIter;
        }

        Iterator operator+(int k){
            Iterator newIter = *this;
            for (int i = 0; i < k; ++i) {
                newIter++;
            }
            return newIter;
        }

        bool operator!=(const Iterator &sec) {
            return index != sec.index;
        }

        bool operator==(const Iterator &sec) const {
            return index == sec.index;
        }
    };

    Iterator begin() {
        return Iterator(table, curSize);
    }

    Iterator end() {
        Iterator iterator(table, curSize);
        for (int i = 0; i < maxSize; ++i) {
            ++iterator;
        }
        return iterator;
    }

//    Node<K, V> *searchNode(const K &key, int release);

//    void deleteNode(const K &key, int release);

//    int insertNode(const K &key, V *value);

    Node<K, V> *searchNode(const K &key, int contNumber);

    void deleteNode(const K &key, int contNumber);

    int insertNode(const K &key, V *value, int contNumber);

    void showTable();

};

//template<typename K, typename V>
//Node<K, V> *Table<K, V>::searchNode(const K &key, int release) {
//    for (int i = 0; i < maxSize; ++i) {
//        if (table[i].isElement && table[i].key == key && table[i].release == release) {
//            return &table[i];
//        }
//    }
//    return nullptr;
//}

//template<typename K, typename V>
//void Table<K, V>::decreaseRelease(const K &key, int release) {
//    for (int i = 0; i < curSize; ++i) {
//        if (table[i].key == key && table[i].release > release) {
//            table[i].release--;
//        }
//    }
//}

//template<typename K, typename V>
//void Table<K, V>::deleteNode(const K &key, int release) {
//    for (int i = 0; i < maxSize; ++i) {
//        if (table[i].key == key && table[i].release == release) {
//            table[i].isElement = false;
//            decreaseRelease(key, release);
//            curSize--;
//            break;
//        }
//    }
//}

//template<typename K, typename V>
//int Table<K, V>::countRelease(const K &key) {
//    int count = 0;
//    for (int i = 0; i < curSize; ++i) {
//        if (key == table[i].key) {
//            count++;
//        }
//    }
//    return count;
//}

//template<typename K, typename V>
//int Table<K, V>::insertNode(const K &key, V *value) {
//    if (curSize >= maxSize) {
//        return -1;
//    }
//    int index = 0;
//    for (int i = 0; i < maxSize; ++i) {
//        if (!table[i].isElement) {
//            index = i;
//            break;
//        }
//    }
//    table[index].value = value;
//    table[index].key = key;
//    table[index].isElement = true;
//    table[index].contractNumber = 0;
//    curSize++;
//    return 0;
//}

template<typename K, typename V>
Node<K, V> *Table<K, V>::searchNode(const K &key, int contNumber) {
    for (int i = 0; i < maxSize; ++i) {
        if (table[i].isElement && table[i].key == key && table[i].contractNumber == contNumber) {
            return &table[i];
        }
    }
    return nullptr;
}

template<typename K, typename V>
void Table<K, V>::deleteNode(const K &key, int contNumber) {
    for (int i = 0; i < maxSize; ++i) {
        if (table[i].key == key && table[i].contractNumber == contNumber) {
            table[i].isElement = false;
            curSize--;
            break;
        }
    }
}

template<typename K, typename V>
int Table<K, V>::insertNode(const K &key, V *value, int contNumber) {
    if (curSize >= maxSize) {
        return -1;
    }
    int index = 0;
    for (int i = 0; i < maxSize; ++i) {
        if (!table[i].isElement) {
            index = i;
            break;
        }
    }
    table[index].value = value;
    table[index].key = key;
    table[index].isElement = true;
    table[index].contractNumber = contNumber;
    curSize++;
    return 0;
}

template<typename K, typename V>
void Table<K, V>::showTable() {
    for (int i = 0; i < maxSize; ++i) {
        if (table[i].isElement && table[i].value) {
            std::cout << i + 1 << " element  ===  key: " << table[i].key << " contract Number: " << table[i].contractNumber << "  exist: "
                      << table[i].isElement << std::endl;
            table[i].value->showInfo();
        }
    }
}



#endif //OOOP3_TABLE_H
