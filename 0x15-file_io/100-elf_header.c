#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define EI_NIDENT 16

/* ELF Header */
typedef struct {
    uint8_t e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

/* Magic numbers */
#define ELFMAG0     0x7f
#define ELFMAG1     'E'
#define ELFMAG2     'L'
#define ELFMAG3     'F'
#define ELFCLASS32  1
#define ELFCLASS64  2
#define ELFDATA2LSB 1
#define ELFOSABI_SYSV 0

/* Display the ELF header */
void display_elf_header(const Elf64_Ehdr *ehdr) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", ehdr->e_ident[i]);
    }
    printf("\n");

    /* Verify magic numbers */
    if (ehdr->e_ident[0] != ELFMAG0 ||
        ehdr->e_ident[1] != ELFMAG1 ||
        ehdr->e_ident[2] != ELFMAG2 ||
        ehdr->e_ident[3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

    printf("  Class:                             ");
    switch (ehdr->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid class\n");
            break;
    }

    printf("  Data:                              ");
    switch (ehdr->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        default:
            printf("Invalid data encoding\n");
            break;
    }

    printf("  Version:                           %d (current)\n",
           ehdr->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (ehdr->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("  ABI Version:                       %d\n",
           ehdr->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (ehdr->e_type) {
        case 1:
            printf("REL (Relocatable file)\n");

