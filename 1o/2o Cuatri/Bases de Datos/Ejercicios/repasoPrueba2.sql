/*Para todas las editoriales que hayan publicado libros en 2005 o posteriormente, 
mostrar el nombre de la editorial junto con el número de libros que ha publicado, 
y el precio y el peso de un lote con un ejemplar de cada uno de sus libros.*/
SELECT 
	E.NOMBRE AS nombre,
	COUNT(CASE WHEN L.AÑO>=2005 THEN 1 END) AS NUMLIBROS,
	CASE WHEN SUM(CASE WHEN L.AÑO>=2005 THEN PRECIO END) IS NULL THEN 0 ELSE SUM(CASE WHEN L.AÑO>=2005 THEN PRECIO END) END AS PRECIOLOTE,
	CASE WHEN SUM(CASE WHEN L.AÑO>=2005 THEN PESO END) IS NULL THEN 0 ELSE SUM(CASE WHEN L.AÑO>=2005 THEN PESO END) END AS PESOLOTE
FROM EDITORIAL AS E
	LEFT JOIN LIBRO AS L ON E.NOMBRE=L.EDITORIAL
GROUP BY E.NOMBRE

/*Mostrar título de los libros, nombre y apellidos (separados por un blanco) del lector y
 días que ha sido prestado el libro para aquellos libros del año 2002 o posterior de la 
 editorial Pergamino que han sido prestados a lectores inscritos a partir del año 2003 en 
 la biblioteca Cervantes y cuya autora tiene de nombre Esther. Descartar aquellos libros que
 aún no han sido devueltos. */
SELECT L.TITULO AS libro, CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS) AS lector, DATEDIFF(P.FECHA_DEVUELTO,P.FECHA_PRESTADO) AS 'Días de lectura'
FROM LIBRO AS L
	JOIN PRESTAMO AS P ON L.ID=P.LIBRO AND FECHA_DEVUELTO IS NOT NULL
	JOIN LECTOR AS LEC ON LEC.ID=P.LECTOR AND YEAR(LEC.FECHA_INSCRIPCION)>2003
	JOIN EJEMPLAR AS E ON L.ID=E.LIBRO
	JOIN BIBLIOTECA AS B ON B.ID=E.BIBLIOTECA AND B.NOMBRE='Cervantes'
	JOIN AUTORLIBRO AS AA ON AA.LIBRO=L.ID
	JOIN AUTOR AS A ON A.ID=AA.AUTOR AND A.NOMBRE='Esther'
WHERE L.AÑO>=2002 AND L.EDITORIAL='Pergamino '
GROUP BY L.TITULO, CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS),DATEDIFF(P.FECHA_DEVUELTO,P.FECHA_PRESTADO)

/*Para todas las editoriales, mostrar el nombre de la editorial junto con el número de autores 
que tienen publicado al menos un libro en esa editorial y el número de libros en dicha editorial
de esos autores. Nota: Obtener también las editoriales con cero autores. */
SELECT ED.nombre,
	COUNT(AA.AUTOR) AS NUMAUTORES,
	COUNT(L.ID)		AS NUMLIBROS
FROM EDITORIAL AS ED
	JOIN LIBRO AS L ON L.EDITORIAL=ED.NOMBRE
	JOIN AUTORLIBRO AS AA ON AA.LIBRO=L.ID
	HAVING COUNT(AA.LIBRO)>=1

/*Obtener todos los datos de los ejemplares que no se hayan prestado nunca 
(con subconsultas). */
SELECT E.*
FROM EJEMPLAR AS E
WHERE E.EJEMPLAR NOT IN (SELECT P.EJEMPLAR
				  		FROM PRESTAMO AS P
					    WHERE E.LIBRO=P.LIBRO)

/*Obtener todos los datos de los ejemplares que no se hayan prestado nunca 
(no utilices subconsultas). */
SELECT E.*
FROM EJEMPLAR AS E
	LEFT JOIN PRESTAMO AS P ON E.LIBRO=P.LIBRO AND E.EJEMPLAR=P.EJEMPLAR
	WHERE P.FECHA_PRESTADO IS NULL;

/*Para todos los libros mostrar el código de libro, el título y el total de préstamos que se han realizado de dicho libro
(TotalPrestamos), solo si el total de préstamos es menor o igual que 2. */
SELECT L.id,L.titulo,COUNT(P.LIBRO) AS TotalPrestamos
FROM LIBRO AS L
	LEFT JOIN PRESTAMO AS P ON P.LIBRO=L.ID 
 	GROUP BY L.ID,L.TITULO
 	HAVING COUNT(P.LIBRO)<=2

/*ID y nombre de todas las bibliotecas de Logroño junto con el número de ejemplares que tienen de peso superior a 980 g
(TotalLibros). Mostrar también la suma del peso de dichos ejemplares (SumaPeso). */
select b.id, b.nombre, count(case when l.peso>=980 then 1 end) as 'TotalLibros', sum(case when l.peso>=980 then l.peso else 0 end) as 'SumaPeso'
from biblioteca as b join
    ejemplar as e on b.id=e.biblioteca join
    libro as l on e.libro=l.id
where b.direccion like '%Logroño'
group by b.id, b.nombre

/*Para todas las editoriales, mostrar el nombre de la editorial junto con el número de libros que ha publicado y 
el número de autores que tienen publicado al menos un libro con dicha editorial. 
Nota: Pueden existir libros anónimos. */
select e.nombre, count(distinct l.id) as 'NUMLIBROS' , count(distinct a.autor) as 'NUMAUTORES'
from editorial as e left join
    libro as l on e.nombre=l.editorial left join
    autorlibro as a on l.id=a.libro
group by e.nombre

/*Para todos los libros mostrar los datos del libro junto con los datos de su primer lector solicitante. */
SELECT L.id,L.titulo,LEC.nombre,LEC.apellidos
FROM LECTOR AS LEC
	RIGHT JOIN LIBRO AS L ON LEC.ID=L.PRIMER_SOLICITANTE

/*Se quiere mostrar el número de lectores que tienen los autores. Se consideran sólo aquellos libros que han sido prestados y
devueltos en un plazo que garantice que han podido ser leídos. Se supone que como máximo un lector puede leer 40 páginas al día, 
de tal manera que si se ha devuelto en un plazo que implique una velocidad mayor de lectura se considera que en realidad el lector no lo ha leído.
No tener en cuenta los libros que aún no han sido devueltos. Mostrar el nombre y apellidos (separado por un blanco) del autor y 
el número de lectores de dicho autor ordenados de mayor a menor.*/
