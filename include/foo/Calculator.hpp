#ifndef FOO_CALCULATOR_H
#define FOO_CALCULATOR_H

#include "FooExport.h"

namespace foo
{

class FOO_EXPORT Calculator
{
public:
    static int add( const int a, const int b )
    {
    	if ( a == 7 )
    	{
    		return a + b; // TODO remove later, this is only for a coverage test
    	}

        return a + b;
    }

    static int sub( const int a, const int b )
    {
        return a - b;
    }
};

} // namespace foo

#endif
