#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int *ages, int i, int j);
int f_median(int *ages, int total_people);
void bubble_sort(int *ages, int total_people);

int main(int argc, char **argv) {
    int *ages = NULL;
    int age_of_the_oldest_person, age_of_the_youngest_person;
    int half, total_people, age_accumulator, mean, median, age;

	cout << "Total de pessoas: ";
	cin >> total_people;

	cout << "Idade da pessoa 1: ";
	cin >> age;

	median = age;
	age_accumulator = age;
	age_of_the_oldest_person = age;
	age_of_the_youngest_person = age;
	ages = (int*) malloc(total_people * sizeof(int));
	*ages = age;

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
		*(ages + i) = age;
	}

	mean = age_accumulator / total_people;
	median = f_median(&ages[0], total_people);

	cout << "Media das idades: " << mean << endl;
	cout << "Mediana das idades: " << median << endl;
	cout << "Idade da pessoa mais velha: " << age_of_the_oldest_person << endl;
	cout << "Idade da pessoa mais nova: " << age_of_the_youngest_person << endl;

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

int f_median(int *ages, int total_people) {
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
