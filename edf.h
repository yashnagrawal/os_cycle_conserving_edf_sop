#define arrival 0
#define execution 1
#define deadline 2
#define period 3
#define abs_arrival 4
#define execution_copy 5
#define abs_deadline 6
#define alpha_task 7
#define false 0
#define true 1

// stucture of a task
typedef struct
{
	int T[8], instance, alive;
	/*
			These task parameters are given by the user
			T[0] == T[arrival]  			(Arrival time)
			T[1] == T[execution]			(Execution time)
			T[2] == T[deadline] 			(Deadline time)  Ci
			T[3] == T[period]  			    (Period) Pi

			These task parameters are internal to the program
			T[4] == T[abs_arrival]  		(Absolute Arrival time)
			T[5] == T[execution_copy]	(Execution time copy)
			T[6] == T[abs_deadline]  	(Absolute Arrival time)

			instance (Number of times the tasks had arrived since time = 0)
			alive (Whether the task is ready? 0 for NOT READY and 1 for READY )
	*/
} task;

#define IDLE_TASK_ID 1023 // Just a number I assigned
#define ALL 1
#define CURRENT 0

void get_tasks(task *t1, int n);						  // Get tasks parameters - Arrival time , Execution time , Deadline and Period
int hyperperiod_calc(task *t1, int n);					  // Calculate hyper period period of the task set
float cpu_util(task *t1, int n);						  // Calculates CPU utilization
int gcd(int a, int b);									  // Find greatest common divisor
int lcm(int *a, int n);									  // Find Least common multiple
int sp_interrupt(task *t1, int tmr, int n);				  // Scheduling point interrupt
int min(task *t1, int n, int p);						  // Find minimum of given task parameter
void update_abs_arrival(task *t1, int n, int k, int all); // Update absolute arrival time (absolute arrival time = arrivaltime + instance*period)
void update_abs_deadline(task *t1, int n, int all);		  // Update absolute deadline (absolute deadline = absolute arrival time + deadline )
void copy_execution_time(task *t1, int n, int all);		  // Keep a backup copy of execution time
int worst_cpu_util_check(task *t1, int n);				  // checks if a feasible alpha to scaled down the frequency can be obtained for the current task
void set_alpha(task *t1, int n, float *alpha);
void update_alpha_completion(task *t1, int n, int active_task_id, float *alpha); // updates alpha on completion of a task. Reduces alpha to actual cycles used this invocation rather than the worst case computation time
void update_alpha_release(task *t1, int n, float *alpha);						 // updates alpha on release of a task after it's invocation. Increases alpha to worst case computation time
