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

    m_move.eat<char>({'a','b'});

    m_move.eat_separate<char>({'a','b'});

    m_move.print();
    m_copy.print();
    // *** caution: the data in m_copy is moved. No longer valid

    /*
    future work: https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
    const 1. ptr
          2. const function() const
          3. const reference l & r

    template 1. class
             2. function
    */
    return 0;
}