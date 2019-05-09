#include "pch.h"
#include <iostream>

char getMedicationTypeFromPatient();

char getSurgeryTypeFromPatient();

//Patient Account

class PatientAccount {

	double daily_rate;

protected:

	double charges;

	int numberOfDays;

public:

	PatientAccount(int n) {

		daily_rate = 200;

		numberOfDays = n;

		charges = 0;

	}

	void displayCharges() {

		double total = numberOfDays * daily_rate + charges;

		std::cout << "The total charges: " << total << std::endl;

	}

	friend class Surgery;

	friend class Pharmacy;

};

// Surgery class

class Surgery {

	double BRAIN, HEART, KNEE, ACL, PLASTIC;

public:

	Surgery() {

		BRAIN = 72000;

		HEART = 40000;

		KNEE = 49500;

		ACL = 12600;

		PLASTIC = 12199;

	}

	void setSurgeryCharges(PatientAccount &p, char type) {

		if (type == 'A' || type == 'a') {

			p.charges += BRAIN;

		}
		else if (type == 'B' || type == 'b') {

			p.charges += HEART;

		}
		else if (type == 'C' || type == 'c') {

			p.charges += KNEE;

		}
		else if (type == 'D' || type == 'd') {

			p.charges += ACL;

		}
		else if (type == 'E' || type == 'e') {

			p.charges += PLASTIC;

		}
		else {

			std::cout << "Unavailable Surgery choice " << std::endl;

		}



	}

};

//pharmacy class

class Pharmacy {

	double ANTIDEPRESSANTS, PAINKILLERS, ANTIBIOTICS, VACCINES, LAUGHTER;

public:

	Pharmacy() {

		ANTIDEPRESSANTS = 200;

		PAINKILLERS = 80;

		ANTIBIOTICS = 100;

		VACCINES = 60;

		LAUGHTER = 0;

	}



	void setMedicationCharges(PatientAccount &p, char type) {

		if (type == 'A' || type == 'a') {

			p.charges += ANTIDEPRESSANTS;

		}
		else if (type == 'B' || type == 'b') {

			p.charges += PAINKILLERS;

		}
		else if (type == 'C' || type == 'c') {

			p.charges += ANTIBIOTICS;

		}
		else if (type == 'D' || type == 'd') {

			p.charges += VACCINES;

		}
		else if (type == 'E' || type == 'e') {

			p.charges += LAUGHTER;

		}
		else {

			std::cout << "Unavailable medication choice " << std::endl;

		}



	}

};

int main() {

	Surgery surgery;

	Pharmacy pharmacy;

	while (true) {

		int days;

		char surgeryType;

		char medicationType;

		std::cout << "Enter number of days spent: " << std::endl;

		std::cin >> days;

		PatientAccount patient(days);

		surgeryType = getSurgeryTypeFromPatient();

		medicationType = getMedicationTypeFromPatient();

		surgery.setSurgeryCharges(patient, surgeryType);

		pharmacy.setMedicationCharges(patient, medicationType);

		/**

		* displaying total charges */

		patient.displayCharges();

		std::cout << "Yes to continue, No to exit." << std::endl;

		char choice;

		std::cin >> choice;

		if (choice != 'y') {

			std::cout << "Thank you for using this program." << std::endl;

			break;

		}

	}

}

//get user input for surgery type

char getSurgeryTypeFromPatient() {

	char surgeryType;

	std::cout << "Enter a surgery type: (a)Brain (b)Heart (c)Knee (d)ACL (e)Plastic" << std::endl;

	std::cin >> surgeryType;

	if (surgeryType != 'a' && surgeryType != 'b' && surgeryType != 'c'&& surgeryType != 'd' && surgeryType != 'e') {

		std::cout << "Invalid choice, try again..." << std::endl;

		return getSurgeryTypeFromPatient();

	}
	else {

		return surgeryType;

	}

}

//get user input for medication type

char getMedicationTypeFromPatient() {

	char medicationType;

	std::cout << "Please enter your choice of medication: (a)Antidepressants (b)Painkillers (c)Antibiotics (d)Vaccines (e)Laughter" << std::endl;

	std::cin >> medicationType;

	if (medicationType != 'a' && medicationType != 'b' && medicationType != 'c' && medicationType != 'd' && medicationType != 'e') {

		std::cout << "Invalid choice, try again..." << std::endl;

		return getMedicationTypeFromPatient();

	}
	else {

		return medicationType;

	}

}
