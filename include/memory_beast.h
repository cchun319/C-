# pragma once
#include <vector>
#include <memory>
#include <iostream>

class MemoryBeast
{
    /*
    pimpl https://en.cppreference.com/w/cpp/language/pimpl
    
    https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three/4172724#4172724
    If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment operator, it almost certainly requires all three. 
    */

    /*
    Application binary interface (ABI) compatibility is the ability of programs to conform to the same runtime conventions 
    by using the same low-level interface between program modules
    */


    public:
        // contructor
        MemoryBeast();

        // copy-constructor, lvalue binding
        MemoryBeast(const MemoryBeast&);
        
        // copy-assignment
        MemoryBeast& operator=(const MemoryBeast&);

        // move-constructor, rvalue binding
        // MemoryBeast(const MemoryBeast&&);
        MemoryBeast(MemoryBeast&&);
        
        // move-assignment
        MemoryBeast& operator=(MemoryBeast&&);
    
        virtual ~MemoryBeast();
        void eat(const std::vector<double>&);

        template<class T>
        void eat(const std::vector<T>& mem)
        {
            // Q: can this moved to cpp
            std::cout << "template not implemented\n";
        }

        template<class T>
        void eat_separate(const std::vector<T>&);

        void print();

        void setName(const std::string& name)
        {
            name_ = name;
        }

        std::string Name() const
        {
            return name_;
        }

        void printName()
        {
            std::cout << "I am " << name_ << '\n';
        }

    private:
        std::string name_;
        class Impl;
        std::unique_ptr<Impl> pImpl;
        std::vector<double> memory;
};
