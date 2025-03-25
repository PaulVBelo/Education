#include <new>

#include <benchmark/benchmark.h>

/////////////////////////////////////////////////////////////////////////////////

void test(benchmark::State & state)
{
    for (auto element : state)
    {
        auto x = operator new(state.range(0));

        benchmark::DoNotOptimize(x);

        operator delete(x, state.range(0));
    }
}

/////////////////////////////////////////////////////////////////////////////////

BENCHMARK(test)->RangeMultiplier(2)->Range(1'024 * 1'024, 1'024 * 1'024 * 1'024);

/////////////////////////////////////////////////////////////////////////////////

int main()
{
    benchmark::RunSpecifiedBenchmarks();
}