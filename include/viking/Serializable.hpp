#ifndef SERIALIZABLE_HPP_INCLUDED
#define SERIALIZABLE_HPP_INCLUDED

#include <irrlicht/IAttributeExchangingObject.h>

namespace vik
{

// interface for serializable classes
class Serializable
{
public:
	virtual void serialize(irr::io::IAttributes* out, irr::io::SAttributeReadWriteOptions* options=0) const {}
	virtual void deserialize(irr::io::IAttributes* in, irr::io::SAttributeReadWriteOptions* options=0){}
};

} // end namespace vik

#endif // SERIALIZABLE_HPP_INCLUDED
