#include "../SEMS_Headers/Init.h"
#include "../SEMS_Headers/Constructor.h"

#include "../SEMS_Headers/Util.h"
#include "../SEMS_Headers/Timer.h"

void init_SEMS(void)
{
	example_optiga_init_true();
	start_cooldown_timer();
}
