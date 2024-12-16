#include "memory_beast.h"
#include <iostream>
class MemoryBeast::Impl {
    public:
        void eat(const std::vector<double>& mem){
            std::cout << "consumed: " << mem.size() << " memory" << '\n';
        }
    
    private:

};

MemoryBeast::MemoryBeast(): pImpl(std::make_unique<Impl>())
{

}

MemoryBeast::~MemoryBeast() = default;

void MemoryBeast::eat(const std::vector<double>& mem)
{
    memory = mem;
    pImpl->eat(memory);
}


// copy-constructor
MemoryBeast::MemoryBeast(const MemoryBeast& other) : pImpl(new Impl(*other.pImpl))
{
    std::cout << "copy constuctor called" << '\n';

    // will this compile?
    // memory(other.memory);
    // std::copy (v1.begin(), v1.end(), v2.begin());?
    
    // copy assignment
    memory = other.memory;
}
        
// copy-assignment
MemoryBeast& MemoryBeast::operator=(const MemoryBeast& other)
{
    std::cout << "copy assignment called" << '\n';
    this->pImpl = std::make_unique<Impl>(*other.pImpl);

    this->memory.reserve(other.memory.size());
    std::copy (other.memory.begin(), other.memory.end(), this->memory.begin());
    return *this;
}


// move-constructor
MemoryBeast::MemoryBeast(MemoryBeast&& other): pImpl(std::move(other.pImpl))
{
    std::cout << "move constructor called" << '\n';
    memory = std::move(other.memory);
}



// move-assignment
MemoryBeast& MemoryBeast::operator=(MemoryBeast&& other)
{
    std::cout << "move assignment called" << '\n';
    this->pImpl = std::move(other.pImpl);
    memory = std::move(other.memory);
    return *this;
}

void MemoryBeast::print()
{
    std::cout << "size of vector: " << memory.size() << '\n';
    for (const auto& element : memory)
    {

    }
    std::string validity = (pImpl.get() != nullptr) ? "valid" : "invalid";
    std::cout << "operator is " << validity << '\n';
}