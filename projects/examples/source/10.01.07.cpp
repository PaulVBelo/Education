#include <memory>

/////////////////////////////////////////////////

class Entity
{
public :

	void make()
	{
		if (!m_x)
		{
			m_x = std::make_unique < int > (1);
		}
	}

private :

	std::unique_ptr < int > m_x;
};

/////////////////////////////////////////////////

int main()
{
    Entity().make();
}