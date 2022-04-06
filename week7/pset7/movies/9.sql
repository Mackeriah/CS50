select DISTINCT name from people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
where movies.year = '2004'
ORDER BY people.birth;



-- where stars.person_id = '158';
-- 'select id from movies where title = "Toy Story";

-- where movies.title = "Toy Story";


-- select name from people where id = '158';

-- select title, rating from movies JOIN ratings ON id = ratings.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;