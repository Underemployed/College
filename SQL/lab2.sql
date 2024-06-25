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

INSERT INTO customer (custid, custname, city)
VALUES (101, 'john doe', 'Thiruvananthapuram'),
       (102, 'jane smith', 'Kottayam'),
       (103, 'Ajay kumar', 'Thiruvananthapuram'),
       (104, 'michael lee', 'Kochi');

INSERT INTO deposit (accno, custid, branchid, amount, date)
VALUES (5001, 101, 1, 2000.00, '2024-03-10'),
       (5002, 102, 2, 3500.00, '2024-03-12'),
       (5003, 103, 1, 1800.00, '2024-03-15'),
       (5004, 104, 3, 4200.00, '2024-03-18');

INSERT INTO loan (loanno, custid, branchid, amount, date)
VALUES (1001, 101, 2, 60000.00, '2024-02-15'),
       (1002, 102, 1, 10000.00, '2024-02-20'),
       (1003, 103, 3, 8000.00, '2024-02-25'),
       (1004, 104, 2, 12000.00, '2024-03-01');

-- (a) Count the total number of customers in each city.
SELECT city, COUNT(custid) total_customers
FROM customer
GROUP BY city;
-- +--------------------+-----------------+
-- | city               | total_customers |
-- +--------------------+-----------------+
-- | Thiruvananthapuram |               2 |
-- | Kottayam           |               1 |
-- | Kochi              |               1 |
-- +--------------------+-----------------+

-- (b) Find the total deposit of customers living in the same city that Ajay is also living.
SELECT SUM(amount) total_deposit
FROM deposit d
JOIN customer c ON d.custid = c.custid
WHERE c.city = (SELECT city FROM customer WHERE custname = 'Ajay kumar');
-- +---------------+
-- | total_deposit |
-- +---------------+
-- |       3800.00 |
-- +---------------+

-- (c) List the name and deposit amount of all depositors and order them by the branch city.
SELECT c.custname, d.amount, b.city
FROM customer c
JOIN deposit d ON c.custid = d.custid
JOIN branch b ON d.branchid = b.branchid
ORDER BY b.city;
-- +-------------+---------+--------------------+
-- | custname    | amount  | city               |
-- +-------------+---------+--------------------+
-- | michael lee | 4200.00 | Kochi              |
-- | jane smith  | 3500.00 | Kottayam           |
-- | john doe    | 2000.00 | Thiruvananthapuram |
-- | Ajay kumar  | 1800.00 | Thiruvananthapuram |
-- +-------------+---------+--------------------+

-- (d) Find the number of customers who are depositors as well as borrowers.
SELECT COUNT(DISTINCT c.custid) num_customers
FROM customer c
JOIN deposit d ON c.custid = d.custid
JOIN loan l ON c.custid = l.custid;
-- +---------------+
-- | num_customers |
-- +---------------+
-- |             4 |
-- +---------------+

-- (e) Display the customer name, along with the date they have deposited and the amount.
SELECT custname, d.date, d.amount
FROM customer c
JOIN deposit d ON c.custid = d.custid;
-- +-------------+------------+---------+
-- | custname    | date       | amount  |
-- +-------------+------------+---------+
-- | john doe    | 2024-03-10 | 2000.00 |
-- | jane smith  | 2024-03-12 | 3500.00 |
-- | Ajay kumar  | 2024-03-15 | 1800.00 |
-- | michael lee | 2024-03-18 | 4200.00 |
-- +-------------+------------+---------+

-- (f) Display the count of customers who have taken a loan and belonging to Kottayam.
SELECT COUNT(c.custid) num_customers
FROM customer c
JOIN loan l ON c.custid = l.custid
WHERE c.city = 'Kottayam';
SELECT COUNT(custid) num_customers
FROM loan 
where custid in (SELECT custid from customer where city = "Kottayam");
-- +---------------+
-- | num_customers |
-- +---------------+
-- |             1 |
-- +---------------+

-- (g) Display the average loan amount. Round the result to two decimal places.
SELECT ROUND(AVG(amount), 2) average_loan_amount
FROM loan;
-- +---------------------+
-- | average_loan_amount |
-- +---------------------+
-- |            22500.00 |
-- +---------------------+

-- (h) Display the total loan which is given from each branch.
SELECT branchname, SUM(amount) total_loan
FROM branch b
JOIN loan l ON b.branchid = l.branchid
GROUP BY branchname;
-- +-------------------+------------+
-- | branchname        | total_loan |
-- +-------------------+------------+
-- | main branch       |   10000.00 |
-- | central branch    |   72000.00 |
-- | west coast branch |    8000.00 |
-- +-------------------+------------+

-- (i) Display the total deposit amount branch-wise.
SELECT branchname, SUM(amount) total_deposit
FROM branch b
JOIN deposit d ON b.branchid = d.branchid
GROUP BY branchname;
-- +-------------------+---------------+
-- | branchname        | total_deposit |
-- +-------------------+---------------+
-- | main branch       |       3800.00 |
-- | central branch    |       3500.00 |
-- | west coast branch |       4200.00 |
-- +-------------------+---------------+

-- (j) List the total deposit of customers living in Thiruvananthapuram.
SELECT SUM(amount) total_deposit_thiruvananthapuram
FROM deposit d
JOIN customer c ON d.custid = c.custid
WHERE city = 'Thiruvananthapuram';

-- +----------------------------------+
-- | total_deposit_thiruvananthapuram |
-- +----------------------------------+
-- |                          3800.00 |
-- +----------------------------------+

-- (k) Find the biggest deposit amount of the customers living in Kochi.
SELECT MAX(d.amount) biggest_deposit_kochi
FROM deposit d
JOIN customer c ON d.custid = c.custid
WHERE c.city = 'Kochi';
-- +-----------------------+
-- | biggest_deposit_kochi |
-- +-----------------------+
-- |               4200.00 |
-- +-----------------------+

-- (l) Count the number of customers in each branch.
SELECT branchname, COUNT(DISTINCT d.custid) num_customers
FROM branch b
 JOIN deposit d ON b.branchid = d.branchid
 JOIN loan l ON b.branchid = l.branchid
GROUP BY branchname;
-- +-------------------+---------------+
-- | branchname        | num_customers |
-- +-------------------+---------------+
-- | central branch    |             1 |
-- | main branch       |             2 |
-- | west coast branch |             1 |
-- +-------------------+---------------+

-- (m) Find the maximum loan amount of each branch.
SELECT branchname, MAX(amount) max_loan_amount
FROM branch b
LEFT JOIN loan l ON b.branchid = l.branchid
GROUP BY branchname;
-- +-------------------+-----------------+
-- | branchname        | max_loan_amount |
-- +-------------------+-----------------+
-- | main branch       |        10000.00 |
-- | central branch    |        60000.00 |
-- | west coast branch |         8000.00 |
-- +-------------------+-----------------+

-- (n) List the total deposit amount per branch by customers after 1st Jan 2022.
SELECT branchname, SUM(amount) total_deposit
FROM branch b
JOIN deposit d ON b.branchid = d.branchid
JOIN customer c ON d.custid = c.custid
WHERE date > '2022-01-01'
GROUP BY branchname;
-- +-------------------+---------------+
-- | branchname        | total_deposit |
-- +-------------------+---------------+
-- | main branch       |       3800.00 |
-- | central branch    |       3500.00 |
-- | west coast branch |       4200.00 |
-- +-------------------+---------------+


