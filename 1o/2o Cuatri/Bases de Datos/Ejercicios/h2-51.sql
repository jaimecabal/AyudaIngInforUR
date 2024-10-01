select a2.*
from asignatura as a1 join asignatura as a2 on a2.creditos>a1.creditos
where a1.nombre='Seguridad Vial'