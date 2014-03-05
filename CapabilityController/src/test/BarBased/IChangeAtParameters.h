/*
 * IChangeAtParameters.h
 *
 *  Created on: 5 Mar 2014
 *      Author: jcockburn
 */

#ifndef ICHANGEATPARAMETERS_H_
#define ICHANGEATPARAMETERS_H_

#include <string>

using namespace std;


class ChangeAt
{
public:
	enum CHANGE_AT {
		END_OF_BAR,
		END_OF_FRAME,
		IMMEDIATE,
	};
private:
	const CHANGE_AT event;
public:
	ChangeAt(CHANGE_AT event);
	const string toString() const;
	CHANGE_AT getEvent() const;
};

class IChangeAtParameters {
public:
	virtual const ChangeAt& getChangeAt() const = 0;
};

#endif /* ICHANGEATPARAMETERS_H_ */
