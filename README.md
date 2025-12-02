Abstract
This project implements a simple Bank Transaction Record System using the C programming language. It allows users to create new accounts, deposit and withdraw money, check balances, and display all account records. Data is stored persistently in a file (bankdata.txt) using binary file handling. The system provides a menu-driven interface for easy navigation and ensures basic transaction management for multiple accounts.

Technical Requirements
- Programming Language: C (ANSI C standard)
- Compiler: GCC or any standard C compiler
- Operating System: Windows/Linux (console-based application)
- File Handling:
- Persistent storage using binary files (bankdata.txt)
- Functions: fopen, fread, fwrite, fseek, fclose
- Data Structures:
- struct Account with fields: accountNumber, name, balance
- Input/Output:
- Console-based interaction using printf and scanf
- Menu-driven interface
- Error Handling:
- File open failure checks
- Validation for insufficient balance during withdrawal
- Account existence check before transactions

 Functional Requirements
- Account Management
- Create new account with unique account number,
- Create new account with unique account number, holder name, and initial deposit
- Display all accounts with details (account number, name, balance)
- Transaction Handling
- Deposit money into an existing account
- Withdraw money with balance validation
- Check balance of a specific account
- System Control
- Menu-driven interface with options for each operation
- Exit option to terminate the program safely

