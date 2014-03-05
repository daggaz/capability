//============================================================================
// Name        : CapabilityController.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CapabilityController.h"
#include <iostream>
#include <algorithm>
#include "Thread.h"

CapabilityController::CapabilityController(const vector<const Row*>& table) : AbstractCapabilityController(table) {
}

void CapabilityController::changeCapability(const ICapability& capability, const IStrategyChangeParameters& params) {
	vector<const Row*> unrequested(table), requested, completed;
	cout << "CCF: Changing to capability " << capability.toString() << endl;
	while (!unrequested.empty() || !requested.empty()) {
		vector<const Row*> temp_vector(unrequested);
		for(vector<const Row*>::const_iterator row_it = temp_vector.begin(); row_it != temp_vector.end(); ++row_it) {
			const Row* row = *row_it;

			// Search for prerequisites
			vector<const IStrategyControllable*> unsatified;

			// Check if this row is mentioned in any unrequested row
			for (vector<const Row*>::const_iterator unrequested_it = unrequested.begin(); unrequested_it != unrequested.end(); ++unrequested_it) {
				bool found = false;
				const Row* unrequested_row = *unrequested_it;
				for (vector<const IStrategyControllable*>::const_iterator prerequisite_it = unrequested_row->prerequisists.begin(); prerequisite_it != unrequested_row->prerequisists.end(); ++prerequisite_it) {
					const IStrategyControllable* prerequisite = *prerequisite_it;
					if (&(row->receiver) == prerequisite)
						found = true;
				}
				if (found)
					unsatified.push_back(&unrequested_row->receiver);
			}

			// Check if this row is mentioned in any requested row
			for (vector<const Row*>::const_iterator requested_it = requested.begin(); requested_it != requested.end(); ++requested_it) {
				bool found = false;
				const Row* requested_row = *requested_it;
				for (vector<const IStrategyControllable*>::const_iterator prerequisite_it = requested_row->prerequisists.begin(); prerequisite_it != requested_row->prerequisists.end(); ++prerequisite_it) {
					const IStrategyControllable* prerequisite = *prerequisite_it;
					if (&(row->receiver) == prerequisite)
						found = true;
				}
				if (found)
					unsatified.push_back(&requested_row->receiver);
			}

			// If this row is not mentioned in either unrequested or requested, then we can proceed
			if (unsatified.empty()) {
				cout << "CCF: sending changeStrategy to " << row->receiver.toString() << endl;
				unrequested.erase(remove(unrequested.begin(), unrequested.end(), row), unrequested.end());
				requested.push_back(row);
				const IStrategyCommandFactory* factory = row->capabilites.at(&capability);
				const IStrategyCommand& command = factory->getCommand(*currentCapabilty, capability, params);
				row->receiver.changeStrategy(command, params, row, queue);
			} else {
				cout << "CCF: leaving " << row->receiver.toString() << " as prerequisites ";
				for (vector<const IStrategyControllable*>::const_iterator unsatisfied_it = unsatified.begin(); unsatisfied_it != unsatified.end(); ++unsatisfied_it)
					cout << (*unsatisfied_it)->toString() << ", ";
				cout << "not satisfied" << endl;
			}
			Thread::sleep(100); // Have a little sleep to de-interlace output
		}

		const Row* complete = queue.pop();

		requested.erase(remove(requested.begin(), requested.end(), complete), requested.end());
		completed.push_back(complete);
	}
	currentCapabilty = &capability;
	cout << "CCF: Capability changed to " << capability.toString() << endl;
}
