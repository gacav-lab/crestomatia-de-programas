#!/usr/bin/env python3

def swap(ages, i, j):
	ages[i] = ages[i] + ages[j]
	ages[j] = ages[i] - ages[j]
	ages[i] = ages[i] - ages[j]

def bubble_sort(ages):
	total_people = len(ages)
	for i in range(total_people):
		for j in range(total_people):
			if(ages[i] > ages[j]):
				swap(ages, i, j)

def f_median(ages):
	total_people = len(ages)

	bubble_sort(ages)

	half = total_people // 2

	if(total_people % 2 != 0):
		return ages[half]
	else:
		half = half - 1
		return (ages[half] + ages[half + 1]) // 2

total_people = int(input("Total de pessoas: "))
age = int(input("Idade da pessoa 1: "))

ages = []
median = age
ages.append(age)
age_accumulator = age
age_of_the_oldest_person = age
age_of_the_youngest_person = age

for counter in range(2, total_people + 1):
	age = int(input("Idade da pessoa {}: ".format(counter)))

	if(age < age_of_the_youngest_person):
		age_of_the_youngest_person = age

	if(age > age_of_the_oldest_person):
		age_of_the_oldest_person = age

	ages.append(age)
	age_accumulator = age_accumulator + age

median = f_median(ages)
mean = age_accumulator // total_people

print("Media das idades:", mean)
print("Mediana das idades:", median)
print("Idade da pessoa mais velha:", age_of_the_oldest_person)
print("Idade da pessoa mais nova:", age_of_the_youngest_person)
