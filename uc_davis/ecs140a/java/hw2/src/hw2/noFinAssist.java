package hw2;

public class noFinAssist extends DSStudent { // Degree-seeking student with financial aid
	public noFinAssist(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs,
			String inMajor, String inAcademicStanding) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs, inMajor, inAcademicStanding);
	}

	public void printData() {
		System.out.println("ID number: " + studentID);
		System.out.println("Name:      " + firstName + " " + lastName);
		System.out.println("Age:       " + age);
		System.out.println(firstName + " is a degree-seeking student enrolled in " + numCreditHrs + " credits");
		System.out.println(firstName + "'s major is " + getMajor());
		System.out.println(firstName + "'s academic standing is " + getAcademicStanding());
	}

	public int computeFees() {
		int fee;
		if (numCreditHrs < maxCreditHrs) {
			fee = recreationAndAthleticsFee + studentUnionFee + creditHrFee * numCreditHrs;
		} else {
			fee = recreationAndAthleticsFee + studentUnionFee + creditHrFee * maxCreditHrs;
		}
		return fee;
	}
}
