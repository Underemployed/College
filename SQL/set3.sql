drop trv52;
use

create table artist (
    artistid int primary key,
    artistfname varchar(50),
    artistlname varchar(50),
    salary int(10)
);

create table director (
    directorid int primary key,
    directorname varchar(100),
    address varchar(200),
    email varchar(50),
    phone varchar(20)
);

create table film (
    filmid int primary key,
    filmname varchar(100),
    releaseyear int,
    language varchar(50),
    directorid int,
    duration int,
    genre varchar(50),
    foreign key (directorid) references director(directorid)
);

create table casting (
    artistid int,
    filmid int,
    role varchar(50),
    foreign key (artistid) references artist(artistid),
    foreign key (filmid) references film(filmid)
);



create table review (
    filmid int,
    noofstarratings int,
    foreign key (filmid) references film(filmid)
);



