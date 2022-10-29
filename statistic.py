#!/usr/bin/env python3

def swap(ages, i, j):
	ages[i] = ages[i] + ages[j]
    ages[j] = ages[i] - ages[j]
    ages[i] = ages[i] - ages[j]
	
def bubble_sort(ages, total_people):
	for i in range(total_people):
		for j in range(total_people):
			if(ages[i] > ages[j]):
				swap(ages, i, j)
	
def f_median(ages, total_people):
	bubble_sort(ages, total_people)
	
	half = total_people / 2
	
	if(total_people % 2 != 0):
		return ages[half]
	else:
		half--
		return (ages[half] + ages[half + 1]) / 2
	

total_people = int(input("Total de pessoas: "))
age = int(input("Idade da pessoa 1: "))

median = age;
ages[0] = age;
age_accumulator = age;
age_of_the_oldest_person = age;
age_of_the_youngest_person = age;

for counter in range(2, total_people + 1):
    age = int(input("Idade da pessoa {}: ".format(counter)))

    if(age < age_of_the_youngest_person):
        age_of_the_youngest_person = age

    if(age > age_of_the_oldest_person):
        age_of_the_oldest_person = age

	ages[i] = age;
    age_accumulator += age;
    
mean = age_accumulator / total_people;
median = f_median(total_people, &ages[0]);

print("Media das idades:", mean)
print("Mediana das idades:", median)
print("Idade da pessoa mais velha:", age_of_the_oldest_person)
print("Idade da pessoa mais nova:", age_of_the_youngest_person)
