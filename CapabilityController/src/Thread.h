/*
 * Thread.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <windows.h>

class Thread {
	HANDLE thread;
	DWORD id;

	static unsigned __stdcall ThreadEntry(void* thread);
public:
	Thread();
	void start();
	void join();
	static void sleep(DWORD millies);
	virtual void run() = 0;
};

#endif /* THREAD_H_ */
