#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *ages, int i, int j) {
	ages[i] = ages[i] + ages[j];
	ages[j] = ages[i] - ages[j];
	ages[i] = ages[i] - ages[j];
}

void bubble_sort(int *ages, int total_people) {
    for(int i = 0; i < total_people; i++) {
        for(int j = 0; j < total_people; j++) {
            if(ages[i] > ages[j]) {
                swap(ages, i, j);
            }
        }
    }
}

int f_median(int *ages, int total_people) {
	int half = total_people / 2;

	bubble_sort(ages, total_people);

	return (total_people % 2 != 0) ? ages[half] : (ages[half - 1] + ages[half]) / 2;
}

int main(int argc, char **argv) {
    int *ages = NULL;
    int total_people, age_accumulator, mean, median, age;
    int age_of_the_oldest_person, age_of_the_youngest_person;

	cout << "Total de pessoas: ";
	cin >> total_people;

	cout << "Idade da pessoa 1: ";
	cin >> age;

	median = age;
	age_accumulator = age;
	age_of_the_oldest_person = age;
	age_of_the_youngest_person = age;
	ages = new int[total_people];
	ages[0] = age;

	for(int i = 1; i < total_people; i++) {
		cout << "Idade da pessoa " << i + 1 << ": ";
		cin >> age;

		if(age < age_of_the_youngest_person) {
			age_of_the_youngest_person = age;
		}

		if(age > age_of_the_oldest_person) {
			age_of_the_oldest_person = age;
		}

		age_accumulator += age;
		ages[i] = age;
	}

	mean = age_accumulator / total_people;
	median = f_median(ages, total_people);

	cout << "Media das idades: " << mean << endl;
	cout << "Mediana das idades: " << median << endl;
	cout << "Idade da pessoa mais velha: " << age_of_the_oldest_person << endl;
	cout << "Idade da pessoa mais nova: " << age_of_the_youngest_person << endl;

	return EXIT_SUCCESS;
}
