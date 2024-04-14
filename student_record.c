#include<stdio.h>
#include<string.h>
 
 // declaring functions for computation of average and the grader
 int average(double [],int size);
 char grader(int average);
 void print_grades(double [], int size);

int main(void){
    //defining the structure called Student with required fields
    struct Student {
        double grades[4];
        char first_name[40];
        char last_name[40];
        char full_name[80];
        char Hall_of_residence[20];
        int number_of_grades;
        char overall_letter_grade;
    }Student;

    struct Student Student1;
    int Average=0;
    Student1.number_of_grades=4;
    // prompting user to input students credentials
    printf("Enter student's First name: ");
    fgets(Student1.first_name,sizeof(Student1.first_name),stdin);

    printf("Enter student's Last name: ");
    fgets(Student1.last_name,sizeof(Student1.last_name),stdin);

    printf("Enter student's Hall of residence: ");
    fgets(Student1.Hall_of_residence,sizeof(Student1.Hall_of_residence),stdin);

    printf("Enter student's Grades:\n");
    for(int i =0 ; i<Student1.number_of_grades; i++){
        scanf("%lf",&Student1.grades[i]);
    }
    printf("\n");
    //computing average and letter grade
    Average = average(Student1.grades,Student1.number_of_grades);
    Student1.overall_letter_grade = grader(Average);
    //output
    strcat(Student1.first_name, Student1.last_name);//concatenation of last and first name
    strcpy(Student1.full_name, Student1.first_name);
    printf("Student's Information\n\n");

    printf("\nFull Name: %s", Student1.full_name);
     
    printf("\nHall of Residence: %s",Student1.Hall_of_residence);
    printf("Grades:");
    print_grades(Student1.grades, Student1.number_of_grades);
    printf("\n");
    printf("Average Grade: %d\n",Average);
    printf("Letter Grade: %c\n",Student1.overall_letter_grade);

    return 0;
}
// function definition for average of students 
int average(double arr[], int size){
    double  Aver=0;
    double sum = 0;
for(int i =0; i<size; i++){
    sum = sum + arr[i];
}
  Aver=(sum/size);
  Aver=((int)Aver);
  return (Aver);
}


//function for grading students based on the average
char grader(int Average){
    if (Average >= 80){
        return 'A';
    }
    else if ((Average < 80) && (Average >= 60))
    {
        return 'B';
    }
    else{
        return 'C';
    }
    
}
//function defintion for printing grades in the array
void print_grades(double arr[],int size){
    int i = 0;
    while (i < size)
    {
        printf(" %d",(int)arr[i]);
        i++;
        if(i < size)
        {
            printf(",");
             }
    }
}
