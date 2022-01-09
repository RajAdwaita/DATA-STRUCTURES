-- Write the trigger for the following:
-- 1. When a customer cancels the tour, do the necessary process and update the cancellation history table.



-- select 
-- id,
-- min(if(month='Jan',revenue,null)) as Jan_Revenue,
-- min(if(month='Feb',revenue,null)) as Feb_Revenue,
-- min(if(month='Mar',revenue,null)) as Mar_Revenue,
-- min(if(month='Apr',revenue,null)) as Apr_Revenue,
-- min(if(month='May',revenue,null)) as May_Revenue,
-- min(if(month='Jun',revenue,null)) as Jun_Revenue,
-- min(if(month='Jul',revenue,null)) as Jul_Revenue,
-- min(if(month='Aug',revenue,null)) as Aug_Revenue,
-- min(if(month='Sep',revenue,null)) as Sep_Revenue,
-- min(if(month='Oct',revenue,null)) as Oct_Revenue,
-- min(if(month='Nov',revenue,null)) as Nov_Revenue,
-- min(if(month='Dec',revenue,null)) as Dec_Revenue

-- from Department 
-- group by id
-- order by id


-- update Salary 
-- set sex= if(sex='m', 'f','m')



-- select * from Cinema
-- where id%2<>0 and description='boring'

-- select firstName, lastName, city, state from Person left join Address
-- on Person.personId=Address.personId;


-- select e1.name as Employee from Employee e1 inner join (select * from Employee) e2 on e1.managerId=e2.id
-- where e1.salary>e2.salary;

-- create table data1(
--     id int not null , 
--     name char(20),
--     primary key(id),
--     t timestamp
-- );

-- insert into data1 values(1111,'one',systimestamp);


-- select driver_id from driver_details join cab_booking 
-- on driver_details.cab_id=cab_booking.cab_id join tour_booking
-- on cab_booking.tour_booking_id=tour_booking.booking_id join customer_details on 
-- tour_booking.customer_id=customer_details.customer_id where 
-- customer_details.first_name='Tom' ;


-- begin
-- for a in 1..5 
-- loop
-- dbms_output.put_line('Hello World');
-- end loop;
-- end;

-- update Dept_Instcount set 
-- budget = 30 
-- where count(instructor_id)>2;

-- create or replace procedure calc_disp(x in char, y in char, z out char) is
-- -- declare 
-- -- a char(25);
-- -- b char(25);
-- -- c char(25);
-- z customer_details.first_name%type;
-- begin
-- select first_name into z from customer_details join tour_booking 
-- on customer_details.customer_id=tour_booking.customer_id 
-- join tour on tour.tour_id=tour_booking.tour_id
-- where tour.place_from='x' and tour.place_to='y';
-- dbms_output.put_line(z);
-- end calc_disp;


-- variable nn char(25);
-- create or replace procedure calcdisp(
--     f in flight_booking.flight_from%type,
--     t in flight_booking.flight_to%type,
--     n1 out customer_details.first_name%type
-- ) is 
-- begin
--     select first_name into n1 from customer_details where customer_id in(
--         select customer_id from flight_booking where flight_from=f and flight_to=t
--         );
-- end;

-- select flight_from,flight_to from flight_booking;


-- variable fid varchar2(10);
-- create or replace procedure calcdisp(
--     f in flight_booking.flight_from%type,
--     t in flight_booking.flight_to%type,
--     id out flight_booking.booking_id%type
-- ) is
-- begin
-- select booking_id into id from flight_booking where 
-- flight_from=f and flight_to=t;
-- end;

-- variable num number(3);
-- create or replace function func1(
--     tid in tour_booking.booking_id%type
-- ) return number is
-- tot number;
-- begin
-- select number_of_persons into tot from tour_booking where booking_id=tid;
-- return tot;
-- end;

-- declare
-- tid varchar2(10);
-- msg number(3);
-- begin
-- tid:='&tid';
-- msg:=func1(tid,0);
-- dbms_output.put_line(msg);
-- end;


-- create table show(
--     show_id varchar2(10),
--     show_name varchar2(25) not null,
--     show_venue char(25) not null,
--     show_date date not null,
--     start_time timestamp not null,
--     end_time timestamp not null,
--     description char(50) not null,
--     primary key(show_id)
-- );

-- create table equipment(
--     e_id varchar2(10),
--     name char(25) not null,
--     e_type varchar2(10) not null,
--     qty number,
--     primary key(e_id)
-- );

-- create table performer(
--     per_id varchar2(10),
--     name char(25) not null,
--     genre char(25) not null,
--     contact_details number(10) check (LENGTH(contact_details)=10)  not null,
--     country char(20),
--     primary key(per_id)
-- );

-- create table participate_details(
--     p_id varchar2(10),
--     name char(25) not null,
--     contact_no number(10) check (LENGTH(contact_no)=10) not null,
--     email varchar2(25) not null,
--     country char(20),
--     primary key(p_id)
-- );

-- create table participate(
--     p_id varchar2(10) not null,
--     show_id varchar2(10) not null,
--     performer_id varchar2(10),
--     start_time timestamp not null,
--     end_time timestamp not null,
--     total_amt number(10),
--     foreign key(show_id) references show(show_id),
--     foreign key(performer_id) references performer(per_id),
--     foreign key(p_id) references participate_details(p_id)
-- );

-- insert into show values('sid1','show1','venue1','10-Mar-2019','10-Mar-2019 10-00-00 PM','10-Mar-2021 11-00-00 PM','desc1');
-- insert into show values('sid2','show2','venue2','10-May-2021','10-May-2021 6-12-54 PM','10-May-2021 11-56-00 PM','desc2');

-- insert into equipment values('eid1','tabla','etype1',10);



-- insert into performer values('per1','justic','pop',5863254789,'australia');

-- insert into participate values('pid1','sid1','per1','10-Mar-2021 10-00-00 PM','10-Mar-2021 11-00-00 PM',10000);
-- insert into participate values('pid2','sid2','per2','10-May-2021 6-12-54 PM','10-May-2021 11-56-00 PM',4568);
-- insert into participate values('pid3','sid3','per3',systimestamp,systimestamp,6325);
-- insert into participate values('pid4','sid4','per4',systimestamp,systimestamp,2154);
-- insert into participate values('pid5','sid5','per5',systimestamp,systimestamp,4564);
-- insert into participate values('pid4','sid4','per4','10-Mar-2021 10-00-00 PM','10-Mar-2021 11-00-00 PM',10000);
-- insert into participate values('pid5','sid5','per5','10-Mar-2021 10-00-00 PM','10-Mar-2021 11-00-00 PM',10000);
-- select show.show_id,show.show_name, show.show_venue, show.show_date, show.start_time,show.end_time, show.description from show 
-- join participate on show.show_id=participate.show_id
-- join performer on performer.per_id=participate.performer_id
-- where genre='pop' and country='australia' and show_date='%2021';


-- SELECT show.show_id, show.show_name, participate.total_amt
-- FROM show JOIN participate 
-- ON show.show_id = participate.show_id
-- JOIN performer
-- ON participate.performer_id = performer.per_id
-- WHERE performer.name = 'justin' OR performer.name = 'bruno';

-- select country, count(*) from performer group by country;


-- 2.4
-- select show.show_id, show.show_name, show.show_venue, show.show_date, show.start_time,show.end_time, show.description
-- from (select show_id ,sum(total_amt) as business from participate )
-- where business > avg(business) group by show.show_id;

-- select SUM(total_amt) as collection_by_non_indian
-- from participate join participate_details
-- on participate.p_id = participate_details.p_id
-- where country != 'India';

-- create or replace function calc
-- (c in performer.country%type) return char 
-- is
-- n char(25);
-- begin
-- select name into n from performer where country=c;
-- return n;
-- end;


-- variable n1 varchar2(10);
-- create or replace procedure pp
-- (d in show.show_date%type,
-- t in show.start_time%type,
-- s out show.show_id%type) is 
-- begin
-- select show_id into s from show where show_date=d and start_time=t;
-- end;

-- declare
-- s show.show_id%type;
-- s1 show.show_name%type;
-- s2 show.show_venue%type;
-- s3 show.show_date%type;
-- cursor c1 is
-- select show.show_id, show.show_name, show.show_venue, show.show_date from show join participate
-- on show.show_id=participate.show_id join performer on performer.per_id=participate.performer_id
-- where genre='pop' and country='australia' and show_date='10-MAR-2021';
-- begin
-- open c1;
-- loop
-- fetch c1 into s,s1,s2,s3;
-- exit
-- when c1%notfound;
-- dbms_output.put_line('performer details --'||s||' '||s1||' '||s2||' '||s3);
-- end loop;
-- close c1;
-- end;



declare
s show.show_id%type;
cursor c1 is
select (show.show_id ,sum(total_amt) as business from participate)
where business > avg(business) group by show.show_id;
begin
open c1;
loop
fetch c1 into s;
exit
when c1%notfound;
dbms_output.put_line('show details --'||s);
end loop;
close c1;
end;