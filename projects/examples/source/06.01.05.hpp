#ifndef PROJECT_HEADER_HPP

#define PROJECT_HEADER_HPP

//////////////////////////////////////

#pragma once

//////////////////////////////////////

#include <iostream>

//////////////////////////////////////

void test_v2();

void test_v3();

//////////////////////////////////////

// void test_v4() // error
// { 
//     std::cout << "test_v4\n";
// } 

//////////////////////////////////////

inline void test_v5()
{ 
    std::cout << "test_v5\n";
}

//////////////////////////////////////

template < typename T > void test_v6()
{
	std::cout << "test_v6\n";
}

//////////////////////////////////////

extern       int g_x1;

extern       int g_x2;

extern const int g_x3;

extern const int g_x4;

       const int g_x5 = 5;

inline const int g_x6 = 6;

//////////////////////////////////////

#endif