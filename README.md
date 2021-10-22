# Calculator

This is a program that uses the Stack abstract data type to compile a simple arithmetic expression without
parentheses. For example, the expression
                                                  a + b * c - d
should be compiled according to the following table

Operator     Operand1    Operand2    Result

    *            b           c         z
    +            a           z         y
    -            y           d         x
    
The table shows the order in which the operations are performed (*, +, –) and operands for each operator. The
result column gives the name of an identifier (working backward from z) chosen to hold each result. The operands 
are the letters a through m and the operators are (+, –, *, /). 
