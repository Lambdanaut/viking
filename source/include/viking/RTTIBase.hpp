#ifndef RTTIBASE_HPP_INCLUDED
#define RTTIBASE_HPP_INCLUDED

#include "viking/HashedString.hpp"

namespace vik
{

// interface to provide RunTime Type Information
class RTTIBase
{
public:
	virtual HashedString getTypeInfo() const = 0;
};

}

#endif // RTTIBASE_HPP_INCLUDED
