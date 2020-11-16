#ifndef EMPLOYEE_INCLUDED
#define EMPLOYEE_INCLUDED

class Employee
{

  public:
    Employee(float worked_hours, float hourly_wage = 120, float tax_rate = 0.3);

    float calculateSalary();
  private:
    float worked_hours;
    float hourly_wage;
    float tax_rate;
};
#endif
