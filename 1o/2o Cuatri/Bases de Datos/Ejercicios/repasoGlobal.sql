/*Código sin repeticiones de los libros con dos o más autores. Se debe resolver la consulta sin utilizar la función count(). */
SELECT AA.libro
FROM AUTORLIBRO AS AA
    JOIN AUTORLIBRO AS AA2 ON AA.LIBRO=AA2.LIBRO AND AA.AUTOR<>AA2.AUTOR
GROUP BY AA.LIBRO

SELECT DISTINCT AA.libro
FROM AUTORLIBRO AS AA
	JOIN AUTORLIBRO AS AA2 ON AA.LIBRO=AA2.LIBRO AND AA.AUTOR<>AA2.AUTOR

/*Mostrar nombre y apellidos de los lectores (separados por un blanco) y nombre de las bibliotecas cercanas (considerando que un 
lector está cercano a una biblioteca si los dos primeros dígitos de su número de teléfono coinciden con los dos primeros dígitos del teléfono de la biblioteca) 
en las que el lector haya tomado en préstamo al menos un libro. Ordenar el resultado por código de lector y código de biblioteca.*/
SELECT CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS) AS 'Lector',B.nombre as 'Biblioteca'
FROM LECTOR AS LEC
	JOIN BIBLIOTECA AS B ON LEFT(B.TFNO,2)=LEFT(LEC.TFNO,2)
	JOIN PRESTAMO AS P ON P.LECTOR=LEC.ID
	JOIN EJEMPLAR AS E ON E.EJEMPLAR=P.EJEMPLAR AND E.LIBRO=P.LIBRO AND E.BIBLIOTECA=B.ID
GROUP BY LEC.ID,LEC.NOMBRE
ORDER BY LEC.ID,B.ID

SELECT CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS) AS 'Lector', B.NOMBRE AS 'Biblioteca'
FROM LECTOR AS LEC
	JOIN PRESTAMO AS P ON LEC.ID=P.LECTOR
	JOIN EJEMPLAR AS E ON P.LIBRO=E.LIBRO AND P.EJEMPLAR=E.EJEMPLAR
	JOIN BIBLIOTECA AS B ON E.BIBLIOTECA=B.ID
WHERE LEFT(LEC.TFNO,2)=LEFT(B.TFNO,2)
GROUP BY LEC.ID,LEC.NOMBRE,LEC.APELLIDOS,B.ID,B.NOMBRE
ORDER BY LEC.ID,B.ID

/*Nombre y apellido de los autores que han escrito algún libro con otro autor junto al nombre de las bibliotecas con alguno de estos ejemplares de autoría compartida */
SELECT A.nombre,A.apellidos, B.nombre
FROM AUTOR AS A
	JOIN AUTORLIBRO AS AA ON AA.AUTOR=A.ID
	JOIN AUTORLIBRO AS AA2 ON AA2.AUTOR<>AA.AUTOR AND AA.LIBRO=AA2.LIBRO
	JOIN EJEMPLAR AS E ON E.LIBRO=AA.LIBRO
	JOIN BIBLIOTECA AS B ON E.BIBLIOTECA = B.ID
	GROUP BY A.nombre,A.apellidos, B.nombre

/*Nombre y apellidos de los lectores que hayan solicitado algún libro (primer solicitante) y que hayan tomado en préstamo uno de sus ejemplares más de 3 años después de comprarlo
 (haciendo resta de años). Añadir a la solución la fecha de compra del ejemplar en cuestión y la fecha en la que lo tomó en préstamo el lector. */
 SELECT LEC.nombre,LEC.apellidos,E.fecha_compra,P.fecha_prestado
FROM LECTOR AS LEC
	JOIN LIBRO AS L ON L.PRIMER_SOLICITANTE=LEC.ID
	JOIN EJEMPLAR AS E ON L.ID=E.LIBRO
	JOIN PRESTAMO AS P ON P.LECTOR=LEC.ID AND P.LIBRO=L.ID AND E.EJEMPLAR=P.EJEMPLAR
WHERE (YEAR(P.FECHA_PRESTADO)-YEAR(E.FECHA_COMPRA)) > 3

/*Para todas las editoriales que hayan publicado libros en 2005 o posteriormente, mostrar el nombre de la editorial junto con el número de libros que ha publicado, 
y el precio y el peso de un lote con un ejemplar de cada uno de sus libros. (Inspirado por Sergio Leiva.) */
SELECT E.nombre, COUNT(L.ID) AS 'NUMLIBROS',
	COALESCE(SUM(L.PRECIO)	,0) AS 'PRECIOLOTE',
	COALESCE(SUM(L.PESO)	,0) AS 'PESOLOTE'
FROM EDITORIAL AS E
	JOIN LIBRO AS L ON L.EDITORIAL=E.NOMBRE AND L.AÑO>=2005
GROUP BY E.NOMBRE

/*Obtener las editoriales cuyo precio medio por página es inferior a 10 céntimos. Mostrar el nombre de la editorial y el precio por página de la misma. 
Ordena el resultado por el precio por página. */
SELECT  E.NOMBRE AS 'Editorial', AVG(L.PRECIO/L.PAGINAS) AS 'Precio medio por página'
FROM LIBRO AS L
	JOIN EDITORIAL AS E ON E.NOMBRE=L.EDITORIAL
	GROUP BY E.NOMBRE
	HAVING AVG(L.PRECIO/L.PAGINAS)<0.10
	ORDER BY 2

SELECT L.Editorial,AVG(L.PRECIO/L.PAGINAS) AS 'Precio medio por página'
FROM LIBRO AS L
GROUP BY L.EDITORIAL
HAVING AVG(L.PRECIO/L.PAGINAS) < 0.10
ORDER BY 2

/*ID y nombre de todas las bibliotecas de Logroño junto con el número de ejemplares que tienen de peso superior a 980 g (TotalLibros). 
Mostrar también la suma del peso de dichos ejemplares (SumaPeso). */
SELECT B.id,B.nombre, 
	COUNT(CASE WHEN L.PESO > 980 THEN 1 END) AS 'TotalLibros',
	SUM(CASE WHEN L.PESO >980 THEN L.PESO ELSE 0 END) AS 'SumaPeso'
FROM BIBLIOTECA AS B
	JOIN EJEMPLAR AS E ON E.BIBLIOTECA=B.ID
	JOIN LIBRO AS L ON E.LIBRO=L.ID
WHERE B.DIRECCION LIKE '%LOGROÑO'
GROUP BY B.id,B.nombre

/*Para todos los libros mostrar el código de libro, el título y el total de préstamos que se han realizado de dicho libro
(TotalPrestamos), solo si el total de préstamos es menor o igual que 2. */
SELECT L.id,L.titulo,COUNT(P.LIBRO) AS TotalPrestamos
FROM LIBRO AS L
	LEFT JOIN PRESTAMO AS P ON P.LIBRO=L.ID 
 	GROUP BY L.ID,L.TITULO
 	HAVING COUNT(P.LIBRO)<=2

/*Para todos los libros mostrar el código del libro, el título y el número de autores (NumeroAutores).
Mostrar el resultado de manera descendente según el númeo de autores, y para aquellos con el mismo número de autores,
ascendente por el código de libro */
SELECT L.id,L.titulo, COUNT(AA.AUTOR) AS 'NumeroAutores'
FROM LIBRO AS L
	LEFT JOIN AUTORLIBRO AS AA ON L.ID=AA.LIBRO
	GROUP BY L.ID,AA.LIBRO,L.titulo
	ORDER BY 3 DESC,L.ID ASC

/*Para todos los libros mostrar los datos del libro junto con los datos de su primer lector solicitante. */
SELECT L.id,L.titulo,LEC.nombre,LEC.apellidos
FROM LIBRO AS L
	LEFT JOIN LECTOR AS LEC ON LEC.ID=L.PRIMER_SOLICITANTE

/*Obtener todos los datos de los ejemplares que no se hayan prestado nunca 
(no utilices subconsultas). */
SELECT E.*
FROM EJEMPLAR AS E
	LEFT JOIN PRESTAMO AS P ON E.LIBRO=P.LIBRO AND E.EJEMPLAR=P.EJEMPLAR
	WHERE P.FECHA_PRESTADO IS NULL;

/*Mostrar el código, el nombre y apellidos de los lectores
(separados por un blanco) y el código y nombre de las bibliotecas 
cercanas considerando que un lector está cercano a una biblioteca 
si los dos primeros dígitos de su número de teléfono coinciden con los dos 
primeros dígitos del teléfono de la biblioteca. */
SELECT  LEC.ID AS CodigoLector, 
		CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS) AS Lector, 
		B.ID AS CodigoBiblioteca,
		B.NOMBRE AS Biblioteca
FROM LECTOR AS LEC
	JOIN BIBLIOTECA AS B ON LEFT(B.TFNO,2)=LEFT(LEC.TFNO,2)

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

SELECT E.nombre,
		COUNT(DISTINCT L.ID) AS NUMLIBROS,
		SUM(CASE WHEN (L.PRECIO) IS NULL THEN 0 ELSE (L.PRECIO) END) AS PRECIOLOTE,
		SUM(CASE WHEN (L.PESO)   IS NULL THEN 0 ELSE (L.PESO) END) AS PESOLOTE
FROM EDITORIAL AS E
	LEFT JOIN LIBRO AS L ON L.EDITORIAL=E.NOMBRE AND L.AÑO>=2005
GROUP BY E.nombre

/*ID y nombre de todas las bibliotecas de Logroño junto con el número de 
ejemplares que tienen de peso superior a 980 g (TotalLibros). 
Mostrar también la suma del peso de dichos ejemplares (SumaPeso). */
SELECT B.id,B.nombre,
			COUNT(CASE WHEN L.PESO>=980 THEN 1 END) AS 'TotalLibros', 
			SUM(CASE WHEN L.PESO>=980 THEN L.PESO ELSE 0 END) AS 'SumaPeso'
FROM BIBLIOTECA AS B
	JOIN EJEMPLAR AS E ON E.BIBLIOTECA=B.ID
	JOIN LIBRO AS L ON E.LIBRO=L.ID
WHERE B.DIRECCION LIKE '%LOGROÑO'
GROUP BY B.ID,B.NOMBRE

/*Para todas las editoriales, mostrar el nombre de la editorial 
junto con el número de autores que tienen publicado al menos un 
libro en esa editorial y el número de libros en dicha editorial 
de esos autores. Nota: Obtener también las editoriales con cero autores.*/
SELECT E.nombre,COUNT(DISTINCT AA.AUTOR) AS NUMAUTORES, COUNT(DISTINCT AA.LIBRO) AS NUMLIBROS
FROM EDITORIAL AS E
	LEFT JOIN LIBRO AS L ON L.EDITORIAL=E.NOMBRE
	LEFT JOIN AUTORLIBRO AS AA ON AA.LIBRO=L.ID
GROUP BY E.NOMBRE

SELECT  E.nombre, 
		(CASE WHEN COUNT(DISTINCT AA.AUTOR) IS NULL THEN 0 ELSE COUNT(DISTINCT AA.AUTOR) END) AS NUMAUTORES,
		(CASE WHEN COUNT(DISTINCT AA.LIBRO) IS NULL THEN 0 ELSE COUNT(DISTINCT AA.LIBRO) END) AS NUMLIBROS
FROM EDITORIAL AS E
	LEFT JOIN LIBRO AS L ON L.EDITORIAL=E.NOMBRE
	LEFT JOIN AUTORLIBRO AS AA ON L.ID=AA.LIBRO
GROUP BY E.NOMBRE

/*Se quiere mostrar el número de lectores que tienen los autores.
Se consideran sólo aquellos libros que han sido prestados y devueltos 
en un plazo que garantice que han podido ser leídos. 
Se supone que como máximo un lector puede leer 40 páginas al día, 
de tal manera que si se ha devuelto en un plazo que implique una 
velocidad mayor de lectura se considera que en realidad el lector
no lo ha leído. No tener en cuenta los libros que aún no han sido devueltos. 
Mostrar el nombre y apellidos (separado por un blanco) del autor y el número 
de lectores de dicho autor ordenados de mayor a menor.  */
SELECT CONCAT(A.NOMBRE,' ',A.APELLIDOS) as 'Autor', COUNT(DISTINCT P.LECTOR) AS 'Número de lectores'
FROM PRESTAMO AS P
      JOIN LIBRO AS L ON L.ID=P.LIBRO
      JOIN AUTORLIBRO AS AA ON L.ID=AA.LIBRO
      JOIN AUTOR AS A ON AA.AUTOR=A.ID
WHERE (L.PAGINAS/(DATEDIFF(P.FECHA_DEVUELTO,P.FECHA_PRESTADO)))<40
AND         P.FECHA_DEVUELTO IS NOT NULL
GROUP BY A.ID, CONCAT(A.NOMBRE,' ',A.APELLIDOS)
ORDER BY 2 DESC

/*Código sin repeticiones de los libros con dos o más autores.
Se debe resolver la consulta sin utilizar la función count(). */
SELECT DISTINCT AA.libro
FROM AUTORLIBRO AS AA
	JOIN AUTORLIBRO AS AA2 ON AA.LIBRO=AA2.LIBRO AND AA2.AUTOR<>AA.AUTOR

/*Mostrar título de los libros, nombre y apellidos (separados por un blanco)
del lector y días que ha sido prestado el libro para aquellos libros del año 
2002 o posterior de la editorial Pergamino que han sido prestados a lectores 
inscritos a partir del año 2003 en la biblioteca Cervantes y cuya autora tiene
de nombre Esther. Descartar aquellos libros que aún no han sido devueltos. */
SELECT L.TITULO AS libro,
		CONCAT(LEC.NOMBRE,' ',LEC.APELLIDOS) AS lector,
		DATEDIFF(P.FECHA_DEVUELTO,P.FECHA_PRESTADO) AS 'Días de lectura'
FROM LIBRO AS L
	JOIN PRESTAMO AS P ON L.ID=P.LIBRO
	JOIN LECTOR AS LEC ON LEC.ID=P.LECTOR AND YEAR(LEC.FECHA_INSCRIPCION)> 2003
	JOIN AUTORLIBRO AS AA ON AA.LIBRO=L.ID
	JOIN AUTOR AS A ON A.NOMBRE LIKE '%ESTHER' AND AA.AUTOR=A.ID
	JOIN EJEMPLAR AS E ON E.LIBRO=P.LIBRO AND E.EJEMPLAR=P.EJEMPLAR
	JOIN BIBLIOTECA AS B ON B.ID=E.BIBLIOTECA AND B.NOMBRE LIKE '%CERVANTES'
WHERE L.AÑO > 2003 AND L.EDITORIAL LIKE '%PERGAMINO'

/*Identificador y título de los libros de la editorial 'Galera'
que tienen ejemplaresen todas las bibliotecas de Logroño */
SELECT L.id,L.titulo
FROM LIBRO AS L
WHERE L.EDITORIAL LIKE '%GALERA'
	AND NOT EXISTS(
		SELECT B.ID
		FROM BIBLIOTECA AS B
		WHERE B.DIRECCION LIKE '%LOGROÑO'
			AND B.ID NOT IN (SELECT E.BIBLIOTECA
						   FROM EJEMPLAR AS E
						   WHERE L.ID=E.LIBRO))

