int main()
{
//	[[maybe_unused]] auto x1; // error

//	[[maybe_unused]] auto x2 {}; // error

	[[maybe_unused]] auto x3 = 3;
    
    [[maybe_unused]] auto x4(4);
    
    [[maybe_unused]] auto x5 { 5 };

//	[[maybe_unused]] auto x6 = { 6 }; // bad
        
//	[[maybe_unused]] auto x7 = 7, x8 = 8.0; // error

    [[maybe_unused]] auto x9 = 9u;
}