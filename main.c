/*
 * main.c
 *
 *  Created on: 27-Jan-2016
 *      Author: winston
 */
#include <stdio.h>
#include <stdlib.h>
#include "edf.h"

// Something like a Timer in a Microcontroller
int timer = 0;
float alpha;

int main()
{
	task *t;
	int n, hyper_period, active_task_id;
	float cpu_utilization;
	printf("Enter number of tasks\n");
	scanf("%d", &n);
	t = malloc(n * sizeof(task));
	get_tasks(t, n);

	cpu_utilization = cpu_util(t, n);
	printf("CPU Utilization %f\n", cpu_utilization);

	if (cpu_utilization < 1)
	{
		if (worst_cpu_util_check(t, n) == true)
		{
			printf("Tasks can be scheduled\n");
		}
		else
		{
			printf("Schedule is not feasible (worst case)\n");
			update_alpha_release(t, n, &alpha);
			printf("Alpha: %f", alpha);
			return 0;
		}
	}
	else
	{
		printf("Schedule is not feasible\n");
		return 0;
	}

	hyper_period = hyperperiod_calc(t, n); // calculates lcm of period of all
	copy_execution_time(t, n, ALL);
	update_abs_arrival(t, n, 0, ALL);
	update_abs_deadline(t, n, ALL);
	set_alpha(t, n, &alpha);

	while (timer <= hyper_period)
	{

		if (sp_interrupt(t, timer, n))
		{
			active_task_id = min(t, n, abs_deadline);
		}

		if (active_task_id == IDLE_TASK_ID)
		{
			printf("%d  Idle\n", timer);
		}

		if (active_task_id != IDLE_TASK_ID)
		{

			if (t[active_task_id].T[execution_copy] != 0)
			{
				if (t[active_task_id].T[execution] == t[active_task_id].T[execution_copy])
				{
					update_alpha_release(t, active_task_id, &alpha);
				}
				t[active_task_id].T[execution_copy]--;
				printf("%d  Task %d\n", timer, active_task_id + 1);
			}

			if (t[active_task_id].T[execution_copy] == 0)
			{
				t[active_task_id].instance++;
				t[active_task_id].alive = 0;
				copy_execution_time(t, active_task_id, CURRENT);
				update_abs_arrival(t, active_task_id, t[active_task_id].instance, CURRENT);
				update_abs_deadline(t, active_task_id, CURRENT);
				update_alpha_completion(t, n, active_task_id, &alpha);
				active_task_id = min(t, n, abs_deadline);
			}
		}
		++timer;
	}
	free(t);
	return 0;
}
