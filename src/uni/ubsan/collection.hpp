////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file uni/ubsan/collection.hpp
/// @brief Declaration of Collection class for undefined behavior sanitizer issues.
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2020-2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace uni
{
namespace ubsan
{
class Collection
{
public:
    void get_signed_integer_overflow( );
    void get_misaligned_pointer( );
    void get_invalid_boolean( );
    void get_out_of_bounds_array( );
    void get_invalid_enumeration( );
    void get_dynamic_type_violation( );
    void get_invalid_float_cast( );
    void get_division_by_zero( );
    void get_nullptr_violation( );
    void get_invalid_object_size( );
};

}  // namespace ubsan
}  // namespace uni
