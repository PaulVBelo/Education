#include <cctype>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <variant>

using namespace std::literals;

//  ================================================================================================

class Stream
{
public:

	using Token = std::variant < char, double, std::string > ;

public:

	explicit Stream(const std::string & data) : m_sin(data + ';') {}

public:

	auto empty()
	{
		char c; m_sin >> c;

		if (c != ';') 
		{ 
			m_sin.putback(c); return false; 
		} 
		else 
		{
			return true;
		}
	}

	auto get()
	{
		if (m_is_full) 
		{ 
			m_is_full = false; return m_token; 
		}

		char c; m_sin >> c;
		
		switch (c)
		{
			case '+': case '-': case '*': case '/': 
			case '(': case ')': case ';':
			{
				return Token(c);
			}
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			case '.':
			{
				m_sin.putback(c); double value; m_sin >> value;

				return Token(value);
			}
			default:
			{
				if (std::string string(1, c); std::isalpha(c))
				{
					while (m_sin.get(c) && (std::isalpha(c) || std::isdigit(c))) 
					{
						string += c;
					}

					if (!std::isspace(c)) 
					{
						m_sin.putback(c); 
					}

					return Token(string);
				}
				else 
				{
					throw std::runtime_error("invalid token");
				}
			}
		}
	}

	void putback(const Token & token)
	{
		m_token = token; m_is_full = true;
	}

private:

	Token m_token; bool m_is_full = false; std::stringstream m_sin;
};

//  ================================================================================================

class Calculator
{
public:

	void test()
	{
		std::cout << "Enter 1 or more expressions : " << std::endl;

		for (std::string line; std::getline(std::cin >> std::ws, line); )
		{
			if (Stream stream(line); !stream.empty())
			{
				std::cout << "= " << statement(stream) << std::endl;
			}
			else 
			{
				break;	
			}		
		}
	}

private:

	double statement(Stream & stream)
	{
		auto token = stream.get();

		if (std::holds_alternative < std::string > (token) && 
			std::get               < std::string > (token) == "set")
		{
			return declaration(stream);
		}
		
		stream.putback(token); 
		
		return expression(stream);
	}

	double declaration(Stream & stream)
	{
		auto name = std::get < std::string > (stream.get());

		m_variables[name] = expression(stream);

		return m_variables[name];
	}

	double expression(Stream & stream) const
	{
		auto left = term(stream);

		for (auto token = stream.get(); true; token = stream.get())
		{
			if (std::holds_alternative < char > (token))
			{
				switch (std::get < char > (token))
				{
					case '+': { left += term(stream); break; }
					case '-': { left -= term(stream); break; }

					default: 
					{ 
						stream.putback(token); 
						
						return left; 
					}
				}
			}
			else 
			{
				throw std::runtime_error("invalid expression");
			}
		}
	}

	double term(Stream & stream) const
	{
		auto left = primary(stream);

		for (auto token = stream.get(); true; token = stream.get())
		{
			if (std::holds_alternative < char > (token))
			{
				switch (std::get < char > (token))
				{
					case '*': { left *= term(stream); break; }
					case '/': { left /= term(stream); break; }

					default: 
					{ 
						stream.putback(token); 
						
						return left; 
					}
				}
			}
			else 
			{
				throw std::runtime_error("invalid term");
			}
		}
	}

	double primary(Stream & stream) const
	{
		auto token = stream.get();

		if (std::holds_alternative < char > (token))
		{
			switch (std::get < char > (token))
			{
				case '(':
				{
					auto result = expression(stream); 
					
					token = stream.get(); 

					if (!std::holds_alternative < char > (token) || 
						 std::get               < char > (token) != ')')
					{
						throw std::runtime_error("invalid token");
					}
					
					return result;
				}
				case '+': { return        primary(stream); }
				case '-': { return -1.0 * primary(stream); }
				
				default: 
				{
					throw std::runtime_error("invalid primary");
				}
			}
		}
		
		if (std::holds_alternative < double > (token))
		{
			return std::get < double > (token);
		}

		return m_variables.at(std::get < std::string > (token));
	}

private:

	std::unordered_map < std::string, double > m_variables;
};

//  ================================================================================================

int main()
{
	Calculator().test();
}