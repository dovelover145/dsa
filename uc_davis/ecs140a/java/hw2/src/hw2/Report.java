package hw2;

import java.util.*;
import java.io.*;
// TODO: Make sure you create a package named hw2 and add the package name to every Java file 

/*
 * To ensure you get graded correctly by autograder, 
 * DO NOT change the file name (Report.java), method name (generateReport), or add parameters to this method.
 * Fill in your code where there is a TODO comment.
 * Use the provided variables in the reportBuilder code. 
 * Check if your generateReport() output is equal to hw2_output.txt (String.equals())
 * 
 * Questions or comments? Direct them to Ty Feng or ask on Piazza
 * 
*/
public class Report {

	// generateReport() should be a public static method that takes no parameters
	// and returns a String
	public static String generateReport() {
		StringBuilder reportBuilder = new StringBuilder();
		// TODO:
		// Read hw2.txt line by line
		// Hardcode "hw2.txt" as your input, which means that you should put hw2.txt
		// right under your Eclipse workspace folder (the top level of the workspace
		// hierarchy).

		// For each record, create an instance from the corresponding class (FinAssist,
		// NoFinAssist, Degree, etc.)

		// Save all instances to a Student[] array. Student is the interface or parent
		// class for all the
		// classes you make.
		Student[] students; // save all the student record objects here

		// DO NOT ADD, CHANGE, OR DELETE ANY reportBuilder code. Use the provided
		// variables.
		// INDIVIDUAL REPORTS, listing of all students and the fees they have each been
		// assessed
		int student_fee = 0; // TODO: Change this! Assign its value in the iteration below and use the
								// provided print statement
		String student_name = ""; // TODO: Change this! Assign its value in the iteration below and use the
									// provided print statement

		// Print out first and last name and fee amount
		reportBuilder.append("Summary of each student's fees assessed: \n\n");
		// TODO: iterate over all Student records and compute the individual
		// student_fee. Assign student_name.
		// TODO: put the following line in your for/while loop so that every student's
		// fee gets printed

		int degree_nofin_fees = 0;
		int degree_fin_fees = 0;
		int certificate_fees = 0;
		int senior_fees = 0;
		int total_fees = 0;

		List<Student> listStudents = new ArrayList<Student>();

		try {
			BufferedReader br = new BufferedReader(new FileReader("hw2.txt"));
			try {
				String line;
				while ((line = br.readLine()) != null) {
					String[] tokens = line.split(";");
					student_name = tokens[1] + " " + tokens[2];
					Student student;
					if (tokens[5].equals("Y")) { // Degree-seeking student
						if (tokens[8].equals("Y")) { // Degree-seeking student with financial assistance
							student = new FinAssist(tokens[0], tokens[1], tokens[2], Integer.valueOf(tokens[3]),
									Integer.valueOf(tokens[4]), tokens[6], tokens[7], Integer.valueOf(tokens[9]));
							student_fee = student.computeFees();
							degree_fin_fees += student_fee;
						} else { // Degree-seeking student without financial assistance
							student = new noFinAssist(tokens[0], tokens[1], tokens[2], Integer.valueOf(tokens[3]),
									Integer.valueOf(tokens[4]), tokens[6], tokens[7]);
							student_fee = student.computeFees();
							degree_nofin_fees += student_fee;
						}
					} else { // Non-degree-seeking student
						if (tokens[6].equals("S")) { // Senior citizen
							student = new Senior(tokens[0], tokens[1], tokens[2], Integer.valueOf(tokens[3]),
									Integer.valueOf(tokens[4]));
							student_fee = student.computeFees();
							senior_fees += student_fee;
						} else { // Certificate student
							student = new Certificate(tokens[0], tokens[1], tokens[2], Integer.valueOf(tokens[3]),
									Integer.valueOf(tokens[4]), tokens[7]);
							student_fee = student.computeFees();
							certificate_fees += student_fee;
						}
					}
					listStudents.add(student);
					reportBuilder
							.append(student_name + " has $" + String.format("%,d", student_fee) + " fees assessed \n");
				}
				total_fees = degree_nofin_fees + degree_fin_fees + certificate_fees + senior_fees;
			} catch (IOException e) {
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		students = listStudents.toArray(new Student[listStudents.size()]);

		// This should work once your Student classes are implemented
		// Don't worry about the string formatting in printData() :)
		// Make sure you do not comment out the following two lines when you submit the
		// hw

		// for (int i = 0; i < students.length; i++) {
		// students[i].printData();
		// System.out.println("");
		// }

		students[0].printData();
		students[1].printData();

		// SUMMARY REPORT of fees assessed for each of the four types of student
		// int degree_nofin_fees = 0;
		// int degree_fin_fees = 0;
		// int certificate_fees = 0;
		// int senior_fees = 0;
		// int total_fees = 0;

		// TODO: Calculate the fees by iterating through all students, or do it in the
		// loop above

		// Print out the total fees for different students
		reportBuilder.append("\n\n");
		reportBuilder.append("Summary of all student fees assessed: \n\n");
		reportBuilder.append(
				"Degree-seeking students without financial assistance: $" + String.format("%,d", degree_nofin_fees)
						+ "\n");
		reportBuilder
				.append("Degree-seeking students with financial assistance: $" + String.format("%,d", degree_fin_fees)
						+ "\n");
		reportBuilder.append("Certificate students: $" + String.format("%,d", certificate_fees) + "\n");
		reportBuilder.append("Senior citizens: $" + String.format("%,d", senior_fees) + "\n\n");
		reportBuilder.append("Total fees assessed: $" + String.format("%,d", total_fees));

		return reportBuilder.toString();
	}

	public static void main(String[] args) {
		// You may test your Report here by comparing the output with the provided
		// hw2_output.txt
		System.out.println(generateReport());
	}
}