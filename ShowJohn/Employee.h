#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <cstdio>

struct employee_s;
struct employee_vtable_s;
typedef employee_s employee_t;
typedef employee_vtable_s employee_vtable_;

struct employee_s
{
	const char *first_name;
	const char *last_name;
	unsigned int employee_number;
	double pay;
	const employee_vtable_ *vtable_;
};

struct employee_vtable_s
{
	void(*print)(employee_t *);
};
const employee_vtable_ EMPLOYEE_VTABLE_[] = { print_employee };

void new_employee(employee_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay);
void print_employee(employee_t *worker);
void print_worker(employee_t *worker);



#endif