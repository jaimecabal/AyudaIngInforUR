/*Quién invierte más horas en proyectos con códigos entre 10 y 500
¿el empleado 55 o el 99? Ayudas: utiliza case en sum y sum en case.*/

select  coalesce((case when (sum(case when Empleado='555555555' then horas end))<
	    (sum(case when Empleado='999887777' then horas end)) then '999887777' end) ,555555555) as 'másHorasEn10_500'
from trabaja
where proyecto between 10 and 500;