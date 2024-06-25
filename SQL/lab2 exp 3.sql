
-- =========================================================== 
-- =========================================================== 
-- EXP 3
-- ===========================================================
-- ===========================================================

CREATE TABLE branch (
  branchid int primary key,
  branchname varchar(50) NOT null,
  city varchar(50) NOT null
);

CREATE TABLE customer (
  custid int primary key,
  custname varchar(50) NOT null,
  city varchar(50) NOT null
);

CREATE TABLE deposit (
  accno int primary key,
  custid int NOT null,
  branchid int NOT null,
  amount decimal(10,2) NOT null,
  date date,
  foreign key (custid) references customer(custid),
  foreign key (branchid) references branch(branchid)
);

CREATE TABLE loan (
  loanno int primary key,
  custid int NOT null,
  branchid int NOT null,
  amount decimal(10,2) NOT null,
  date date,
  foreign key (custid) references customer(custid),
  foreign key (branchid) references branch(branchid)
);
DROP DATABASE IF EXISTS nithin;
CREATE DATABASE nithin;
USE nithin;

CREATE TABLE branch (
  branchid int primary key,
  branchname varchar(50) NOT null,
  city varchar(50) NOT null
);

CREATE TABLE customer (
  custid int primary key,
  custname varchar(50) NOT null,
  city varchar(50) NOT null
);

CREATE TABLE deposit (
  accno int primary key,
  custid int NOT null,
  branchid int NOT null,
  amount decimal(10,2) NOT null,
  date date,
  foreign key (custid) references customer(custid),
  foreign key (branchid) references branch(branchid)
);

CREATE TABLE loan (
  loanno int primary key,
  custid int NOT null,
  branchid int NOT null,
  amount decimal(10,2) NOT null,
  date date,
  foreign key (custid) references customer(custid),
  foreign key (branchid) references branch(branchid)
);
INSERT INTO branch (branchid, branchname, city)
VALUES (1, 'main branch', 'Thiruvananthapuram'),
       (2, 'central branch', 'Kottayam'),
       (3, 'west coast branch', 'Kochi');
       (4, 'Super branch', 'Kochi');

INSERT INTO customer (custid, custname, city)
VALUES (101, 'john doe', 'Thiruvananthapuram'),
       (102, 'jane smith', 'Kottayam'),
       (103, 'Ajay kumar', 'Thiruvananthapuram'),
       (104, 'michael lee', 'Kochi'),
       (105, 'Sally', 'Kochi'),


INSERT INTO deposit (accno, custid, branchid, amount, date)
VALUES (5001, 101, 1, 2000.00, '2020-03-10'),
       (5002, 102, 2, 3500.00, '2019-11-12'),
       (5003, 103, 1, 1800.00, '2024-03-15'),
       (5004, 105, 4, 4200.00, '2024-03-18');

INSERT INTO loan (loanno, custid, branchid, amount, date)
VALUES (1001, 101, 2, 60000.00, '2024-02-15'),
       (1002, 102, 1, 10000.00, '2024-02-20'),
       (1003, 103, 3, 5000.00, '2024-02-25'),
       (1004, 104, 2, 12000.00, '2024-03-01');

-- (a) Display the details of all customers having a loan amount greater than 50000.

-- (b) Display the names of all borrowers and their corresponding loan numbers.


-- (d) Display the details of customers (in alphabetical order of their name) having a loan amount between 5000 and 15000.


-- (e) Display the customer name and branch name of customers who have made a deposit on or before 25-12-2020.


-- (f) Display the customer name, along with the date they have deposited and the amount.


-- (g) Display the names of all customers who have made deposits between 31 Oct 2019 and 31 Dec 2020.

-- (h) Display the customers whose name starts with 'S' and the branch in which they have deposited. Branch name should also start with 'S'.