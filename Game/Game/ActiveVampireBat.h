#pragma once
#include "GObject.h"
class ActiveVampireBat :
	public GObject
{
public:
	void onInterserct(GObject* other);
	ActiveVampireBat();
	~ActiveVampireBat();
};

