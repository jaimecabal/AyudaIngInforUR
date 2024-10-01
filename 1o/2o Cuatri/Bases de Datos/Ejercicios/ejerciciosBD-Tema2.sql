/*201. Crea la vista PresNoDevuelto que obtenga los préstamos no devueltos hechos hace 365 días o más. 
Escribir una consulta con la vista que obtenga código, título de libro y nº de préstamos no devueltos hechos hace 365 días o más.*/
Create view as PresNoDevuelto
    select *
    from prestamo
    where datediff(current_date(), fecha_prestado)>365 and fecha_devuelto is null

select l.id, l.titulo, count(*)
where libro l join
           PresNoDevuelto p on l.id=p.libro
group by l.id, l.titulo

/*202. Introducir el libro (“L111”, “Bases de Datos”, “Editores Reunidos”, 2015, 34, 160, 33, “Le48”). El autor es Andrés Pérez de código A12. Ni este ni la editorial (dirección La Paz 5, Logroño) están en la BD, pero sí el 1º solicitante.*/
Insert into autor values (‘A12’, ‘Andrés Pérez’);

Insert into editorial values (‘Editores Reunidos’, ‘La Paz, 5, Logroño’, null);

Insert into libro values (‘111’, ‘Bases de Datos’, ‘Editores Reunidos’, 2015, 34, 160, 33, ‘Le48’);

Insert into autorlibro values (‘A12’,’L111’);

/*203. Incluir en la biblioteca P1 el ejemplar de código L112 del único libro del autor Pepe Pérez. La fecha de solicitud es hoy y la de compra nula.*/
insert into ejemplar
       values ((select libro from autorlibro join autor on autor.id = autorlibro.autor where nombre =‘Pepe’ and apellido=‘Pérez’), ‘L112’, ‘P1’,current_date(), null);

/*204. Se va a cerrar la biblioteca de Almendralejo. Se van a trasladar sus ejemplares a la biblioteca de Haro. Hay que eliminar la biblioteca y la información de sus préstamos.*/
delete from prestamo

where (libro, ejemplar) in (select libro, ejemplar
                                  from  ejemplar e 
                                  join  biblioteca b on e.biblioteca=b.id
                                    where direccion like ‘%Almendralejo’);

update ejemplar
set biblioteca = (select id
                    from  biblioteca
                    where direccion like ‘%Haro’)

where biblioteca = (select id
                        from  biblioteca
                        where direccion like ‘%Almendralejo’);

delete from biblioteca
where direccion like ‘%Almendralejo’;

/*205. El lector Mario Redondo (sólo hay uno con ese nombre) se da de baja y hay que eliminarlo junto a toda la información de su actividad (préstamos y libros solicitados).*/
delete from prestamo
where lector = (select id
                from  lector
                where nombre =‘Mario’ and apellidos = ‘Redondo’);

update libro
set primer_solicitante = null
where lector = (select id
                from  lector
                where nombre =‘Mario’ and apellidos = ‘Redondo’);

delete from lector
where nombre =‘Mario’ and apellidos = ‘Redondo’;

/*206. Escribe las instrucciones de creación de las tablas de esta parte de la BD Empresa en el orden adecuado*/
create table empleado
( NSS varchar(15) not null,
  nombre varchar(30) not null,
  apellidos varchar(30) not null,
  fechaNcto date,
  dirección varchar(100),
  sexo varchar(1),
  salario int,
  jefe varchar(15),
  depto int,  -- tiene que ser el mismo tipo de datos que la clave primaria de departamento
  primary key (NSS),
  foreign key (jefe) references empleado(NSS)
);

create table familiar
( empleado varchar(15) not null,
  nombre varchar(30) not null,
  fechaNcto date not null,
  sexo varchar(1),
  parentesco varchar(30)
  primary key (empleado, nombre, fechaNcto),
  foreign key (empleado) references empleado(NSS)
);

/*207.    Crea la tabla profesorPrimerC con los profesores del 1º cuatrimestre. Llamar a las columnas idProf, dniProf, idAsig.*/
create table profesorPrimerC (idProf, dniProf, IdAsig)  as
            select distinct P.idprofesor, P.dni, A.idAsignatura
            from  profesor P 
            join asignatura A on P.idprofesor=A.idprofesor
            where cuatrimestre = 1 ;

/*Crea la tabla AsigMuchaMatricula con las asignaturas con más de 100 alumnos. Tendrá las mismas columnas que la tabla Asignatura.*/
create table AsigMuchaMatricula    as
            select A.idasignatura, A.nombre, A.idTitulacion, creditos, cuatrimestre, costeBasico,idProfesor, curso
            from  asignatura A join alumnoasignatura AA on A.idasignatura=AA.idasignatura
            group by A.idasignatura, A.nombre, A.idTitulacion, creditos, cuatrimestre,costeBasico, idProfesor, curso
            having count(*)>100 ;

/*Haz algo similar para asignaturas sin matrícula.*/
create table AsigSinMatricula    as
            select A.*
            from  asignatura A
            where id_asignatura not in (select idasignatura
            from alumnoasignatura) ;

/*206 bis. Escribe las instrucciones de creación de las tablas de la BD Empresa en el orden adecuado*/
create table proyecto
( numero int not null,
  nombre varchar(30) not null,
  localidad varchar(30),
  depto int,  -- tiene que ser el mismo tipo de datos que la clave primaria de departamento
  primary key (numero),
  unique(nombre)
);
-- antes de definir la clave extranjera “depto” hay que crear la tabla departamento
-- Los cambios sobre la definición de una tabla los veremos a continuación
alter table proyecto
  add constraint fk_departamento foreign key (depto) references departamento(numero)
            on delete restrict on update cascade;

create table trabaja
(empleado int not null, -- mismo tipo que primaria de empleado
 proyecto int not null, -- mismo tipo que primaria de proyecto
 horas int,
 primary key (empleado, proyecto),
 foreign key (proyecto) references proyecto(numero)
);

-- antes de definir la clave extranjera “empleado” hay que crear la tabla empleado

alter table trabaja
 add constraint fk_empleado foreign key (empleado) references empleado(nss)
            on delete restrict on update cascade;
/*210.    Añade el campo ciudad a la tabla empleado. 
Actualiza las filas de empleado para que ciudad contenga la ciudad de la dirección y dirección contenga sólo la calle y el número
(suponer funciones ciudad() y resto() que obtienen a partir de una dirección, la ciudad, por un lado, y la calle y número por otro).*/
Alter table empleado
    add column ciudad varchar(30);

-- suponemos que hemos hecho las funciones ciudad y resto utilizando substring, instr, length, …

update empleado
    set ciudad=ciudad(dirección), direccion=resto(direccion);

/*211. Sobre la BD recién definida y sin filas, elimina la tabla trabaja.*/
DROP TABLE TRABAJA;

/*212. Crea la tabla jefe y llénala con los empleados sin jefe. Deberá tener las mismas restricciones que empleado. Borra la columna jefe esta tabla.*/
create table jefe as
   select *
   from empleado
   where jefe is null;   -- crea la tabla sin restricciones

alter table jefe
    drop column jefe,
    add constraint pk_jefe primary key(nss),
    add constraint fk_depto foreign key(depto)
           references departamento(numero)
           on delete cascade on update cascade

/*122.Nombre de titulación, curso y cuatrimestre con a su nº de asignaturas y coste básico medio.*/
select ti.nombre, curso, cuatrimestre, count(*) as numasig, avg(costebasico) costebasicomed
from asignatura as ag 
join titulacion as ti on  ag.idtitulacion = ti.idtitulacion
group by ti.nombre, curso, cuatrimestre

/*55. Nombre de cada asignatura y número de alumnos matriculados en ella.*/
select nombre as asig, count(*) as numalum
from asignatura as ag 
join alumnoAsignatura as aa on  ag.idasignatura = aa.idasignatura
group by ag.idAsignatura, nombre

/*123. Cada nueva matrícula de una asignatura (numeroMatrícula) supone un 10% de aumento sobre el coste básico.
Mostrar el identificador de cada alumno junto a lo que ha pagado en concepto de matrícula.*/
select idalumno, sum(CosteBasico * (1 + (NumeroMatricula-1)*0.1) as ‘Coste matricula’
from asignatura as ag
join alumnoAsignatura as aa on  ag.idasignatura = aa.idasignatura
group by idalumno

/*124. Nombre de biblioteca, nº de libros distintos prestados y nº de préstamos hechos (de las bibliotecas que hayan hecho algún préstamo)*/
select b.nombre, count(distinct e.libro) as ‘Total libros’, count(*) as ‘Total prestamos’
from biblioteca b 
join ejemplar e on  b.id=e.biblioteca 
join prestamo p on e.libro = p.libro and e.ejemplar = p.ejemplar
group by b.id, b.nombre

/*125. Código y nombre de titulación, nº de asignaturas y media del coste básico de las mismas, para
titulaciones cuyo coste básico total de las asignaturas sea mayor de 600€*/
select ti.idtitulacion, ti.nombre, count(*), avg(costebasico)
from asignatura as ag 
join titulacion as ti on  ag.idtitulacion = ti.idtitulacion
group by ti.idtitulacion, ti.nombre
having sum(costebasico) > 600

/*61. Apellido y nombre de los alumnos con dos asignaturas o más, ordenados alfabéticamente.*/
 select nombre, apellido
  from persona as pe 
  join alumno as al on pe.dni = al.dni 
  join alumnoAsignatura as aa on al.idalumno = aa.idalumno
  group by al.idAlumno, nombre, apellido
  having count(*) >= 2
  order by nombre, apellido

/*62. Apellido y nombre de alumnos que pagaron más de 500€ por asignaturas de la titulación de ‘Matemáticas’*/
select p.nombre, p.apellido
from persona as p join
         alumno as a on p.dni = a.dni join
         alumnoAsignatura as aa on a.idalumno = aa.idalumno join
         asignatura as asig on asig.idAsignatura=aa.idAsignatura join
         titulacion as t on  asig.idtitulacion = t.idtitulacion
where t.nombre= ‘Matemáticas’
group by a.idAlumno, p.nombre, p.apellido
having  sum(asig.costebasico)>500

/*66. Identificador de los alumnos matriculados en las asignaturas 150212 y 130113 (en ambas a la vez).*/
select idAlumno
from alumnoasignatura
where idAsignatura in ('150212', '130113')
group by idAlumno
having count(*) = 2

/*126. Código de los clientes que han gastado en su ciudad un total de más de 20 € */
select c.ident_client

from cliente c 
join venta v on c.ident_client = v.ident_client 
join tienda t on  t.ident_tiend = v.ident_tiend and c.ciud = t.ciud
 group by c.ident_client
 having sum(prec_total)>20

/*127. Código de tienda y nº de clientes procedentes de otra localidad (diferentes) a los que la tienda les ha vendido algo (si no ha vendido nada a gente de otras localidades no sacarla).*/
select t.ident_tiend, count(distinct v.ident_client) as 'Clientes de fuera'
from cliente c 
join venta v on c.ident_client = v.ident_client 
join tienda t on  t.ident_tiend = v.ident_tiend and c.ciud <> t.ciud
 group by t.ident_tiend;

/*118. Parejas de dni donde uno pertenece a un alumno y el otro a un profesor y 
ambos tienen el mismo nombre y el mismo apellido (exceptuando las parejas que sean de la misma persona)*/
select pa.dni as dni_alumno, pp.dni as dni_profesor
from  persona as pa 
join alumno as a on pa.dni=a.dni 
join persona as pp on pa.nombre=pp.nombre and pa.apellido=pp.apellido and pa.dni<>pp.dni
join profesor as pr on pp.dni=pr.dni

/*118’. …pero sólo para alumnos que tengan más de cinco asignaturas y para profesores de Logroño*/
select pa.dni, pp.dni
from  persona as pa 
join alumno as a on pa.dni=a.dni 
join persona as pp on pa.nombre=pp.nombre and pa.apellido=pp.apellido and pa.dni<>pp.dni
join profesor as pr on pp.dni=pr.dni 
join alumnoasignatura as aa on a.idalumno=aa.idalumno
where pp.ciudad=‘Logroño’
group by pa.dni, pp.dni
having count(*)>5

/*128. DNI de quienes son alumnos o profesores*/
select dni
from alumno
union
select dni
from profesor

/*129. Todos los datos de las personas que no son profesores*/
select *
from persona
except
select *
from persona join profesor on persona.dni=profesor.dni

/*130. DNI de quienes no son profesores ni alumnos*/
select dni
from persona
except
(select dni
  from profesor
  unión
  select dni
  from alumno
)

/*66. Identificador de los alumnos matriculados en las asignaturas 150212 y 130113 (en ambas a la vez)*/
select idAlumno
from alumnoasignatura
where idAsignatura = '150212'
intersect
select idAlumno
from alumnoasignatura
where idAsignatura = '130113'

/*131. Códigos de artículo del proveedor ‘El Barato’ sin ventas a clientes de ‘Madrid’*/
select a.ident_artic
from articulo a 
join proveedor p on a.ident_prov=p.ident_prov
where p.nombr_prov=‘El Barato’
except
select v.ident_artic
from venta v 
join cliente c on v.ident_client=c.ident_client
where c.ciud=‘Madrid’

/*132. Id de asignaturas sin matriculaciones.*/
select A.idAsignatura
from  asignatura A  
left join alumnoasignatura as AA on A.Idasignatura=AA. Idasignatura
where AA.idasignatura is null;

/*133. También podemos hacerlo con except:*/
select A.idAsignatura
from asignatura A
except
select AA.idAsignatura
from alumnoasignatura as AA

/*134. Nombre, apellido y nº de créditos matriculados de los alumnos, incluyendo los de 0 créditos.*/
select P.nombre, P.apellido, coalesce(sum(creditos),0)
from ( persona P join
           alumno A on P.dni=A.dni)
         left join
         ( alumnoasignatura as AA join
            asignatura as AG on AA.IdAsignatura=AG.IdAsignatura)
        on A.Idalumno=AA. Idalumno
group by A.IdAlumno, P.nombre, P.apellido;

/*134. Nombre, apellido y nº de créditos matriculados de los alumnos, incluyendo los de 0 créditos.*/
select P.nombre, P.apellido, sum(creditos)
from (persona P join
          alumno A on P.dni = A.dni) join 
          alumnoasignatura as AA on A.Idalumno=AA. Idalumno join
          asignatura as AG on AA.IdAsignatura=AG.IdAsignatura
group by A.IdAlumno, P.nombre, P.apellido
union
select P.nombre, P.apellido, 0
from (persona P join
          alumno A on P.dni = A.dni) left join
          alumnoasignatura as AA on A.Idalumno=AA. Idalumno
where AA.idalumno is null;

/*135. Nombre de titulaciones, nº de asignaturas que tienen y nº total de créditos, incluyendo las titulaciones sin asignaturas con sendos ceros*/
select T.nombre, count(IdAsignatura), coalesce(sum(creditos),0)
from titulacion T left outer join
         asignatura A on T.idtitulacion = A.idtitulacion
group by T.IdTitulacion, T.nombre;

/*135. Nombre de titulaciones, nº de asignaturas que tienen y nº total de créditos, incluyendo las titulaciones sin asignaturas con sendos ceros*/
select T.nombre, count(IdAsignatura), coalesce(sum(creditos),0)
from titulacion T left outer join
         asignatura A on T.idtitulacion = A.idtitulacion
group by T.IdTitulacion, T.nombre;

/*136. Para cada asignatura obtener su código, nombre de asignatura y nombre de titulación. Si no tiene titulación poner ‘Asignatura de Campus’ en lugar del código de titulación*/
select idAsignatura, A.nombre, coalesce(T.nombre, 'Asignatura Campus')
 from asignatura as A left join
          titulacion as T on A.idtitulacion=T.idtitulacion;
    /*O usando CASE*/
select idAsignatura, A.nombre,
          case
               when T.nombre is not null thenT.nombre
               else 'Asignatura Campus'
         end
 from asignatura as A left join
          titulacion as T on A.idtitulacion=T.idtitulacion;

/*137. NSS, salario, salario total de los subordinados (salarioSub) y nº de subordinados (numSub) de todos los empleados */
select  je.nss, je.salario, coalesce(sum(e.salario),0) as salarioSub, count(e.nss) as numSub
from empleado je left join
         empleado e on je.nss= e.jefe
group by je.nss, je.salario;

/*141. Nombre, nº de libros de más de 1.000 páginas y nº total de páginas de los libros de las editoriales de Barcelona.*/
select e.nombre, count(l.id) as TotalLibros, coalesce(sum(l.paginas), 0) as SumaPaginas
from editorial e left join
         libro l  on e.nombre = l.editorial and paginas>1000
where e.direccion like '%Barcelona'
group by e.nombre;

/*142. ID y nombre de bibliotecas de Logroño, nº de ejemplares que pesen más de 980 gr. (NumLibros) y peso total de dichos ejemplares (PesoLibros).*/
select b.id, b.nombre, count(e.libro) as NumLibros, coalesce(sum(l.peso), 0) as PesoLibros
from  biblioteca b left join
          (libro l join
          ejemplar e on l.id=e.libro and peso >980) on b.id =e.biblioteca
where direccion like '%Logroño'
group by b.id, b.nombre;

/*51. Listado de asignaturas que tengan más créditos que la asignatura de libre elección Seguridad Vial.*/
select a.*
from asignatura a
where a.creditos > (select creditos
                   from asignatura
                   where nombre= 'Seguridad Vial' and IdTitulacion is null)

/*67. Nombre de las asignaturas de la titulación 130110 cuyo coste básico sobrepase el coste básico promedio por asignatura en dicha titulación.*/
select nombre
from asignatura
where idTitulacion = '130110' and
         costeBasico > (select avg(costeBasico)
                               from asignatura
                               where idTitulacion = '130110')

/*18. Nombre y apellido de los alumnos que tengan cualquier asignatura menos la 150 ó la 130.*/
select p.nombre, p.apellido
from    persona as p join
            alumno as a on p.dni=a.dni join
            alumnoAsignatura as aa on a.idalumno=aa.idalumno
where idalumno not in
 (select idalumno
 from alumnoasignatura
 where idasignatura in (‘150’,’130’))

/*114.Nombres de asignatura con mayor nº de créditos */
select nombre
from asignatura a cross join
         asignatura b
group by a.idasinatura, a.nombre, a.creditos
having a.creditos = max(b.créditos)

/*145. Nombre de las asignaturas excepto las que tengan más créditos.*/
select nombre
from asignatura
where creditos < (select max(creditos) from asignatura)

/*74. Personas domiciliadas en una de las localidades con más personas de la BD*/
select p.nombre, p.apellido
from persona p
where p.ciudad in
          (select p1.ciudad
           from persona p1
           group by p1.ciudad
           having count(*) >= ALL
                      (select count(*)
                       from persona p1
                       group by p1.ciudad
                      )
          );

/*146. Personas de la BD no domiciliadas en alguna de las localidades con más personas*/
select p.nombre, p.apellido
from persona p
where dni not in
 (select dni
  from persona p
  where p.ciudad in
          (select p1.ciudad
           from persona p1
           group by p1.ciudad
           having count(*) >= ALL
                      (select count(*)
                       from persona p1
                       group by p1.ciudad
                      )
          )
);

/*147. Nombre de las asignaturas de Matemáticas con coste básico mayor al coste básico promedio por asignatura de la titulación.*/
select A.nombre
from asignatura A join
          titulacíon T on A.idTitulacion = T.titulacion
where T.nombre =‘Matemáticas’
And costeBasico >= (select avg(costeBasico)
                          from asignatura A join
                                               titulacíon T on A.idTitulacion = T.titulación
                                      where T.nombre =‘Matemáticas’)

/*148. Nombre de las asignaturas con coste básico mayor al coste básico promedio por asignatura de _su_ titulación.*/
select nombre
from asignatura as A
where costeBasico > (select avg(costeBasico)
                               from asignatura as A1
                               where A.Idtitulacion= A1.Idtitulacion)
/*149. DNI de los alumnos de Madrid con más créditos de entre todos los alumnos de Madrid (sin correlación)*/
select P.dni
from persona P join
         alumno A on P.dni=A.dni join
         alumnoAsignatura AA on A.idalumno = AA.idAlumno join
         asignatura Asig on AA.idasignatura = Asig.idasignatura
where P.ciudad='Madrid'
group by P.dni
having sum(Asig.creditos) >=all (select sum(Asig.creditos)
                                               from persona P join
                        alumno A on P.dni=A.dni join
                        alumnoAsignatura AA on A.idalumno =AA.idAlumno join
                        asignatura Asig on AA.idasignatura = Asig.idasignatura
                        where P.ciudad='Madrid'
                        group by P.dni)

/*150. DNI y localidad de los alumnos con más créditos de entre todos los alumnos de _su_ misma localidad*/
select P.dni, P.ciudad
from persona P join
         alumno A on P.dni=A.dni join
         alumnoAsignatura AA on A.idalumno = AA.idAlumno join
         asignatura Asig on AA.idasignatura = Asig.idasignatura
group by P.dni, P.ciudad
having sum(Asig.creditos) >=all
            (select sum(Asig.creditos)
             from persona P1 join
                      alumno A on P1.dni=A.dni join
                      alumnoAsignatura AA on A.idalumno =AA.idAlumno join
                      asignatura Asig on AA.idasignatura = Asig.idasignatura
            where P1.ciudad=P.ciudad --correlación
            group by P1.dni);

/*68. Lista de asignaturas sin alumnos*/
SELECT *
FROM asignatura
WHERE idAsignatura not in (select idAsignatura
                           from AlumnoAsignatura)
/*151. Listado de asignaturas en las que se han matriculado todos los alumnos*/
select *
from asignatura 
where not exists (select idalumno
                  from alumno
                  except
                  select idalumno
                  from alumnoasignatura AA
                  where AA.idAsignatura = A.idAsignatura);
