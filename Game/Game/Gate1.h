#pragma once
#include "GObject.h"
class Gate1 :
	public GObject
{
public:
	void onInterserct(GObject* other);
	Gate1();
	~Gate1();
};

