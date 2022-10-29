#!/usr/bin/env bash

declare -i age
declare -i half
declare -i mean
declare -ia ages
declare -i median
declare -i total_people
declare -i age_accumulator
declare -i age_of_the_oldest_person
declare -i age_of_the_youngest_person

swap() {
    ages[i]=$((ages[i] + ages[j]))
    ages[j]=$((ages[i] - ages[j]))
    ages[i]=$((ages[i] - ages[j]))
}

bubble_sort() {
  declare -i local i
  declare -i local j
  
  for i in $(seq 0 $((total_people - 1))); do
    for j in $(seq 0 $((total_people - 1))); do
      if [ ${ages[i]} -gt ${ages[j]} ]; then
        swap
      fi
    done
  done
}

f_median() {
	declare -i local half
	
	bubble_sort
	
	half=$((total_people / 2))
	
	if [ $((total_people % 2)) -ne 0 ]; then
		echo "${ages[half]}"
	else
		((half--))
		echo "$(((ages[half] + ages[$((half + 1))]) / 2))"
	fi
}

read -p "Total de pessoas: " total_people
read -p "Idade da pessoa 1: " age

median=$age
ages=$age
age_accumulator=$age
age_of_the_oldest_person=$age
age_of_the_youngest_person=$age

for i in $(seq 1 $((total_people - 1))); do
	read -p "Idade da pessoa $((i + 1)): " age
	
	if [ $age -lt $age_of_the_youngest_person ]; then
		age_of_the_youngest_person=$age
	fi
	
	if [ $age -gt $age_of_the_oldest_person ]; then
		age_of_the_oldest_person=$age
	fi
	
	age_accumulator=$((age_accumulator + age))
	ages[$i]=$age
done

mean=$((age_accumulator / total_people))
median=`f_median`

echo "Media das idades: $mean"
echo "Mediana das idades: $median"
echo "Idade da pessoa mais velha: $age_of_the_oldest_person"
echo "Idade da pessoa mais nova: $age_of_the_youngest_person"
