select title, rating from movies JOIN ratings ON id = ratings.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;


