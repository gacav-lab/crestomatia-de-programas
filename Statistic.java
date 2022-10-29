class Statistic {
	public static void swap(int ages[], int i, int j) {
		ages[i] = ages[i] + ages[j];
		ages[j] = ages[i] - ages[j];
		ages[i] = ages[i] - ages[j];
	}

	public static void bubbleSort(int ages[]) {
		int totalPeople = ages.length;

		for(int i = 0; i < totalPeople; i++) {
		    for(int j = 0; j < totalPeople; j++) {
		        if(ages[i] > ages[j]) {
		            swap(ages, i, j);
		        }
		    }
		}
	}

	public static int FMedian(int ages[]) {
		int half, totalPeople = ages.length;

		bubbleSort(ages);

		half = totalPeople / 2;

		if(totalPeople % 2 != 0) {
			return ages[half];
		} else {
			half--;
			return (ages[half] + ages[half + 1]) / 2;
		}
	}

	public static void main(String[] args) {
		int[] ages = null;
		int ageOfTheOldestPerson, ageOfTheYoungestPerson;
		int half, totalPeople, ageAccumulator, mean, median, age;

		System.out.print("Total de pessoas: ");
		totalPeople = Integer.parseInt(System.console().readLine());

		System.out.print("Idade da pessoa 1: ");
		age = Integer.parseInt(System.console().readLine());

		median = age;
		ageAccumulator = age;
		ageOfTheOldestPerson = age;
		ageOfTheYoungestPerson = age;
		ages = new int[totalPeople];
		ages[0] = age;

		for(int i = 1; i < totalPeople; i++) {
			System.out.printf("Idade da pessoa %d: ", i + 1);
			age = Integer.parseInt(System.console().readLine());

			if(age < ageOfTheYoungestPerson) {
				ageOfTheYoungestPerson = age;
			}

			if(age > ageOfTheOldestPerson) {
				ageOfTheOldestPerson = age;
			}

			ageAccumulator += age;
			ages[i] = age;
		}

		median = FMedian(ages);
		mean = ageAccumulator / totalPeople;

		System.out.println("Media das idades: " + mean);
		System.out.println("Mediana das idades: " + median);
		System.out.println("Idade da pessoa mais velha: " + ageOfTheOldestPerson);
		System.out.println("Idade da pessoa mais nova: " + ageOfTheYoungestPerson);
	}
}
