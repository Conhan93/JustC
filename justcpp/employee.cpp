#include "Employee.h"

Employee::Employee(float worked_hours, float hourly_wage, float tax_rate)
{
  this->worked_hours = worked_hours;
  this->hourly_wage = hourly_wage;
  this->tax_rate = tax_rate;
}
float Employee::calculateSalary()
{
  return (this->worked_hours * this->hourly_wage) * (1 - this->tax_rate);
}
