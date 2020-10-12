/**
* @file bubblesort.cpp
* @author Saurav Bhattarai
* @date 2020/09/29
* @brief A program that implements bubblesort
* @details Best case runtime: O(n^2)
* Average case runtime: O(n ^ 2)
* Worst case runtime: O(n ^ 2)
*/

//##################################################

#include <vector>

/**
* @brief A helper templated function to swap two variables
* @param[in,out] a is the reference to the first variable
* @param[in,out] b is the reference to the second variable
* @return void
*/
template <class T>
void swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
    return;
}

/**
* @brief a templated function that bubblesorts the vector provided
* @param[in,out] vec is a vector that is to be sorted
* @return void
*/
template <class T>
void bubblesort(std::vector< int > & vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1]) swap(vec[j], vec[j + 1]);
        }
    }
    return;
}
