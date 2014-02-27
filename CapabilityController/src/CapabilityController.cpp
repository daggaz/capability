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

CapabilityController::CapabilityController(const vector<const Row*>& table) : AbstractCapabilityController(table) {
}

void CapabilityController::changeCapability(const ICapability& capability, const IStrategyChangeParameters& params) {
	vector<const Row*> unrequested(table), requested, completed;
	cout << "Changing to capability " << capability.toString() << endl;
	while (!unrequested.empty() || !requested.empty()) {
		vector<const Row*> temp_vector(unrequested);
		for(vector<const Row*>::const_iterator row_it = temp_vector.begin(); row_it != temp_vector.end(); ++row_it) {
			const Row* row = *row_it;
			// Search for prerequisites
			vector<const IStrategyControllable*> unsatified;
			for (vector<const IStrategyControllable*>::const_iterator prerequisite_it = row->prerequisists.begin(); prerequisite_it != row->prerequisists.end(); ++prerequisite_it) {
				bool found = false;
				const IStrategyControllable* prerequisite = *prerequisite_it;
				for (vector<const Row*>::const_iterator completed_it = completed.begin(); completed_it != completed.end(); ++completed_it) {
					const Row* complete = *completed_it;
					if (&(complete->receiver) == prerequisite)
						found = true;
				}
				if (!found)
					unsatified.push_back(prerequisite);
			}

			// If unsatisfied
			if (!unsatified.empty()) {
				cout << "leaving " << row->receiver.toString() << " as prerequisites ";
				for (vector<const IStrategyControllable*>::const_iterator unsatisfied_it = unsatified.begin(); unsatisfied_it != unsatified.end(); ++unsatisfied_it)
					cout << (*unsatisfied_it)->toString() << ", ";
				cout << "not satisfied" << endl;

			// If satisfied
			} else {
				unrequested.erase(remove(unrequested.begin(), unrequested.end(), row), unrequested.end());
				requested.push_back(row);
				const IStrategyCommandFactory* factory = row->capabilites.at(&capability);
				const IStrategyCommand& command = factory->getCommand(*currentCapabilty, capability, params);
				row->receiver.changeStrategy(command, params, row, queue);
			}
		}

		const Row* complete = queue.pop();

		requested.erase(remove(requested.begin(), requested.end(), complete), requested.end());
		completed.push_back(complete);
	}
	currentCapabilty = &capability;
	cout << "Capability changed to " << capability.toString() << endl;
}
