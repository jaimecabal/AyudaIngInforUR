/*Identificador y ciudad de las tiendas que han vendido a todos los clientes que son de Lyon */
SELECT T.ident_tiend,T.ciud
FROM TIENDA AS T
WHERE NOT EXISTS (SELECT C.IDENT_CLIENT
			   FROM CLIENTE AS C
			   WHERE C.CIUD='LYON'
			   AND C.IDENT_CLIENT NOT IN (SELECT V.IDENT_CLIENT
										 FROM VENTA AS V
										 WHERE V.IDENT_TIEND=T.IDENT_TIEND))

/*Para cada artículo llamado pesacartas obtener su identificador y el identificador y ciudad de la tienda que ha vendido más unidades del mismo (cant_artics). */
SELECT A.ident_artic,T.ident_tiend,T.ciud
FROM ARTICULO AS A
	JOIN VENTA AS V ON V.IDENT_ARTIC=A.IDENT_ARTIC
	JOIN TIENDA AS T ON T.IDENT_TIEND=V.IDENT_TIEND
	WHERE A.NOMBR_ARTIC='PESACARTAS'
	GROUP BY A.IDENT_ARTIC,T.IDENT_TIEND,T.CIUD
	HAVING SUM(V.CANT_ARTICS) >=ALL (SELECT SUM(VV.CANT_ARTICS)
									 FROM ARTICULO AS AA
										JOIN VENTA AS VV ON VV.IDENT_ARTIC=AA.IDENT_ARTIC
										JOIN TIENDA AS TT ON TT.IDENT_TIEND=VV.IDENT_TIEND
									WHERE AA.IDENT_ARTIC=A.IDENT_ARTIC
									GROUP BY AA.IDENT_ARTIC)

/*Obtener todas las filas y columnas de la tabla proveedor de forma que el proveedor que haya vendido más artículos (en número de unidades) pase a denominarse 'Rodapén'.*/
SELECT P.ident_prov,CASE WHEN P.NOMBR_PROV = ( SELECT P.NOMBR_PROV
								FROM PROVEEDOR AS P
									JOIN ARTICULO AS A ON A.IDENT_PROV=P.IDENT_PROV
									JOIN VENTA AS V ON V.IDENT_ARTIC=A.IDENT_ARTIC
									GROUP BY P.IDENT_PROV,P.NOMBR_PROV
									HAVING SUM(V.CANT_ARTICS)>=ALL (SELECT SUM(VV.CANT_ARTICS)
																	FROM PROVEEDOR AS PP
																		JOIN ARTICULO AS AA ON AA.IDENT_PROV=PP.IDENT_PROV
																		JOIN VENTA AS VV ON VV.IDENT_ARTIC=AA.IDENT_ARTIC
																	GROUP BY PP.IDENT_PROV)) THEN 'Rodapén' ELSE P.NOMBR_PROV
					END AS nombr_prov
FROM PROVEEDOR AS P