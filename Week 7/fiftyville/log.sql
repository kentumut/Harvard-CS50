-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT id FROM crime_scene_reports
WHERE year == 2021
AND month == 7
AND day == 28
AND street == "Humphrey Street";
-- Finding ids how matching incidents 295 (297)
SELECT description FROM crime_scene_reports
WHERE id == 295;
-- Interviews
SELECT id FROM interviews
WHERE year == 2021
AND month == 7
AND day == 28;
-- Transcripts 161, 162, 163
SELECT transcript FROM interviews
WHERE id == 163;
-- License plate is within these logs
SELECT id FROM bakery_security_logs
WHERE year == 2021
AND month == 7
AND day == 28
AND hour = 10
AND minute > 5
AND minute < 26;
-- People within these phone calls
SELECT id FROM phone_calls
WHERE year == 2021
AND month == 7
AND day == 28
AND duration < 61;
-- Checking ATM
SELECT id FROM atm_transactions
WHERE year == 2021
AND month == 7
AND day == 28
AND atm_location == "Leggett Street"
AND transaction_type == "withdraw";
-- Checking flights out of Fifftyville
-- Finding the airport id
SELECT id FROM airports
WHERE city == "Fiftyville";
-- Checking flights
SELECT id FROM flights
WHERE origin_airport_id == 8
AND year == 2021
AND month == 7
AND day == 29;
-- Checking their time
SELECT id, hour, minute FROM flights
WHERE id IN(SELECT id FROM flights
WHERE origin_airport_id == 8
AND year == 2021
AND month == 7
AND day == 29)
ORDER BY hour;
-- What is the city of the first flight
SELECT city FROM airports
WHERE id ==
(SELECT destination_airport_id FROM flights
WHERE id == 36);
-- Finding the thief
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE phone_number IN
(SELECT caller FROM phone_calls
WHERE id > 220
AND id < 282)
AND people.id IN
(SELECT person_id FROM bank_accounts
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE bank_accounts.account_number IN
(SELECT account_number FROM atm_transactions
WHERE id > 245
AND id < 337))
AND people.passport_number IN(
SELECT passport_number FROM passengers
WHERE flight_id == 36)
AND bakery_security_logs.license_plate IN
(SELECT license_plate FROM bakery_security_logs
WHERE id > 257
AND id < 268);
-- Finding the accomplice
SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE people.phone_number IN
(SELECT receiver FROM phone_calls
WHERE year == 2021
AND month == 7
AND day == 28
AND duration < 60
AND caller == "(367) 555-5533");