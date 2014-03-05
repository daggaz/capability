/*
 * IChangeAtParameters.cpp
 *
 *  Created on: 5 Mar 2014
 *      Author: jcockburn
 */

#include "IChangeAtParameters.h"

ChangeAt::ChangeAt(ChangeAt::CHANGE_AT event) : event(event)
{
}

ChangeAt::CHANGE_AT ChangeAt::getEvent() const
{
	return event;
}


const string ChangeAt::toString() const
{
	switch (event)
	{
	case END_OF_BAR:
		return "End of bar";
	case END_OF_FRAME:
			return "End of frame";
	case IMMEDIATE:
			return "Immediately";
	}
	return "Unknown!";
}
