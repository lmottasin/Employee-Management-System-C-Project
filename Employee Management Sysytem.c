#include <stdio.h>
#include <string.h>
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    int ID;
    char name[50];
    char designation[50]; //
    float salary;
    char phone_no[12];
    struct date joining_date;

} employee_information[500];
void add_employee();
int search_id(int emp_id);
void update_info(int emp_id);
int max_sal();
void search_name(char name[]);
float display_avd_sal();
int count_rank(char string[]);
void search_join_date(int day, int month, int year);
void delete_employee();

//struct employee employee_information[500]
int size = 0;

int main()
{

    int n = 0;
    while (n >= 0)
    {
        printf("\n******************************************************\n");
        printf("1. Add new employee\n");
        printf("2. Search an employee by id\n");
        printf("3. Update employee info\n");
        printf("4. Delete employee\n");
        printf("5. Display average salary\n");
        printf("6. Search employee ids after a given joining date\n");
        printf("7. Search employee ids having maximum salary\n");
        printf("8. Search total no of employees by designation\n");
        printf("9. Search employee ids having the given name\n");
        printf(" \n\n Enter -1 to exit.");
        printf("\n******************************************************\n");
        scanf("%d", &n);
        if (n == 1)
        {
            add_employee();
        }
        else if (n == 2)
        {
            int emp_id;
            printf("Enter employee  id to search\n");
            scanf("%d", &emp_id);
            int save = search_id(emp_id);

            if (save == -1)
            {
                printf("Not Found");
            }
            else
            {
                printf("ID: %d\n", employee_information[save].ID);

                printf("name: %s\n", employee_information[save].name);

                printf("Designation: %s\n", employee_information[save].designation);

                printf("Designation: %f\n", employee_information[save].salary);

                printf("Phone no: %s\n", employee_information[save].phone_no);

                printf("Joining Date: %d\t%d\t%d\n", employee_information[save].joining_date.day, employee_information[save].joining_date.month, employee_information[save].joining_date.year);
            }
        }
        else if (n == 3)
        {
            int emp_id;
            printf("\nEnter employee  id to update\n\n");
            scanf("%d", &emp_id);
            update_info(emp_id);
        }
        else if (n == 4)
        {
            delete_employee();
        }
        else if (n == 5)
        {
            float avd_sal = display_avd_sal();
            printf("average salary %f", avd_sal);
        }
        else if (n == 6)
        {
            int day1, month1, year1;
            printf("enter day(space)month(space)year ");
            scanf("%d%d%d", &day1, &month1, &year1);

            search_join_date(day1, month1, year1);
        }
        else if (n == 7)
        {
            int index = max_sal();
            printf("maximum salary :%f  Employee ID %d", employee_information[index].salary, employee_information[index].ID);
        }
        else if (n == 8)
        {
            char string[100];
            printf("\nenter employees by designation\n");
            scanf("%s", string);
            int count = count_rank(string);
            printf("\n There are %d  %s\n", count, string);
        }

        else if (n == 9)
        {
            printf("enter name to search");
            char name[100];
            scanf("%s", &name);
            search_name(name);
        }
    }
    return 0;
}
void add_employee()
{
    printf("Enter ID \n");
    scanf("%d", &employee_information[size].ID);

    printf("Enter Name\n");
    scanf("%s", employee_information[size].name);

    printf("Enter Designation\n");
    scanf("%s", employee_information[size].designation);

    printf("Enter Salary\n");
    scanf("%f", &employee_information[size].salary);

    printf("Enter Phone no\n");
    scanf("%s", employee_information[size].phone_no);

    printf("Enter Joining day\n");
    scanf("%d", &employee_information[size].joining_date.day);
    printf("Enter Joining month\n");
    scanf("%d", &employee_information[size].joining_date.month);
    printf("Enter Joining year\n");
    scanf("%d", &employee_information[size].joining_date.year);
    size++;
}
int search_id(int emp_id)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (emp_id == employee_information[i].ID)
        {
            return i;
            break;
        }
    }
    if (emp_id != employee_information[i].ID)
    {
        return -1;
    }
}
void update_info(int emp_id)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (emp_id == employee_information[i].ID)
        {
            printf("Enter ID \n");
            scanf("%d", &employee_information[i].ID);

            printf("Enter Name\n");
            scanf("%s", employee_information[i].name);

            printf("Enter Designation\n");
            scanf("%s", employee_information[i].designation);

            printf("Enter Salary\n");
            scanf("%f", &employee_information[i].salary);

            printf("Enter Phone no\n");
            scanf("%s", employee_information[i].phone_no);

            printf("Enter Joining day\n");
            scanf("%d", &employee_information[i].joining_date.day);
            printf("Enter Joining month\n");
            scanf("%d", &employee_information[i].joining_date.month);
            printf("Enter Joining year\n");
            scanf("%d", &employee_information[i].joining_date.year);

            printf("\nUpdated Successfully\n\n");
            break;
        }
    }
    if (emp_id != employee_information[i].ID)
    {
        printf("\nNot Exists\n\n");
    }
}
int max_sal()
{
    float max_salary = 0;
    int index;
    int i;
    for (i = 0; i < size; i++)
    {
        if (max_salary < employee_information[i].salary)
        {
            max_salary = employee_information[i].salary;
            index = i;
        }
        return index;
    }
}
void search_name(char name[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(name, employee_information[i].name) == 0)
        {
            printf("name %s and ID %d\n", employee_information[i].name, employee_information[i].ID);
        }
    }
}
float display_avd_sal()
{
    int i;
    float sum = 0, avg;
    for (i = 0; i < size; i++)
    {
        sum += employee_information[i].salary;
    }
    return avg = sum / size;
}

int count_rank(char string[])
{
    int i;
    int count = 0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(string, employee_information[i].designation) == 0)
        {

            count++;
        }
    }
    return count;
}
int day1, month1, year1;
void search_join_date(int day1, int month1, int year1)
{
    int i;
    for (i = 0; i < 500; i++)
    {
        if (employee_information[i].joining_date.year > year1)
        {
            printf("%d\n", employee_information[i].ID);
        }
        else if (employee_information[i].joining_date.year == year1)
        {
            if (employee_information[i].joining_date.month > month1)
                printf("%d\n", employee_information[i].ID);
            else if (employee_information[i].joining_date.month == month1)
            {
                if (employee_information[i].joining_date.day > day1)
                    printf("%d\n", employee_information[i].ID);
            }
        }
    }
}

void delete_employee()
{
    int i;
    int choice;
    int n = 500; // if  employee quantity = 500, if is has initialized before then remove initialization from here...
    printf("Input Id of the employee you want to delete: ");
    scanf("%d", &choice);
    int p = search_id(choice);
    for (i = p; i < 499; i++)
    {
        employee_information[i] = employee_information[i + 1];
    }
    struct employee inco;
    employee_information[i] = inco;
    --size;
}
