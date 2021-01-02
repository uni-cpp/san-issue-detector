#include <sanitizer/address/issue/collection.hpp>
#include <sanitizer/undefined/issue/collection.hpp>

int main()
{
    sanitizer::address::issue::Collection asan_collection;
    asan_collection.get_heap_use_after_free();
    asan_collection.get_heap_buffer_overflow();
    asan_collection.get_stack_buffer_overflow();
    asan_collection.get_global_buffer_overflow();
    asan_collection.get_stack_use_after_return();
    asan_collection.get_stack_use_after_scope();
    asan_collection.get_memory_leaks();

    sanitizer::undefined::issue::Collection ub_collection;
    ub_collection.get_signed_integer_overflow();
    ub_collection.get_misaligned_pointer();
    ub_collection.get_invalid_boolean();
    ub_collection.get_out_of_bounds_array();
    ub_collection.get_invalid_enumeration();
    ub_collection.get_dynamic_type_violation();
    ub_collection.get_invalid_float_cast();
    // ub_collection.get_division_by_zero();
    // ub_collection.get_nullptr_violation();
    ub_collection.get_invalid_object_size();

    return 0;
}
