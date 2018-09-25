#include <catch2/catch.hpp>

#include "Calculator.hpp"

namespace
{

TEST_CASE( "Additions are computed", "[add]" )
{
    REQUIRE( foo::Calculator::add( 1, 2 ) == 3 );
    REQUIRE( foo::Calculator::add( 2, 1 ) == 3 );
    REQUIRE( foo::Calculator::add( 0, 3 ) == 3 );
    REQUIRE( foo::Calculator::add( 3, -3 ) == 0 );
    REQUIRE( foo::Calculator::add( -3, 3 ) == 0 );
    REQUIRE( foo::Calculator::add( -3, -3 ) == -6 );
}

TEST_CASE( "Subtractions are computed", "[sub]" )
{
    REQUIRE( foo::Calculator::sub( 2, 2 ) == 0 );
    REQUIRE( foo::Calculator::sub( 2, 0 ) == 2 );
    REQUIRE( foo::Calculator::sub( 0, 2 ) == -2 );
    REQUIRE( foo::Calculator::sub( -2, 2 ) == -4 );
    REQUIRE( foo::Calculator::sub( 2, -2 ) == 4 );
}

} // namespace
