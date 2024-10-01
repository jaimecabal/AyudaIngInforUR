-- Universidad de La Rioja 
-- Bases de Datos 
-- Curso 2019-2020

﻿-- En este script presentamos algunos ejemplos de operaciones
-- conjuntistas (UNION, INTERSECT, EXCEPT)
-- Estos ejemplos no son para ejecutar en MySQL, 
-- MySQL no tiene implementado INTERSECT ni EXCEPT
 
-- Los instrucciones UNION, INTERSECT, EXCEPT son instrucciones muy potentes
-- que permiten resolver consultas complejas de forma sencilla.
-- Se basan en la idea de "romper" la consulta en dos (o más) consultas
-- para después devolver la unión, la intersección o la diferencia de 
-- los resultados de dichas consultas.

-- IMPORTANTE: Los resultados de ambos trozos deben ser "compatibles con la unión".
-- Esto es, deben tener el mismo número de atributos en el select
-- y con tipos compatibles dos a dos. 


-- Utilizaremos el esquema bibliotecas

-- Código y nombre de las bibliotecas con más de 50 libros diferentes y 
-- más de 60 ejemplares diferentes, pero que hayan realizado menos de 160 préstamos. 
-- Nota pueden existir bibliotecas con libros pero sin préstamos.

-- Solución: Por un lado, obtenemos el código y nombre de las bibliotecas
-- con más de 50 libros diferentes y más de 60 ejemplares diferentes. 
-- Por otro lado, obtenemos el código y nombre de las bibliotecas con 
-- menos de 160 préstamos.
-- Finalmente a las obtenidas en primer lugar, quitamos las obtenidas en 
-- segundo lugar.

select b.id, b.nombre 
from biblioteca b join
ejemplar e on b.id = e.biblioteca
group by b.id, b.nombre
having count(e.libro)>60 and count(distinct e.libro)>50
except
select b.id, b.nombre
from biblioteca b join
ejemplar e on b.id = e.biblioteca left join -- Bibliotecas sin préstamos
prestamo p on e.libro=p.libro and e.ejemplar = p.ejemplar
group by b.id, b.nombre
having count(p.libro)< 160;

-- Código y nombre de las bibliotecas con más de 50 libros diferentes 
-- o bien más de 50 préstamos a lectores diferentes.

select b.id, b.nombre 
from biblioteca b join
ejemplar e on b.id = e.biblioteca
group by b.id, b.nombre
having count(distinct e.libro)>50
union
select b.id, b.nombre
from biblioteca b join
ejemplar e on b.id = e.biblioteca join
prestamo p on e.libro=p.libro and e.ejemplar = p.ejemplar
group by b.id, b.nombre
having count(distinct p.lector)>50;


-- Código de libro y título de libros con más de 2 ejemplares 
-- que hayan sido prestados a más de 4 lectores diferentes (en cualquier biblioteca).

select l.id, l.titulo 
from libro l join
ejemplar e on l.id = e.libro
group by l.id, l.titulo
having count(l.id)>2
intersect
select l.id, l.titulo
from libro l join
prestamo p on l.id=p.libro
group by l.id, l.titulo
having count(distinct p.lector)>4;


-- Fin
-- Espero que te haya sido de utilidad este script.
-- No dudes en preguntarnos cualquier duda que te haya surgido.
