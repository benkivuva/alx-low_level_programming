int main(int argc, char **argv)
{
    // Check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    // Open the ELF file for reading
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error opening file %s: %s\n", argv[1], strerror(errno));
        exit(98);
    }

    // Get the size of the file
    off_t file_size = lseek(fd, 0, SEEK_END);
    if (file_size < 0) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        exit(98);
    }

    // Reset the file position to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read the ELF header into memory
    Elf64_Ehdr elf_header;
    ssize_t num_bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (num_bytes_read != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        exit(98);
    }

    // Display the ELF header information
    display_elf_header_info(elf_header);

    // Close the file
    close(fd);

    return 0;
}

