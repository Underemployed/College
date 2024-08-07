drop database if exists lab;

create database lab;
use lab
create table supplier(
    sno varchar(30) primary key,
    sname   varchar(30),
    address varchar(30)
);

delimiter //

create trigger supplier_s 
before insert on supplier
For each row 
begin 
    IF NEW.sno NOT like 's%' THEN
        SIGNAL SQLSTATE  "45000"
            set MESSAGE_TEXT = "must start with s";
    END IF;
end;//


delimiter ;


create table part(
    pno varchar(30) primary key,
    pname varchar(30),
    color varchar(30)
);

create table catalog(
    sno varchar(30),
    foreign key(sno) REFERENCES supplier(sno),
    pno varchar(30),
    foreign key(pno) REFERENCES part(pno),
    cost int,
    primary key(sno, pno)
);

delimiter //
create trigger catalog_cost 
before insert on catalog
for each row
begin 
    if new.cost < 0 then 
    SIGNAL Sqlstate "45000" 
        set MESSAGE_TEXT = "Cost must be greater than 0 dumbass";
    End if;
end//

delimiter ;


-- ===============================================================================

-- Insert into supplier table
INSERT INTO supplier (sno, sname, address) VALUES ('s001', 'Supplier One', '123 Main St');
INSERT INTO supplier (sno, sname, address) VALUES ('s002', 'Supplier Two', '456 Elm St');
INSERT INTO supplier (sno, sname, address) VALUES ('s003', 'Supplier Three', '789 Oak St');

-- Insert into part table
INSERT INTO part (pno, pname, color) VALUES ('p001', 'Part One', 'Red');
INSERT INTO part (pno, pname, color) VALUES ('p002', 'Part Two', 'Blue');
INSERT INTO part (pno, pname, color) VALUES ('p003', 'Part Three', 'Green');

-- Insert into catalog table
INSERT INTO catalog (sno, pno, cost) VALUES ('s001', 'p001', 1300);
INSERT INTO catalog (sno, pno, cost) VALUES ('s001', 'p002', 150);
INSERT INTO catalog (sno, pno, cost) VALUES ('s001', 'p003', 200);

INSERT INTO catalog (sno, pno, cost) VALUES ('s002', 'p001', 110);
INSERT INTO catalog (sno, pno, cost) VALUES ('s002', 'p002', 160);
INSERT INTO catalog (sno, pno, cost) VALUES ('s002', 'p003', 210);

INSERT INTO catalog (sno, pno, cost) VALUES ('s003', 'p001', 120);
INSERT INTO catalog (sno, pno, cost) VALUES ('s003', 'p002', 170);
INSERT INTO catalog (sno, pno, cost) VALUES ('s003', 'p003', 220);
de
-- ===============================================================================

SELECT p.pno, p.pname 
FROM part p 
JOIN catalog c ON p.pno = c.pno ;


select  c.sno ,sname from catalog c
join supplier s on s.sno = c.sno  
group by s.sname,s.sno having count(distinct c.pno)  =  (select count(distinct p1.pno) from part p1);



select distinct s.sno,s.sname from supplier s inner join catalog c 
on s.sno = c.sno where (c.pno,c.cost)  in (
select c1.pno,max(c1.cost) from catalog c1 group by c1.pno);


select c.sno  from catalog c inner join part p 
on c.pno = p.pno 
where lower(p.color) = "green" 
intersect
select c.sno from catalog c inner join part p 
on c.pno = p.pno 
where lower(p.color) = "red" 

select c.sno,c.pno  from catalog c inner join part p 
on c.pno = p.pno 
where lower(p.color) = "green" group by c.pno 
having count(distinct c) = 1;