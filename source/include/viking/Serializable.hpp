#ifndef SERIALIZABLE_HPP_INCLUDED
#define SERIALIZABLE_HPP_INCLUDED

#include <irrlicht/IAttributeExchangingObject.h>

namespace vik
{

// interface for serializable classes
// follows the exact same interface as Irrlicht's serializable class.
// Read its documentation or find uses of it for more information on how to use this.
class Serializable
{
public:
	virtual void serialize(irr::io::IAttributes* out, irr::io::SAttributeReadWriteOptions* options=0) const {}
	virtual void deserialize(irr::io::IAttributes* in, irr::io::SAttributeReadWriteOptions* options=0){}
};

} // end namespace vik

#endif // SERIALIZABLE_HPP_INCLUDED
