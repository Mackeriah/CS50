-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 'Come, Watson, come!' he cried. 'The game is afoot."

-- ran .schema and copied contents into a text file to view as required
.schema

-- ran this to take an initial look at this table
SELECT * FROM "crime_scene_reports";

-- ran this to see if the word 'duck' was mentioned
SELECT * FROM "crime_scene_reports" where description like "%duck%";

-- ran this to find interviews conducted on the day of theft (28/7/2020)
select * from interviews where year = 2020 and month = 7 and day = 28;

-- ran this to look at Fiftyville airport
select * from airports where city = "Fiftyville"

-- ran this to see the list of flights from Fiftyville airport the day after the theft
select * from airports
join flights ON airports.id = flights.origin_airport_id
where flights.origin_airport_id = 8
and flights.year = '2020'
and flights.month = '7'
and flights.day = '29'
ORDER BY flights.hour;

-- looked at airports to see which destination number 4 was
select full_name from airports
where id = '4';

-- Eugene said they recognised the thief when saw them at the ATM, so now I'm trying to determine who that was
select * from atm_transactions
where year = 2020 and month = 7 and day = 28
and atm_location LIKE '%Fifer%';

-- now looking at courthouse security to see if I can tell what time Eugene arrived to narrow the time down for ATM
select * from courthouse_security_logs
where year = 2020 and month = 7 and day = 28;

-- oh you people are loving this aren't you?!  ;)
-- OK so now I need to find Eugene's licence plate to see what time they arrived
select * from people
where name like '%Eugene%';

-- courthouse security again with licence plate
select * from courthouse_security_logs
where year = 2020 and month = 7 and day = 28
and license_plate = '47592FJ';

-- hmm, dead end and I noticed Eugene said they walked, not drove, hence no licence plate.
-- Raymond said theif made a phonecall which was less than a minute, so looking at phone logs now
select * from phone_calls
where year = 2020 and month = 7 and day = 28
and duration < 60;

-- now I want to get details of those people (so I can compare to ATM transactions)
select people.id, people.name from people
join phone_calls ON phone_calls.caller = people.phone_number
where phone_calls.year = 2020 and phone_calls.month = 7 and phone_calls.day = 28
and phone_calls.duration < 60;

-- I need to add account number
select person_id, transaction_type from atm_transactions
join bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
where year = 2020 and month = 7 and day = 28
and atm_location LIKE '%Fifer%';

-- add passengers to flight
select * from airports
join flights ON airports.id = flights.origin_airport_id
join passengers ON passengers.flight_id = flights.id
join people ON people.passport_number = passengers.passport_number
where flights.origin_airport_id = 8
and flights.year = '2020'
and flights.month = '7'
and flights.day = '29'
and flights.hour = '8'
and people.name IN ("Bobby", "Ernest", "Madison");

-- check courthouse data to see if one of my 3 suspects cars was seen
select * from courthouse_security_logs
join people ON courthouse_security_logs.license_plate = people.license_plate
where year = 2020 and month = 7 and day = 28
and people.name IN ("Ernest", "Bobby", "Madison");

-- who did Ernest and Madison call and is that person also on this flight
select caller, name, receiver, duration, day from phone_calls
join people ON phone_calls.caller = people.phone_number
where people.name IN ("Ernest", "Madison")
and year = 2020 and month = 7 and day = 28
and duration < 60;

-- find out who those 2 people are and their passport numbers
select receiver, name, passport_number from phone_calls
join people ON phone_calls.receiver = people.phone_number
where people.phone_number IN ("(375) 555-8161", "(676) 555-6554");


-- only james has a passport so was he on the flight?  (No...damn)
select * from airports
join flights ON airports.id = flights.origin_airport_id
join passengers ON passengers.flight_id = flights.id
join people ON people.passport_number = passengers.passport_number
where flights.origin_airport_id = 8
and flights.year = '2020'
and flights.month = '7'
and flights.day = '29'
and flights.hour = '8';
and people.name IN ("James");

-- can I check their bank accounts to see if they bought a flight?
select * from bank_accounts
join people ON people.id = bank_accounts.person_id
where name = "Berthold";

-- Aha! Out of my two suspects, James and Berthold, only Berthold has a bank account and thus I don't see how James could have booked the flight.