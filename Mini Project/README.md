#  Design and Development of online banking management system

## Description

The project aims to develop a banking system that is user-friendly and multi-
functional. The project should have the following functionalities:   
* All account transactional details and customer information are stored in files.
* Account holders have to pass through a login system to enter their accounts.
* The application should possess password-protected administrative access; thus
preventing the whole management system from unauthorized access.
* Three types of login should be created: normal user, joint account user; administrator;
* Once you login as administrator, you should be able to add, delete, modify, search for a
specific account details.
* Once the customer connect to the server, you should get login and password prompt.
After successful login, you should get menu for example:
Do you want to:
	* Deposit
	* Withdraw
	* Balance Enquiry
	* Password Change
	* View details
	* Exit
* If you login as a joint account holder, proper file locking should be implemented. If you
want to view the account details then read lock is to be set else if you want to client_withdraw_money
or client_deposit_money then write lock should be used to protect the critical data section.
* Use socket programming – Server maintains the data base and service multiple clients
concurrently. Client program can connect to the server and access their specific account
details.
* Use system calls instead of Library functions wherever it is possible in the project:
Process Management, File Management, File Locking, Multithreading and Inter Process
Communication Mechanisms.

## How to run the system

1. Firstly run the data.c and fill in the sign up details  
```
$ gcc data.c -o data  
$ ./data
```

2. Run the Server  
```
$ gcc -pthread server.c -o server  
$ ./server
```

3. Run the client  
```
$ gcc client.c -o client  
$ ./client
```

