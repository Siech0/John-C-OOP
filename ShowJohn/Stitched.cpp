#include <stdio.h>
#include <stdlib.h>


struct employee_s;
struct boss_s;
struct employee_vtable_s;

typedef employee_s employee_t;
typedef boss_s boss_t;
typedef employee_vtable_s employee_vtable_;


struct employee_vtable_s
{
	void(*print)(employee_t *);
};

struct employee_s
{
	const char *first_name;
	const char *last_name;
	unsigned int employee_number;
	double pay;
	const employee_vtable_ *vtable_;
};
const employee_vtable_ EMPLOYEE_VTABLE_[] = { {print_employee } };


typedef struct boss_s
{
	employee_t base;
	employee_t *underlings;
	unsigned int underling_count;
}boss_t;
const employee_vtable_ BOSS_VTABLE_[] = {{ print_boss }};


void new_employee(employee_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay);
void print_employee(employee_t *worker);
void print_worker(employee_t *worker);


void new_boss(boss_t *obj, const char *first_name, const char *last_name,
	unsigned int employee_number, double pay, employee_t *underlings,
	unsigned int underling_count);
void print_boss(employee_t *worker_temp);
//END DEFINITIONS


int main(int argc, char *argv[])
{
	employee_t *employees = (employee_t *)malloc(sizeof(employee_t) * 3);
	if (employees == NULL)
		return 1;
	new_employee(&employees[0], "Alex", "German", 1, 10.0f);
	new_employee(&employees[1], "Dolan", "the Duck", 1, 69.0f);
	new_employee(&employees[2], "John", "TotallyHisLastName", 1, 1337.0f);

	boss_t *boss = (boss_t *)malloc(sizeof(boss_t));
	if (boss == NULL)
		return 1;
	new_boss(boss, "Russian", "Bear", 0, 1668000.0f, employees, 3);

	print_worker((employee_t *)boss);
	puts("\n\n");
	print_worker(&employees[0]);

	getchar();
	free(employees);
	free(boss);
	return 0;
}


//end main
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
