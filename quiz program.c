#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 50
#define MAX_ID 20
#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz.
#define TOTAL_QUESTIONS 5

typedef struct {
  char question[MAX_QUESTION];
  char answerA[MAX_ANSWER];
  char answerB[MAX_ANSWER];
  char answerC[MAX_ANSWER];
  char answerD[MAX_ANSWER];
  char correct_answer;
} quiz_question;

typedef struct {
  char name[MAX_NAME];
  char id[MAX_ID];
  int correct_answers;
} student_info;

void saveQuizToFile(quiz_question quiz[], int total_questions, const student_info *student) {
  FILE *file = fopen("quiz_results.txt", "w");
  if (file == NULL) {
    printf("Error opening file for writing.\n");
    return;
  }

  // Write student information to file
  fprintf(file, "Student Name: %s\n", student->name);
  fprintf(file, "Student ID: %s\n", student->id);
  fprintf(file, "Correct Answers: %d/%d\n\n", student->correct_answers, total_questions);

  // Write quiz questions and answers to file
  for (int i = 0; i < total_questions; i++) {
    fprintf(file, "Question %d: %s\n", i + 1, quiz[i].question);
    fprintf(file, "A) %s\n", quiz[i].answerA);
    fprintf(file, "B) %s\n", quiz[i].answerB);
    fprintf(file, "C) %s\n", quiz[i].answerC);
    fprintf(file, "D) %s\n", quiz[i].answerD);
    fprintf(file, "Correct Answer: %c\n\n", quiz[i].correct_answer);
  }

  fclose(file);
  printf("Quiz results saved to quiz_results.txt\n");
}

int main(void) {
  quiz_question quiz[TOTAL_QUESTIONS];
  student_info student;

  // Get student name
  printf("Enter student name: ");
  fgets(student.name, sizeof(student.name), stdin);
  student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character if present

  // Get student ID
  printf("Enter student ID: ");
  fgets(student.id, sizeof(student.id), stdin);
  student.id[strcspn(student.id, "\n")] = '\0'; // Remove newline character if present

  // Initialize quiz questions
  strcpy(quiz[0].question, "What does the ++ operator do?");
  strcpy(quiz[0].answerA, "Add two to a number");
  strcpy(quiz[0].answerB, "Add one to a number");
  strcpy(quiz[0].answerC, "Subtract one from a number");
  strcpy(quiz[0].answerD, "Subtract two from a number");
  quiz[0].correct_answer = 'B';
   // Create the second quiz question
  strcpy(quiz[1].question, "C is a successor of which language?");
  strcpy(quiz[1].answerA, "B");
  strcpy(quiz[1].answerB, "C++");
  strcpy(quiz[1].answerC, "Python");
  strcpy(quiz[1].answerD, "Java");
  quiz[1].correct_answer = 'A';
 // Create the third quiz question
  strcpy(quiz[2].question, "When is a do-while loop condition checked?");
  strcpy(quiz[2].answerA, "Before the loop body executes");
  strcpy(quiz[2].answerB, "Never");
  strcpy(quiz[2].answerC, "While the loop body executes");
  strcpy(quiz[2].answerD, "After the loop body executes");
  quiz[2].correct_answer = 'D';

  // Create the fourth quiz question
  strcpy(quiz[3].question, "What does a pointer variable store?");
  strcpy(quiz[3].answerA, "A floating-point number");
  strcpy(quiz[3].answerB, "A string");
  strcpy(quiz[3].answerC, "A memory address");
  strcpy(quiz[3].answerD, "An array");
  quiz[3].correct_answer = 'C';

  // Create the fifth quiz question
  strcpy(quiz[4].question, "How can we check if x does not equal y in C?");
  strcpy(quiz[4].answerA, "x <> y");
  strcpy(quiz[4].answerB, "x != y");
  strcpy(quiz[4].answerC, "x === y");
  strcpy(quiz[4].answerD, "x DNE y");
  quiz[4].correct_answer = 'B';

  int total_correct = 0;

  // Declare variable to store the answers entered by the user
  char answer;

  // Loop through quiz questions
  for (int i = 0; i < TOTAL_QUESTIONS; i++) {
    printf("Question %d: %s\n\n", (i+1), quiz[i].question);

    // Output the possible answers as a menu of options A,B,C, or D
    printf("A) %s\n", quiz[i].answerA);
    printf("B) %s\n", quiz[i].answerB);
    printf("C) %s\n", quiz[i].answerC);
    printf("D) %s\n", quiz[i].answerD);

    // Prompt the user to enter either A,B,C, or D
    printf("\nEnter Answer (A,B,C or D): ");

    scanf(" %c", &answer);

    // Check if answer is correct
    if (toupper(answer) == quiz[i].correct_answer) {
      total_correct++;
      printf("\n\nCorrect Answer!");
    } else {
      printf("\n\nIncorrect Answer!");
      printf("\n\nThe correct answer was %c.", quiz[i].correct_answer);
    }

    // Output newlines to separate the questions
    printf("\n\n\n");
  }

  // Update student's correct answers count
  student.correct_answers = total_correct;

  // Call the function to save the quiz results to a file
  saveQuizToFile(quiz, TOTAL_QUESTIONS, &student);

  return 0;
}
