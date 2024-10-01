/*Nombre de asignatura de la titulacion de Matematicas*/
select a.nombre
from asignatura as a,titulacion as t
where a.idTitulacion=t.idTitulacion
and t.nombre='Matemáticas'

/*Nombre de asignaturas y creditos
donde estan matriculadas 'Rosa','Garcia'*/
select asig.nombre,asig.creditos 
from asignatura as asig,persona as p, alumnoAsignatura as alA,alumno as alum
where p.nombre='Rosa' and p.apellido='García'
and p.dni=alum.dni and alum.idAlumno=alA.idAlumno
and alA.idAsignatura=asig.idAsignatura
/*Obten el nombre de los proyectos en los que la inicial
de su localidad esta entre M y T*/
select nombre
from proyecto
where left(localidad,1) between 'M' and 'T'

/*Calcular el numero de empleados distintos que trabajan en total en 
los proyectos 1,2 y 3, junto al maximo y el valor medio de las
horas trabajadas en dichos proyectos*/
select count(case when proyecto in (1,2,3) then 1 end),max(case when proyecto in (1,2,3) then horas end),avg(case when proyecto in (1,2,3) then horas end)
from trabaja
where proyecto in (1,2,3)