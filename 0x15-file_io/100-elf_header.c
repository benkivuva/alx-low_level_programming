#include "main.h"
#include <elf.h>

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
    printf("Magic:   %02x %02x %02x %02x\n",
           header.e_ident[EI_MAG0],
           header.e_ident[EI_MAG1],
           header.e_ident[EI_MAG2],
           header.e_ident[EI_MAG3]);

    printf("Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header.e_ident[EI_CLASS] == ELFCLASSNONE ? "none" : "unknown");

    printf("Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
           header.e_ident[EI_DATA] == ELFDATANONE ? "none" : "unknown");

    printf("Version:                           %d\n",
           header.e_ident[EI_VERSION]);

    printf("OS/ABI:                            %s\n",
           header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
           header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
           header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           header.e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
           header.e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
           header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "

