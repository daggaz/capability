#include "../CapabilityController.h"
#include "../SimpleCommandFactory.h"
#include "TestStrategyControllable.h"
#include "TestStrategyCommand.h"
#include "TestCapability.h"
#include "TestStrategyChangeParameters.h"

int main(int argc, char **argv) {
	vector<const Row*> table;

	CapabilityController controller(table);

	TestStrategyControllable RRM("RRM");
	TestStrategyControllable TWS("TWS");
	TestStrategyControllable CAL("CAL");
	TestStrategyControllable CS("CS");

	RRM.start();
	CAL.start();
	TWS.start();
	CS.start();

	TestCapability A("A");
	TestCapability B("B");
	TestCapability C("C");

	map<const ICapability*, const IStrategyCommandFactory*> tws_capabilites;
	TestStrategyCommand tws_a_command("TWS to A!");
	SimpleCommandFactory tws_a_factory(tws_a_command);
	tws_capabilites[&A] = &tws_a_factory;
	TestStrategyCommand tws_b_command("TWS to B!");
	SimpleCommandFactory tws_b_factory(tws_b_command);
	tws_capabilites[&B] = &tws_b_factory;
	TestStrategyCommand tws_c_command("TWS to C!");
	SimpleCommandFactory tws_c_factory(tws_c_command);
	tws_capabilites[&C] = &tws_c_factory;
	vector<const IStrategyControllable*> tws_prereqs;
	tws_prereqs.push_back(&RRM);
	tws_prereqs.push_back(&CAL);
	Row tws_row(TWS, tws_capabilites, tws_prereqs);
	table.push_back(&tws_row);

	map<const ICapability*, const IStrategyCommandFactory*> cal_capabilites;
	TestStrategyCommand cal_a_command("CAL to A!");
	SimpleCommandFactory cal_a_factory(cal_a_command);
	cal_capabilites[&A] = &cal_a_factory;
	TestStrategyCommand cal_b_command("CAL to B!");
	SimpleCommandFactory cal_b_factory(cal_b_command);
	cal_capabilites[&B] = &cal_b_factory;
	TestStrategyCommand cal_c_command("CAL to C!");
	SimpleCommandFactory cal_c_factory(cal_c_command);
	cal_capabilites[&C] = &cal_c_factory;
	vector<const IStrategyControllable*> cal_prereqs;
	cal_prereqs.push_back(&RRM);
	Row cal_row(CAL, cal_capabilites, cal_prereqs);
	table.push_back(&cal_row);

	map<const ICapability*, const IStrategyCommandFactory*> cs_capabilites;
	TestStrategyCommand cs_a_command("CS to A!");
	SimpleCommandFactory cs_a_factory(cs_a_command);
	cs_capabilites[&A] = &cs_a_factory;
	TestStrategyCommand cs_b_command("CS to B!");
	SimpleCommandFactory cs_b_factory(cs_b_command);
	cs_capabilites[&B] = &cs_b_factory;
	TestStrategyCommand cs_c_command("CS to C!");
	SimpleCommandFactory cs_c_factory(cs_c_command);
	cs_capabilites[&C] = &cs_c_factory;
	vector<const IStrategyControllable*> cs_prereqs;
	cs_prereqs.push_back(&RRM);
	cs_prereqs.push_back(&CAL);
	Row cs_row(CS, cs_capabilites, cs_prereqs);
	table.push_back(&cs_row);

	map<const ICapability*, const IStrategyCommandFactory*> rrm_capabilites;
	TestStrategyCommand rrm_a_command("RRM to A!");
	SimpleCommandFactory rrm_a_factory(rrm_a_command);
	rrm_capabilites[&A] = &rrm_a_factory;
	TestStrategyCommand rrm_b_command("RRM to B!");
	SimpleCommandFactory rrm_b_factory(rrm_b_command);
	rrm_capabilites[&B] = &rrm_b_factory;
	TestStrategyCommand rrm_c_command("RRM to C!");
	SimpleCommandFactory rrm_c_factory(rrm_c_command);
	rrm_capabilites[&C] = &rrm_c_factory;
	vector<const IStrategyControllable*> rrm_prereqs;
	Row rrm_row(RRM, rrm_capabilites, rrm_prereqs);
	table.push_back(&rrm_row);

	TestStrategyChangeParameters params;

	Thread::sleep(500);

	cout << endl << "**********************" << endl;
	controller.changeCapability(A, params);

	cout << endl << "**********************" << endl;
	controller.changeCapability(B, params);

	RRM.join();
	CAL.join();
	TWS.join();
	CS.join();
}

