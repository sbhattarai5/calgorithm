/**
* @file debugger.h
* @author Saurav Bhattarai
* @date 2020/09/29
* @brief Collection of functions that helps to debug
* @details includes function like printing vectors
*/

//##################################################

#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>
#include <vector>

template <class T>
void print_vec(const std::vector< T > & vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
    return;
}


#endif
