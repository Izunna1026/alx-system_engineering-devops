#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * infinite_while - To run an infinite loop
 * Return: 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - the main function to create 5 zombie
 * Return: 0
 */
int main(void)
{
	pid_t my_pid;
	char k = 0;

	while (k < 5)
	{
		my_pid = fork();
		if (my_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", my_pid);
			sleep(1);
			k++;
		}
		else
			exit(0);
	}
	infinite_while();

	return (EXIT_SUCCESS);
}
