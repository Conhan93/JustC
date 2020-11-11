class Employee
{

  private:
    float worked_hours;
    float hourly_wage;
    float tax_rate;
  public:
    Employee(float hours, float wage = 120, float rate = 0.3)
    {
      worked_hours = hours;
      hourly_wage = wage;
      tax_rate = rate;
    }
    float getHours() { return worked_hours; }
    float getWage() { return hourly_wage; }
    float getRate() { return tax_rate; }

    float calculateSalary()
    {
      return (worked_hours * hourly_wage) * (1 - tax_rate);
    }
};
