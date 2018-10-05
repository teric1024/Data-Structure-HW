/*
  Briefly explain the function of this class.

  @author 			Tu hao wei
  @ID 				B06505001
  @Department 		Engineering Science and Ocean Engineering
  @Affiliation 	    National Taiwan University

  Date.cpp
  version 1.0
*/


#include "Date.h"



/*
   Constructs a Date with the given month, day and year.   If the date is
   not valid, the entire program will halt with an error message.
   @param month is a month, numbered in the range 1...12.
   @param day is between 1 and the number of days in the given month.
   @param year is the year in question, with no digits omitted.

   Grade: 15%
 */
Date::Date(int month, int day, int year) throw(DateException)
{
    try
    {
        if(isValidDate(month,day,year))
        {
            dyear = year;
            dmonth = month;
            ddate = day;
        }
        else
        {
            throw DateException("Invalid Date!!\n");
        }
    }
    catch(DateException &de)
    {
        cout << de.getmsg();
    }
}


/*
 *  Constructs a Date object corresponding to the given string.
 *  @param s should be a string of the form "month/day/year" where month must
 *  be one or two digits, day must be one or two digits, and year must be
 *  between 1 and 4 digits.  If s does not match these requirements or is not
 *  a valid date, the program halts with an error message.
 *
 *  Grade: 30%
 */
Date::Date(const string& s)throw(DateException, DateInputException)
{
    string m, d, y; //declare three string to store date
    int pos[2]= {}; //declare two ints to store positions of '/'
    int month = 0, day = 0, year = 0;
    try
    {
        pos[0] = s.find("/", 0);
        pos[1] = s.find("/", pos[0]+1);
        m = m.assign(s, 0, pos[0]-0);
        d = d.assign(s, pos[0]+1, pos[1]-pos[0]);
        y = y.assign(s, pos[1]+1, s.size());
        if(m.empty() || d.empty() || y.empty())
        {
            throw DateInputException("Missing input!!\n");
        }
        month = stoi(m);
        day = stoi(d);
        year = stoi(y);
        if(!isValidDate(month,day,year))
        {
            throw DateException("Invalid Date!!\n");
        }
        dmonth = month;
        ddate = day;
        dyear = year;
    }
    catch(DateInputException &die)
    {
        cout << die.getmsg();
    }
    catch(DateException &de)
    {
        cout << de.getmsg();
    }
}


/*
 *  Checks whether the given year is a leap year.
 *  @return true if and only if the input year is a leap year.
 *
 *  Grade: 10%
 */
bool Date::isLeapYear(int year) //completed
{
    bool flag = false;
    if(year % 400 == 0)
    {
        flag = true;
    }
    else if(year % 100 == 0)
    {
        flag = false;
    }
    else if(year % 4 == 0)
    {
        flag = true;
    }
    return flag;                    // replace this line with your solution
}


/*
 *  Returns the number of days in a given month.
 *  @param month is a month, numbered in the range 1...12.
 *  @param year is the year in question, with no digits omitted.
 *  @return the number of days in the given month.
 *
 *  Grade: 10%
 */
int Date::daysInMonth(int month, int year) //completed
{
    int days = 0;
    if(month == 2) //address days in Feb
    {
        if(isLeapYear(year))
            days = 29;
        else
            days = 28;
    }
    else
    {
        //discuss in two parts, Jan-Jul, Aug--Dec
        if(month <= 7)
        {
            if(month % 2 == 0)
                days = 30;
            else
                days = 31;
        }
        else
        {
            if(month % 2 == 0)
                days = 31;
            else
                days = 30;
        }
    }
    return days;                           // replace this line with your solution
}


/*
 *  Checks whether the given date is valid.
 *  @return true if and only if month/day/year constitute a valid date.
 *
 *  Years prior to A.D. 1 are NOT valid.
 *
 *  Grade: 20%
 */
bool Date::isValidDate(int month, int day, int year) // completed
{
    bool flag = true;
    //check year
    if(year < 1)
    {
        flag = false;
    }
    else
    {
        //check month
        if(month <= 12 && month >= 1)
        {
            //check date
            if(day < 1)
            {
                flag = false;
            }
            else
            {
                if(day <= daysInMonth(month,year))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
        }
        else
        {
            flag = false;
        }
    }
    return flag;                        // replace this line with your solution
}


/*
 *  Returns a string representation of this Date in the form month/day/year.
 *  The month, day, and year are expressed in full as integers; for example,
 *  10/17/2010 or 5/11/258.
 *  @return a String representation of this Date.
 *
 *  Grade: 20%
 */
string Date::toString()//completed
{
    string ans = to_string(dmonth) + "/"
                 + to_string(ddate) + "/"
                 + to_string(dyear);
    return ans;                     // replace this line with your solution
}


/*
 *  Determines whether this Date is before the Date d.
 *  @return true if and only if this Date is before d.
 *
 *  Grade: 10%
 */
bool Date::isBefore(const Date& d) //completed
{
    bool flag = true;
    // check year
    if(dyear < d.dyear)
    {
        flag = true;
    }
    else if(dyear > d.dyear)
    {
        flag = false;
    }
    else // when dyear is same as d.dyear
    {
        //check month
        if(dmonth < d.dmonth)
        {
            flag = true;
        }
        else if (dmonth > d.dmonth)
        {
            flag = false;
        }
        else // when dmonth is same as d.dmonth
        {
            //check date
            if(ddate < d.ddate)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
    }
    return flag;                        // replace this line with your solution
}


/*
 *  Determines whether this Date is after the Date d.
 *  @return true if and only if this Date is after d.
 *
 *  Grade: 10%
 */
bool Date::isAfter(const Date& d) // completed
{
    bool flag = true;
    if(isEqual(d) || isBefore(d))
    {
        flag = false;
    }
    else
    {
        flag = true;
    }
    return flag;                        // replace this line with your solution
}


/*
 *  Determines whether this Date is equal to the Date d.
 *  @return true if and only if this Date is the same as d.
 *
 *  Grade: 10%
 */
bool Date::isEqual(const Date& d) // completed
{
    bool flag = true;
    if(dyear == d.dyear)
    {
        if(dmonth == d.dmonth)
        {
            if(ddate == d.ddate)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        else
        {
            flag = false;
        }
    }
    else
    {
        flag = false;
    }
    return flag;                        // replace this line with your solution
}


/*
 *  Returns the number of this Date in the year.
 *  @return a number n in the range 1...366, inclusive, such that this Date
 *  is the nth day of its year.  (366 is only used for December 31 in a leap
 *  year.)
 *
 *  Grade: 15%
 */
int Date::dayInYear() // completed
{
    int nthday = 0;
    for(int i = 1; i < dmonth; i += 1)
    {
        nthday += daysInMonth(i,dyear);
    }
    nthday += ddate;
    return nthday;                           // replace this line with your solution
}


/* Determines the difference in days between d and this Date.  For example,
 *  if this Date is 6/16/2006 and d is 6/15/2006, the difference is 1.
 *  If this Date occurs before d, the result is negative.
 *  @return the difference in days between d and this Date.
 *
 *  Grade: 10%
 */
int Date::difference(const Date& d)// cannot use const
{
    int ans = 0;
    Date dc = d;
    if(isEqual(dc))
    {
        ans = 0;
    }
    else if (isBefore(dc))
    {
        //check year
        if(dyear < dc.dyear)
        {
            for(int i = dyear; i < dc.dyear; i += 1)
            {
                if(isLeapYear(i))
                {
                    ans += 366;
                }
                else
                {
                    ans += 365;
                }
            }
        }
        ans -= dayInYear();
        ans += dc.dayInYear();
        ans = 0-ans;
    }
    else
    {
        if(dyear > dc.dyear)
        {
            for(int i = dc.dyear; i < dyear; i += 1)
            {
                if(isLeapYear(i))
                {
                    ans += 366;
                }
                else
                {
                    ans += 365;
                }
            }
        }
        ans -= dc.dayInYear();
        ans += dayInYear();
    }
    return ans;                           // replace this line with your solution
}

