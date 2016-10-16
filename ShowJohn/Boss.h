#ifndef BOSS_H
#define BOSS_H

#include <cstdio>
#include "Employee.h"


typedef struct boss_s
{
	employee_t base;
	employee_t *underlings;
	unsigned int underling_count;
}boss_t;
const employee_vtable_ BOSS_VTABLE_[] = { { print_boss } };

void new_boss(boss_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay, employee_t *underlings,
	unsigned int underling_count);
void print_boss(employee_t *worker_temp);



#endif
