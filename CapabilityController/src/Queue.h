/*
 * Queue.h
 *
 *  Created on: 24 Feb 2014
 *      Author: jcockburn
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <windows.h>
#include <deque>
#include <climits>

using namespace std;


template <typename T> class Queue{
    CRITICAL_SECTION access;
    deque<T> *objectQueue;
    HANDLE queueSema;
public:
    Queue() {
        objectQueue = new deque<T>;
        InitializeCriticalSection(&access);
        queueSema = CreateSemaphore(NULL, 0, INT_MAX, NULL);
    };
    void push(T ref){
        EnterCriticalSection(&access);
        objectQueue->push_front(ref);
        LeaveCriticalSection(&access);
        ReleaseSemaphore(queueSema,1,NULL);
    };
    T pop() {
    	WaitForSingleObject(queueSema, INFINITE);
		EnterCriticalSection(&access);
		T object = objectQueue->back();
		objectQueue->pop_back();
		LeaveCriticalSection(&access);
		return object;
    };
};
#endif /* QUEUE_H_ */
