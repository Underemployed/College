drop database if exists nithin;
create database nithin;
use nithin;

CREATE TABLE Physician (
  PhyID INT PRIMARY KEY,
  PhyFName VARCHAR(50) NOT NULL,
  PhyLName VARCHAR(50) NOT NULL,
  Address VARCHAR(255),
  Salary DECIMAL(10,2),
  Degree VARCHAR(50)
);

CREATE TABLE PhysicianSpeciality (
  PhyID INT,
  FieldOfSpecialization VARCHAR(50),
  YearOfSpecialization INT,
  FOREIGN KEY (PhyID) REFERENCES Physician(PhyID)
);

CREATE TABLE Nurse (
  NurseID INT PRIMARY KEY,
  NurseFName VARCHAR(50) NOT NULL,
  NurseLName VARCHAR(50) NOT NULL,
  Shift VARCHAR(20)
);

CREATE TABLE Ward (
  WardNum INT PRIMARY KEY,
  WardName VARCHAR(50) NOT NULL,
  NumOfBeds INT,
  NurseID INT,
  PhoneNo VARCHAR(20),
  FOREIGN KEY (NurseID) REFERENCES Nurse(NurseID)
);

CREATE TABLE Patient (
  PatID INT PRIMARY KEY,
  PatFName VARCHAR(50) NOT NULL,
  PatLName VARCHAR(50) NOT NULL,
  Age INT,
  PhyID INT,
  WardNum INT,
  AdmitDate DATE,
  FOREIGN KEY (PhyID) REFERENCES Physician(PhyID),
  FOREIGN KEY (WardNum) REFERENCES Ward(WardNum)
);


INSERT INTO Physician (PhyID, PhyFName, PhyLName, Address, Salary, Degree)
VALUES (1, 'John', 'Smith', '123 Main St', 60000.00, 'MD'),
       (2, 'Jane', 'Doe', '456 Elm St', 75000.00, 'PhD');

INSERT INTO PhysicianSpeciality (PhyID, FieldOfSpecialization, YearOfSpecialization)
VALUES (1, 'Cardiology', 2010),
       (2, 'Dermatology', 2015);

INSERT INTO Nurse (NurseID, NurseFName, NurseLName, Shift)
VALUES (101, 'Alice', 'Johnson', 'Day'),
       (102, 'Bob', 'Williams', 'Night');

INSERT INTO Ward (WardNum, WardName, NumOfBeds, NurseID, PhoneNo)
VALUES (1, 'East Wing', 10, 101, '555-1234'),
       (2, 'West Wing', 8, 102, '555-5678');

INSERT INTO Patient (PatID, PatFName, PatLName, Age, PhyID, WardNum, AdmitDate)
VALUES (1001, 'David', 'Miller', 35, 1, 1, '2024-03-15'),
       (1002, 'Sarah', 'Thompson', 28, 2, 2, '2024-03-18');
-- 1
SELECT PatID, WardNum FROM Patient;
-- 2 
SELECT p.PatFName, p.PatLName, phy.PhyFName, phy.PhyLName
FROM Patient p
INNER JOIN Physician phy ON p.PhyID = phy.PhyID
WHERE WardNum IS NOT NULL;
-- 3
SELECT * FROM Patient p
INNER JOIN Physician phy ON p.PhyID = phy.PhyID
WHERE p.PatFName LIKE 'D%' AND phy.PhyLName = 'Sreekumar';
-- 4
SELECT n.NurseFName, n.NurseLName, n.Shift
FROM Patient p
INNER JOIN Ward w ON p.WardNum = w.WardNum
INNER JOIN Nurse n ON w.NurseID = n.NurseID
WHERE p.PatID = 1001;
-- 5
SELECT * FROM Physician WHERE Salary > 50000.00;
-- 6
SELECT DISTINCT FieldOfSpecialization FROM PhysicianSpeciality;

  
