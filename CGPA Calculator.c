#include<stdio.h>
#include<conio.h>
int readMarks(int i,int j); //Function to read Subject Marks
void main()
{
int sem,sub,i,j,status=0;
int marks[8][7];
float gp,cgpa=0,gpa=0;
printf("\t\t\t\tWelcome to GPA Assistant\n\n");
for(i=0;i<8;i++)
{
for(j=0;j<7;j++)
{
    marks[i][j]=-1;
}
}
printf("How many semesters have you completed?(max=8):\t");
scanf("%d",&sem);
if((sem<1)||(sem>8)) //For Input Validation
{
    printf("Invalid Number! Enter Again: ");
    scanf("%d",&sem);
}
for(i=0;i<sem;i++)
{
printf("\n\n\t\t\t*** Semester %d ***\n\n",i+1);
printf("Number of Subjects Taken: ");
scanf("%d",&sub);
if((sub<1)||(sub>7)) //For Input Validation
{
printf("Enter subjects again: ");
scanf("%d",&sub);
}
for(j=0;j<sub;j++)
{
printf("Enter marks in subject# %d: ",j+1);
marks[i][j]=readMarks(i,j); //Calling Function
}
}
for(i=0;i<sem;i++)
{gpa=0;
printf("\n-------------------------------------------\n");
printf("-------------------------------------------\n");
printf("Semester #%d Result :\n",i+1);
printf("-------------------------\n");
printf("-------------------------\n");
printf("Subject No#\t\tMarks\t\tSubject Grade\t\tGPA\n");
for(j=0;j<7;j++)
{
//Using IF Conditions to Print Grade
if(marks[i][j]<=100&&marks[i][j]>=91)
{
gp=4.0;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("A\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=90&&marks[i][j]>=86)
{
gp=3.7;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("A-\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=85&&marks[i][j]>=81)
{
gp=3.3;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("B+\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=80&&marks[i][j]>=76)
{
gp=3.0;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("B\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=75&&marks[i][j]>=71)
{
gp=2.7;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("B-\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=70&&marks[i][j]>=66)
{
gp=2.3;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("C+\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=65&&marks[i][j]>=61)
{
gp=2.0;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("C\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=60&&marks[i][j]>=56)
{
gp=1.7;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("C-\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<=55&&marks[i][j]>=50)
{
gp=1.3;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("D\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]<50&&marks[i][j]>=0)
{
gp=0.0;
gpa=gpa+gp;
printf("%d\t\t\t",j+1);
printf("%d\t\t",marks[i][j]);
printf("F\t\t\t");
printf("%.1f\n",gp);
}
if(marks[i][j]==-1) //Setting Sentinel Value of -1
{
    gpa=gpa/j;
    cgpa=cgpa+gpa;
    break;
}
}
printf("\n");
 //To Print the Final SGPA and CGPA
printf("Semester GPA: %.1f\n",gpa);
printf("CGPA: %.1f\n",cgpa/(i+1));

//To Print the Current Status of Student
/*
    0 = Continued
    1 = Probation
    2 = DI
    3 = Completed
*/
if(status==0)
{
if(gpa<2)
status=1;
else if(gpa>2)
{
if(sem==8)
status=3;
else status=0;
}
}
if(status==1)
{
if(gpa<2)
status=2;
else if(gpa>2)
status=0;
}
if(status==0)
printf("Degree Status: Continued\n");
else if(status==1)
printf("Degree Status: Probation\n");
else if(status==3)
printf("Degree Status: Completed\n");
else if(status==2)
{
printf("Degree Status: DI\n");
if(i=1<=4)
printf("Start over in the first semester\n");
else
printf("Repeat this particular semester\n");
}
}
}
int readMarks(int i,int j)
{
int a;
scanf("%d",&a);
if((a>100)||(a<0))
{
printf("Enter Marks Again: ");
scanf("%d",&a);
}
return(a);
}
