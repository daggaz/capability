#include "../CapabilityController.h"
#include "../SimpleCommandFactory.h"
#include "TestStrategyControllable.h"
#include "TestStrategyCommand.h"
#include "TestCapability.h"
#include "TestStrategyChangeParameters.h"
#include "BarBased/BarBased.h"
#include "BarBased/IChangeAtParameters.h"

int main(int argc, char **argv) {
	vector<const Row*> table;

	CapabilityController controller(table);

	TestStrategyControllable RRM("RRM");
	BarBased TWS("TWS");
	TestStrategyControllable CAL("CAL");
	TestStrategyControllable CS("CS");

	RRM.start();
	CAL.start();
	TWS.start();
	CS.start();

	map<const ICapability*, const IStrategyCommandFactory*> tws_capabilites;

	TestStrategyCommand shutdown_command("Shutdown");
	SimpleCommandFactory shutdown_factory(shutdown_command);

	TestStrategyCommand tws_a_command("TWS to A!");
	SimpleCommandFactory tws_a_factory(tws_a_command);
	tws_capabilites[&TestCapability::A] = &tws_a_factory;
	TestStrategyCommand tws_b_command("TWS to B!");
	SimpleCommandFactory tws_b_factory(tws_b_command);
	tws_capabilites[&TestCapability::B] = &tws_b_factory;
	tws_capabilites[&TestCapability::Shutdown] = &shutdown_factory;
	vector<const IStrategyControllable*> tws_prereqs;
	tws_prereqs.push_back(&RRM);
	tws_prereqs.push_back(&CAL);
	Row tws_row(TWS, tws_capabilites, tws_prereqs);
	table.push_back(&tws_row);

	map<const ICapability*, const IStrategyCommandFactory*> cal_capabilites;
	TestStrategyCommand cal_a_command("CAL to A!");
	SimpleCommandFactory cal_a_factory(cal_a_command);
	cal_capabilites[&TestCapability::A] = &cal_a_factory;
	TestStrategyCommand cal_b_command("CAL to B!");
	SimpleCommandFactory cal_b_factory(cal_b_command);
	cal_capabilites[&TestCapability::B] = &cal_b_factory;
	cal_capabilites[&TestCapability::Shutdown] = &shutdown_factory;
	vector<const IStrategyControllable*> cal_prereqs;
	cal_prereqs.push_back(&RRM);
	Row cal_row(CAL, cal_capabilites, cal_prereqs);
	table.push_back(&cal_row);

	map<const ICapability*, const IStrategyCommandFactory*> cs_capabilites;
	TestStrategyCommand cs_a_command("CS to A!");
	SimpleCommandFactory cs_a_factory(cs_a_command);
	cs_capabilites[&TestCapability::A] = &cs_a_factory;
	TestStrategyCommand cs_b_command("CS to B!");
	SimpleCommandFactory cs_b_factory(cs_b_command);
	cs_capabilites[&TestCapability::B] = &cs_b_factory;
	cs_capabilites[&TestCapability::Shutdown] = &shutdown_factory;
	vector<const IStrategyControllable*> cs_prereqs;
	cs_prereqs.push_back(&RRM);
	cs_prereqs.push_back(&CAL);
	Row cs_row(CS, cs_capabilites, cs_prereqs);
	table.push_back(&cs_row);

	map<const ICapability*, const IStrategyCommandFactory*> rrm_capabilites;
	TestStrategyCommand rrm_a_command("RRM to A!");
	SimpleCommandFactory rrm_a_factory(rrm_a_command);
	rrm_capabilites[&TestCapability::A] = &rrm_a_factory;
	TestStrategyCommand rrm_b_command("RRM to B!");
	SimpleCommandFactory rrm_b_factory(rrm_b_command);
	rrm_capabilites[&TestCapability::B] = &rrm_b_factory;
	rrm_capabilites[&TestCapability::Shutdown] = &shutdown_factory;
	vector<const IStrategyControllable*> rrm_prereqs;
	Row rrm_row(RRM, rrm_capabilites, rrm_prereqs);
	table.push_back(&rrm_row);

	Thread::sleep(500);

	ChangeAt change_at_bar(ChangeAt::END_OF_BAR);
	TestStrategyChangeParameters params_bar(change_at_bar);
	cout << endl << "**********************" << endl;
	cout << "main: Asking for change to Capability A at end of bar" << endl;
	controller.changeCapability(TestCapability::A, params_bar);

	ChangeAt change_at_frame(ChangeAt::END_OF_FRAME);
	TestStrategyChangeParameters params_frame(change_at_frame);
	cout << endl << "**********************" << endl;
	cout << "main: Asking for change to Capability B at end of frame" << endl;
	controller.changeCapability(TestCapability::B, params_frame);

	ChangeAt change_at_now(ChangeAt::IMMEDIATE);
	TestStrategyChangeParameters params_now(change_at_now);
	cout << endl << "**********************" << endl;
	cout << "main: Asking for immediate shutdown" << endl;
	controller.changeCapability(TestCapability::Shutdown, params_now);

	RRM.join();
	CAL.join();
	TWS.join();
	CS.join();
}

