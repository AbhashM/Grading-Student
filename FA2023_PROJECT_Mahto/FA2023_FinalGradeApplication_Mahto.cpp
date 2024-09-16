//FA2023_FinalGradeApplication_Mahto.cpp                 
#include<iostream>//Headers Required
#include<iomanip>
#include<array>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
int displaymenu() {//To display menu to users for selecting their task
	int task;	
		cout << "FA2023_FinalGradeApplication_Mahto.cpp" << endl;
		cout << "TASKS OF GRADING - ABHASH MAHTO" << endl;
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "1.Grading One Student " << endl;
		cout << "2.Search one Student Grade from Printing The Grade of One Student" << endl;
		cout << "3.Printing The Grades of Class" << endl;
		cout << "O.Exit" << endl;
		cout << "Enter Your Task" << endl;
		cin >> task;//Asking user for task
		return task;//Returning task to main 
}
int* size(string ASSIGNMENT_NAMES[]) {//To get the number of Assignments of each category
	static int assignment_size[7];
	 
	
	for (int i = 0; i < 7; i++) {
		cout << "Enter number of " << ASSIGNMENT_NAMES[i] << endl;
		cin >> assignment_size[i];
	}
	
	return assignment_size;
}
float* maxx(string ASSIGNMENT_NAMES[],int* assignment_size ) {//To get max score of each assignment type 
	static float max[7];
	float score = 0;
	for (int i = 0; i < 7; i++) {
		cout << "Enter max score of one " << ASSIGNMENT_NAMES[i] << endl;
		cin >> score;
		max[i] = score * assignment_size[i];
	}
	return max;
}
void task1(string ASSIGNMENT_NAMES [],int* assignment_size, float* max) {//To record each student score in user's desired file
	char decision;//To make the function re do if user's wants to input another student's grade
	do {
		char choice;
		ofstream outfile;
		string  course, student_id, L_student_name, F_student_name, filename;
		float bonus, sum = 0, Total_Sum = 0;
		float Total_max = 0;
		float studentScores[7] = { 0 };
		string scoreString[7];
		float score;
		float numgrade = 0;
		char letter_Grade;
		stringstream Total_MAX;
		cout << "Enter Course Name" << endl;//Asking basic info of student
		cin >> course;
		cout << "Enter Student ID" << endl;
		cin >> student_id;
		cout << "Enter Your Student First Name" << endl;
		cin >> F_student_name;
		cout << "Enter Your Student Last Name" << endl;
		cin >> L_student_name;
		cout << "Enter Bonus Score For Policy Quiz" << endl;
		cin >> bonus;
		for (int i = 0; i < 7; i++) {
			stringstream ScoresString;
			sum = 0;
			cout << "Enter " << ASSIGNMENT_NAMES[i] << " scores" << endl;//To get score of each assignment type
			for (int j = 0; j < assignment_size[i]; j++) {//To get score of each test of a assignment type
				cout << "Enter Score for " << j + 1 << " Test" << endl;
				cin >> score;
				sum = sum + score;//To store the value of total score of one assignmnet type
				ScoresString << score << " ";//To display each test score
				if (j == assignment_size[i] - 1) {
					studentScores[i] = sum;//Assigning total score of each assignment type
					scoreString[i] = ScoresString.str();//Assigning test score of all tests of each assignment type
				}
			}
		}
		for (int i = 0; i < 7; i++) {
			Total_Sum = studentScores[i] + Total_Sum;//To calculate total score of a stdeunt after all test scores are given to program
		}
		Total_Sum += bonus;//Adding policy quiz score to total sum
		for (int i = 0; i < 7; i++) {
			Total_max = max[i] + Total_max;//To calculate total max score of a course
		}
		Total_MAX << Total_max;
		string MAX = Total_MAX.str();//To display it as a string 

		numgrade = 100 * (Total_Sum / Total_max);//To decide the letter grade of a student
		if (numgrade >= 90)
			letter_Grade = 'A';
		else if (numgrade >= 80 && numgrade <= 89)
			letter_Grade = 'B';
		else if (numgrade >= 70 && numgrade <= 79)
			letter_Grade = 'C';
		else if (numgrade >= 60 && numgrade <= 69)
			letter_Grade = 'D';
		else
			letter_Grade = 'F';
		cout << "FA2023_FinalGradeApplication_Mahto.java" << endl;
		cout << "FINAL GRADE OF STUDENT - ABHASH MAHTO" << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(20) << "COURSE NAME:" << course << endl;
		cout << left << setw(20) << "STUDENT ID:" << student_id << endl;
		cout << left << setw(20) << "STUDENT NAME:" << F_student_name << " " << L_student_name << endl;
		cout << "--------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(20) << "EXTRA CREDIT:" << fixed << setprecision(2) << bonus << endl;
		cout << left << setw(20) << "QUIZZES:" << scoreString[0] << endl;
		cout << left << setw(20) << "HOMEWORK:" << scoreString[1] << endl;
		cout << left << setw(20) << "LABS:" << scoreString[2] << endl;
		cout << left << setw(20) << "PROJECT:" << scoreString[3] << endl;
		cout << left << setw(20) << "DISCUSSION:" << scoreString[4] << endl;
		cout << left << setw(20) << "TEAM WORK:" << scoreString[5] << endl;
		cout << left << setw(20) << "TESTS:" << scoreString[6] << endl;
		cout << "---------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(20) << "Total scores:" << Total_Sum << "/" << MAX << endl;
		cout << left << setw(20) << "Numeric grade:" << numgrade << endl;
		cout << left << setw(20) << "Letter grade:" << letter_Grade << endl;
		cout << "PRESS Y IF YOU WANT TO STORE THE GRADE OF THE STUDENT IN A FILE" << endl;
		cin >> choice;
		if (choice == 'Y') {//Asking users if they want to store the data in a file
			cout << "Please Enter the File Name" << endl;
			cin >> filename;
			outfile.open(filename, ios::app);
			outfile << course << "," << student_id << "," << F_student_name << "," << L_student_name << "," << numgrade << "," << letter_Grade << "," << bonus << "," << scoreString[0] << "," << scoreString[1] << "," << scoreString[2] << "," << scoreString[3] << "," << scoreString[4] << "," << scoreString[5] << "," << scoreString[6] << endl;
			outfile.close();//closing the file after the data has been appended
		}
		cout << "PRESS Y IF YOU WANT TO WORK ON ANOTHER STUDENT" << endl;
		cin >> decision;//To make the function run again if user wants to store another student's grade in file
	} while (decision == 'Y');
}
void task2() {//To display a specific student's grade
	string ID, line;	
	ifstream inputfile;
	string Fname = "studentGrade.txt";
	cout << "Please Enter Student ID" << endl;
	cin >> ID;//To ask user which student grade needs to be printed
	inputfile.open(Fname);
	while (!inputfile.eof()) {
		getline(inputfile, line);
		stringstream stream(line);
		string array[14];
		int i = 0;
		while (stream.good()&&i<15) {	//To split the string using , as delimeter
			string word;
			getline(stream, word, ',');
			array[i] = word;
			i++;
		}
		
		if (array[1] == ID) {//To macth the user's ID and IDs available in file "studentGrade.txt"
			cout <<left<< setw(20)<<"Student ID: " << array[1] << endl;
			cout << left << setw(20) << "Student Name: " << array[2] << " " << array[3] << endl;
			cout << left << setw(20) << "Numeric Grade: " << array[4] << endl;
			cout << left << setw(20) << "Letter Grade: " << array[5] << endl;
			cout << left << setw(20) << "Policy Quiz Score: " << array[6] << endl;
			cout << left << setw(20) << "Quizzes Scores: " << array[7] << endl;
			cout << left << setw(20) << "Homework Scores: " << array[8] << endl;
			cout << left << setw(20) << "Lab Scores: " << array[9] << endl;
			cout << left << setw(20) << "Project Score: " << array[10] << endl;
			cout << left << setw(20) << "Teamwork Score: " << array[11] << endl;
			cout << left << setw(20) << "Topic Score: " << array[12] << endl;
			cout << left << setw(20) << "Test Scores: " << array[13] << endl;
		}
		
		
		
	}
	
	inputfile.close();
	
}

void task3() {//To display grades of a whole class or fle
	string fname, line;
	cout << "Please Enter File Name" << endl;
	cin >> fname;//To ask users which file they wanna display 
	ifstream inputfile;
	inputfile.open(fname);
	if (!inputfile.is_open()) {//Checking if the user provided file exists
		cout << "File doesnt exist" << endl;
	}
	else {
		cout << "FA2023_FinalGradeApplication_Mahto.java" << endl;
		cout << "LIST OF STUDENT GRADES - ABHASH MATHO" << endl;
		cout << "-------------------------------------------------------------" << endl;
		while (getline(inputfile, line)) {

			stringstream stream(line);
			string array[6];
			int i = 0;
			while (stream.good() && i < 6) {//Spliting the string with , as delimeter and repeating the loop until it reaches end of file
				string word;
				getline(stream, word, ',');
				array[i] = word;
				i++;
			}
			cout << left << setw(18) << "COURSE NAME: " << array[0] << endl;
			cout << left << setw(18) << "Student ID: " << array[1] << endl;
			cout << left << setw(18) << "Student Name: " << array[2] << " " << array[3] << endl;
			cout << left << setw(18) << "Numeric Grade: " << array[4] << endl;
			cout << left << setw(18) << "Letter Grade: " << array[5] << endl;
			cout << "-------------------------------------------------------------" << endl;
		}
	}
}



int main() {
int* assignment_size;//Pointers for array
float* max;
 string ASSIGNMENT_NAMES[] = { "QUIZ", "HOMEWORK", "LAB", "PROJECT", "TEAMWORK", "DISCUSSION TOPIC", "TEST" };
 assignment_size = size(ASSIGNMENT_NAMES);
 max = maxx(ASSIGNMENT_NAMES,assignment_size);
 int task;
 do {//To keep re displaying menu until user is done
	 task = displaymenu();
	 switch (task) {
	 case 1: 
		 task1(ASSIGNMENT_NAMES, assignment_size, max);//calls function task1
		 break;
	 case 2:
		 task2();//calls function task2
		 break;
	 case 3:
		 task3();//calls function task3
		 break;
	 case 0:
		 break;//Exits loop
	default:
		cout << "Invalid task Please Re-Enter Your Task" << endl;
		break;

	 }

 } while (task != 0);
	system("pause");
	return 0;
}

