#include <elf.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>

#include <stdlib.h>
  
void check_elf(unsigned char *e_ident); 
 void print_magic(unsigned char *e_ident); 
 void print_class(unsigned char *e_ident); 
 void print_data(unsigned char *e_ident); 
 void print_version(unsigned char *e_ident); 
 void print_abi(unsigned char *e_ident); 
 void print_osabi(unsigned char *e_ident); 
 void print_type(unsigned int e_type, unsigned char *e_ident); 
 void print_entry(unsigned long int e_entry, unsigned char *e_ident); 
 void close_elf(int elf);

/**
 * check_elf - Check if the file is an ELF file
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void check_elf(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

    if (e_ident[EI_CLASS] != ELFCLASS32 && e_ident[EI_CLASS] != ELFCLASS64)
    {
        fprintf(stderr, "Error: Unsupported ELF file class\n");
        exit(98);
    }

    if (e_ident[EI_DATA] != ELFDATA2LSB && e_ident[EI_DATA] != ELFDATA2MSB)
    {
        fprintf(stderr, "Error: Unsupported ELF file data encoding\n");
        exit(98);
    }

    if (e_ident[EI_VERSION] != EV_CURRENT)
    {
        fprintf(stderr, "Error: Unsupported ELF file version\n");
        exit(98);
    }

    if (e_ident[EI_OSABI] != ELFOSABI_NONE)
    {
        fprintf(stderr, "Error: Unsupported ELF file OS/ABI\n");
        exit(98);
    }
}


/**
 * print_magic - Print the ELF magic number
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_magic(unsigned char *e_ident) {
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < 16; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

/**
 * print_class - Print the ELF class
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_class(unsigned char *e_ident) {
    switch (e_ident[4]) {
        case 0x01:
            printf("Class: ELF32\n");
            break;
        case 0x02:
            printf("Class: ELF64\n");
            break;
        default:
            printf("Class: Invalid ELF class\n");
    }
}

/**
 * print_data - Print the ELF data encoding
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_data(unsigned char *e_ident)
{
	printf("Data: ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("None\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid\n");
			break;
	}
}

/**
 * print_version - Print the ELF version
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_version(unsigned char *e_ident)
{
	printf("Version: ");
	if (e_ident[EI_VERSION] == EV_CURRENT)
	printf("%d (current)\n", e_ident[EI_VERSION]);
	else
	printf("Invalid\n");
}

/**
 * print_abi - Print the ELF ABI version
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version: ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("%d (UNIX System V ABI)\n", e_ident[EI_ABIVERSION]);
			break;
		case ELFOSABI_HPUX:
			printf("%d (HP-UX ABI)\n", e_ident[EI_ABIVERSION]);
			break;
		case ELFOSABI_NETBSD:
			printf("%d (NetBSD ABI)\n", e_ident[EI_ABIVERSION]);
			break;
		default:
			printf("Unrecognized ABI\n");
			break;
	}
}

/**
 * print_osabi - Print the ELF OS ABI
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI: ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("OpenBSD\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM EABI\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
}

/**
 * print_type - Print the ELF file type
 * @e_type: The ELF file type value
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    printf("Type: ");
    switch (e_type)
    {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

/**
 * print_entry - Print the entry point of the ELF file
 * @e_entry: The entry point value
 * @e_ident: The ELF identification bytes
 *
 * Return: Void
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    if (e_ident[EI_CLASS] == ELFCLASS32)
    {
        printf("Entry point address: 0x%x\n", (unsigned int) e_entry);
    }
    else if (e_ident[EI_CLASS] == ELFCLASS64)
    {
        printf("Entry point address: 0x%lx\n", e_entry);
    }
    else
    {
        printf("Unknown ELF class\n");
    }
}

/**
 * close_elf - Close the ELF file
 * @elf: The file descriptor of the ELF file
 *
 * Return: Void
 */
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
    int fd;
    unsigned char e_ident[EI_NIDENT];
    unsigned int e_type;
    unsigned long int e_entry;

    if (argc != 2)
    {
        printf("Usage: %s <ELF file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    {
        printf("Error reading ELF identification bytes\n");
        close_elf(fd);
        exit(EXIT_FAILURE);
    }

    check_elf(e_ident);
    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_abi(e_ident);
    print_osabi(e_ident);

    if (lseek(fd, 16, SEEK_SET) == -1)
    {
        perror("lseek");
        close_elf(fd);
        exit(EXIT_FAILURE);
    }

    if (read(fd, &e_type, sizeof(e_type)) != sizeof(e_type))
    {
        printf("Error reading ELF type\n");
        close_elf(fd);
        exit(EXIT_FAILURE);
    }

    print_type(e_type, e_ident);

    if (lseek(fd, 24, SEEK_SET) == -1)
    {
        perror("lseek");
        close_elf(fd);
        exit(EXIT_FAILURE);
    }

    if (read(fd, &e_entry, sizeof(e_entry)) != sizeof(e_entry))
    {
        printf("Error reading ELF entry point\n");
        close_elf(fd);
        exit(EXIT_FAILURE);
    }

    print_entry(e_entry, e_ident);

    close_elf(fd);
    exit(EXIT_SUCCESS);
}
