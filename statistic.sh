#!/usr/bin/env bash

swap() {
    ages[i]=$((ages[i] + ages[j]))
    ages[j]=$((ages[i] - ages[j]))
    ages[i]=$((ages[i] - ages[j]))
}

bubble_sort() {
  local i j

  for i in `seq 0 $((total_people - 1))`; do
    for j in `seq 0 $((total_people - 1))`; do
      if [ ${ages[i]} -gt ${ages[j]} ]; then
        swap
      fi
    done
  done
}

f_median() {
	local half

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

ages=$age
median=$age
age_accumulator=$age
age_of_the_oldest_person=$age
age_of_the_youngest_person=$age

for i in `seq 1 $((total_people - 1))`; do
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

median=`f_median`
mean=$((age_accumulator / total_people))

echo "Media das idades: $mean"
echo "Mediana das idades: $median"
echo "Idade da pessoa mais velha: $age_of_the_oldest_person"
echo "Idade da pessoa mais nova: $age_of_the_youngest_person"
