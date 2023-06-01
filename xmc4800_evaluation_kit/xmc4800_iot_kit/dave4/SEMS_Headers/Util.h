#ifndef UTIL_H_
#define UTIL_H


#include "optiga/optiga_crypt.h"
#include "optiga/optiga_util.h"
#include "optiga_example.h"
#include "optiga/pal/pal_logger.h"

#include "../SEMS_Headers/Config.h"
#include "../SEMS_Headers/Constructor.h"


extern void example_optiga_init(void);
extern void example_optiga_deinit(void);


extern volatile optiga_lib_status_t optiga_lib_status;

#endif
