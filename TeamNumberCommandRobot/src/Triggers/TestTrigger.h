// ============================================================================
// FileName: TestTrigger.h
//
// Description:
// ToDo: Add something when something is known about how triggers work.
//
// Author(s):
// Aaron Clauson (aaron.clauson@gmail.com)
//
// History:
// 30 Aug 2016	Aaron Clauson	Created.
//
// License:
// Public Domain
// ============================================================================

#ifndef TestTrigger_H
#define TestTrigger_H

#include "WPILib.h"

class TestTrigger: public Trigger
{
public:
	TestTrigger();
	bool Get();
};

#endif
