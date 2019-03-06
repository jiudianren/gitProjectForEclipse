/*
 * RCObject.h
 *
 *  Created on: 2019Äê3ÔÂ6ÈÕ
 *      Author: Administrator
 */

#ifndef EFFECTIVE_MOREEFFECTIVECPP_RCOBJECT_H_
#define EFFECTIVE_MOREEFFECTIVECPP_RCOBJECT_H_

class RCObject
{
public:
	RCObject(): refCount(0), shareable(true) {}
	RCObject(const RCObject&)
	: refCount(0), shareable(true) {}
	RCObject& RCObject::operator=(const RCObject&)
	{ return *this; }
	RCObject::~RCObject() {} // virtual dtors must always
	// be implemented, even if
	// they are pure virtual
	// and do nothing (see also
	// Item M33 and Item E14)
	void RCObject::addReference() { ++refCount; }
	void RCObject::removeReference()
	{ if (--refCount == 0) delete this; }
	void RCObject::markUnshareable()
	{ shareable = false; }
	bool RCObject::isShareable() const
	{ return shareable; }
	bool RCObject::isShared() const
	{ return refCount > 1; }
public:
	int refCount;
	bool shareable;
};

#endif /* EFFECTIVE_MOREEFFECTIVECPP_RCOBJECT_H_ */
