SELECT a.name,
       a.start_date,
       AVG(c.score),
       STDEV(c.score),
       MIN(c.score),
       MAX(c.score)
FROM courses a,
     exams b,
     evaluations c
WHERE c.exam_fk = b.pk AND b.course_fk = a.pk
GROUP BY a.name, a.start_date;