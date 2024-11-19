# OOP PROJECT Library Management System

## Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Setup Instructions](#setup-instructions)
5. [Usage Guide](#usage-guide)
6. [Code Structure](#code-structure)
7. [Future Improvements](#future-improvements)
8. [License](#license)

---

## Overview

The **Library Management System** is a simple, console-based application developed in C++. It allows library administrators to manage books, members, and transactions (borrowing and returning books) efficiently. The system ensures data persistence across sessions through file handling and provides advanced functionalities like searching, overdue management, and report generation.

---

## Features

### Basic Functionalities
1. **Add Book**  
   Add new books with details such as title, author, and genre.  
2. **Add Member**  
   Register new members with their name, address, and phone number.  
3. **Borrow Book**  
   Enable members to borrow available books.  
4. **Return Book**  
   Process the return of borrowed books and calculate overdue fees.  
5. **View Books**  
   Display all books with their availability status.  
6. **View Members**  
   Display all registered members.  
7. **View Transactions**  
   List all transactions, including borrowing and return history.

### Advanced Functionalities
1. **File Handling**  
   - Store and retrieve data for books, members, and transactions in separate files (`books.txt`, `members.txt`, and `transactions.txt`).  
   - Ensure data persistence across program sessions.  
2. **Search Functionality**  
   - Search books by title.  
   - Search members by name.  
3. **Overdue Management**  
   - Calculate overdue fees for books not returned on time (default: $1 per day after 7 days).  
   - Display members with overdue books and their outstanding fees.  
4. **Reports Generation**  
   - Generate a list of all available books.  
   - Generate a list of all currently borrowed books.  
   - Display members with overdue books.  

---

## Technologies Used
- **Programming Language**: C++  
- **Libraries**:  
  - `iostream`: Input and output operations.  
  - `vector`: Dynamic data storage for books, members, and transactions.  
  - `string`: Text data handling.  
  - `ctime`: Date and time operations for borrowing and returning books.  
  - `fstream`: File handling for data persistence.  

---

## Setup Instructions
1. **Prerequisites**:
   - A C++ compiler (e.g., GCC, Clang, or MSVC).
   - Basic knowledge of running programs in a terminal/IDE.  

2. **Clone or Download the Project**:
   ```bash
   git clone <repository-url>
   cd Library-Management-System
   ```

3. **Compile the Code**:
   Use a C++ compiler to compile the project. For example:  
   ```bash
   g++ library_management.cpp -o library_management
   ```

4. **Run the Program**:
   ```bash
   ./library_management
   ```

5. **File Setup**:
   Ensure the following files are in the same directory as the executable:
   - `books.txt`
   - `members.txt`
   - `transactions.txt`  
   These files will be automatically created if they don't exist.

---

## Usage Guide
1. **Start the Program**:
   Run the program from the terminal or IDE.  
2. **Choose an Option**:
   Use the menu to select an action (e.g., Add Book, Borrow Book).  
3. **Follow Prompts**:
   Input the required details (e.g., book title, member ID) as prompted.  
4. **Exit the Program**:
   Choose the "Exit" option to save all changes to files.  

---

## Code Structure
- **`Book` Class**: Handles book details and availability status.  
- **`Member` Class**: Handles member information.  
- **`Transaction` Class**: Records borrowing and returning activities.  
- **File Handling**:
  - `loadData()`: Reads data from files (`books.txt`, `members.txt`, `transactions.txt`).  
  - `saveData()`: Writes data to files before exiting the program.  
- **Advanced Functionalities**:
  - Search books by title.
  - Search members by name.
  - View overdue members and calculate fees.
  - Generate reports for available and borrowed books.

---

## Future Improvements
1. **GUI Implementation**: Develop a graphical interface for better user experience.  
2. **Advanced Search Options**: Include filters for genres, authors, etc.  
3. **Enhanced Overdue Management**: Send notifications for overdue books via email/SMS.  
4. **User Roles**: Add roles like "Admin" and "Member" with different privileges.  
5. **Database Integration**: Migrate from file-based storage to a relational database (e.g., SQLite, MySQL).  

---

## License
This project is licensed under the MIT License. You are free to use, modify, and distribute the code with proper attribution.

---

Feel free to customize this README for your specific requirements. Let me know if you need further edits!