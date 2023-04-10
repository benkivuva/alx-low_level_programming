#include "main.h"
#include <elf.h>

/**
 * display_elf_header - displays the information contained in the ELF header at the start of an ELF file
 * @filename: name of the ELF file
 */
void display_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr elf_header;

	/* Open the file and check for errors*/
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
		exit(98);
	}

	/* Read the ELF header into memory*/
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		fprintf(stderr, "Error: Failed to read ELF header from file '%s'.\n", filename);
		close(fd);
		exit(98);
	}

	/* Print out the ELF header information*/
	printf("Magic: %02x %02x %02x %02x\n", elf_header.e_ident[EI_MAG0],
		elf_header.e_ident[EI_MAG1], elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
	printf("Class: %d-bit\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("Data: %s-endian\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
	printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", elf_header.e_type);
	printf("Entry point address: 0x%lx\n", elf_header.e_entry);

	/* Close the file*/
	close(fd);
}

/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	/* Check for correct usage*/
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	display_elf_header(argv[1]);

	return (0);
}
