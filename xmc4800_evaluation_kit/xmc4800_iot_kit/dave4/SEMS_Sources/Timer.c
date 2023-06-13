#include "../SEMS_Headers/Timer.h"
#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Util.h"


extern volatile uint8_t failed_req;
extern volatile uint8_t cooldowned;


void start_cooldown_timer(void)
{
	uint32_t timeout = TIMEOUT_IN_SECONDS * 100u * 1000u * 1000u ;
	TIMER_SetTimeInterval(&TIMER_Cooldwon, timeout);
	TIMER_Start(&TIMER_Cooldwon);
}


void TimerInterval_ISR(void)
{
	if(failed_req > 0u)
	{
		failed_req--;

		if(failed_req == 0)
		{
			cooldowned = false;
		}
	}

}
