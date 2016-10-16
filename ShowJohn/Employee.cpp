#include "Employee.h"

void print_employee(employee_t *worker)
{
	printf("Name: %s %s ID: %u, Pay: %.2f\n",
		worker->first_name, worker->last_name,
		worker->employee_number, worker->pay);
}

void new_employee(employee_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay)
{
	obj->first_name = first_name;
	obj->last_name = last_name;
	obj->employee_number = employee_number;
	obj->pay = pay;
	obj->vtable_ = EMPLOYEE_VTABLE_;
}

void print_worker(employee_t *worker)
{
	worker->vtable_->print(worker);
}
