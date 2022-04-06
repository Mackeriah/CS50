select title from movies
where movies.id IN (select stars.movie_id from stars
where stars.person_id IN (select people.id from people where people.name = "Johnny Depp"))
INTERSECT
select title from movies
where movies.id IN (select stars.movie_id from stars
where stars.person_id IN (select people.id from people where people.name = "Helena Bonham Carter"));


-- select person_id, name from stars
-- join people ON person_id = people.id
-- where people.name = "Johnny Depp";


-- select title from movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- where people.name IN ("Johnny Depp", "Helena Bonham Carter");

-- select name from people
-- JOIN directors ON people.id = directors.person_id
-- JOIN movies ON movies.id = directors.movie_id
-- JOIN ratings ON ratings.movie_id = movies.id
-- where rating >= '9.0';

-- select name from people
-- JOIN stars ON people.id = stars.person_id
-- JOIN movies ON stars.movie_id = movies.id
-- where movies.year = '2004'
-- ORDER BY people.birth;



-- where stars.person_id = '158';
-- 'select id from movies where title = "Toy Story";

-- where movies.title = "Toy Story";


-- select name from people where id = '158';

-- select title, rating from movies JOIN ratings ON id = ratings.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;