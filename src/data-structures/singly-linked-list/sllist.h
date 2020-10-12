/**
 * @file sllist.h
 * @author Saurav Bhattarai
 * @date 2020/09/30
 * @brief Implementation of a Singly Linked List
 * @details A data structure for fast operations on one end
 * adding and deleting on one end is O(1), on the other end is O(n)
*/

//##################################################################

#ifndef SLList_H
#define SLList_H
#include <iostream>
#include "slnode.h"


class IndexError
{};

/**
 * @brief a singly linked list class that uses pointers
*/
template <class T >
class SLList
{
  public:
    /**
     * @brief constructor initializes a singly linked list with head pointer as NULL
     */
    SLList()
        : phead_(NULL), size_(0)   
    {}
    
    /**
     * @brief destructor that deletes the pointer
     */
    ~SLList()
    {
        while(phead_ != NULL)
        {
            SLNode < T > *ptr = phead_->get_next();
            delete phead_;
            phead_ = ptr;
        }
        return;
    }
    
    /**
     * @brief gets the size of the list
     */
    int size() const { return size_; }

    /**
     * @brief a function that adds item to the head of the list
     * @param[in] key is the key of the node to be added in the head
     * @return void
     */
    void push_front(const T & key)
    {
        phead_ = new SLNode < T >(key, phead_);
        ++size_;
        return;
    }

    /**
     * @brief a function that removes item from the head of the list
     * @return void
     */
    void pop_front()
    {
        if (phead_ != NULL)
        {
            SLNode < T > *p = phead_->get_next();
            delete phead_;
            phead_ = p;
            --size_;
        }
        return;
    }

    
    /**
     * @brief a function that returns the pointer to a node which lives in given index
     * @return pointer to the node in the given index
     */
    SLNode < T > & operator[](int index)
    {
        if (index < 0 || index >= size_) { throw IndexError(); }
        int cidx = 0;
        SLNode < T > *ptr = phead_;
        while (cidx != index)
        {
            ptr = ptr->get_next();
            ++cidx;
        }
        return *ptr;
    }

    /**
     * @brief adding element to the end of the list
     * @param[in] the key of the new node 
     * @details the runtime is O(n) where n is size of the list
     */
    void push_back(const T & key)
    {
        if (phead_ == NULL)
        {
            phead_ = new SLNode < T >(key);
        }
        else
        {
            (*this)[size_ - 1].set_next(new SLNode< T >(key));
        }
        ++size_;
        return;
    }
    /**
     * @brief overloaded operator<< to print the list
     */
    friend std::ostream & operator<<(std::ostream & cout, const SLList < T >& sllist)
    {
        if (SLList< T >::debug_mode)
        {
            cout << "SLList addr:" << &sllist
                 << " phead_:" << sllist.phead_
                 << " size:" << sllist.size_ << "\n[\n";
            
            SLNode < T > *ptr = sllist.phead_;
            while (ptr != NULL)
            {
                cout << "    " << *ptr << '\n';
                ptr = ptr->get_next();
            }
            cout << ']';
        }
        else
        {
            SLNode < T > *ptr = sllist.phead_;
            cout << '[';
            while (ptr != NULL)
            {
                cout << *ptr;
                ptr = ptr->get_next();
                if (ptr != NULL) cout << ", ";
            }
            cout << ']';
        }
        return cout;
    }
    
    /**
     * @brief turning the debug_mode will enable debug printing
     */
    static bool debug_mode;
    
  private:
    SLNode < T > *phead_;
    int size_;
};

template<typename T>
bool SLList < T >::debug_mode = false;

#endif

