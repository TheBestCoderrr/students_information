#include "Student.h"

bool Student::operator==(const Student& other) const
{
    return ((Fname == other.Fname) && (Lname == other.Lname) && (Sname == other.Sname));
}

bool Student::operator!=(const Student& other) const
{
    return ((Fname != other.Fname) || (Lname != other.Lname) || (Sname != other.Sname));
}
