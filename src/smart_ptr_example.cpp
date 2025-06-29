#include "memory_beast.h"
#include <memory>
#include <cassert>

/*
void changeName(std::unique_ptr<MemoryBeast> ptr, const std::string& new_name)
{
    Q: does this build?
    It can't as the function call is calling copy constructor which is not allowed for unique ptr
    Q: how to get it work?
    hint: &
}
*/

void changeName(std::unique_ptr<MemoryBeast>& ptr, const std::string& new_name)
{
    ptr->setName(new_name);
}

int main()
{
    // EXAMPLE FOR UNIQUE ptr
    std::unique_ptr<MemoryBeast> unique_beast = std::make_unique<MemoryBeast>();
    unique_beast->setName("unique");
    unique_beast->printName();
    changeName(unique_beast, "super unique");
    unique_beast->printName();

    MemoryBeast* raw_beast = unique_beast.get();
    // MemoryBeast* raw_beast_get_again = unique_beast.get();
    // ALERT!!! The pointers are not unique neigher controlled anymore

    if(unique_beast)
    {
        unique_beast->printName();
    }
    MemoryBeast* raw_beast2 = unique_beast.release();
    // MemoryBeast* raw_beast3 = unique_beast.get(); ----> this gets null because release

    if(unique_beast)
    {
        unique_beast->printName();
    }
    else{
        std::cout << "unique beast is not valid anymore!\n";
    }
    raw_beast2->printName();

    assert(raw_beast2 == raw_beast && "they are pointing to the same thing!");

    // std::unique_ptr<MemoryBeast> copy_constructor = unique_beast;
    // this doesn't work as it has to be unique so copy doesn't work

    // move the ownership and the original one becomes null
    std::unique_ptr<MemoryBeast> move_constructor = std::move(unique_beast);
    assert(unique_beast == nullptr && " released");

    // EXAMPLE FOR shared ptr
    std::shared_ptr<MemoryBeast> from_unique(std::move(raw_beast));
    std::shared_ptr<MemoryBeast> from_unique_2nd(raw_beast);

    assert(from_unique.get() == raw_beast && "shared and raw are pointing to the same address");
    // delete raw_beast Q: how to remove ptr after initiating a smart ptr?
    from_unique->printName();

    std::shared_ptr<MemoryBeast> common_beast = std::make_shared<MemoryBeast>();
    common_beast->setName("shared");
    std::cout << "count of ref to "  << common_beast->Name() << " is " << common_beast.use_count() << '\n';
    std::shared_ptr<MemoryBeast> s1 = common_beast;

    std::cout << "count of ref to "  << s1->Name() << " is " << s1.use_count() << '\n';
    common_beast.reset();
    std::cout << "count of ref to "  << s1->Name() << " is " << s1.use_count() << '\n';
    if(!common_beast)
    {
        std::cout << "common beast is gone";
    }
    else{
        std::cout << "count of ref to "  << common_beast->Name() << " is " << common_beast.use_count() << '\n';
    }
    // weak ptr https://stackoverflow.com/questions/22185896/what-is-the-cyclic-dependency-issue-with-shared-ptr
    return 0;
}