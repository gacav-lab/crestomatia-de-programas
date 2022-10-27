#!/usr/bin/env bash

swap() {
    ages[i]=$((ages[i] + ages[j]))
    ages[j]=$((ages[i] - ages[j]))
    ages[i]=$((ages[i] - ages[j]))
}

bubble_sort() {
  local i
  local j
  
  for i in $(seq 0 $total_people): do
    for j in $(seq 0 $total_people); do
      if [ ages[i] > ages[j] ]; then
        swap
      fi
    done
  done
}
