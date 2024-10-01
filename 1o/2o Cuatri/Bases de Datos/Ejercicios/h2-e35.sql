/*Seleccion el DNI, nombre y apellido de los estudiantes a los que les de clase Jorge Saenz*/
select 	estu.dni,estu.nombre,estu.apellido
from 	persona as estu,persona as profe,
		profesor as p,alumno as al,
		alumnoAsignatura as alA,
		asignatura as asig
where 	estu.dni=al.dni
and 	al.idAlumno=alA.idAlumno
and 	profe.dni=p.dni
and 	p.idProfesor=asig.idProfesor
and 	alA.idAsignatura=asig.idAsignatura
and		profe.nombre like 'Jorge'
and 	profe.apellido like 'Saenz'