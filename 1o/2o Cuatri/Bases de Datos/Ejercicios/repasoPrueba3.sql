/*Nombre de la biblioteca y mes en el que historicamente el total de ejemplares
comprados no fue superado por el total de ejemplares comprados en ninguno de los meses siguientes de esa biblioteca.
Excluye del resultado el mes de diciembre*/
SELECT B.NOMBRE
FROM EJEMPLAR AS E
	JOIN BIBLIOTECA AS B ON E.BIBLIOTECA=B.ID
	GROUP BY B.ID,B.NOMBRE,MONTH(E.FECHA_COMPRA)
	HAVING COUNT(E.FECHA_COMPRA)<12 AND COUNT(*)>ALL(
		SELECT COUNT(*)
		FROM EJEMPLAR AS EL
		WHERE EL.BIBLIOTECA = B.ID
		GROUP BY MONTH(EL.FECHA_COMPRA)
		HAVING MONTH(E.FECHA_COMPRA)<MONTH(EL.FECHA_COMPRA)
	)

/*Mostrar el codigo y el titulo de los libros de la editorial "El feriante" con dos o mas autores que tengan ejemplares prestados
en todas las bibliotecas de arnedo y logroño*/

SELECT L.ID,L.titulo
FROM LIBRO AS L 
	JOIN AUTORLIBRO AS AA ON AA.LIBRO=L.ID
WHERE EDITORIAL='EL FERIANTE'
AND NOT EXISTS(
	SELECT	ID
	FROM	BIBLIOTECA
	WHERE	DIRECCION LIKE '%ARNEDO' OR DIRECCION LIKE '%LOGROÑO'

	EXCEPT

	SELECT	E.BIBLIOTECA
	FROM	EJEMPLAR AS E 
		JOIN PRESTAMO AS P ON E.LIBRO=P.LIBRO
			AND E.EJEMPLAR=P.EJEMPLAR
	WHERE	E.LIBRO=L.ID
)
GROUP BY L.ID.L.TITULO
HAVING COUNT(AL.AUTOR)>1