////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file uni/asan/collection.hpp
/// @brief Declaration of Collection class for address sanitizer issues.
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2020-2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace uni
{
namespace asan
{
class Collection
{
public:
    void get_heap_use_after_free( );
    void get_heap_buffer_overflow( );
    void get_stack_buffer_overflow( );
    void get_global_buffer_overflow( );
    void get_stack_use_after_return( );
    void get_stack_use_after_scope( );
    // TODO https://github.com/google/sanitizers/wiki/AddressSanitizerInitializationOrderFiasco
    // + strict-order
    void get_memory_leaks( );
};

}  // namespace asan
}  // namespace uni
