/*DNI, apellido y nombre de los alumnos de la titulación de matemáticas
que tengan el mismo nombre de pila que algun profesor.*/
select alum.dni,alum.apellido,alum.nombre
from persona as alum
join persona as prof on alum.nombre=prof.nombre
join alumno as a on alum.dni=a.dni
join profesor as p on p.dni=prof.dni

/*Identificador, apellido y nombre de los alumnos matriculados
en las asignaturas 150212 y 130113 (en ambas a la vez).*/
select a.idAlumno as idalumno, p.apellido,p.nombre
from persona as p
join alumno as a on a.dni=p.dni
join alumnoAsignatura as ala1 on a.idAlumno=ala1.idAlumno
join alumnoAsignatura as ala2 on ala1.idAlumno=ala2.idAlumno
where ala1.idAsignatura=150212 and ala2.idAsignatura=130113;

/*Identificador y nombre de las asignaturas con más créditos
que la asignatura de libre elección (sin titulación) “Seguridad Vial”.*/
select /*a2.idAsignatura,*/ a2.nombre
from asignatura as a1
join asignatura as a2 on a1.creditos < a2.creditos
where a1.nombre='Seguridad Vial';

/*Nombre de cada asignatura de la BD, exceptuando las de la titulación 160000,
junto al número de horas de clase (1 crédito ECTS = 10 horas clase)
y al número de horas total a dedicar por el estudiante
(1 crédito ECTS = 25 horas de dedicación).*/
select a.nombre,a.creditos*10 as 'horas clase',a.creditos*25 as horas_dedicación
from asignatura as a
where idTitulacion <> 160000;

/*Mostrar el nombre, apellidos y edad de los empleados que tengan algún hijo o hija
 que se lleven entre ellos 25 o más años, y entre el empleado y su esposa o esposo se
 lleven entre ellos 2 o más años. (Sugerido por Nerea Miguel.)
 Ayuda: Para calcular la edad el ejercicio usa truncate(datediff(current_date(),E.fechaNcto)/365,0)*/

select distinct e.nombre,e.apellidos, truncate(datediff(current_date(),e.fechaNcto)/365,0) as edad
from empleado as e
join familiar as h 	 on (truncate(datediff(current_date(),e.fechaNcto)/365,0)-truncate(datediff(current_date(),h.fechaNcto)/365,0))>25
					  and h.parentesco like ('hij_')
					  and h.empleado=e.nss
join familiar as esp on (truncate(datediff(current_date(),e.fechaNcto)/365,0)-truncate(datediff(current_date(),esp.fechaNcto)/365,0))>2
					  or (truncate(datediff(current_date(),esp.fechaNcto)/365,0)-truncate(datediff(current_date(),e.fechaNcto)/365,0)>2)
					  and esp.parentesco like ('espos_')
					  and esp.empleado=e.nss

/*Calcular el número de jefes (empleados con jefe nulo) repetidos en los departamentos,
es decir cuántos son segundos, terceros, cuartos... jefes en el mismo departamento.*/
select count(*) - count(distinct e.depto) as jefesRepetidos
from empleado as e
join empleado as j on e.depto=j.depto and e.nss<>j.nss
where e.jefe is null and j.jefe is null

/*Nombre y apellido de los clientes que hayan realizado compras en alguna tienda de la localidad en la que ellos mismos residen.*/
select distinct c.nombr_client,c.apell1
from cliente as c
join tienda as t on c.ciud=t.ciud
join venta as v on v.ident_client=c.ident_client and v.ident_tiend=t.ident_tiend

/*Identificadores de alumno que tengan alguna asignatura en primera matricula ordenados por su identificador de alumno.*/
select alA.idalumno
from alumnoAsignatura as alA
where alA.numeroMatricula=1;

/*Listado de ciudades donde vive tanto algún profesor como algún alumno.*/
select distinct prof.ciudad
from persona as prof
join persona as al on al.ciudad=prof.ciudad
join alumno as a on al.dni=a.dni
join profesor as pr on pr.dni=prof.dni

/*Nombre, apellido y fecha de nacimiento de las personas residentes en Logroño que no nacieran ni en el año 78 ni en el mes de mayo.*/
select p.nombre,p.apellido,p.fechaNacimiento
from persona as p
where 	year(p.fechaNacimiento)<>1978
and 	month(p.fechaNacimiento)<>5
and     p.ciudad='Logroño'

/*Contar el número de hombres y mujeres en la empresa*/
select 	count(case when e.sexo='V' then 1 end) as 'Hombres',
		count(case when e.sexo='M' then 1 end) as 'Mujeres'
from empleado as e

/*Nombre de los empleados que están trabajando en un departamento de Zaragoza
y cuyo director (de departamento) es más viejo que ellos.*/
select e.nombre
from empleado as e
	join departamento as d on e.depto=d.numero
	join localidadesDepto as l on l.depto=d.numero and l.localidad='Zaragoza'
	join empleado as dir on dir.nss=d.director and dir.fechaNcto<e.fechaNcto

/* Calcula el procentaje de trabajadores que tienen jefe,
el salario medio de los que no tienen jefe y el promedio de edad de las mujeres que no tienen jefe */
select (count(case when e.jefe is not null then 1 end)/count(nss))*100 as PorcentajeconJefe,
		avg(case when e.jefe is null then salario end) as mediosinjefe,
		avg(case when e.jefe is null and sexo='M' then (year(current_date())-year(fechaNcto))end) as mediaEdadMujer
	from empleado as e

/*Calcular el NSS, nombre y apellidos de los empleados que trabajan en los proyectos 
'ProductoY', 'Informatización' y 'Reorganización' (en los tres proyectos a la vez). */
select distinct e.NSS,e.nombre,e.apellidos
from empleado as e
	join trabaja as t1 on t1.empleado=e.nss
	join trabaja as t2 on t2.empleado=e.nss
	join trabaja as t3 on t3.empleado=e.nss
	join proyecto as p1 on p1.numero=t1.proyecto and p1.nombre='ProductoY' 
	join proyecto as p2 on p2.numero=t2.proyecto and p2.nombre='Informatización' 
	join proyecto as p3 on p3.numero=t3.proyecto and p3.nombre='Reorganización'

/*Nombre y apellidos de los lectores que hayan solicitado algún libro (primer solicitante)
y que hayan tomado en préstamo uno de sus ejemplares más de 3 años después de comprarlo (haciendo resta de años).
Añadir a la solución la fecha de compra del ejemplar en cuestión y la fecha en la que lo tomó en préstamo el lector.*/
select lec.nombre,lec.apellidos,e.fecha_compra,p.fecha_prestado
from lector as lec
	join prestamo as p on p.lector=lec.id
	join ejemplar as e on p.ejemplar=e.ejemplar and 
		(year(p.fecha_prestado)-year(e.fecha_compra))>3 and p.fecha_prestado>e.fecha_compra
	join libro as l on l.primer_solicitante=lec.id and l.id=e.libro and l.id=p.libro

/*Obtenga el nombre de los proyectos en los que la inicial de su localidad está entre M y T. Puede usar la función left. */
select p.nombre
from proyecto as p
where left(p.localidad,1) between 'M' and 'T'

/*Obtenga los empleados en los que los dígitos tercero y cuarto de su número de la seguridad social 
y de su jefe son 3 y 4 respectivamente y su fecha de nacimiento coincide con la última fecha del mes. 
Muestre nombre, apellidos, año de nacimiento y día de la semana de su fecha de nacimiento. 
Para filtrar el número de la seguridad social utilizar únicamente like. 
Serán de utilidad las funciones dayname y last_day. */
select e.nombre,e.apellidos,year(e.fechaNcto) as 'Año_nacimiento',dayname(e.fechaNcto) as 'Día_de_la_semana_nacimiento'
from empleado as e
where e.nss like ('__34%')
	and e.jefe like ('__34%')
	and day(e.fechaNcto)=day(last_day(e.fechaNcto))

/*Identificadores de las asignaturas en las que están matriculados alumnos que a su vez son profesores.*/
select distinct alA.idasignatura
from alumnoAsignatura as alA
	join alumno as a on a.idAlumno=alA.idAlumno
	join profesor as p on p.dni=a.dni

/*Identificadores de alumno que tengan alguna asignatura en primera matricula ordenados por su identificador de alumno.*/
select alA.idalumno
from alumnoAsignatura as alA
where alA.numeroMatricula=1
order by alA.idAlumno

/*Calcular el número de empleados distintos que trabajan en los proyectos 10, 2 y 3 (en los tres proyectos a la vez),
junto al máximo y el valor medio de las horas trabajadas en dichos proyectos*/
select count(distinct t.empleado) as 'Empleados',max(t.horas) as 'Máximo_horas',avg(t.horas) as 'Media_de_horas'
from trabaja as t
	join trabaja as t2 on t.empleado=t2.empleado and t2.proyecto=2
	join trabaja as t3 on t.empleado=t3.empleado and t3.proyecto=3
	where t.proyecto=10

/*Identificadores de titulación con alguna asignatura de con coste básico por crédito inferior a 7€ en segundo curso
o inferior a 12 y de primer curso */
select distinct a.idtitulacion
from asignatura as a
where ((a.costeBasico)/a.creditos<7 and a.curso=2) or ((a.costeBasico)/a.creditos<12 and a.curso=1)

/*Código sin repeticiones de los libros con dos o más autores. Se debe resolver la consulta sin utilizar la función count().*/
select distinct a1.libro
from autorlibro as a1 
join autorlibro as a2 on a1.libro=a2.libro and a1.autor<>a2.autor

/*Nombre de asignaturas de titulaciones que no sean Matemáticas con menos créditos que alguna de las asignaturas de Matemáticas.*/
select distinct a2.nombre
from asignatura as a
join titulacion as t on t.idtitulacion=a.idtitulacion and t.nombre='Matemáticas'
join asignatura as a2 on a2.idtitulacion<>a.idtitulacion and a.creditos>a2.creditos

/*Qué posibilidades de créditos de asignatura hay en asignaturas de la titulación 130110
 *junto al coste básico por hora de clase (1 crédito=10 horas de clase). */
select distinct creditos, costeBasico/(creditos*10)
from asignatura
where idTitulacion=130110

/*Coste básico y cuatro primeras letras del nombre de las asignaturas de primer curso y
primer cuatrimestre correspondientes a alguna titulación cuyo código acabe en 00. Ayuda: puedes utilizar la función substr */
select left(nombre,4),costebasico 
from asignatura
where curso=1 and cuatrimestre=1 and idtitulacion like '%00'

/*Nombre y apellido de los autores que han escrito algún libro con otro autor
junto al nombre de las bibliotecas con alguno de estos ejemplares de autoría compartida */
select distinct a.nombre,a.apellidos,b.nombre
from autor as a
	join autorlibro as al on al.autor=a.id
	join autorlibro as a2 on a2.autor<>a.id and al.libro=a2.libro
	join ejemplar as e on e.libro=al.libro
	join biblioteca as b on e.biblioteca=b.id