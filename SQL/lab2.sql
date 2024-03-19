drop database if exists nithin;
create database nithin;
use nithin;

CREATE TABLE Branch (
  BranchID INT PRIMARY KEY,
  BranchName VARCHAR(50) NOT NULL,
  City VARCHAR(50) NOT NULL
);

CREATE TABLE Customer (
  CustID INT PRIMARY KEY,
  CustName VARCHAR(50) NOT NULL,
  City VARCHAR(50) NOT NULL
);

CREATE TABLE Deposit (
  AccNo INT PRIMARY KEY,
  CustID INT NOT NULL,
  BranchID INT NOT NULL,
  Amount DECIMAL(10,2) NOT NULL,
  Date DATE,
  FOREIGN KEY (CustID) REFERENCES Customer(CustID),
  FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);

CREATE TABLE Loan (
  LoanNo INT PRIMARY KEY,
  CustID INT NOT NULL,
  BranchID INT NOT NULL,
  Amount DECIMAL(10,2) NOT NULL,
  Date DATE,
  FOREIGN KEY (CustID) REFERENCES Customer(CustID),
  FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);
INSERT INTO Branch (BranchID, BranchName, City)
VALUES (1, 'Main Branch', 'New York'),
       (2, 'Central Branch', 'Chicago'),
       (3, 'West Coast Branch', 'Los Angeles');

INSERT INTO Customer (CustID, CustName, City)
VALUES (101, 'John Doe', 'New York'),
       (102, 'Jane Smith', 'Chicago'),
       (103, 'Ajay Kumar', 'New York'),
       (104, 'Michael Lee', 'Los Angeles');

INSERT INTO Deposit (AccNo, CustID, BranchID, Amount, Date)
VALUES (5001, 101, 1, 2000.00, '2024-03-10'),
       (5002, 102, 2, 3500.00, '2024-03-12'),
       (5003, 103, 1, 1800.00, '2024-03-15'),
       (5004, 104, 3, 4200.00, '2024-03-18');

INSERT INTO Loan (LoanNo, CustID, BranchID, Amount, Date)
VALUES (1001, 101, 2, 60000.00, '2024-02-15'),
       (1002, 102, 1, 10000.00, '2024-02-20'),
       (1003, 103, 3, 8000.00, '2024-02-25'),
       (1004, 104, 2, 12000.00, '2024-03-01');
-- 1
SELECT c.CustName, l.LoanNo, l.Amount, l.Date
FROM Customer c
INNER JOIN Loan l ON c.CustID = l.CustID
WHERE l.Amount > 50000.00;
-- 2
SELECT c.CustName, l.LoanNo
FROM Customer c
INNER JOIN Loan l ON c.CustID = l.CustID;
-- 3
SELECT City, COUNT(*) AS TotalCustomers
FROM Customer
GROUP BY City;
-- 4
SELECT c.CustName, l.LoanNo, l.Amount, l.Date
FROM Customer c
INNER JOIN Loan l ON c.CustID = l.CustID
WHERE l.Amount BETWEEN 5000.00 AND 15000.00
ORDER BY c.CustName;
-- 5
SELECT SUM(Amount) AS TotalDeposit
FROM Deposit d
INNER JOIN Customer c ON d.CustID = c.CustID
WHERE c.City = 'New York';
-- 6
SELECT c.CustName, d.Amount, b.City AS BranchCity
FROM Customer c
INNER JOIN Deposit d ON c.CustID = d.CustID
INNER JOIN Branch b ON d.BranchID = b.BranchID
ORDER BY BranchCity, c.CustName;
   
   