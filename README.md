Hotel Management System – C Project
Overview

The Hotel Management System is a console-based application written in C that helps manage basic hotel operations such as room bookings, customer records, and billing. Designed for learning and educational purposes, the system demonstrates core programming concepts including file handling, structures, arrays, functions, and menu-driven programming.

Features

Room Booking

Check room availability

Book rooms for customers

Store customer details

Customer Management

Add new customer information

View customer records

Search customers by room number or name

Room Management

Display all available and occupied rooms

Update or modify room status

Billing

Calculate total charges based on room type and number of days

Generate a simple invoice

File Handling

Save customer and room data in text files

Load existing data when the program starts

Technologies Used

Programming Language: C

Concepts Used:

Structures

File I/O

Functions

Loops and conditional statements

Menu-driven interface

How It Works

The user is presented with a menu to choose an operation.

Based on input, the system performs actions such as booking a room, viewing customer data, or generating a bill.

Data is stored persistently using external files so that bookings remain available even after restarting the program.

Project Goals

This project is intended for:

Students learning C programming

Demonstrating the use of file handling and structures

Understanding basic hotel workflow simulation

Limitations

No graphical interface (console-based only)

Single-user mode only

Does not handle advanced features like online booking, authentication, or multi-branch management

Future Enhancements

Add user authentication

Add graphical interface using GTK or other C libraries

Implement database storage (MySQL/SQLite)



OUTPUT-:
PS C:\Users\rajal\OneDrive\Desktop\project> cd 'c:\Users\rajal\OneDrive\Desktop\project\output'
PS C:\Users\rajal\OneDrive\Desktop\project\output> & .\'hotel_managment.exe'

========= HOTEL MANAGEMENT SYSTEM =========
1. Add Customer
2. Display All Customers
3. Search Customer
4. Delete Customer
5. Exit
Enter Your Choice: 1

Enter Room Number: 12
Enter Customer Name: Disha
Enter Address: Ranchi
Enter Phone Number: 34677546789
Enter Number of Days Stayed: 5 

Customer Added Successfully!

========= HOTEL MANAGEMENT SYSTEM =========
1. Add Customer
2. Display All Customers
3. Search Customer
4. Delete Customer
5. Exit
Enter Your Choice: 3

Enter Room Number to Search: 12

Record Found!
Room No : 12
Name    : Disha
Address : Ranchi
Phone   : 34677546789
Days    : 5
Bill    : 7500.00

========= HOTEL MANAGEMENT SYSTEM =========
1. Add Customer
2. Display All Customers
3. Search Customer
4. Delete Customer
5. Exit
Enter Your Choice:

Add advanced billing features and reporting

Support for multiple hotel branches
