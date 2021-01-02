#include <sanitizer/address/issue/collection.hpp>

#include <iostream>

namespace sanitizer {
namespace address {
namespace issue {

namespace {
int* ptr;
__attribute__((noinline)) void FunctionThatEscapesLocalObject()
{
    int local[100] = {50};
    ptr = &local[0];
}
} // namespace

void Collection::get_heap_use_after_free()
{
    std::cout << "HEAP_USE_AFTER_FREE" << std::endl;
    uint32_t* array = new uint32_t[100];
    delete[] array;
    std::cout << array[55] << std::endl;
    std::cout << "~HEAP_USE_AFTER_FREE" << std::endl;
}

void Collection::get_heap_buffer_overflow()
{
    std::cout << "HEAP_BUFFER_OVERFLOW" << std::endl;
    uint64_t* array = new uint64_t[100];
    array[0] = 0;
    int res = array[1 + 100];
    delete[] array;
    std::cout << res << std::endl;
    std::cout << "~HEAP_BUFFER_OVERFLOW" << std::endl;
}

void Collection::get_stack_buffer_overflow()
{
    std::cout << "STACK_BUFFER_OVERFLOW" << std::endl;
    uint32_t stack_array[100];
    stack_array[1] = 0;
    std::cout << stack_array[1 + 100] << std::endl;
    std::cout << "~STACK_BUFFER_OVERFLOW" << std::endl;
}

void Collection::get_global_buffer_overflow()
{
    std::cout << "GLOBAL_BUFFER_OVERFLOW" << std::endl;
    static uint32_t global_array[100] = {1};
    std::cout << global_array[101] << std::endl;
    std::cout << "~GLOBAL_BUFFER_OVERFLOW" << std::endl;
}

void Collection::get_stack_use_after_return()
{
    std::cout << "STACK_USE_AFTER_RETURN" << std::endl;
    FunctionThatEscapesLocalObject();
    std::cout << ptr[50] << std::endl;
    std::cout << "~STACK_USE_AFTER_RETURN" << std::endl;
}

void Collection::get_stack_use_after_scope()
{
    std::cout << "STACK_USE_AFTER_SCOPE" << std::endl;
    uint32_t* pointer;
    {
        uint32_t local[100] = {3};
        pointer = &local[0];
    }
    std::cout << pointer[50] << std::endl;
    std::cout << "~STACK_USE_AFTER_SCOPE" << std::endl;
}

void Collection::get_memory_leaks()
{
    std::cout << "Memory leaks" << std::endl;
    auto* x = new uint32_t[100];
    x[50] = 500;
    std::cout << x[50] << std::endl;
    std::cout << "~Memory leaks" << std::endl;
}

} // namespace issue
} // namespace address
} // namespace sanitizer
