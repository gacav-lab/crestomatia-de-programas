#include <stdio.h>
#include <stdlib.h>

void swap(int *ages, int i, int j);
void bubble_sort(int *ages, int total_people);
int f_median(int total_people, int *ages);

int main(int argc, char **argv) {
    int *ages = NULL;
    int age_of_the_oldest_person, age_of_the_youngest_person;
    int half, total_people, age_accumulator, mean, median, age;

	printf("Total de pessoas: ");
	scanf("%d", &total_people);

	printf("Idade da pessoa 1: ");
	scanf("%d", &age);

	age_accumulator = age;
	age_of_the_oldest_person = age;
	age_of_the_youngest_person = age;
	ages = malloc(total_people * sizeof(int));
	*ages = age;

	for(int i = 1; i < total_people; i++) {
		printf("Idade da pessoa %d: ", i + 1);
		scanf("%d", &age);

		if(age < age_of_the_youngest_person) {
			age_of_the_youngest_person = age;
		}

		if(age > age_of_the_oldest_person) {
			age_of_the_oldest_person = age;
		}
		
		age_accumulator += age;
		*(ages + i) = age;
	}

	mean = age_accumulator / total_people;
	median = f_median(total_people, &ages[0]);

	printf("Media das idades: %d\n", mean);
	printf("Mediana das idades: %d\n", median);
	printf("Idade da pessoa mais velha: %d\n", age_of_the_oldest_person);
	printf("Idade da pessoa mais nova: %d\n", age_of_the_youngest_person);

	return EXIT_SUCCESS;
}

void swap(int *ages, int i, int j) {
    *(ages + i) = *(ages + i) + *(ages + j);
    *(ages + j) = *(ages + i) - *(ages + j);
    *(ages + i) = *(ages + i) - *(ages + j);
}

void bubble_sort(int *ages, int total_people) {
    for(int i = 0; i < total_people; i++) {
        for(int j = 0; j < total_people; j++) {
            if(*(ages + i) > *(ages + j)) {
                swap(&ages[0], i, j);
            }
        }
    }
}

int f_median(int total_people, int *ages) {
	int half;

	bubble_sort(&ages[0], total_people);

	half = total_people / 2;

	if(total_people % 2 != 0) {
	    return *(ages + half);
	} else {
		half--;
	    return (*(ages + half) + *(ages + half + 1)) / 2;
	}
}
