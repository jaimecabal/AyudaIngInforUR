/*Identificador de proveedores que tengan alguna venta en Pamplona de más de 5 euros y
 más de 20 euros en el total de ventas de esa misma ciudad. Añadir a las columnas del resultado el número de artículos diferentes vendidos en Pamplona. */

select a.ident_prov, v.cant_artics as 'Total articulos'
from venta as v
	join articulo 	as a on v.ident_artic=a.ident_artic and a.prec_vent>5
	join tienda 	as t on t.ident_tiend=v.ident_tiend and t.ciud='Pamplona'
	where v.prec_total > 20;

/*Mostrar título de los libros, nombre y apellidos (separados por un blanco) del lector y días que ha sido prestado el libro 
para aquellos libros del año 2002 o posterior de la editorial Pergamino que han sido prestados a lectores inscritos a partir 
del año 2003 en la biblioteca Cervantes y cuya autora tiene de nombre Esther. Descartar aquellos libros que aún no han sido devueltos. */
select distinct l.titulo as libro,concat(lec.nombre,' ',lec.apellidos) as lector, datediff(fecha_devuelto,fecha_prestado) as 'Días de lectura'
from lector as lec
	join prestamo as p on p.lector=lec.id
	join libro as l on p.libro=l.id and l.año>=2002 and l.editorial='Pergamino'
	join ejemplar as e on e.libro=l.id
	join biblioteca as b on b.id=e.biblioteca and b.nombre='Cervantes'
	join autorlibro as al on l.id=al.libro
	join autor as a on a.id=al.autor and a.nombre='Esther'
	where year(lec.fecha_inscripcion)>=2003
	and p.fecha_devuelto is not null

/*DNI, apellido y nombre de los alumnos de la titulación de matemáticas que tengan el mismo nombre de pila que algun profesor.*/
select p.dni,p.apellido,p.nombre
from persona as p
	join alumno as a on p.dni=a.dni
	join alumnoAsignatura as al on al.idAlumno=a.idAlumno
	join asignatura as asig on asig.idAsignatura=al.idAsignatura
	join titulacion as t on t.idTitulacion=asig.idTitulacion and t.nombre='Matematicas'
	join persona as profe on profe.nombre=p.nombre
	join profesor as pr on profe.dni=pr.dni

/*Nombre de las titulaciones que tengan al menos un alumno mayor de 35 años (el 1 de enero). */
select distinct t.nombre
from titulacion as t
	join asignatura as asig on asig.idTitulacion=t.idTitulacion
	join alumnoAsignatura as al on al.idAsignatura=asig.idAsignatura
	join alumno as a on al.idAlumno=a.idAlumno
	join persona as p on p.dni=a.dni 
		and (year(current_date())-year(p.fechaNacimiento))>35