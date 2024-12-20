#include <algorithm>
#include <array>
#include <chrono>
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
#include <vector>

#include <benchmark/benchmark.h>

//  ================================================================================================

using Clock = std::chrono::steady_clock;

//  ================================================================================================

void test_v1(benchmark::State & state) 
{
    for (auto value : state)
    {
        std::array < int, 100'000 > array;

        std::ranges::iota(array, 1); 

        auto start = Clock::now();

        std::ranges::sort(array, std::greater());

        auto delta = Clock::now() - start;

        state.SetIterationTime
        (
            std::chrono::duration_cast < std::chrono::duration < double > > (delta).count()
        );

        benchmark::DoNotOptimize(array);
    }
}

//  ================================================================================================

void test_v2(benchmark::State & state) 
{
    for (auto value : state)
    {
        std::vector < int > vector(100'000, 0);

        std::ranges::iota(vector, 1); 

        auto start = Clock::now();

        std::ranges::sort(vector, std::greater());

        auto delta = Clock::now() - start;

        state.SetIterationTime
        (
            std::chrono::duration_cast < std::chrono::duration < double > > (delta).count()
        );

        benchmark::DoNotOptimize(vector);
    }
}

//  ================================================================================================

void test_v3(benchmark::State & state) 
{
    for (auto value : state)
    {
        std::deque < int > deque(100'000, 0);

        std::ranges::iota(deque, 1); 

        auto start = Clock::now();

        std::ranges::sort(deque, std::greater());

        auto delta = Clock::now() - start;

        state.SetIterationTime
        (
            std::chrono::duration_cast < std::chrono::duration < double > > (delta).count()
        );

        benchmark::DoNotOptimize(deque);
    }
}

//  ================================================================================================

void test_v4(benchmark::State & state) 
{
    for (auto value : state)
    {
        std::list < int > list(100'000, 0);

        std::ranges::iota(list, 1); 

        auto start = Clock::now();

        list.sort(std::greater());

        auto delta = Clock::now() - start;

        state.SetIterationTime
        (
            std::chrono::duration_cast < std::chrono::duration < double > > (delta).count()
        );

        benchmark::DoNotOptimize(list);
    }
}

//  ================================================================================================

void test_v5(benchmark::State & state) 
{
    for (auto value : state)
    {
        std::forward_list < int > forward_list(100'000, 0);

        std::ranges::iota(forward_list, 1); 

        auto start = Clock::now();

        forward_list.sort(std::greater());

        auto delta = Clock::now() - start;

        state.SetIterationTime
        (
            std::chrono::duration_cast < std::chrono::duration < double > > (delta).count()
        );
        
        benchmark::DoNotOptimize(forward_list);
    }
}

//  ================================================================================================

BENCHMARK(test_v1); 
BENCHMARK(test_v2);
BENCHMARK(test_v3);
BENCHMARK(test_v4);
BENCHMARK(test_v5);

BENCHMARK_MAIN();