package hw2;

public class Certificate extends NDSStudent {
	public static final int termFee = 700;
	public static final int creditHrFee = 300;
	private String certificate;

	public Certificate(String inStudentID, String inFirstName, String inLastName, int inAge,
			int inNumCreditHrs, String inCertificate) {
		super(inStudentID, inFirstName, inLastName, inAge, inNumCreditHrs);
		certificate = inCertificate;
	}

	public void printData() {
		System.out.println("ID number: " + studentID);
		System.out.println("Name:      " + firstName + " " + lastName);
		System.out.println("Age:       " + age);
		System.out.println(firstName + " is a non-degree-seeking student enrolled in "
				+ numCreditHrs + " credits");
		System.out.println(firstName + "'s certificate is " + getCertificate());
	}

	public int computeFees() {
		return termFee + numCreditHrs * creditHrFee;
	}

	protected String getCertificate() {
		if (certificate.equals("S")) {
			return "gaming science";
		} else if (certificate.equals("M")) {
			return "hotel management";
		} else if (certificate.equals("A")) {
			return "lounge arts";
		} else { // "E"
			return "beverage engineering";
		}
	}
}