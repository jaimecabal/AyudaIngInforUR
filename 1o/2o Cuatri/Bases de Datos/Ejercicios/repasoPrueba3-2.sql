/*Se quiere mostrar el número de lectores que tienen los autores. 
Se consideran sólo aquellos libros que han sido prestados y devueltos en un plazo que garantice que han podido ser leídos. Se supone que como máximo un lector puede leer 40 páginas al día, de tal manera que si se ha devuelto en un plazo que implique una velocidad mayor de lectura se considera que en realidad el lector no lo ha leído. No tener en cuenta los libros que aún no han sido devueltos. Mostrar el nombre y apellidos (separado por un blanco) del autor y el número de lectores de dicho autor ordenados de mayor a menor./*Identificador y título de los libros que se hayan prestado 10 o más veces 
y que tienen ejemplares en todas las bibliotecas de Logroño. */
SELECT L.id,L.titulo
FROM LIBRO AS L
	JOIN PRESTAMO AS P ON L.ID=P.LIBRO
WHERE NOT EXISTS(
	SELECT B.ID
	FROM BIBLIOTECA AS B
	WHERE B.DIRECCION LIKE '%LOGROÑO'
	AND B.ID NOT IN
	(SELECT E.BIBLIOTECA
	FROM EJEMPLAR AS E
	WHERE L.ID=E.LIBRO)
	)
GROUP BY L.ID,L.TITULO
HAVING COUNT(*)>=10


/*Identificador, nombre y apellidos de los lectores de Lardero que han 
tomado ejemplares en préstamo de todas las bibliotecas de Logroño  */
SELECT L.id,L.nombre,L.apellidos
FROM LECTOR AS L
WHERE L.DIRECCION LIKE '%LARDERO' 
AND NOT EXISTS(
	SELECT B.ID
	FROM BIBLIOTECA AS B
	WHERE B.DIRECCION LIKE '%LOGROÑO'
	AND B.ID NOT IN
	(SELECT E.BIBLIOTECA
	 FROM EJEMPLAR AS E
	 	JOIN PRESTAMO AS P ON E.EJEMPLAR=P.EJEMPLAR AND P.LIBRO=E.LIBRO
	WHERE P.LECTOR=L.ID)
)
GROUP BY L.id,L.nombre,L.apellidos

/*Identificador y título de los libros de la editorial 'Galera' que tienen
ejemplares en todas las bibliotecas de Logroño */

SELECT L.id,L.titulo
FROM LIBRO AS L
WHERE L.EDITORIAL='Galera'
AND NOT EXISTS(
	SELECT B.ID
	FROM BIBLIOTECA AS B
	WHERE B.DIRECCION LIKE '%LOGROÑO'
	AND B.ID NOT IN
	(SELECT E.BIBLIOTECA
	FROM EJEMPLAR AS E
	WHERE L.ID=E.LIBRO)
)
GROUP BY L.id,L.titulo;

/*Nombre e identificador de artículos vendidos en alguna tienda de Lyon para 
los que se obtiene un ganancia por unidad vendida (prec_vent-prec_compr) superior al precio de compra algún artículo del mismo color vendido en la ciudad de Madrid */
SELECT A.nombr_artic,A.ident_artic
FROM ARTICULO AS A
	JOIN VENTA AS V ON V.IDENT_ARTIC=A.IDENT_ARTIC
	JOIN TIENDA AS T ON T.IDENT_TIEND=V.IDENT_TIEND AND T.CIUD='LYON'
WHERE (A.PREC_VENT-A.PREC_COMPR) > ANY (SELECT (AA.PREC_VENT-AA.PREC_COMPR)
										FROM ARTICULO AS AA
										    JOIN VENTA AS VV ON VV.IDENT_ARTIC=VV.IDENT_ARTIC
									   		JOIN TIENDA AS TT ON TT.IDENT_TIEND=VV.IDENT_TIEND AND TT.CIUD='MADRID'
									  	WHERE AA.COLOR=A.COLOR);

/*Nombre y apellido de los clientes que han comprado todos los artículos que contenga la palabra bolígrafo en su nombre y sea de color azul. */
SELECT C.nombr_client,C.apell1
FROM CLIENTE AS C
WHERE NOT EXISTS(
	SELECT A.IDENT_ARTIC
	FROM ARTICULO AS A
	WHERE A.NOMBR_ARTIC LIKE '%BOLIGRAFO%' AND A.COLOR LIKE '%AZUL%'
	AND A.IDENT_ARTIC NOT IN
	(SELECT V.IDENT_ARTIC
	 FROM VENTA AS V
	 WHERE V.IDENT_CLIENT=C.IDENT_CLIENT)
)
GROUP BY C.IDENT_CLIENT,C.NOMBR_CLIENT,C.APELL1

/*Nombre e identificador de los proveedores a los que se ha aplicado en las ventas de sus productos un descuento medio
por unidad superior en las tiendas de Barcelona (en todas las tiendas de Barcelona en conjunto) que en alguna de las ciudades con una sola tienda. 
(Descuento por unidad: prec_vent - prec_total / cant_artics). */
SELECT P.nombr_prov,P.ident_prov
FROM PROVEEDOR AS P
	JOIN ARTICULO AS A ON A.IDENT_PROV=P.IDENT_PROV
	JOIN VENTA AS V ON V.IDENT_ARTIC=A.IDENT_ARTIC
	JOIN TIENDA AS T ON T.IDENT_TIEND=V.IDENT_TIEND AND T.CIUD='BARCELONA'
	WHERE (A.prec_vent - V.prec_total / V.cant_artics) 
		>= ANY (SELECT (AA.prec_vent - VV.prec_total / VV.cant_artics)
			    FROM ARTICULO AS AA
					JOIN VENTA AS VV ON VV.IDENT_ARTIC=AA.IDENT_ARTIC
					JOIN TIENDA AS TT ON TT.IDENT_TIEND=VV.IDENT_TIEND AND TT.CIUD<>'BARCELONA')

/*Obtener todos los datos de los ejemplares que no se hayan prestado nunca 
(con subconsultas). */
SELECT E.*
FROM EJEMPLAR AS E
WHERE E.EJEMPLAR NOT IN (SELECT P.EJEMPLAR
				  		FROM PRESTAMO AS P
					    WHERE E.LIBRO=P.LIBRO)

/*Obtener todos los datos de los ejemplares que no se hayan prestado nunca 
(no utilices subconsultas). */
SELECT E.libro,E.ejemplar,E.biblioteca,E.fecha_solicitud,E.fecha_compra
FROM EJEMPLAR AS E
	LEFT JOIN PRESTAMO AS P ON P.LIBRO=E.LIBRO AND P.EJEMPLAR=E.EJEMPLAR
	WHERE P.FECHA_PRESTADO IS NULL
	GROUP BY E.LIBRO,E.EJEMPLAR,E.BIBLIOTECA,E.FECHA_SOLICITUD,E.FECHA_COMPRA