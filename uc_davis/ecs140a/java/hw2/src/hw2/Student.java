package hw2;

abstract class Student {
	protected String studentID;
	protected String firstName;
	protected String lastName;
	protected int age;
	protected int numCreditHrs;

	public Student(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs) {
		studentID = inStudentID;
		firstName = inFirstName;
		lastName = inLastName;
		age = inAge;
		numCreditHrs = inNumCreditHrs;
	}

	public abstract void printData();

	public abstract int computeFees();
}