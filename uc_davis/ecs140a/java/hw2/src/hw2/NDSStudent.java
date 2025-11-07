package hw2;

abstract class NDSStudent extends Student {
	public NDSStudent(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs);
	}

	public abstract void printData();

	public abstract int computeFees();
}