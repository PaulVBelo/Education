#include <iterator>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

/////////////////////////////////////////////////////////////////////////////////

auto is_even(int x) 
{
    if (x % 2 == 0)
    {
        return testing::AssertionSuccess();
    }
    else
    {
        return testing::AssertionFailure() << x << " is odd";
    }
}

/////////////////////////////////////////////////////////////////////////////////

TEST(Expect, Is_Even)
{
    std::cout << "Test::Expect::Is_Even (1)\n"; EXPECT_TRUE(is_even(1));

    std::cout << "Test::Expect::Is_Even (2)\n"; EXPECT_TRUE(is_even(2));
}

TEST(Assert, Is_Even)
{
    std::cout << "Test::Assert::Is_Even (1)\n"; ASSERT_TRUE(is_even(1));

    std::cout << "Test::Assert::Is_Even (2)\n"; ASSERT_TRUE(is_even(2));
}

/////////////////////////////////////////////////////////////////////////////////

TEST(Assert, Miscellaneous) 
{
    ASSERT_NEAR(1.0, 1.0, 1e-6);

    ASSERT_THAT("aaaaa", testing::StartsWith("aaa"));
}

/////////////////////////////////////////////////////////////////////////////////

class Fixture : public testing::Test 
{
public:

    std::vector < int > data;
};

TEST_F(Fixture, Data) 
{
    data.push_back(1); ASSERT_EQ(std::size(data), 1); 
    
    data.push_back(1); ASSERT_EQ(std::size(data), 2); 
}

/////////////////////////////////////////////////////////////////////////////////

class Adapter : public Fixture, public testing::WithParamInterface < int > {};

TEST_P(Adapter, Data) 
{ 
    auto x = GetParam();
    
    data.resize(x, 0);
    
    ASSERT_EQ(std::size(data), x);
}

INSTANTIATE_TEST_CASE_P(Fixture, Adapter, testing::Values(1, 2, 3, 4, 5));

/////////////////////////////////////////////////////////////////////////////////

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}