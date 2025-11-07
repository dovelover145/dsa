package hw2;

public class FinAssist extends DSStudent {
	protected int finAssist;

	public FinAssist(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs,
			String inMajor, String inAcademicStanding, int inFinAssist) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs, inMajor, inAcademicStanding);
		finAssist = inFinAssist;
	}

	public void printData() {
		System.out.println("ID number: " + studentID);
		System.out.println("Name:      " + firstName + " " + lastName);
		System.out.println("Age:       " + age);
		System.out.println(firstName + " is a degree-seeking student enrolled in " + numCreditHrs + " credits");
		System.out.println(firstName + " receives $" + finAssist + ".00 in financial assistance per term");
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
		fee -= finAssist;
		if (fee > 0) {
			return fee;
		} else {
			return 0;
		}
	}
}