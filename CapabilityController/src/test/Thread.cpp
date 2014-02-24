/*
 * Thread.cpp
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#include "Thread.h"

unsigned __stdcall Thread::ThreadEntry(void* thread) {
	((Thread*)thread)->run();
	return 0;
}

Thread::Thread() {

    thread = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        ThreadEntry,       // thread function name
        this,          // argument to thread function
        CREATE_SUSPENDED,       // use default creation flags
        &id);   // returns the thread identifier
}

void Thread::start() {
	ResumeThread(thread);
}

void Thread::join() {
	WaitForSingleObject(thread, INFINITE);
}

void Thread::sleep(DWORD millies) {
	Sleep(millies);
}
