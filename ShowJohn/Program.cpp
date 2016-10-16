#include <cstdio>
#include <cstdlib>

#include "Boss.h"
#include "Employee.h"

int main(int argc, char *argv[])
{
	employee_t *employees = (employee_t *)malloc(sizeof(employee_t) * 3);
	new_employee(&employees[0], "Adolf", "Hitler", 1, 10.0f);
	new_employee(&employees[1], "Stalin", "", 1, 69.0f);
	new_employee(&employees[2], "John", "West", 1, 1337.0f);

	boss_t *boss = (boss_t *)malloc(sizeof(boss_t));
	new_boss(boss, "Russian", "Bear", 0, 166800.0f, employees, 3);

	print_worker((employee_t *)boss);

	getchar();
	free(employees);
	free(boss);
	return EXIT_SUCCESS;
}





