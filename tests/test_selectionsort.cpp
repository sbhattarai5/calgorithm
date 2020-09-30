/**
* @file test_selectionsort.cpp
* @author Saurav Bhattarai
* @date 2020/09/30
* @brief A program that tests selectionsort
* @details Randomly generate a vector of integers, characters, objects and sort them.
* We test the sorted vector by looping through the vector and making sure it's sorted
*/

//##################################################

#include "../src/sorting/selectionsort/selectionsort.cpp"
#include "debugger.h"
#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>



// tests vector of integers
TEST(TESTSELECTIONSORT, INTEGERTEST)
{
    std::vector< int > vec;
    int len = rand() % 1001;  // randoming the length of the vec from 0 to 1000
    for (int i = 0; i < len; ++i)
    {
        vec.push_back(rand() % 2001 - 1000);  // randomly generating each number
    }
    
    selectionsort< int >(vec);
    
    // check if sorted
    bool inorder = true;
    for (int i = 0; i < len - 1; ++i)
    {
        if (vec[i] > vec[i + 1])
        {
            inorder = false;
            break;
        }
    }
    ASSERT_EQ(true, inorder);
}

// runs all the tests
int main(int argc, char **argv)
{
    srand(time(NULL)); // seeding the rand function
    testing::InitGoogleTest(&argc, argv); // initializing it
    return RUN_ALL_TESTS(); // this will run all your tests
}  
