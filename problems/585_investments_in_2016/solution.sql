SELECT tiv_2016 AS TIV_2016
FROM (
  SELECT tiv_2016,
    COUNT(*) OVER (PARTITION BY tiv_2015) AS cnt_tiv,
    COUNT(*) OVER (PARTITION BY lat, lon) AS cnt_loc
  FROM Insurance
) t
WHERE cnt_tiv > 1 AND cnt_loc = 1;
