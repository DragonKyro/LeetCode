(
  SELECT name AS results
  FROM (
    SELECT u.name, AVG(mr.rating) AS avg_rating
    FROM MovieRating mr
    JOIN Users u ON mr.user_id = u.user_id
    GROUP BY mr.user_id, u.name
    ORDER BY avg_rating DESC, u.name ASC
    LIMIT 1
  ) t1
)
UNION ALL
(
  SELECT title AS results
  FROM (
    SELECT m.title, AVG(mr.rating) AS avg_rating
    FROM MovieRating mr
    JOIN Movies m ON mr.movie_id = m.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY mr.movie_id, m.title
    ORDER BY avg_rating DESC, m.title ASC
    LIMIT 1
  ) t2
);
