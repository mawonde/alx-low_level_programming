#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_address - Prints the address
 * @pointer: magic pointer.
 * Return: NULL.
 */
void print_address(char *pointer)
{
	int i;
	int start;
	char sys;

	printf("  Entry point address:               0x");

	sys = pointer[4] + '0';
	if (sys == '1')
	{
		start = 26;
		printf("80");
		for (i = start; i >= 22; i--)
		{
			if (pointer[i] > 0)
				printf("%x", pointer[i]);
			else if (pointer[i] < 0)
				printf("%x", 256 + pointer[i]);
		}
		if (pointer[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		start = 26;
		for (i = start; i > 23; i--)
		{
			if (pointer[i] >= 0)
				printf("%02x", pointer[i]);

			else if (pointer[i] < 0)
				printf("%02x", 256 + pointer[i]);

		}
	}
	printf("\n");
}

/**
 * print_type - prints the type
 * @pointer: magic pointer.
 * Return: NULL.
 */
void print_type(char *pointer)
{
	char type = pointer[16];

	if (pointer[5] == 1)
		type = pointer[16];
	else
		type = pointer[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - prints osabi
 * @pointer: magic pointer.
 * Return: NULL.
 */
void print_osabi(char *pointer)
{
	char osabi = pointer[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", pointer[8]);
}


/**
 * print_vers - prints version
 * @pointer: magic.
 * Return: no return.
 */
void print_vers(char *pointer)
{
	int version = pointer[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - prints data
 * @pointer: magic.
 * Return: no return.
 */
void print_data(char *pointer)
{
	char data = pointer[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @pointer: magic pointer.
 * Return: NULL.
 */
void print_magic(char *pointer)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", pointer[bytes]);

	printf("\n");

}

/**
 * check_system - checks  version of the system.
 * @pointer: magic pointer.
 * Return: NULL.
 */
void check_system(char *pointer)
{
	char sys = pointer[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(pointer);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(pointer);
	print_vers(pointer);
	print_osabi(pointer);
	print_type(pointer);
	print_address(pointer);
}

/**
 * check_elf - check if it is an elf file.
 * @pointer: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *pointer)
{
	int addr = (int)pointer[0];
	char E = pointer[1];
	char L = pointer[2];
	char F = pointer[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
* main - Checks the code and copies contents to another file.
 * @argc: Number of arguments provided.
 * @argv: Array of pointer to Arguments .
 * Return:  0.
 */
int main(int argc, char *argv[])
{
	int fd, reader;
	char pointer[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	reader = read(fd, pointer, 27);

	if (reader == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(pointer))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_system(pointer);
	close(fd);

	return (0);
}
