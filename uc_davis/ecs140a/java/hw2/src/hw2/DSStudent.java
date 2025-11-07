package hw2;

abstract class DSStudent extends Student { // Degree-seeking student without financial aid
	protected static final int recreationAndAthleticsFee = 100;
	protected static final int studentUnionFee = 50;
	protected static final int creditHrFee = 275;
	protected static final int maxCreditHrs = 12; // Maximum number of credit hours that can be charged for
	protected String major;
	protected String academicStanding;

	public DSStudent(String inStudentID, String inFirstName, String inLastName, int inAge, int inNumCreditHrs,
			String inMajor, String inAcademicStanding) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs);
		major = inMajor;
		academicStanding = inAcademicStanding;
	}

	public abstract void printData();

	public abstract int computeFees();

	protected String getMajor() {
		if (major.equals("S")) {
			return "gaming science";
		} else if (major.equals("M")) {
			return "hotel management";
		} else if (major.equals("A")) {
			return "lounge arts";
		} else { // "E"
			return "beverage engineering";
		}
	}

	protected String getAcademicStanding() {
		if (academicStanding.equals("G")) {
			return "good";
		} else if (academicStanding.equals("W")) {
			return "warning";
		} else { // "P"
			return "probation";
		}
	}
}