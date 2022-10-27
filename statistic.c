#include <stdio.h>
#include <stdlib.h>

void swap(int *ages, int i, int j);
void bubble_sort(int *ages, int total_people);

int main(int argc, char **argv) {
    int* ages = NULL, onces = NULL;
    int age_of_the_oldest_person, age_of_the_youngest_person;
    int half, total_people, age_accumulator, most_frequently, mean, mode, median, age;

	printf("Total de pessoas: ");
	scanf("%d", &total_people);

	printf("Idade da pessoa 1: ");
	scanf("%d", &age);

	age_accumulator = age;
	age_of_the_oldest_person = age;
	age_of_the_youngest_person = age;
	ages = malloc(total_people * sizeof(int));
	onces = malloc(total_people * sizeof(int));
	*ages = age;

    for(int i = 0; i < total_people; i++) {
        *(onces + i) = 0;
    }

	for(int i = 1; i < total_people; i++) {
		printf("Idade da pessoa %d: ", i + 1);
		scanf("%d", &age);

		age_accumulator += age;

		if(age < age_of_the_youngest_person) {
			age_of_the_youngest_person = age;
		}

		if(age > age_of_the_oldest_person) {
			age_of_the_oldest_person = age;
		}
		
		*(ages + i) = age;
	}

    bubble_sort(&ages[0], total_people);

	mean = age_accumulator / total_people;
	half = total_people / 2;
	half--;
	
	if(total_people % 2 != 0) {
	    median = total_people / 2 + 1;
	} else {
	    median = (*(ages + half) + *(ages + half + 1)) / 2;
	}

    for(int i = 0; i < total_people; i++) {
        for(int j = 0; j < total_people; j++) {
            if(*(ages + j) == *(ages + i)) {
                onces[i]++;
            }
        }
    }

    most_frequently = *onces;

    for(int i = 1; i < total_people; i++) {
        if(*(onces + i) > most_frequently) {
            most_frequently = i;
        }
    }

    mode = *(ages + most_frequently);

	printf("Moda das idades: %d\n", mode);
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
