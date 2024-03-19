drop database if exists nithin;
create database nithin;
use nithin;
CREATE TABLE Artist (
  ArtistID INT PRIMARY KEY,
  ArtistFName VARCHAR(50) NOT NULL,
  ArtistLName VARCHAR(50) NOT NULL,
  Salary DECIMAL(10,2)
);

CREATE TABLE Director (
  DirectorID INT PRIMARY KEY,
  DirectorName VARCHAR(50) NOT NULL,
  Address VARCHAR(255),
  Email VARCHAR(50),
  Phone VARCHAR(20)
);

CREATE TABLE Film (
  FilmID INT PRIMARY KEY,
  FilmName VARCHAR(100) NOT NULL,
  ReleaseYear INT,
  Language VARCHAR(50),
  DirectorID INT,
  Duration INT,
  Genre VARCHAR(50),
  FOREIGN KEY (DirectorID) REFERENCES Director(DirectorID)
);

CREATE TABLE Casting (
  ArtistID INT,
  FilmID INT,
  Role VARCHAR(50),
  PRIMARY KEY (ArtistID, FilmID),
  FOREIGN KEY (ArtistID) REFERENCES Artist(ArtistID),
  FOREIGN KEY (FilmID) REFERENCES Film(FilmID)
);

CREATE TABLE Review (
  FilmID INT PRIMARY KEY,
  NoOfStarRatings INT,
  FOREIGN KEY (FilmID) REFERENCES Film(FilmID)
);

INSERT INTO Artist (ArtistID, ArtistFName, ArtistLName, Salary)
VALUES (1, 'Mohanlal', 'Viswanathan', 100000.00),
       (2, 'Mammootty', 'Muhammad Kutty Paniparambil', 120000.00),
       (3, 'Surabhi Lakshmi', 'Gopalakrishnan', 75000.00);

INSERT INTO Director (DirectorID, DirectorName, Address, Email, Phone)
VALUES (101, 'Siddique', 'Kochi, India', 'siddique@movies.com', '+91 9876543210'),
       (102, 'Basil Joseph', 'Trivandrum, India', 'basiljoseph@movies.com', '+91 8765432100');

INSERT INTO Film (FilmID, FilmName, ReleaseYear, Language, DirectorID, Duration, Genre)
VALUES (2001, 'Aadu 2', 2022, 'Malayalam', 101, 130, 'Comedy'),
       (2002, 'Minnal Murali', 2021, 'Malayalam', 102, 145, 'Superhero'),
       (2003, 'Churuli', 2020, 'Malayalam', 101, 120, 'Drama'),
       (2004, 'Kumbalangi Nights', 2019, 'Malayalam', 102, 150, 'Drama');

INSERT INTO Casting (ArtistID, FilmID, Role)
VALUES (1, 2001, 'Shaji'),
       (2, 2001, 'Issa'),
       (3, 2003, 'Elizabeth'),
       (1, 2004, 'Suni');

INSERT INTO Review (FilmID, NoOfStarRatings)
VALUES (2001, 4),
       (2002, 3),
       (2003, 5),
       (2004, 4);
-- 1
SELECT FilmName
FROM Film f
INNER JOIN Director d ON f.DirectorID = d.DirectorID
WHERE d.DirectorName = 'Siddique';
-- 2
SELECT Genre, AVG(Duration) AS AverageDuration
FROM Film
GROUP BY Genre;
-- 3
SELECT a.ArtistFName, a.ArtistLName, f.FilmName, f.ReleaseYear
FROM Artist a
INNER JOIN Casting c ON a.ArtistID = c.ArtistID
INNER JOIN Film f ON c.FilmID = f.FilmID
WHERE f.ReleaseYear BETWEEN 2020 AND 2023;
-- 4
SELECT f.FilmName, r.NoOfStarRatings
FROM Film f
INNER JOIN Review r ON f.FilmID = r.FilmID
ORDER BY r.NoOfStarRatings DESC;
-- 5
SELECT Genre, AVG(r.NoOfStarRatings) AS AverageRating
FROM Film f
INNER JOIN Review r ON f.FilmID = r.FilmID
GROUP BY Genre
ORDER BY AverageRating DESC;
-- 6
UPDATE Review r
INNER JOIN Film f ON r.FilmID = f.FilmID
INNER JOIN Director d ON f.DirectorID = d.DirectorID
SET r.NoOfStarRatings = 5
WHERE d.DirectorName = 'Basil Joseph';
   
 
