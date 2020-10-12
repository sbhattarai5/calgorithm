/**
 * @file slnode.h
 * @author Saurav Bhattarai
 * @date 2020/09/30
 * @brief Implementation of node a singly linked list
 * @details instance of this class is a building blocks for singly linked list
*/

//##################################################################

#ifndef SLNode_H
#define SLNode_H
#include <iostream>

template <class T>
class SLList;

/**
 * @brief a class for node in a singly linked list
*/
template <class T>
class SLNode
{
  public:
    /**
     * @brief constructor initializes object with key and next pointer
     * param[in] key is the key of the node
     * param[in] next is the pointer to the next node
     */
    SLNode(const T & key, SLNode < T > *next=NULL)
        : key_(key), next_(next)
    {}
    /**
     * @brief A getter function to return key_
     */
    T get_key() const { return key_; }
    
    /**
     * @brief A getter function to return next_
     */
    SLNode< T > * get_next() const { return next_; }
    
    /**
     * @brief A setter function to set key_ to given value
     */
    void set_key(const T & key) { key_ = key; }
    
    /**
     * @brief A setter function to set next_ to given value
     */
    void set_next(SLNode< T > *next) { next_ = next; }
    
    /**
     * @brief overloaded operator<< to print the node
     * @details debug_mode is a static variable that can be set true or false
     * turning debug_mode on will display info like this pointer, next pointer
     */
    friend std::ostream & operator<<(std::ostream & cout, const SLNode < T >& slnode)
    {
        if (SLList< T >::debug_mode)
        {
            cout << "<SLNode addr:"
                 << &slnode
                 << " key:"
                 << slnode.key_
                 << " next:"
                 << slnode.next_ << '>';
                
        }
        else
            cout << slnode.key_;
        return cout;
    }
  
  private:
    
    T key_;
    SLNode < T > *next_;
};





#endif
