#include "main.h"

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		open_and_exec_file(argv[1]);
	}
	else
	{
		execute_commands_stdin();
	}

	return (0);
}
