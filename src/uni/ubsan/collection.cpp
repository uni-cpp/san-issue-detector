#include <iostream>
#include <limits>
#include <vector>

#include <uni/ubsan/collection.hpp>

namespace uni
{
namespace ubsan
{
namespace
{
struct Base
{
    int32_t pad1;
};
struct Derived : Base
{
    int32_t pad2;
};
Derived*
get_derived( )
{
    return static_cast< Derived* >( new Base );
}
}  // namespace

void
Collection::get_signed_integer_overflow( )
{
    std::cout << "Signed integer overflow" << std::endl;
    auto k = std::numeric_limits< int32_t >::max( );
    ++k;
    std::cout << "~Signed integer overflow" << std::endl;
}

void
Collection::get_misaligned_pointer( )
{
    std::cout << "Misaligned integer pointer assignment" << std::endl;
    {
        auto buffer = static_cast< int8_t* >( malloc( 8 * 8 ) );
        int32_t* pointer = ( int32_t* ) ( buffer + 1 );
        *pointer = 42;
        delete buffer;
    }
    std::cout << "~Misaligned integer pointer assignment" << std::endl;

    std::cout << "Misaligned structure pointer assignment" << std::endl;
    struct A
    {
        int32_t i32;
        int64_t i64;
    };
    auto buffer = static_cast< int8_t* >( malloc( 8 * 4 ) );
    auto pointer = reinterpret_cast< struct A* >( buffer + 1 );
    pointer->i32 = 7;
    std::cout << "~Misaligned structure pointer assignment" << std::endl;
}

void
Collection::get_invalid_boolean( )
{
    std::cout << "Invalid boolean" << std::endl;
    int32_t result = 2;
    auto predicate = ( bool* ) &result;
    if( *predicate )
    {
        std::cout << result << " after cast is true" << std::endl;
    }
    else
    {
        std::cout << result << " after cast is false" << std::endl;
    }
    std::cout << "~Invalid boolean" << std::endl;
}

void
Collection::get_out_of_bounds_array( )
{
    std::cout << "Out of bounds array" << std::endl;
    int32_t array[ 5 ] = { 1 };
    for( int32_t i{ 0 }; i <= 5; ++i )
    {
        array[ i ] += 1;
    }
    std::cout << "~Out of bounds array" << std::endl;
}

void
Collection::get_invalid_enumeration( )
{
    std::cout << "Invalid enum" << std::endl;
    enum E
    {
        a = 1,
    };
    int value = 2;
    auto e = ( enum E* ) &value;
    std::cout << "Enum after cast " << *e << std::endl;
    std::cout << "~Invalid enum" << std::endl;
}

void
Collection::get_dynamic_type_violation( )
{
    std::cout << "Dynamic type violation" << std::endl;
    struct Animal
    {
        virtual const char* speak( ) = 0;
        virtual ~Animal( ) = default;
    };

    struct Cat : public Animal
    {
        const char*
        speak( ) override
        {
            return "meow";
        }
    };

    struct Dog : public Animal
    {
        const char*
        speak( ) override
        {
            return "woof";
        }
    };
    auto* dog = reinterpret_cast< Dog* >( new Cat );  // Error: dog has incorrect dynamic type
    std::cout << dog->speak( ) << std::endl;          // Error: this call has undefined behavior
    delete dog;
    std::cout << "~Dynamic type violation" << std::endl;
}

void
Collection::get_invalid_float_cast( )
{
    std::cout << "Invalid float cast" << std::endl;
    double n = 10e50;
    auto m = ( float ) n;  // Error: 10e50 can't be represented as a float.
    std::cout << n << " <-double   float-> " << m << std::endl;
    std::cout << "~Invalid float cast" << std::endl;
}

void
Collection::get_division_by_zero( )
{
    std::cout << "Division by zero" << std::endl;
    int32_t sum = 10;
    for( int32_t i{ 0 }; i < 64; ++i )
    {
        sum /= i;
    }
    std::cout << sum << std::endl;
    std::cout << "~Division by zero" << std::endl;
}

void
Collection::get_nullptr_violation( )
{
    std::cout << "Nullptr violation" << std::endl;
    std::vector< uint32_t >* x{ nullptr };
    x->clear( );
    std::cout << "~Nullptr violation" << std::endl;
}

void
Collection::get_invalid_object_size( )
{
    // Increase optimize level
    std::cout << "Invalid object size" << std::endl;

    auto x = get_derived( );
    delete x;

    std::cout << "~Invalid object size" << std::endl;
}

}  // namespace ubsan
}  // namespace uni
