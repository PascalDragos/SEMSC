#include "../SEMS_Headers/Init.h"
#include "../SEMS_Headers/Constructor.h"

#include "../SEMS_Headers/Util.h"
#include "../SEMS_Headers/Timer.h"
#include "../SEMS_Headers/SecNvM.h"


void init_SEMS(void)
{
	// Init communication with Optiga
	example_optiga_init_true();

	// Start timer for cooldown
	start_cooldown_timer();

	// Read from SecNvM
	read_sec_config();

}
