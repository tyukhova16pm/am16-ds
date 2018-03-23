#ifndef LIST_H
#define LIST_H

class list {
    private:
        m_list l;
        m_list *node;
    public:
        list();
        list(int key, std::string data, _list *n, _list *p);
        ~list();
        void set(int key, std::string data);
        std::string get(int key);
};

#endif
