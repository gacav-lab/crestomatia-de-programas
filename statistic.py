#!/usr/bin/env python3

# INCOMPLETO

#median=0
#mode=0

total_people = int(input("Total de pessoas: "))
age = int(input("Idade da pessoa 1: "))

age_accumulator = age
age_of_the_oldest_person = age
age_of_the_youngest_person = age

for counter in range(2, total_people + 1):
    age = int(input("Idade da pessoa {}: ".format(counter)))

    age_accumulator += age;

    if(age < age_of_the_youngest_person):
        age_of_the_youngest_person = age

    if(age > age_of_the_oldest_person):
        age_of_the_oldest_person = age

mean = age_accumulator / total_people;

#print("Moda das idades:", mode)
print("Media das idades:", mean)
#print("Mediana das idades:", median)
print("Idade da pessoa mais velha:", age_of_the_oldest_person)
print("Idade da pessoa mais nova:", age_of_the_youngest_person)
