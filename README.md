# Cycle-Conserving Earliest Deadline First

Took implementation of EDF from https://github.com/jabezwinston/Earliest_Deadline_First </br>
Created 3 custom functions for alpha (scaling factor): 
void set_alpha(task *t1, int n, float *alpha);
void update_alpha_completion(task *t1, int n, int active_task_id, float *alpha);
void update_alpha_release(task *t1, int n, int active_task_id, float *alpha);

Assumption: 
* The scaling factor chosen is the minimum value, i.e. alpha = C1/P1+C2/P2+C3/P3.......
* Actual execution take 90% of the worst case time for all tasks (can be modified to custom values for each task)

Use the make command to compile in GCC.

### Sample

| Tasks | Arrival	| Execution  |  Deadline | Period |  
|:-----:|:---------:|:----------:|:---------:|:-------:
|T1	    |   0		|	  2 	 |	  5      |   20   |
|T2	    |   1		|	  3 	 |	  7      |   30   |



### How the program looks like
```bash
winston@winston-VirtualBox:~/EDF_Scheduler$ ./EDF
Enter number of tasks
2
Enter Task 1 parameters
Arrival time: 0
Worst case execution time: 2
Deadline time: 5
Period: 20
Enter Task 2 parameters
Arrival time: 1
Worst case execution time: 3
Deadline time: 7
Period: 30
CPU Utilization 0.116667
Tasks can be scheduled
   Set: Aplha scaled to 0.200000
   Release: Aplha scaled to 0.200000
0  Task 1
   Completion: Aplha scaled to 0.190000
   Release: Aplha scaled to 0.200000
1  Task 2
2  Task 2
   Completion: Aplha scaled to 0.190000
3  Idle
4  Idle
5  Idle
6  Idle
7  Idle
8  Idle
9  Idle
10  Idle
11  Idle
12  Idle
13  Idle
14  Idle
15  Idle
16  Idle
17  Idle
18  Idle
19  Idle
   Release: Aplha scaled to 0.200000
20  Task 1
   Completion: Aplha scaled to 0.190000
21  Idle
22  Idle
23  Idle
24  Idle
25  Idle
26  Idle
27  Idle
28  Idle
29  Idle
30  Idle
   Release: Aplha scaled to 0.200000
31  Task 2
32  Task 2
   Completion: Aplha scaled to 0.190000
33  Idle
34  Idle
35  Idle
36  Idle
37  Idle
38  Idle
39  Idle
   Release: Aplha scaled to 0.200000
40  Task 1
   Completion: Aplha scaled to 0.190000
41  Idle
42  Idle
43  Idle
44  Idle
45  Idle
46  Idle
47  Idle
48  Idle
49  Idle
50  Idle
51  Idle
52  Idle
53  Idle
54  Idle
55  Idle
56  Idle
57  Idle
58  Idle
59  Idle
   Release: Aplha scaled to 0.200000
60  Task 1
   Completion: Aplha scaled to 0.190000
