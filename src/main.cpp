#include "memory_beast.h"


int main()
{
    MemoryBeast m, m_copy_assignment, m_move;
    m.eat({1, 2, 3});

    MemoryBeast m_copy(m);

    m_copy_assignment = m_copy;
    m_copy.print();

    m_move = std::move(m_copy);
    m_move.eat({4,5,6,7});

    m_move.print();
    m_copy.print();
    return 0;
}