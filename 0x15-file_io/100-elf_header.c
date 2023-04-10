#include <main.h>
#include <fcntl.h>
#include <elf.h>

void print_magic(unsigned char *magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_osabi(unsigned char osabi);

/**
 * main - displays the ELF header of an ELF file
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    /* Check for correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return (98);
    }

    /* Open the file for reading */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (98);
    }

    /* Read the ELF header */
    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        fprintf(stderr, "Error reading ELF header\n");
        close(fd);
        return (98);
    }

    /* Verify that the file is an ELF file */
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "File is not an ELF file\n");
        close(fd);
        return (98);
    }

    /* Print the ELF header information */
    print_magic(header.e_ident);
    print_class(header.e_ident[EI_CLASS]);
    print_data(header.e_ident[EI_DATA]);
    print_version(header.e_ident[EI_VERSION]);
    print_osabi(header.e_ident[EI_OSABI]);

    printf("ABI Version:                       %d\n",
           header.e_ident[EI_ABIVERSION]);

    printf("Type:                              %s\n",
           header.e_type == ET_NONE ? "NONE (None)" :
           header.e_type == ET_REL ? "REL (Relocatable file)" :
           header.e_type == ET_EXEC ? "EXEC (Executable file)" :
           header.e_type == ET_DYN ? "DYN (Shared object file)" :
           header.e_type == ET_CORE ? "CORE (Core file)" :
           "unknown");

    printf("Entry point address:               0x%lx\n",
           (unsigned long) header.e_entry);

    close(fd);
    return (0);
}

/**
 * print_magic - prints the ELF magic number
 * @magic: a pointer to the magic number bytes
 */
void print_magic(unsigned char *magic)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", magic[i]);
    printf("\n");
}

/**
 * print_class - prints the ELF class
 * @class: the class byte from the ELF header
 */
void print_class(unsigned char class)
{
    printf("Class:                             %s\n",
           class == ELFCLASS64 ? "ELF64" :
           class == ELFCLASS32 ? "ELF32" :
           class == ELFCLASSNONE ? "none" : "unknown");
