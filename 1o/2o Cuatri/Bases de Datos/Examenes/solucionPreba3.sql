/*Mostrar el número de lectores de Logroño que han tomado en préstamo algún ejemplar 
de todos y cada uno de los libros escritos por escritores que se llaman como ellos
(coincide nombre y apellido). 

Puedes usar ciudad(dirección) para extraer la ciudad de una dirección.*/

  

select count(*)-- cualquier campo

from lector as l

where ciudad (l.dirección) = ‘Logroño’ and

not exists

     (select a.id

     from autor as a

     where a.nombre = l.nombre and a.apellido = l.apellido -- correlación autores con el mismo nombre y apellido

     except

     select a1.autor

     from autorlibro as al join

          prestamo as p on al.libro= p.libro

     where p.lector = l.id -- correlación de la división: lector

     )

 

/*Mostrar los nombres de las bibliotecas de La Rioja (tfno comienza por 941) que tienen 
ejemplares de todas las editoriales ubicadas en su misma ciudad (al menos un ejemplar de 
cada una de esas editoriales). Puedes usar la función ciudad(dirección) para extraer la 
ciudad de una dirección.*/

 

select b.nombre

from biblioteca as b

where tfn like ‘941%’ and

not exists

     (select e.nombre

     from editorial as e

     where ciudad(e.direccion) = ciudad(b.direccion) -- correlación editoriales de su misma ciudad

     except

     select l.editorial

     from libro as l join

          ejemplar as ej on l.id = ej.libro

     where ej.biblioteca = b.id -- correlación de la división: biblioteca

     )

 

/*Mostrar el código y el título de los libros del autor “Isaac Asimov” como único autor que 
tengan ejemplares prestados y no devueltos en todas las bibliotecas de La Rioja 
(tfno comienza por 941).*/

 

select l.id, l.titulo

from libro as l join

     autorlibro as al on l.id = al.libro join

     autor on al.autor = a.id left join

autorlibro al2 on al.libro=al2.libro and al.autor<>al2.autor

where a.nombre= ‘Isaac’ and a.apellidos = ‘Asimov’ and

      al2.libro is null

and not exists

     (select b.id

     from biblioteca b

     where b.tfn like ‘941%’

     except

     select e.biblioteca

     from ejemplar as e join

          prestamo as p on e.libro = p.libro 

and e.ejemplar = p.ejemplar

     where p.fecha_devuelto is null

and e.libro = l.id -- correlación de la división: libro

     )

 

/*Mostrar los años que llevan de media inscritos los lectores que han tomado 
ejemplares en préstamo en todas las bibliotecas de su misma ciudad. 

Puedes usar las funciones  

    year(fecha) para extraer el año de una fecha 
    hoy() para obtener la fecha de hoy .
    ciudad(dirección) para extraer la ciudad de una dirección.*/

select avg(year(hoy())-year(l.fecha_inscripcion))

from lector as l

where

not exists

     (select b.id

     from biblioteca as b

     where ciudad (b.direccion) = ciudad (l.dirección) -- correlación bibliotecas de su misma ciudad

     except

     select e.biblioteca

     from ejemplar as e join

          prestamo as p on e.libro = p.libro 

and e.ejemplar = p.ejemplar

     where p.lector = l.id -- correlación de la división: lector

     )

 

/*Nombre y apellidos de los lectores que tienen para todos los libros de los que es 
primer_solicitante algún préstamo de más de 15 días (para cada uno de estos libros debe 
tener un préstamo mayor de 15 días). Por simplicidad no se consideran los préstamos 
no devueltos en el cálculo de la solución. En la solución sólo queremos que aparezcan 
lectores que sean primer solicitante de algún libro. Se puede utilizar la 
función dias(fecha_inicial, fecha_final) */

 

select l.nombre, l.apellidos

from lector as l join

     libro as li on l.id = li.primer_solicitante

where

not exists

     (select li2.id

     from libro as li2

     where li2.primer_solicitante = l.id -- correlación para todos los libros del que es primer solicitante

     except

     select p.libro

     from prestamo as p 

     where dias(p.fecha_prestado, p.fecha_devuelto)>15

     and p.lector = l.id -- correlación de la división: lector

     )

 

/*Nombre y tfno de las editoriales, y año en el que la editorial editó su último libro
 (el más reciente de la editorial) y cuyo número de lectores diferentes de los libros 
 de la editorial en ese año aumentó respecto al número de lectores diferentes de todos 
 los libros de esa editorial editados el año anterior.*/

 

select l.editorial, e.tfno, l.año

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.año >=all (select l1.año from libro l1 where l1.editorial=l.editorial) -- correlación

group by l.editorial, e.tfno, l.año

having count(distinct p.lector)>

(

select count(distinct p1.lector)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and l2.año=l.año-1 -- correlación

)

 

/*Alternativa*/

 

select l.editorial, e.tfno

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.precio<10

group by l.editorial, e.tfno, l.año

having l.año >=all (select l1.año from libro l1 where l1.editorial=l.editorial) and count(distinct p.lector)>

(

select count(distinct p1.lector)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and l2.año=l.año-1 -- correlación

)

 

/*Nombre y dirección de las editoriales, y año que editaron el libro (o libros) 
más caro de la editorial y cuyo número de lectores diferentes 
(del libro o libros más caros ese año) disminuyó respecto al total de lectores 
diferentes de todos los libros de esa editorial editados el año anterior.*/

 

select l.editorial, e.direccion

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.precio >=all (select l1.precio from libro l1 where l1.editorial=l.editorial)

group by l.editorial, e.direccion, l.año

having count(distinct p.lector)<

(

select count(distinct p1.lector)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and l2.año=l.año-1 -- correlación

)

 

/*Nombre y teléfono de las editoriales junto al año en el que editaron el libro (o libros)
 más voluminoso (con mayor número de páginas) de la editorial y cuyo número de 
 ejemplares prestados (de ese libro o libros más voluminosos) aumentó al menos un 20% respecto
  al total de ejemplares prestados de esa editorial editados el año anterior.*/

 

select l.editorial, e.tfno, l.año

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.paginas >=all (select l1.paginas from libro l1 where l1.editorial=l.editorial) 

group by l.editorial, e.tfno, l.año

having count(p.ejemplar)>=

(

select 1.20*count(p1.ejemplar)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and l2.año=l.año-1 -- correlación

)

 

/*
Nombre y dirección de las editoriales junto al año en el que se prestó el libro (o libros)
más barato de la editorial y cuyo número de lectores diferentes (de ese libro o libros más baratos)
aumentó respecto al total de lectores de todos los libros de esa editorial prestados el 
año anterior. */

 

select l.editorial, e.direccion, year(p.fecha_prestado)

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.precio <=all (select l1.precio from libro l1 where l1.editorial=l.editorial)

group by l.editorial, e.direccion, year(p.fecha_prestado)

having count(distinct p.lector)>

(

select count(distinct p1.lector)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and year(p1.fecha_prestado)=year(p.fecha_prestado)-1 -- correlación

)

 

/*Nombre y tfno de las editoriales y año en el que la editorial editó su último libro 
(el más reciente de la editorial) y cuyo número de lectores diferentes de los libros de la 
editorial en ese año aumentó respecto al número de lectores diferentes de los libros no devueltos 
de esa editorial editados el año anterior.*/

 

select l.editorial, e.tfno, l.año

from editorial e

join libro l on l.editorial=e.nombre

join prestamo p on p.libro=l.id

where l.año >=all (select l1.año from libro l1 where l1.editorial=l.editorial) -- correlación

group by l.editorial, e.tfno, l.año

having count(distinct p.lector)>

(

select count( distinct p1.lector)

from libro l2

join prestamo p1 on p1.libro=l2.id

where l2.editorial=l.editorial -- correlación

and l2.año=l.año-1 -- correlación

and p1.fecha_devuelto is null

)