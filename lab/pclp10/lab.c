#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME_LEN 31

typedef struct __attribute__((__packed__)) {
	char name[NAME_LEN];
	int age;
} person_t;

person_t struct_read(void)
{
    person_t person;
    memset(person.name, 0, NAME_LEN);
    scanf("%s", person.name);
    scanf("%d", &person.age);
    return person;
}

typedef struct {
	char *name;
	int age;    
} person_t2;

person_t2 struct_read2(void)
{
    person_t2 person;
    person.name = malloc(NAME_LEN);
    scanf("%s", person.name);
    person.name = realloc(person.name, strlen(person.name) + 1);
    scanf("%d", &person.age);
    return person;
}

int main(void)
{
    // FILE *out = fopen("2-gigel.bin", "rb");
    // person_t2 person ;
    // // int lg = strlen(person.name) + 1;
    // // fwrite(&lg, sizeof(int), 1, out);
    // // fwrite(person.name, sizeof(char), lg, out);
    // // fwrite(&person.age, sizeof(int), 1, out);
    // // printf("%s\n", person.name);
    // // person_t person;
    // // fread(&person, sizeof(person_t), 1, out);
    // // // fwrite(&person, sizeof(person_t), 1, out);
    // // printf("%s %d\n", person.name, person.age);
    // int lg;
    // fread(&lg, sizeof(int), 1, out);
    // person.name = malloc(lg);
    // fread(person.name, sizeof(char), lg, out);
    // fread(&person.age, sizeof(int), 1, out);
    // printf("%s %d\n", person.name, person.age);
    // free(person.name);
    // fclose(out);

    FILE *out = fopen("3-gigel.bin", "wb");
    int n;
    scanf("%d", &n);
    person_t2 *person = malloc(n * sizeof(person_t2));

    for (int i = 0; i < n; i++) {
        person[i] = struct_read2();
    }

    int lg;

    for (int i = 0; i < n; i++) {
        lg = strlen(person[i].name) + 1;
        fwrite(&lg, sizeof(int), 1, out);
        fwrite(person[i].name, sizeof(char), lg, out);
        fwrite(&person[i].age, sizeof(int), 1, out);
        free(person[i].name);
    }

    free(person);
    fclose(out);

    return 0;
}
// 00000000  06 00 00 00 47 69 67 65  6c 00 19 00 00 00        |....Gigel.....|
// 0000000e