#include <stdio.h>
#include <stdlib.h>

// INCOMPLETO

int main(int argc, char **argv) {
	int total_people;
	int age_accumulator;
	int mean, median, mode
	int age, age_of_the_oldest_person, age_of_the_youngest_person;

	printf("Total de pessoas: ");
	scanf("%d", &total_people);

	printf("Idade da pessoa 1: ", counter + 1);
	scanf("%d", &age);

	age_accumulator = age;
	age_of_the_oldest_person = age;
	age_of_the_youngest_person = age;

	for(int counter = 1; counter < total_people; counter++) {
		printf("Idade da pessoa %d: ", counter + 1);
		scanf("%d", &age);

		age_accumulator += age;

		if(age < age_of_the_youngest_person) {
			age_of_the_youngest_person = age;
		}

		if(age > age_of_the_oldest_person) {
			age_of_the_oldest_person = age;
		}
	}

	mean = age_accumulator / total_people;

	//printf("Moda das idades: %d\n", mode);
	printf("Media das idades: %d\n", mean);
	//printf("Mediana das idades: %d\n", median);
	printf("Idade da pessoa mais velha: %d\n", age_of_the_oldest_person);
	printf("Idade da pessoa mais nova: %d\n", age_of_the_youngest_person);

	return EXIT_SUCCESS;
}
