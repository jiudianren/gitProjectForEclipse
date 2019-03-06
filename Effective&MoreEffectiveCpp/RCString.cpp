/*
 * RCString.cpp
 *
 *  Created on: 2019年3月6日
 *      Author: Administrator
 */

#include "RCString.h"

String::StringValue::StringValue(const char *initValue)
: refCount(1),shareable(true)
{
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
}
String::StringValue::~StringValue()
{
	delete [] data;
}


String::String(const char *initValue)
: value(new StringValue(initValue))
{}

String::String(const String& rhs)
{
	if (rhs.value->shareable) {
		value = rhs.value;
		++value->refCount;
	}
	else {
		value = new StringValue(rhs.value->data);
	}
}

String& String::operator=(const String& rhs)
{
	if (value == rhs.value) { // do nothing if the values
		return *this; // are already the same; this
	} // subsumes the usual test of
	// this against &rhs (see Item E17)
	if (--value->refCount == 0) { // destroy *this's value if
		delete value; // no one else is using it
	}
	value = rhs.value; // have *this share rhs's
	++value->refCount; // value
	return *this;
}

const char& String::operator[](int index) const
{
	return value->data[index];
}


/*写时拷贝 下面这种实现是有问题的
 *
 * String s1 = "Hello";
char *p = &s1[1];
String s2=s1;
*p='x;
'*/
char& String::operator[](int index)
{
	// if we're sharing a value with other String objects,
	// break off a separate copy of the value for ourselves
	if (value->refCount > 1) {
		--value->refCount; // decrement current value's
		// refCount, because we won't
		// be using that value any more
		value = // make a copy of the
				new StringValue(value->data); // value for ourselves
	}
	// return a reference to a character inside our
	// unshared StringValue object
	return value->data[index];
}

char& String::operator[](int index)
{
	if (value->refCount > 1) {
		--value->refCount;
		value = new StringValue(value->data);
	}
	value->shareable = false; // add this
	return value->data[index];
}


String::~String()
{
	if (--value->refCount == 0) delete value;
}
