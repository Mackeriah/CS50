select distinct(name) from people
join stars ON people.id = stars.person_id
join movies ON movies.id = stars.movie_id
where movies.title IN (select distinct(movies.title) from people
join stars ON people.id = stars.person_id
join movies ON movies.id = stars.movie_id
where people.name = "Kevin Bacon" and people.birth = 1958) and people.name != "Kevin Bacon";

-- not sure why I still need to join stars and movies a second time, but it works!  /shrug


-- CS50 said "query did not return results, but actually it does and appears to be correct!"
-- I then changed from ID to name (so had to include birth date) and CS50 gives pass!!  what?  :/
-- select distinct(name) from people
-- join stars ON person_id = people.id
-- join movies ON stars.movie_id = movies.id
-- where movies.title IN (select distinct(movies.title) from people
-- join stars ON people.id = stars.person_id
-- join movies ON stars.movie_id = movies.id
-- where stars.person_id = '102') and stars.person_id != '102';