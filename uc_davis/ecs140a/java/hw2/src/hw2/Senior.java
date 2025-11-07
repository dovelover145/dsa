package hw2;

public class Senior extends NDSStudent {
	public static final int termFee = 100;
	public static final int baseCreditHrs = 6;
	public static final int creditHrFee = 50;

	public Senior(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs);
	}

	public void printData() {
		System.out.println("ID number: " + studentID);
		System.out.println("Name:      " + firstName + " " + lastName);
		System.out.println("Age:       " + age);
		System.out.println(firstName + " is a non-degree-seeking student enrolled in " + numCreditHrs + " credits");
	}

	public int computeFees() {
		if (numCreditHrs > baseCreditHrs) {
			return termFee + (numCreditHrs - baseCreditHrs) * creditHrFee;
		}
		return termFee;
	}
}