# Library-Management-System-Cpp
A library management system coded in Cpp - CS253 Assignment 1

To run the program, execute **Main.cpp** in the *Source* folder.
The compilation command to create the executable is as follows:

**g++ Book.cpp Book_Database.cpp User.cpp User_Database.cpp Librarian.cpp Student.cpp Professor.cpp Main.cpp -o Main**

User Database only one admin, one student and one professor with the following details (you can also open User_db.dat to obtain these informations):<br>

Username: **Admin**<br>
Password: **password**

Username: **Soham Samaddar**<br>
Password: **password**

Username: **Indranil Saha**<br>
Password: **password**

Book Database contains 6 books. Please open the Book_db.dat file to obtain the ISBNs of all books since all transactions are made via the ISBN.<br>

Please populate the User Database and Book Database using the Admin.<br>
To create a student, give permission character as **S**<br>
To create a professor, give permission character as **P**<br>
To create an admin, give permission character as **A**<br>

**TO TEST THE FINE SYSTEM, CHANGE SYSTEM DATE AND TIME**<br>
**PLEASE DO NOT GIVE A COMMA IN ANY OF THE INPUTS AS THE INPUTS ARE NOT BEING SANITIZED**
