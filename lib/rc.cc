#include <rc.hh>

using rc::body_t;
body_t::body_t()
	: refCount(0), shareable(true) 
{
}
 
body_t::body_t(const body_t&)
	: refCount(0), shareable(true) 
{
}
 
body_t& body_t::operator=(const body_t&)
{
	return *this;
}  
 
body_t::~body_t()
{
}
 
void body_t::addReference() 
{
	++refCount;
}
 
void body_t::removeReference()
{
	if (--refCount == 0)
		delete this;
}
 
void body_t::markUnshareable()
{
	shareable = false;
}
 
bool body_t::isShareable() const
{
	return shareable;
}

bool body_t::isShared() const
{
	return refCount > 1;
}  
