/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h" /*Display information in the right way (printf on UNIX...)*/

DeclareEvent(Event1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t2_instance(void)
{
	
	int result_inst_1, result_inst_2;
	
	result_inst_1 = ClearEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_1);
	
	result_inst_2 = WaitEvent(Event1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq7_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence7",NULL,NULL,fixtures);

	return (TestRef)&AlarmsTest;
}
