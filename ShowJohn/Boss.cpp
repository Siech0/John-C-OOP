#include "Boss.h"

/*
void print_boss(employee_t *worker_temp)
{
	unsigned int i;
	boss_t *worker = (boss_t *)worker_temp;

	printf("Name: %s %s ID: %u, Pay: %.2f\nUnderlings: %u\n\nUnderlings:\n",
		worker->base.first_name, worker->base.last_name,
		worker->base.employee_number, worker->base.pay,
		worker->underling_count);
	for (i = 0; i < worker->underling_count; ++i)
	{
		fputs("\t", stdout);
		worker->underlings[i].vtable_->print((worker->underlings + i));
	}
}

void new_boss(boss_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay, employee_t *underlings,
	unsigned int underling_count)
{
	new_employee(&obj->base, first_name, last_name, employee_number, pay);
	obj->underlings = underlings;
	obj->underling_count = underling_count;
	obj->base.vtable_ = BOSS_VTABLE_;
}
*/