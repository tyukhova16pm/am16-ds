#ifndef M_LIST_H
#define M_LIST_H

#include <iostream>
#include <string>

struct m_list {
    int key;
    std::string data;
    struct m_list *next;
    struct m_list *prev;
    
    m_list(int key, std::string data, _list *_n, _list *_p);
    m_list();
};
