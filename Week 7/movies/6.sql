SELECT AVG(rating) FROM movies
JOIN ratings ON movie_id == id
WHERE year == 2012;