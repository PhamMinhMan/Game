#include "ActiveVampireBat.h"
#include "Simon.h"
#include "Vampire_Bat.h"


void ActiveVampireBat::onInterserct(GObject * other)
{
	Vampire_Bat::instance->setActive(true);
}

ActiveVampireBat::ActiveVampireBat()
{
	curFrame = 0;
	objectFilter = CF_ActiveVampireBat;
}


ActiveVampireBat::~ActiveVampireBat()
{
}
