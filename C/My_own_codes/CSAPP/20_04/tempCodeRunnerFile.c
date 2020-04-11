char *readSource(const char *filename)
{

    FILE *file = fopen(filename, "r");
    char *code = (char *)malloc(sizeof(char) * CODESIZE);
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%c", &code[i]);
        i++;
    }
    fclose(file);

    return code;
}
