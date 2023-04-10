#include <elf.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include "main.h"
  
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
  * check_elf - Checking if a file is an ELF file. 
  * @e_ident: A pointer to an array 
  * 
  * Description: If the file is not an ELF file - exit code 98. 
  */ 
 void check_elf(unsigned char *e_ident) 
 { 
         int benindex; 
  
         for (benindex = 0; benindex < 4; benindex++) 
         { 
                 if (e_ident[benindex] != 127 && 
                     e_ident[benindex] != 'E' && 
                     e_ident[benindex] != 'L' && 
                     e_ident[benindex] != 'F') 
                 { 
                         dprintf(STDERR_FILENO, "Error: Not an ELF file\n"); 
                         exit(98); 
                 } 
         } 
 } 
  
 /** 
  * print_magic - Prints the magic number of elf head 
  * @e_ident: A pointer to an array 
  * 
  * Description: Magic numbers are separated by spaces. 
  */ 
 void print_magic(unsigned char *e_ident) 
 { 
         int benindex; 
  
         printf("  Magic:   "); 
  
         for (benindex = 0; benindex < EI_NIDENT; benindex++) 
         { 
                 printf("%02x", e_ident[benindex]); 
  
                 if (benindex == EI_NIDENT - 1) 
                         printf("\n"); 
                 else 
                         printf(" "); 
         } 
 } 
  
 /** 
  * print_class - Print the class of the ELF head. 
  * @e_ident: pointer to array containing the ELF class
  */ 
 void print_class(unsigned char *e_ident) 
 { 
         printf("  Class:                             "); 
  
         switch (e_ident[EI_CLASS]) 
         { 
         case ELFCLASSNONE: 
                 printf("none\n"); 
                 break; 
         case ELFCLASS32: 
                 printf("ELF32\n"); 
                 break; 
         case ELFCLASS64: 
                 printf("ELF64\n"); 
                 break; 
         default: 
                 printf("<unknown: %x>\n", e_ident[EI_CLASS]); 
         } 
 } 
  
 /** 
  * print_data - Printing data of an ELF head
  * @e_ident: pointer to array containing the ELF class
  */ 
 void print_data(unsigned char *e_ident) 
 { 
         printf("  Data:                              "); 
  
         switch (e_ident[EI_DATA]) 
         { 
         case ELFDATANONE: 
                 printf("none\n"); 
                 break; 
         case ELFDATA2LSB: 
                 printf("2's complement, little endian\n"); 
                 break; 
         case ELFDATA2MSB: 
                 printf("2's complement, big endian\n"); 
                 break; 
         default: 
                 printf("<unknown: %x>\n", e_ident[EI_CLASS]); 
         } 
 } 
  
 /** 
  * print_version - Print version of an ELF head 
  * @e_ident: pointer to array containing the ELF version
  */ 
 void print_version(unsigned char *e_ident) 
 { 
         printf("  Version:                           %d", 
                e_ident[EI_VERSION]); 
  
         switch (e_ident[EI_VERSION]) 
         { 
         case EV_CURRENT: 
                 printf(" (current)\n"); 
                 break; 
         default: 
                 printf("\n"); 
                 break; 
         } 
 } 
  
 /** 
  * print_osabi - Print OS/ABI of an ELF head
  * @e_ident: pointer array containing the ELF version
  */ 
 void print_osabi(unsigned char *e_ident) 
 { 
         printf("  OS/ABI:                            "); 
  
         switch (e_ident[EI_OSABI]) 
         { 
         case ELFOSABI_NONE: 
                 printf("UNIX - System V\n"); 
                 break; 
         case ELFOSABI_HPUX: 
                 printf("UNIX - HP-UX\n"); 
                 break; 
         case ELFOSABI_NETBSD: 
                 printf("UNIX - NetBSD\n"); 
                 break; 
         case ELFOSABI_LINUX: 
                 printf("UNIX - Linux\n"); 
                 break; 
         case ELFOSABI_SOLARIS: 
                 printf("UNIX - Solaris\n"); 
                 break; 
         case ELFOSABI_IRIX: 
                 printf("UNIX - IRIX\n"); 
                 break; 
         case ELFOSABI_FREEBSD: 
                 printf("UNIX - FreeBSD\n"); 
                 break; 
         case ELFOSABI_TRU64: 
                 printf("UNIX - TRU64\n"); 
                 break; 
         case ELFOSABI_ARM: 
                 printf("ARM\n"); 
                 break; 
         case ELFOSABI_STANDALONE: 
                 printf("Standalone App\n"); 
                 break; 
         default: 
                 printf("<unknown: %x>\n", e_ident[EI_OSABI]); 
         } 
 } 
  
 /** 
  * print_abi - Printing the ABI version of ELF head
  * @e_ident: pointer to an array containing the ELF ABI version
  */ 
 void print_abi(unsigned char *e_ident) 
 { 
         printf("  ABI Version:                       %d\n", 
                e_ident[EI_ABIVERSION]); 
 } 
  
 /** 
  * print_type - Prints type of an ELF head
  * @e_type: The ELF type 
  * @e_ident: pointer to array containing the ELF class. 
  */ 
 void print_type(unsigned int e_type, unsigned char *e_ident) 
 { 
         if (e_ident[EI_DATA] == ELFDATA2MSB) 
                 e_type >>= 8; 
  
         printf("  Type:                              "); 
  
         switch (e_type) 
         { 
         case ET_NONE: 
                 printf("NONE (None)\n"); 
                 break; 
         case ET_REL: 
                 printf("REL (Relocatable file)\n"); 
                 break; 
         case ET_EXEC: 
                 printf("EXEC (Executable file)\n"); 
                 break; 
         case ET_DYN: 
                 printf("DYN (Shared object file)\n"); 
                 break; 
         case ET_CORE: 
                 printf("CORE (Core file)\n"); 
                 break; 
         default: 
                 printf("<unknown: %x>\n", e_type); 
         } 
 } 
  
 /** 
  * print_entry - Printing entry point of an ELF head. 
  * @e_entry: address of the ELF entry point. 
  * @e_ident: pointer to an array containing the ELF class 
  */ 
 void print_entry(unsigned long int e_entry, unsigned char *e_ident) 
 { 
         printf("  Entry point address:               "); 
  
         if (e_ident[EI_DATA] == ELFDATA2MSB) 
         { 
                 e_entry = ((e_entry << 8) & 0xFF00FF00) | 
                           ((e_entry >> 8) & 0xFF00FF); 
                 e_entry = (e_entry << 16) | (e_entry >> 16); 
         } 
  
         if (e_ident[EI_CLASS] == ELFCLASS32) 
                 printf("%#x\n", (unsigned int)e_entry); 
  
         else 
                 printf("%#lx\n", e_entry); 
 } 
  
 /** 
  * close_elf - function to close an ELF file 
  * @elf: file descriptor of the ELF file
  * 
  * Description: If the file cannot be closed - exit code 98. 
  */ 
 void close_elf(int elf) 
 { 
         if (close(elf) == -1) 
         { 
                 dprintf(STDERR_FILENO, 
                         "Error: Can't close fd %d\n", elf); 
                 exit(98); 
         } 
 } 
  
 /** 
  * main - Displays information contained in
  *        ELF head file of an ELF file
  * @argc: The number of arguments supplied to the program
  * @argv: An array of the arguments pointers
  * 
  * Return: 0 on success. 
  * 
  * Description: If the file is not an ELF File or 
  *              the function fails - exit code 98  */ 
 int main(int __attribute__((__unused__)) argc, char *argv[]) 
 { 
         Elf64_Ehdr *head; 
         int y, z; 
  
         y = open(argv[1], O_RDONLY); 
         if (y == -1) 
         { 
                 dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]); 
                 exit(98); 
         } 
         head = malloc(sizeof(Elf64_Ehdr)); 
         if (head == NULL) 
         { 
                 close_elf(y); 
                 dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]); 
                 exit(98); 
         } 
         z = read(y, head, sizeof(Elf64_Ehdr)); 
         if (z == -1) 
         { 
                 free(head); 
                 close_elf(y); 
                 dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]); 
                 exit(98); 
         } 
  
         check_elf(head->e_ident); 
         printf("ELF Header:\n"); 
         print_magic(head->e_ident); 
         print_class(head->e_ident); 
         print_data(head->e_ident); 
         print_version(head->e_ident); 
         print_osabi(head->e_ident); 
         print_abi(head->e_ident); 
         print_type(head->e_type, head->e_ident); 
         print_entry(head->e_entry, head->e_ident); 
  
         free(head); 
         close_elf(y); 
         return (0); 
 }
